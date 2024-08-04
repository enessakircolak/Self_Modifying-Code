#include <Windows.h>
#include <assert.h>
#include <iostream>
#include "Self.h"

using namespace std;

#pragma warning(disable : 4996)

int init_func(int size);
int second_func();


int main(){

    get_write_perm();
    self_func((int*)init_func, (int*)second_func);

    std::cout << "Func value: " << second_func() << std::endl;
    return 0;
}



int second_func() {

    std::string b = "ifyoucan";
    MessageBoxA(0, b.c_str(), "catchme", NULL);
    char buffer[MAX_PATH];
    DWORD length = GetTempPathA(MAX_PATH, buffer);
    MessageBoxA(0, buffer, "ifyoucan", NULL);

    // you need to close optimization settings to use this junk codes
    // Junk code reason ->  need to more size than which is written to this function

    int junk1 = { 5 };
    junk1 = junk1 + 26;
    junk1 = junk1 + (int)second_func;
    junk1 = junk1 ^ 0x55;
    junk1 = junk1 * 3;
    // junk1 = junk1 - (int)init_func();

     // end of the junk code implementation
    spiynxx asd; // junk code implementation but this one is just {e8 (address)} (call 0xXXXXXXXX) so add just 5 byte
    
    // https://junkcode.gehaxelt.in/

    int a = 0;

    bool JunkCode8200 = true;
    if (JunkCode8200 == true)
        JunkCode8200 = false;
    try {
        JunkCode8200 = true;
    }
    catch (...) {}
    try {
        JunkCode8200 = false;
    }
    catch (...) {}
    try {
        JunkCode8200 = false;
    }
    catch (...) {}
    bool While5512 = true;
    while (While5512 == true) {
        JunkCode8200 = false;
        While5512 = false;
    }
    if (JunkCode8200 == true)
        JunkCode8200 = true;
    else
        JunkCode8200 = true;
    bool While4363 = true;
    while (While4363 == true) {
        JunkCode8200 = true;
        While4363 = false;
    }
    bool While9845 = true;
    while (While9845 == true) {
        JunkCode8200 = false;
        While9845 = false;
    }
    try {
        JunkCode8200 = false;
    }
    catch (...) {}
    if (JunkCode8200 == true)
        JunkCode8200 = false;


    return a;
};

int init_func(int size) {

    //char buffer[MAX_PATH];
    //DWORD length = GetTempPathA(MAX_PATH, buffer);
    //MessageBoxA(0, buffer, "IGotYou", NULL);

    MessageBoxA(0, "iGotYou", "catchme", NULL);

    int a = 6;
    return a;
};
