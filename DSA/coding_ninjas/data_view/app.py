import os
from flask import Flask, render_template, jsonify

app = Flask(__name__)

# Directory to scan (parent directory of data_view, which is coding_ninjas)
BASE_DIR = os.path.abspath(os.path.join(os.path.dirname(__file__), '..'))

def analyze_progress():
    stats = {
        'total_questions': 0,
        'total_solved': 0,
        'total_remaining': 0,
        'percentage_complete': 0,
        'topics': []
    }

    # Helper to check if a directory contains solution files
    def is_solved(question_path):
        toushik_path = os.path.join(question_path, "toushik")
        if os.path.exists(toushik_path) and os.path.isdir(toushik_path):
            try:
                # Check for any file in toushik folder
                files = [f for f in os.listdir(toushik_path) if not f.startswith('.')]
                return len(files) > 0
            except OSError:
                return False
        return False

    # Get all entries in BASE_DIR
    try:
        entries = os.listdir(BASE_DIR)
        entries.sort()
    except OSError:
        return stats

    for entry in entries:
        # Check if it looks like a topic folder (starts with a digit)
        if not entry[0].isdigit():
            continue
            
        topic_path = os.path.join(BASE_DIR, entry)
        if not os.path.isdir(topic_path):
            continue
            
        topic_data = {
            'name': entry,
            'total': 0,
            'solved': 0,
            'remaining': 0,
            'completed_percent': 0,
            'questions': [] # Optional: list specific questions if needed later
        }

        # Scan for questions inside the topic
        try:
            questions = sorted(os.listdir(topic_path))
        except OSError:
            continue

        for q in questions:
            # Skip metadata/special folders
            if q.startswith('.') or q in ['toushik', 'shiwang', 'data_view', '__MACOSX']:
                continue
            
            q_path = os.path.join(topic_path, q)
            if not os.path.isdir(q_path):
                continue
            
            # Count this as a question
            topic_data['total'] += 1
            
            if is_solved(q_path):
                topic_data['solved'] += 1
        
        topic_data['remaining'] = topic_data['total'] - topic_data['solved']
        if topic_data['total'] > 0:
            topic_data['completed_percent'] = round((topic_data['solved'] / topic_data['total']) * 100, 1)
        
        stats['topics'].append(topic_data)
        stats['total_questions'] += topic_data['total']
        stats['total_solved'] += topic_data['solved']

    stats['total_remaining'] = stats['total_questions'] - stats['total_solved']
    if stats['total_questions'] > 0:
        stats['percentage_complete'] = round((stats['total_solved'] / stats['total_questions']) * 100, 1)
        
    return stats

def generate_markdown_report(stats):
    report_path = os.path.join(BASE_DIR, "DSA_Progress_Report.md")
    
    lines = []
    lines.append("# DSA Progress Report")
    lines.append("")
    lines.append("## Executive Summary")
    lines.append(f"- **Total Questions**: {stats['total_questions']}")
    lines.append(f"- **Solved**: {stats['total_solved']}")
    lines.append(f"- **Remaining**: {stats['total_remaining']}")
    lines.append(f"- **Overall Progress**: {stats['percentage_complete']}%")
    lines.append("")
    lines.append("## Topic Breakdown")
    lines.append("")
    lines.append("| Topic | Total | Solved | Remaining | Progress |")
    lines.append("|---|---|---|---|---|")
    
    for topic in stats['topics']:
        name = topic['name']
        # Make the name friendlier if needed, but keeping original folder name is good for mapping
        lines.append(f"| {name} | {topic['total']} | {topic['solved']} | {topic['remaining']} | {topic['completed_percent']}% |")
        
    try:
        with open(report_path, "w") as f:
            f.write("\n".join(lines))
        return True
    except IOError:
        return False

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/api/scan')
def scan():
    stats = analyze_progress()
    # Generate report on every scan for freshness
    generate_markdown_report(stats)
    return jsonify(stats)

if __name__ == '__main__':
    app.run(debug=False, port=5001)
