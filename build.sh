#!/bin/bash

echo Compiler is starting..

if [[ -f "app" ]]; then
    rm app
    echo Old app file has been removed!
fi

g++ main.cpp -o app

echo Completed!
