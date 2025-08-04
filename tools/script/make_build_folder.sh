#!/bin/bash

folder="build/"

if [[ -d $folder ]]; then
    rm -rf $folder
fi

mkdir $folder