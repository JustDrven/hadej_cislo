#pragma once

#include "../compiler/precompile.h"
#include "../compiler/file_sys.h"

typedef struct CompileData {
    STR cFileName;
    STR fileName;
    UINT statusCode;
} COMPILE_DATA; 

void Compile(COMPILE_DATA* data) {
    char command[512];
    snprintf(command, sizeof(command), "clang %s -o %s", data->cFileName, data->fileName);

    int statusCode = system(command);
    data->statusCode = statusCode;
}

COMPILE_DATA CompileDataFactory(STR cFileName, STR fileName) {
    COMPILE_DATA data;
    data.cFileName = cFileName;
    char fileCommand[512];
    snprintf(fileCommand, sizeof(fileCommand), "%s.%s", fileName, __SUFFIX);
    
    data.fileName = fileCommand;
    data.statusCode = 1;

    return data;
}
