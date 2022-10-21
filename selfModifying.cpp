// selfModifying.cpp : Bu dosya 'main' işlevi içeriyor. Program yürütme orada başlayıp biter.
//

#include <iostream>
#include <stdio.h>
using namespace std;


extern "C" int SomeFunction(int i);
extern "C" int LittleFunction(int i);
extern "C" int sunu(int i);

int main()



{

  

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
/*int number = 0, times = 0, result = 0;
    cout << "input : "<< endl;
    cin >> number;
    cout << "input times: " << endl;
    cin >> times;


    for (int i = 0; i < times; i++)
        result += number;

    cout << "Final : " << result << endl;*/


// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin


