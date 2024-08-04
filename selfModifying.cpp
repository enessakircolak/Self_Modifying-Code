// selfModifying.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <stdio.h>
using namespace std;

extern "C" int SomeFunction(int i);
extern "C" int LittleFunction(int i);
extern "C" int sunu(int i);

int main(){
    int a = 16;
    cout << "result1 :" << SomeFunction(a) << endl;
   
  /*  int a;
    cin >> a;
    if (a%2 == 0) {
        cout << "result1 :" << SomeFunction(a) << endl;
    }
    else {
        cout << "result :" << LittleFunction(a-1) << endl;
    }*/
    return 0;
}


 

