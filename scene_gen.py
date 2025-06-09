import os
from typing import List
import yaml


def yml_files() -> List[str]:
    return ["intro.yml", "inn.yml", "customers.yml"]


template_h = """
#pragma once
#include "scene_common.h"
extern struct Scene gen_scene_{scene_name};
"""

template_c = """
#include "gen_scene_{scene_name}.h"

static uint8_t progress;

static void process_input(void) {{
    {process_input}
}}

static void render(uint8_t swapped) {{
    if(swapped){{ progress = 0; }}
    {render}
}}

struct Scene gen_scene_{scene_name} =
{{
    .process_input = process_input,
    .render = render,
}};
"""

template_chat_input = """
if(progress == {progress_step})
{{
    if(input_joycon_a_pressed)
    {{
        progress = {next_progress_step};
    }}
}}
"""

template_chat_render = """
if(progress == {progress_step})
{{
    if(swapped) {{
        text_progress_init({dialog_0}, {dialog_1}, &frame);
    }}
    text_draw_frame_progress(&frame);
}}
"""

template_menu_input = """
if(progress == {progress_step})
{{
    switch(menu_process_input(menu_{progress_step}))
    {{
    case 0:
        progress = {menu_0};
        break;
    case 1:
        progress = {menu_1};
        break;
    }}
}}
"""


def dialog_tree(contents) -> (str, str):
    progress = 0
    process_input = ""
    render = ""
    # print(contents)
    for dialog in contents["dialog"]:
        if isinstance(dialog, str):
            process_input += template_chat_input.format(
                progress_step=progress, next_progress_step=progress + 1
            )
            render += template_chat_render.format(
                progress_step=progress, menu_0=progress + 1, dialog_0="1", dialog_1="1"
            )
        else:
            # menu
            process_input += template_menu_input.format(
                progress_step=progress,
                next_progress_step=progress + 1,
                menu_0="0",
                menu_1="1",
            )
            # render += template_menu_render.format(progress_step=progress)
        progress += 1

    return (process_input, render)


if __name__ == "__main__":
    output_dir = "."

    for file in yml_files():
        with open(file, "r") as f:
            parsed = yaml.load(f.read(), Loader=yaml.Loader)
        (process_input, render) = dialog_tree(parsed)
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
            scene_name=scene_name, process_input=process_input, render=render
        )
        c_filename = os.path.join(output_dir, f"gen_scene_{scene_name}.c")
        with open(c_filename, "w") as f:
            f.write(c_content)
