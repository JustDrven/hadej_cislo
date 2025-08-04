/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#pragma once

#include "../compiler/precompile.h"
#include "../compiler/file_sys.h"

typedef struct {
    STR cFileName;
    STR fileName;
    int statusCode;
} COMPILE_DATA; 

void Compile(COMPILE_DATA* data) {
    char command[9000];
    snprintf(command, sizeof(command), "clang %s -o %s", data->cFileName, data->fileName);

    printf("%s \n", command);

    int statusCode = system(command);
    data->statusCode = statusCode;
}

COMPILE_DATA* CompileDataFactory(STR cFileName, STR fileName) {
    COMPILE_DATA* data = malloc(sizeof(COMPILE_DATA));
    if (!data) return NULL;

    data->cFileName = cFileName;

    char buffer[512];
    snprintf(buffer, sizeof(buffer), "%s.%s", fileName, __SUFFIX);
    data->fileName = buffer;

    data->statusCode = 1;

    return data;
}
