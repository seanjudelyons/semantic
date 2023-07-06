#!/bin/bash

# just a bin directory
bindir=~/mybin

# create if it does not exist
mkdir -p "$bindir"

# compile binary
gcc -o semantic ./src/main.c ./src/file_reader.c ./src/cosine_similarity.c ./src/vector_processor.c ./src/word_comparison.c -lm

# move to bin
mv semantic "$bindir"

# check shell
current_shell=$(echo $SHELL)

# add to PATH if not already there
if [[ ":$PATH:" != *":$bindir:"* ]]; then
    pathline='export PATH="$PATH:'$bindir'"'
    if [[ $current_shell == *"bash"* ]]; then
        if ! grep -qF "$pathline" ~/.bashrc; then
            echo "$pathline" >> ~/.bashrc
            source ~/.bashrc
        fi
    elif [[ $current_shell == *"zsh"* ]]; then
        if ! grep -qF "$pathline" ~/.zshrc; then
            echo "$pathline" >> ~/.zshrc
            source ~/.zshrc
        fi
    fi
fi
