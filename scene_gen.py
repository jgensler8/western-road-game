import os
from typing import List


def yml_files() -> List[str]:
    return ["intro.yml", "inn.yml", "customers.yml"]


template_h = """
#pragma once
#include "scene_common.h"
extern struct Scene gen_scene_{scene_name};
"""

template_c = """
#include "gen_scene_{scene_name}.h"

static void process_input(void) {{

}}

static void render(uint8_t swapped) {{
    if(swapped){{}}
}}

struct Scene gen_scene_{scene_name} =
{{
    .process_input = process_input,
    .render = render,
}};
"""

if __name__ == "__main__":
    output_dir = "."

    for file in yml_files():
        # extract name root
        scene_name = os.path.splitext(file)[0]
        # template h file (use format)
        h_content = template_h.format(scene_name=scene_name)
        h_filename = os.path.join(output_dir, f"gen_scene_{scene_name}.h")
        with open(h_filename, "w") as f:
            f.write(h_content)
        # template c file (use format)
        c_content = template_c.format(scene_name=scene_name)
        c_filename = os.path.join(output_dir, f"gen_scene_{scene_name}.c")
        with open(c_filename, "w") as f:
            f.write(c_content)
