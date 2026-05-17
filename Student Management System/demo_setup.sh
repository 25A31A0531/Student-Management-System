#!/bin/bash

# Demo script for Student Management System
# This script creates sample student data for testing

echo "Student Management System - Demo Setup"
echo "========================================"
echo ""

# Create sample data file
cat > students.txt << 'EOF'
101
Alice Johnson
Computer Science
92.5
alice.johnson@university.edu
102
Bob Smith
Electrical Engineering
78.0
bob.smith@university.edu
103
Carol Davis
Computer Science
85.5
carol.davis@university.edu
104
David Wilson
Mechanical Engineering
67.0
david.wilson@university.edu
105
Emma Brown
Computer Science
95.0
emma.brown@university.edu
106
Frank Miller
Electrical Engineering
72.5
frank.miller@university.edu
107
Grace Lee
Computer Science
88.0
grace.lee@university.edu
108
Henry Taylor
Mechanical Engineering
81.0
henry.taylor@university.edu
EOF

echo "✓ Created sample student data with 8 students:"
echo "  - 4 Computer Science students"
echo "  - 2 Electrical Engineering students"
echo "  - 2 Mechanical Engineering students"
echo ""
echo "Sample students created:"
echo "  1. Alice Johnson (CS) - 92.5"
echo "  2. Bob Smith (EE) - 78.0"
echo "  3. Carol Davis (CS) - 85.5"
echo "  4. David Wilson (ME) - 67.0"
echo "  5. Emma Brown (CS) - 95.0"
echo "  6. Frank Miller (EE) - 72.5"
echo "  7. Grace Lee (CS) - 88.0"
echo "  8. Henry Taylor (ME) - 81.0"
echo ""
echo "You can now run: ./student_system"
echo "Try these operations:"
echo "  - Option 2: View all students"
echo "  - Option 3: Search for student (try roll 105)"
echo "  - Option 6: View statistics"
echo "  - Option 7: Filter by course (try 'Computer Science')"
echo ""
