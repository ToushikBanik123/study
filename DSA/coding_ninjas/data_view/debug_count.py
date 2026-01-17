import os

# Directory to scan (parent directory of data_view)
BASE_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))

def has_valid_files(directory):
    """Check if directory contains any file other than .DS_Store"""
    try:
        files = []
        for item in os.listdir(directory):
            if item != '.DS_Store' and not item.startswith('.'):
                files.append(item)
        
        if files:
            return True, files
    except OSError:
        pass
    return False, []

def debug_counts():
    toushik_paths = []
    shiwang_paths = []
    
    print(f"Scanning BASE_DIR: {BASE_DIR}")
    
    # Walk through the directory tree
    for root, dirs, files in os.walk(BASE_DIR):
        # Skip the data_view directory itself
        if 'data_view' in root:
            continue
            
        for dir_name in dirs:
            if dir_name.lower() == 'shiwang':
                user_path = os.path.join(root, dir_name)
                is_valid, found_files = has_valid_files(user_path)
                if is_valid:
                    shiwang_paths.append((user_path, found_files))
            elif dir_name.lower() == 'toushik':
                user_path = os.path.join(root, dir_name)
                is_valid, found_files = has_valid_files(user_path)
                if is_valid:
                    toushik_paths.append((user_path, found_files))

    print("\n--- SHIWANG'S SOLUTIONS ---")
    for path, files in shiwang_paths:
        print(f"[COUNTED] {path}")
        print(f"    Files: {files}")
    
    print("\n--- TOUSHIK'S SOLUTIONS ---")
    for path, files in toushik_paths:
        print(f"[COUNTED] {path}")
        print(f"    Files: {files}")
        
    print(f"\nTOTAL COUNTS:")
    print(f"Shiwang: {len(shiwang_paths)}")
    print(f"Toushik: {len(toushik_paths)}")

if __name__ == '__main__':
    debug_counts()
