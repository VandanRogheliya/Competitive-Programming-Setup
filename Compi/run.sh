#!/bin/bash

# Check if the user has provided a file as an argument
if [ -z "$1" ]; then
  echo "Usage: $0 <path_to_cpp_file>"
  exit 1
fi

# Compile the provided C++ file using C++17 standard and output as 'out'
g++-14 --std=c++20 "$1" -o out

# Check if compilation was successful
if [ $? -eq 0 ]; then
  # Run the compiled output and store it in a temporary file
  ./out > out_output.txt

  # Remove trailing whitespace and newlines from output.txt and store in a temporary file
  sed -e 's/[[:space:]]*$//' -e '/^$/d' output.txt > output_clean.txt

  # Remove trailing whitespace and newlines from binary output as well (for consistency)
  sed -e 's/[[:space:]]*$//' -e '/^$/d' out_output.txt > out_output_clean.txt

  # Compare the cleaned outputs
  if diff -q out_output_clean.txt output_clean.txt > /dev/null; then
    echo "Passed"
  else
    echo "Wrong answer"
    echo ""
    echo "Output:"
    cat out_output_clean.txt
    echo ""
    echo "Diff:"
    diff out_output_clean.txt output_clean.txt
  fi

  rm out_output.txt output_clean.txt out_output_clean.txt
else
  echo "Compilation failed."
  exit 1
fi
