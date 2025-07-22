import os
import re
import glob
import json
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


def get_instruction_width(instruction, opcodes_data) -> int:
    for opcode_info in opcodes_data["unprefixed"].values():
        if opcode_info["mnemonic"].lower() == instruction.lower():
            return opcode_info["bytes"]
    for opcode_info in opcodes_data["cbprefixed"].values():
        if opcode_info["mnemonic"].lower() == instruction.lower():
            return opcode_info["bytes"]
    if instruction == "ldhl":
        return 3
    print(f"Unknown instruction: {instruction}")
    return 0


if __name__ == "__main__":
    all_funcs = {}
    file_max_len = 32
    func_max_len = 36

    OPCODES_FILE = "tools/Opcodes.json"
    with open(OPCODES_FILE, "r") as f:
        opcodes_data = json.load(f)

    asm_files = glob.glob(pathname="build/**/*.asm", recursive=True)
    for asm_filepath in asm_files:
        if os.path.exists(asm_filepath):
            # print(f"Reading map file: {asm_filepath}")
            map_data = read_map_file(asm_filepath)
            asm_file_short = asm_filepath.removeprefix("build\\").removesuffix(".asm")
            for func, instrs in map_data.items():
                if not func:
                    # asm files without instructions
                    continue
                sum_width = sum(
                    [
                        get_instruction_width(i, opcodes_data) * c
                        for i, c in instrs.items()
                    ]
                )
                # print(f"  {func}: {sum_width} width")
                all_funcs[
                    f"{asm_file_short:<{file_max_len+1}} {func:<{func_max_len+1}}"
                ] = sum_width
        else:
            print(f"File not found: {asm_filepath}")
    for k, v in sorted(all_funcs.items(), key=lambda x: x[1], reverse=True):
        print(f"{k:<40} {v}")
