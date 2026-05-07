import os
import re

files = [f for f in os.listdir('.') if f.endswith('.cpp')]
files.sort() # We sort ascending this time so we don't overwrite files as we shift down

# 1. Nuke the imposter file
duplicate_file = "0009-encode-and-decode-strings.cpp"
if os.path.exists(duplicate_file):
    os.remove(duplicate_file)
    print(f"🗑️ Nuked the duplicate: {duplicate_file}")

# 2. Shift everything from 10 onwards DOWN by 1
for filename in files:
    match = re.match(r'^(\d{4})-(.*\.cpp)$', filename)
    if match:
        num = int(match.group(1))
        name_part = match.group(2)
        
        if num >= 10:
            new_num = num - 1
            new_name = f"{new_num:04d}-{name_part}"
            os.rename(filename, new_name)
            print(f"⬇️ Fixed: {filename} -> {new_name}")

print("\n✅ File system is now perfectly synced with the README!")