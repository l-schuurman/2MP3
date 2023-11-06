#!/bin/bash

# Get the directory of the script
# script_dir=$(dirname "$0") # .
script_dir=$(pwd)

# Set the path to the test case results directory
results_dir="$script_dir/tests/results"
solutions_dir="$script_dir/tests/solutions"

# Compile and execute C files with naming convention macid.c
cfile="quiz2.c"

# Compile the C file
gcc -o "$results_dir/quiz2" "$cfile"

if [ $? -eq 0 ]; then
    # Run the C program 20 times with different integer values
    for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20; do
        # Generate a random integer value (modify the range as needed)
        value=$i
        # echo $value

        # Run the program with the integer value and capture the output
        cd $results_dir
        # echo $PWD
        ./quiz2 "$value" > /dev/null

        # echo "Executed $macid with value $value (Result saved to $output)"
    done
fi

# Initialize counters for matching outputs and total files matched
matchingComparisons=0
totalComparisons=0

# Loop through all files in the student's directory
for test_case in "$test_case_dir"/*; do
    if [ -f "$test_case" ]; then
        # Get the corresponding solution file
        solutionFile="$solutions_dir/$(basename "$test_case")"

        # Check if the solution file exists
        if [ -f "$solutionFile" ]; then
            # Compare the student's output with the solution
            if cmp -s "$test_case" "$solutionFile"; then
                matchingComparisons=$((matchingComparisons + 1))
                # echo $test_case
            fi

            totalComparisons=$((totalComparisons + 1))
            # echo "$matchingComparisons $totalComparisons"
        fi
    fi
done

echo "$matchingComparisons/$totalComparisons"