import os
import re

print("⚠️ Initiating Targeted Generation (Skipping 0001-0009)...")

with open('README.md', 'r', encoding='utf-8') as file:
    lines = file.readlines()

count = 0
skipped = 0
for line in lines:
    match = re.match(r'^\|\s*(\d{4})\s*\|\s*([^|]+?)\s*\|', line)
    if match:
        num_str = match.group(1)
        raw_name = match.group(2).strip()
        
        # The Shield: Skip anything below 10
        if int(num_str) < 10:
            skipped += 1
            continue
            
        # Clean up the name for the file
        slug = re.sub(r'[^a-zA-Z0-9\s-]', '', raw_name).strip().lower().replace(' ', '-')
        slug = re.sub(r'-+', '-', slug) 
        
        filename = f"{num_str}-{slug}.cpp"
        
        # Generate the fresh file
        with open(filename, 'w', encoding='utf-8') as f:
            f.write(f"// Problem {num_str}: {raw_name}\n")
            f.write("// Let's get to work!\n\n")
        
        print(f"✅ Generated: {filename}")
        count += 1

print(f"\n🚀 Complete! Generated {count} fresh files. Safely skipped {skipped} files.")