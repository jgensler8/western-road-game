import os
import re
from typing import List

def read_map_file(filepath):
    symbol_data = []
    symbol_pattern = re.compile(r'^(?:\s+)(\w+)(?:\s+)(\S+)(?:\s+)(\S+)$')
    section_pattern = re.compile(r'(\w+)(?:\s+)(?:\w+)(?:\s+)(?:\w+)(?:\s+)=')
    current_section = None

    with open(filepath, 'r') as f:
        for line in f:
            match = section_pattern.match(line)
            if match:
                current_section = match.group(1)
                continue
            match = symbol_pattern.match(line)
            if match:
                address, symbol_name, src_file = match.groups()
                address_i = int(address, 16)
                symbol_data.append({'section': current_section, 'address': address_i, 'symbol_name': symbol_name, 'file_name': src_file})
    return symbol_data

def get_file_usage(map_data: List[any]):
    sizes = {}
    for section in set([item['section'] for item in map_data]):
        sizes[section] = {}
        
        # Sort all symbols for the current section by address
        section_symbols = sorted([item for item in map_data if item['section'] == section], key=lambda x: x['address'])

        for i in range(len(section_symbols)):
            current_symbol = section_symbols[i]
            next_symbol_address = None
            if i + 1 < len(section_symbols):
                next_symbol_address = section_symbols[i+1]['address']
            
            size = 0
            if next_symbol_address:
                size = next_symbol_address - current_symbol['address']
            sizes[section][current_symbol['file_name']] = sizes[section].get(current_symbol['file_name'], 0) + size
    return sizes


if __name__ == "__main__":
    map_filepath = "compo25.map" # Adjust to your .map file path

    if os.path.exists(map_filepath):
        print(f"Reading map file: {map_filepath}")
        map_data = read_map_file(map_filepath)
        # print(map_data) # Uncomment to see the raw parsed data
        file_usage = get_file_usage(map_data)
        # print(file_usage) # Uncomment to see the raw file usage data
        # Sort sections by their total size (largest first)
        sorted_sections = sorted(file_usage.keys(), key=lambda s: sum(file_usage[s].values()), reverse=True)
        for section in sorted_sections:
            print(f"Section: {section}")
            sorted_usage = sorted(file_usage[section].items(), key=lambda item: item[1], reverse=True)
            max_name_len = max([len(name) for name, _ in sorted_usage])
            for file, size in sorted_usage:
                print(f"  {file:<{max_name_len + 1}}{size}")

        