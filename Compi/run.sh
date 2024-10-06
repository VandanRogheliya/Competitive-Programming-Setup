#!/bin/bash

# Check if the user has provided a file as an argument
if [ -z "$1" ]; then
  echo "Usage: $0 <path_to_cpp_file>"
  exit 1
fi

# Compile the provided C++ file using C++17 standard and output as 'out'
g++ --std=c++17 "$1" -o out

# Check if compilation was successful
if [ $? -eq 0 ]; then
  # Run the compiled output
  ./out
else
  echo "Compilation failed."
  exit 1
fi
