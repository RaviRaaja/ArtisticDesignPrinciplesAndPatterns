#!/bin/bash
# To create clang format : clang-format -style=llvm -dump-config > .clang-format
# Directories to format
DIRS=("src" "include")

# File extensions to format
EXTENSIONS=("*.cpp" "*.h" "*.hpp")

for DIR in "${DIRS[@]}"; do
    for EXT in "${EXTENSIONS[@]}"; do
        find $DIR -name $EXT -exec clang-format -i {} \;
    done
done
