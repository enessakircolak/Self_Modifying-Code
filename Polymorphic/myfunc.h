#ifndef MYFUNC_H
#define MYFUNC_H

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

    // Define struct once, outside extern "C"
    struct sender {
        int* textBaseAdress;
        int size;
        int* entryPoint;
        int entryOffset;
        int rawTextoffset;
        int architecture;
    };

    // Function declarations (Use `struct sender` for C compatibility)
    struct sender PeParser(char*);
    //int getSize(char*);
    void writeToFile(int*, int, char*);

#ifdef __cplusplus
}
#endif

#endif // MYFUNC_H