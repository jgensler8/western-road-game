import os
import re
import glob
from typing import List, Dict


def read_map_file(filepath) -> Dict[str, Dict[str, int]]:
    function_instructions = {}
    function_start = re.compile(r"^; Function (\w+)")
    instruction_match = re.compile(
        r"\t(add|adc|sub|sbc|and|xor|or|cp|inc|dec|daa|cpl|scf|ccf|nop|halt|stop|di|ei|rlca|rrca|rla|rra|rlc|rrc|rl|rr|sla|sra|srl|bit|set|res|jp|jr|call|ret|reti|rst|pop|push|ld|ldh|ldhl)\b"
    )
    instructions = {}
    current_function = None

    with open(filepath, "r") as f:
        for line in f:
            match = function_start.match(line)
            if match:
                # save intermediate function
                if current_function:
                    function_instructions[current_function] = instructions
                current_function = match.group(1)
                instructions = {}
                continue
            match = instruction_match.match(line)
            if match:
                instruction = match.group(1)
                instructions[instruction] = instructions.get(instruction, 0) + 1

    # save last function
    function_instructions[current_function] = instructions
    return function_instructions


def get_instruction_width(instruction) -> int:
    if instruction in ["add", "adc", "sub", "sbc", "and", "xor", "or", "cp"]:
        return 2
    elif instruction in ["inc", "dec", "daa", "cpl", "scf", "ccf"]:
        return 1
    elif instruction in ["nop", "halt", "stop", "di", "ei"]:
        return 1
    elif instruction in [
        "rlca",
        "rrca",
        "rla",
        "rra",
        "rlc",
        "rrc",
        "rl",
        "rr",
        "sla",
        "sra",
        "srl",
    ]:
        return 1
    elif instruction in ["bit", "set", "res"]:
        return 2
    elif instruction in ["jp", "jr", "call", "ret", "reti", "rst"]:
        return 2
    elif instruction in ["pop", "push", "ld", "ldh", "ldhl"]:
        return 3
    else:
        print(f"Unknown instruction: {instruction}")
        return 0


if __name__ == "__main__":
    # Use glob to get all .asm files in the 'build' directory
    asm_files = glob.glob("build/*.asm")

    all_funcs = {}
    
    file_max_len = 32
    func_max_len = 36
    for asm_filepath in asm_files:
        if os.path.exists(asm_filepath):
            # print(f"Reading map file: {asm_filepath}")
            map_data = read_map_file(asm_filepath)
            asm_file_short = asm_filepath.removeprefix("build\\").removesuffix(".asm")
            for func, instrs in map_data.items():
                sum_width = sum([get_instruction_width(i)*c for i, c in instrs.items()])
                # print(f"  {func}: {sum_width} width")
                all_funcs[f"{asm_file_short:<{file_max_len+1}} {func:<{func_max_len+1}}"] = sum_width
        else:
            print(f"File not found: {asm_filepath}")
    for k, v in sorted(all_funcs.items(), key=lambda x: x[1], reverse=True):
        print(f"{k:<40} {v}")

