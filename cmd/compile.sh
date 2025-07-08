#!/bin/bash

echo [+] Compiler is starting..

file="$1"
build_folder="build/"
compile_files="main.cpp utils/console.cpp utils/number.cpp utils/strings.cpp src/models/player.cpp src/game.cpp src/messages.cpp stats/stats.cpp"

if [[ -d $build_folder ]]; then
    rm -rf $build_folder
fi

mkdir $build_folder

g++ -std=c++17 $compile_files -o $build_folder/$file

echo [+] Completed!
