#!/bin/bash

echo [+] Compiler is starting..

file="$1"
build_folder="build/"
statsFile="stats.dat"
compile_files="main.cpp core/utils/console.cpp core/utils/number.cpp core/utils/strings.cpp core/models/player.cpp core/game.cpp core/messages.cpp core/stats/stats.cpp"

if [[ -d $build_folder ]]; then
    rm -rf $build_folder
fi

if [[ -f $statsFile ]]; then
    rm $statsFile
fi

mkdir $build_folder

g++ -std=c++17 $compile_files -o $build_folder/$file

echo [+] Completed!
