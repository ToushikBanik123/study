import os
from flask import Flask, render_template, jsonify

app = Flask(__name__)

# Directory to scan (parent directory of data_view)
BASE_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))

def get_solved_counts():
    counts = {
        'shiwang': 0,
        'toushik': 0
    }
    
    # We want to count distinct folders that contain solutions, not just every file
    # A "solved question" is valid if the user folder is not empty
    
    # Walk through the directory tree
    for root, dirs, files in os.walk(BASE_DIR):
        # Skip the data_view directory itself to valid infinite recursion or counting itself
        if 'data_view' in root:
            continue
            
        for dir_name in dirs:
            if dir_name.lower() == 'shiwang':
                user_path = os.path.join(root, dir_name)
                # Check if directory is not empty (ignoring .DS_Store)
                if has_valid_files(user_path):
                    counts['shiwang'] += 1
            elif dir_name.lower() == 'toushik':
                user_path = os.path.join(root, dir_name)
                # Check if directory is not empty (ignoring .DS_Store)
                if has_valid_files(user_path):
                    counts['toushik'] += 1
                    
    return counts

def has_valid_files(directory):
    """Check if directory contains any file other than .DS_Store"""
    try:
        for item in os.listdir(directory):
            if item != '.DS_Store' and not item.startswith('.'):
                return True
    except OSError:
        pass
    return False

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/api/scan')
def scan():
    counts = get_solved_counts()
    return jsonify(counts)

if __name__ == '__main__':
    app.run(debug=True, port=5001)
