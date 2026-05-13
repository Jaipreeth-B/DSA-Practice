import sys
import re
import os

if len(sys.argv) != 5:
    print('Usage: nclog <number> "<strategy>" "<time>" "<space>"')
    sys.exit(1)

# Format the inputs
p_num = str(sys.argv[1]).zfill(4)
strategy = sys.argv[2]
time_c = sys.argv[3]
space_c = sys.argv[4]

readme_path = "README.md"

# 1. Missing File Safety Check
if not os.path.exists(readme_path):
    print("❌ Error: README.md not found in the current directory.")
    sys.exit(1)

with open(readme_path, "r", encoding="utf-8") as file:
    lines = file.readlines()

with open(readme_path, "w", encoding="utf-8") as file:
    updated = False
    for line in lines:
        if line.startswith(f"| {p_num} |"):
            parts = [p.strip() for p in line.split("|")]
            
            # 2. Malformed Row Safety Check
            if len(parts) < 8:
                print(f"⚠️ Warning: Row for {p_num} is malformed. Skipping update.")
                file.write(line)
                continue
                
            name_raw = parts[2]
            if "[" in name_raw:
                name_raw = re.search(r'\[(.*?)\]', name_raw).group(1)
            
            difficulty = parts[3]
            existing_strat = parts[4]
            existing_time = parts[5]
            existing_space = parts[6]
            
            # 3. The Regex Polish (Matches file system exactly)
            slug = re.sub(r'[^a-zA-Z0-9\s-]', '', name_raw).strip().lower().replace(' ', '-')
            slug = re.sub(r'-+', '-', slug) # Clean up any double-hyphens
            filename = f"./{p_num}-{slug}.cpp"
            
            # 4. Prevent Accidental Double-Logging
            if strategy in existing_strat:
                print(f"⚠️ Notice: Strategy '{strategy}' already logged for {p_num}. Skipping duplicate.")
                file.write(line)
                updated = True
                continue

            # 5. Stack Solutions or Add First Solution
            if existing_strat != "":
                final_strat = f"{existing_strat}<br>👉 {strategy}"
                final_time = f"{existing_time}<br>{time_c}"
                final_space = f"{existing_space}<br>{space_c}"
            else:
                final_strat = strategy
                final_time = time_c
                final_space = space_c
            
            new_line = f"| {p_num} | [{name_raw}]({filename}) | {difficulty} | {final_strat} | {final_time} | {final_space} |\n"
            file.write(new_line)
            updated = True
            print(f"✅ README Updated: Problem {p_num} ({name_raw})")
        else:
            file.write(line)
            
    if not updated:
        print(f"❌ Could not find problem {p_num} in README.")