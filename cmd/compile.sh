#!/bin/bash

echo [+] Compiler is starting..

file="$1"
compile_files="main.cpp utils/console.cpp utils/number.cpp utils/strings.cpp src/models/player.cpp src/game.cpp stats/stats.cpp"

if [[ -f "$file" ]]; then
    rm $file
    echo [-] Old app file has been removed!
fi

g++ -std=c++17 $compile_files -o $file

echo [+] Completed!
