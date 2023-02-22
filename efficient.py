"""
A memory-efficient implementation of the 100 doors problem.

Runs 100 doors by default.
"""
# Set up default doors
doors = 100

# Import dependency to get command line
import sys

if len(sys.argv) >= 2:
    doors = int(sys.argv[1])

status = 0

# Run over the doors
# Outer loop covers the gap
for i in range (1, doors + 1):
    # Inner loop covers door number
    for j in range(1, doors + 1):
        # Check divisibility
        if j % i == 0:
            # Toggle door using bitwise XOR.
            status ^= 2**j

for i in range (1, doors + 1):
    # Compare using bitwise and, using truthy, print door number
    if status & 2**i:
        print(i)
        
