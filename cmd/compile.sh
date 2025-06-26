#!/bin/bash

echo [+] Compiler is starting..
file="$1"

if [[ -f "$file" ]]; then
    rm $file
    echo [-] Old app file has been removed!
fi

g++ -std=c++17 main.cpp utils/console.cpp src/game.cpp -o $file

echo [+] Completed!
