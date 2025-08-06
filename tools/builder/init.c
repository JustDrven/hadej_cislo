/*
  Copyright (C) - All right reserved

  Author:     JustDrven (petr.nemec11111@gmail.com)
*/

#include "builder_util.h"

int main(int argc, char const *argv[])
{
    if (!__CAN_START)
    {
        ERROR("Neznámý operační system");
        return 1;
    }

    if (argc != 3)
    {
        LOG("Použíj: ./cBuilder [cFile] [file]");
        return 1;
    }

    COMPILE_DATA *data = CompileDataFactory(argv[1], argv[2]);

    Compile(data);

    free(data);

    return data->statusCode;
}
