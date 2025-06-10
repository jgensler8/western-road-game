from __future__ import annotations
import os
from typing import List, Mapping
from dataclasses import dataclass
import yaml
import re
from enum import Enum


def yml_files() -> List[str]:
    return ["intro.yml", "inn.yml", "customers.yml"]


template_h = """
#pragma once
#include "scene_common.h"
extern struct Scene gen_scene_{scene_name};
"""

template_c = """#pragma bank 0
#include "gen_scene_{scene_name}.h"

static uint8_t progress;
static uint8_t progress_changed;
static struct ProgressableFrame frame;
{variables}

static void process_input(void) {{
    switch(progress){{
        {process_input}
    }}
}}

static void render(uint8_t swapped) {{
    if(swapped){{ progress = 0; progress_changed = 1; }}
    switch(progress)
    {{
    {render}
    }}
    progress_changed = 0;
}}

BANKREF(gen_scene_{scene_name}_ref)
struct Scene gen_scene_{scene_name} =
{{
    .process_input = process_input,
    .render = render,
}};
"""

template_chat_input = """    case {progress_step}:
        if(joypad_a_pressed)
        {{
            progress = {next_progress_step};
            progress_changed = 1;
        }}
        break;
"""

template_chat_render = """    case {progress_step}:
        if(progress_changed) {{
            text_progress_init("{dialog_0}", "{dialog_1}", &frame);
        }}
        text_draw_frame_progress(&frame);
        break;
"""

template_menu_variables = """
struct Menu menu_{progress_step} = {{
    .options = {{
        "{menu_0_prompt}",
        "{menu_1_prompt}"
    }},
    .max_option = 2,
}};
"""

template_menu_input = """    case {progress_step}:
        if(menu_process_input(&menu_{progress_step}))
        {{
            switch(menu_{progress_step}.selection)
            {{
            case 0:
                progress = {menu_0};
                break;
            case 1:
                progress = {menu_1};
                break;
            }}
            progress_changed = 1;
        }}
        break;
"""

template_menu_render = """    case {progress_step}:
        menu_render(&menu_{progress_step});
        break;
"""


@dataclass
class DialogOptions:
    """Class for keeping track of an item in inventory."""

    flags: Mapping[str, str]
    character: str = ""
    dialog_0: str = ""
    dialog_1: str = ""


class NodeType(Enum):
    DIALOG = 1
    MENU = 2


class Node:
    next: Node = None
    parent: Node = None
    child: List[Node] = []
    type: NodeType
    options: DialogOptions
    id: int = -1


dialog_re = re.compile(r"^((?:\w+=\w+\s+)*)(\S+)\s*(.*)$")


def parse_dialog(dialog: str) -> DialogOptions:
    m = dialog_re.match(dialog)
    if not m:
        raise ValueError(f"dialog does not match re: {dialog}")
    character = m.group(2)
    line = m.group(3)
    lines = ["" for i in range(2)]
    curline = 0
    max_line_len = 18
    for word in line.split(" "):
        if not word:
            continue
        if len(lines[curline]) + 1 + len(word) > max_line_len:
            curline += 1
        if curline >= len(lines):
            raise ValueError(f"total split word len exceeds line count: {dialog}")
        if len(lines[curline]) > 0:
            maybe_space = " "
        else:
            maybe_space = ""
        lines[curline] += maybe_space + word.upper()
    return DialogOptions(
        flags={}, character=character, dialog_0=lines[0], dialog_1=lines[1]
    )


def dialog_build_map(parent: Node, dialog_arr: List[any]) -> Node:
    prev = parent
    start = None
    # link current level
    for d in dialog_arr:
        # print(d)
        if prev == parent:
            start = Node()
            parent.child.append(start)
            prev = start
        else:
            prev.next = Node()
            prev = prev.next
        prev.parent = parent
    # then descend into children
    cur = start
    for d in dialog_arr:
        if isinstance(d, str):
            cur.type = NodeType.DIALOG
            cur.options = parse_dialog(d)
        else:
            cur.type = NodeType.MENU
            if isinstance(d[0], str) or isinstance(d[1], str):
                raise ValueError(f"used simple string instead of list: {d}")
            cur.child = [
                dialog_build_map(cur, d[0]),
                dialog_build_map(cur, d[1]),
            ]
        cur = cur.next
    return start


def dialog_map_init_ids(start: Node):
    id: int = 0
    nodes: List[Node] = [start]
    while len(nodes) > 0:
        cur = nodes[0]
        nodes = nodes[1:]
        # print(id)
        cur.id = id
        id += 1
        if cur.next != None:
            nodes.append(cur.next)
        # if len(cur.child) > 0:
        #     print(cur.child)
        # nodes.extend(n.child)
        # print(nodes)


def dialog_find_next(cur: Node):
    while cur != None:
        if cur.next == None:
            cur = cur.parent
        else:
            return cur.next.id
    # use uint8_t max
    # there will be cases where scene_swap happens at the end of all trees
    # so next will not really exist
    return 254


def dialog_render(start: Node) -> (str, str, str):
    variables = ""
    process_input = ""
    render = ""
    # print(contents)
    cur = start
    while cur != None:
        if cur.type == NodeType.DIALOG:
            next_progress_step = dialog_find_next(cur)
            process_input += template_chat_input.format(
                progress_step=cur.id, next_progress_step=next_progress_step
            )
            render += template_chat_render.format(
                progress_step=cur.id,
                dialog_0=cur.options.dialog_0,
                dialog_1=cur.options.dialog_1,
            )
        elif cur.type == NodeType.MENU:
            # menu
            (v, pi, r) = dialog_render(cur.child[0])
            variables += v
            process_input += pi
            render += r
            (v, pi, r) = dialog_render(cur.child[1])
            variables += v
            process_input += pi
            render += r
            variables += template_menu_variables.format(
                progress_step=cur.id,
                menu_0_prompt=cur.child[0].options.dialog_0,
                menu_1_prompt=cur.child[1].options.dialog_0,
            )
            process_input += template_menu_input.format(
                progress_step=cur.id,
                menu_0=cur.child[0].id,
                menu_1=cur.child[1].id,
            )
            render += template_menu_render.format(progress_step=cur.id)
        cur = cur.next

    return (variables, process_input, render)


if __name__ == "__main__":
    output_dir = "."

    for file in yml_files():
        with open(file, "r") as f:
            parsed = yaml.load(f.read(), Loader=yaml.Loader)
        print(file)
        dialog_map = Node()
        dialog_build_map(parent=dialog_map, dialog_arr=parsed["dialog"])
        dialog_map_init_ids(start=dialog_map.child[0])
        (variables, process_input, render) = dialog_render(start=dialog_map.child[0])
        # extract name root
        scene_name = os.path.splitext(file)[0]
        # template h file (use format)
        h_content = template_h.format(
            scene_name=scene_name, process_input=process_input, render=render
        )
        h_filename = os.path.join(output_dir, f"gen_scene_{scene_name}.h")
        with open(h_filename, "w") as f:
            f.write(h_content)
        # template c file (use format)
        c_content = template_c.format(
            scene_name=scene_name,
            variables=variables,
            process_input=process_input,
            render=render,
        )
        c_filename = os.path.join(output_dir, f"gen_scene_{scene_name}.c")
        with open(c_filename, "w") as f:
            f.write(c_content)
