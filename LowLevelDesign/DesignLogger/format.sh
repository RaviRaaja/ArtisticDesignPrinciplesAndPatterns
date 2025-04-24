#!/bin/bash

# Function to check prerequisites
check_prerequisites() {
    if ! command -v clang-format &>/dev/null; then
        echo "clang-format is not installed. Please install it first."
        exit 1
    fi
}

# Function to format files
format_files() {
    local dirs=("$@")
    for dir in "${dirs[@]}"; do
        find "$dir" \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) -type f -exec clang-format -i {} \;
    done
}

# Main script
check_prerequisites
DIRS=("src" "include")
format_files "${DIRS[@]}"

