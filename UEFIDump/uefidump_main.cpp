/* uefidump_main.cpp

Copyright (c) 2016, Nikolaj Schlej. All rights reserved.
This program and the accompanying materials
are licensed and made available under the terms and conditions of the BSD License
which accompanies this distribution.  The full text of the license may be found at
http://opensource.org/licenses/bsd-license.php

THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.

*/
#include <iostream>
#include <fstream>

#include "uefidump.h"

int main(int argc, char *argv[])
{
    if (argc > 32) {
        std::cout << "Too many arguments" << std::endl;
        return 1;
    }

    if (argc > 1) {
        std::ifstream inputFile;
        inputFile.open(argv[1], std::ios::in | std::ios::binary);
        std::vector<char> buffer(std::istreambuf_iterator<char>(inputFile),
            (std::istreambuf_iterator<char>()));
        inputFile.close();
        
        UEFIDumper uefidumper;
        return (uefidumper.dump(buffer, UString(argv[1])) != U_SUCCESS);
    }
    else {
        std::cout << "UEFIDump 0.1.0" << std::endl << std::endl
                  << "Usage: UEFIDump imagefile" << std::endl;
        return 1;
    }

    return 1;
}
