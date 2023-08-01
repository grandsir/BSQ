#!/bin/bash

# Function to run ./bsq on each file
run_bsq_on_file() {
  file="$1"
  echo "Running ./bsq on $file"
  ./bsq "$file"
}

# Check if the ./bsq executable exists
if [ ! -x "./bsq" ]; then
  echo "Error: The ./bsq executable does not exist or is not executable."
  exit 1
fi

# Check if the user provided the folder path as an argument
if [ "$#" -ne 1 ]; then
  echo "Usage: $0 folder_path"
  exit 1
fi

# Get the folder path from the argument
folder_path="$1"

# Check if the folder exists
if [ ! -d "$folder_path" ]; then
  echo "Error: The provided folder path does not exist or is not a directory."
  exit 1
fi

# Find all files in the folder recursively and run ./bsq on each file
find "$folder_path" -type f -exec bash -c 'run_bsq_on_file "$0"' {} \;
