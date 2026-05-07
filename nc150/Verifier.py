import os
import re

print("🔍 Initiating Repository Integrity Check...")

# 1. Ask the README what files SHOULD exist
expected_files = set()
with open('README.md', 'r', encoding='utf-8') as file:
    for line in file:
        match = re.match(r'^\|\s*(\d{4})\s*\|\s*([^|]+?)\s*\|', line)
        if match:
            num = match.group(1)
            raw_name = match.group(2).strip()
            
            slug = re.sub(r'[^a-zA-Z0-9\s-]', '', raw_name).strip().lower().replace(' ', '-')
            slug = re.sub(r'-+', '-', slug)
            expected_files.add(f"{num}-{slug}.cpp")

# 2. Look at what ACTUALLY exists
actual_files = set(f for f in os.listdir('.') if f.endswith('.cpp'))

# 3. Find the differences
missing = expected_files - actual_files
extra = actual_files - expected_files

# 4. Report the results
if not missing and not extra and len(expected_files) == 150:
    print("\n✅ PERFECT MATCH! All 150 files are perfectly synced with the README.")
else:
    if missing:
        print("\n❌ MISSING FILES (In README, but not in folder):")
        for f in sorted(missing): 
            print(f"  - {f}")
    if extra:
        print("\n⚠️ EXTRA FILES (In folder, but not in README):")
        for f in sorted(extra): 
            print(f"  - {f}")
            
print(f"\nTotal Expected: {len(expected_files)} | Total Actual: {len(actual_files)}")