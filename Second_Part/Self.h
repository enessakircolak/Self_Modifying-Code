#pragma once
#include <Windows.h>
#include <assert.h>
#include <iostream>


#include <stdio.h>
#include <string>



using namespace std;



int self_func(int* source_addr, int* dest_addr) {


	BYTE* init_func_address = (BYTE*)(void*)source_addr;
	BYTE* second_func_address = (BYTE*)(void*)dest_addr;
 

    for (int i = 0; i < 0x100; i++) {


        second_func_address[i] = init_func_address[i];//use only far call at init_func, local functions offset calculation is confusing at replacing
        // burada fonksiyonun içini alýp direkt diðerine kopyalýyor 
        //fakat þöyle bir sorun var ki içindeki offset ile compile edilmiþ o yüzden corrupt etmiþ oluyoruz(local fonksiyonlar çaðýrýlýrken offsetleri baz alýnarak jmp yapýlýyor o yüzden adresler karýþýyor) 
        //yani memoryde o fonksiyondan sonra neresi varsa, boyut aþarsa oraya yazmaya baþlýyoruz.
        //dikkatli ve saf shellcode halinde fonksiyon yerleþtirilirse sorunsuz çalýþýr.
        if ((int)init_func_address[i] == 0xc3 || (int)init_func_address[i] == 0xc2 || (int)init_func_address[i] == 0xca || (int)init_func_address[i] == 0xcb) 
            goto label2;
   
    }
label2:



    return 0;
}



void get_write_perm() {
    HMODULE hmod = GetModuleHandleA(NULL);
    MEMORY_BASIC_INFORMATION info;
    // Start at PE32 header
    SIZE_T len = VirtualQuery(hmod, &info, sizeof(info));
    assert(len > 0);
    BYTE* dllBase = (BYTE*)info.AllocationBase;
    BYTE* address = dllBase;
    int x = 0;
    int y = 0;
    PVOID xs = &y;
    for (;;) {
        len = VirtualQuery(address, &info, sizeof(info));
        assert(len > 0);
        if (info.AllocationBase != dllBase) break;
        DWORD oldprotect;
        if (info.Protect == 0) std::cout << ", VirtualProtect skipped" << std::endl;
        else {
            BOOL ok = VirtualProtect(info.BaseAddress, info.RegionSize, PAGE_EXECUTE_READWRITE, &oldprotect);
        }
        if (x == 1) {
            xs = info.BaseAddress;
            break;
        }
        address = (BYTE*)info.BaseAddress + info.RegionSize;
        x++;
    }




}

void junk2() {
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
}


class spiynxx {
public:
    int hmytvkgrekpyak;
    spiynxx();
    double qwqlvzvinbyjyrfcwt(string uwlfp, bool ddzynqfzvwse, string qutyzvag, double hqqppnakiw, string irljrbc);
    int dwrpwdtrdcvwchdzckbvje(bool nrgdpcqrox, bool sqjqude, bool hmydqiqwlezp, double lrqcbzxgafph, double loyykbtewrc, double ztmugtj, string cwzqajfnyt, string iwpbdh, double tehozqchd);
    bool cifgveqrrcqszzqouxavimtj(string zqccamnqso, int umbquw, double cuhpkvinfbbsn, int xwwmnmac, string rrsbhlxe, double jdtjpy, bool zglprat);
    void lmtoqchdpu(int huochfbwgvnfqzr, string hkrcg, string yftjko, int iefbm, string lmfgqgii, int lsrid, bool remny, double lmyjeoodjpu);

protected:
    string ciegrofpnwxlvhc;

    bool iuqlgmrcpsv(double bavluuqqhqiud, bool izdfyfg, double llqlboepfjbzpp, double kbbunpwpernughq, int nqlvcrkgdh, int lgzjcygqvp, int qnvogmzxgztx);
    void rztbfbevqadwvestqwojij(double obburiirpcqj, bool mtxajsoe, string zzzntejevltana, string ydzthj, double eojxzny, bool opibcurogpzb, double yylzx, bool ygvchfriqrc, string solggsksjt, string anfhw);
    bool fxkdqqedrfr(string auplhmxipb, bool foaegyitc, int coiiqotat, int behiul);
    string wxspdjtpnrqnc(double yuatkcwsnuqjjb, string ymonfjxveoauhf, double totlvvksqjfsh, int ngundkhd, double ueqbzexxhmgvb, bool zgppeqipp);
    int tesoqjvgcsvum(double qgajbahfsalbs, int ujngsmjfgi, int zzvaoaarbqrc, string iynsztsatrdwalt, int upcpveworgtuk, string vfoeffkdnbmmb, int ozplxocpr);
    int ozhrskizbvdzmsymmdma(string bobuxlcfmz, bool czwiwtrphseyq, string iaovjpjppwpp, string utrkazovffefx);
    void hmkeuceuvzdpbcyryjqioa(int ibdpmpcvf, bool gdgbw, int ttdvoiuju);
    bool dwxtwvtdvdyv(double acjaiypjxfkwmf);
    bool mjirnbxqiefanbcaui(bool zkosm, double odpwuxin, string ickrrjygokc, int glwcnqlwvgjnbe, int qqfgmpo, string ldcqcgrdvo, bool yhtscwzhijbvtu, bool rgvymakysj, int bsxni);

private:
    double ktdvomhqovs;
    bool ymmevgdpcbu;
    double hysssxowtmfhsvi;

    void cnxdecptqsbgxphtiek();
    int sirctpsttdnvkvltqvmdaxn(bool pjheowwcj, bool ynitmoxqmmwfyex, int bjhwtu, double xouvgr, bool spfvsx, string kgsjvj, string zjmjzcfp, string mlduxnzfi, string hlcedlswy);
    int dcbtuvozzxailbjsvlsnwd(string bjukuxphbithju);

};


void spiynxx::cnxdecptqsbgxphtiek() {
    int acoield = 947;
    string rmmwtzmnoejldkq = "ehjvigmcmafmrkojaqvejrinylssupyquzsgroylddwaoaudxzxhzbiooadapnynfnolish";
    int jzoabjcvzpjxfs = 1521;
    if (1521 != 1521) {
        int nvvjgnyyig;
        for (nvvjgnyyig = 0; nvvjgnyyig > 0; nvvjgnyyig--) {
            continue;
        }
    }
    if (string("ehjvigmcmafmrkojaqvejrinylssupyquzsgroylddwaoaudxzxhzbiooadapnynfnolish") != string("ehjvigmcmafmrkojaqvejrinylssupyquzsgroylddwaoaudxzxhzbiooadapnynfnolish")) {
        int ukks;
        for (ukks = 66; ukks > 0; ukks--) {
            continue;
        }
    }
    if (string("ehjvigmcmafmrkojaqvejrinylssupyquzsgroylddwaoaudxzxhzbiooadapnynfnolish") != string("ehjvigmcmafmrkojaqvejrinylssupyquzsgroylddwaoaudxzxhzbiooadapnynfnolish")) {
        int xs;
        for (xs = 90; xs > 0; xs--) {
            continue;
        }
    }
    if (string("ehjvigmcmafmrkojaqvejrinylssupyquzsgroylddwaoaudxzxhzbiooadapnynfnolish") == string("ehjvigmcmafmrkojaqvejrinylssupyquzsgroylddwaoaudxzxhzbiooadapnynfnolish")) {
        int grtpswkb;
        for (grtpswkb = 12; grtpswkb > 0; grtpswkb--) {
            continue;
        }
    }

}

int spiynxx::sirctpsttdnvkvltqvmdaxn(bool pjheowwcj, bool ynitmoxqmmwfyex, int bjhwtu, double xouvgr, bool spfvsx, string kgsjvj, string zjmjzcfp, string mlduxnzfi, string hlcedlswy) {
    int desggwmrrf = 2501;
    int tylcfeqrz = 341;
    string wzpabtov = "rohbxkphquulucndonmilhpfftupzcyrjnnorgiljgwiegtzjpxznvqlkzmwafytjrlplnsdfxiox";
    bool uiweduxmxiu = false;
    int shcuwltxbsgn = 2316;
    bool zrnpghbpzgfxjq = true;
    string lxtjb = "vxlli";
    bool nvifomawvz = false;
    if (true != true) {
        int hschohop;
        for (hschohop = 68; hschohop > 0; hschohop--) {
            continue;
        }
    }
    return 48042;
}

int spiynxx::dcbtuvozzxailbjsvlsnwd(string bjukuxphbithju) {
    double bpdipmxvxxfw = 5895;
    bool urkmitwji = false;
    string fxbnokmzfjcjz = "lfadrkjcxwnnpgltmfravmtiso";
    int qybacjvrqg = 411;
    double cxvhj = 7746;
    string cgdcjfzn = "baytfdvllavznws";
    double lerzaiawqoqefg = 42024;
    bool zqrril = false;
    int wgotzxfibl = 576;
    int zzeuqxwmvgqdln = 4238;
    return 79161;
}

bool spiynxx::iuqlgmrcpsv(double bavluuqqhqiud, bool izdfyfg, double llqlboepfjbzpp, double kbbunpwpernughq, int nqlvcrkgdh, int lgzjcygqvp, int qnvogmzxgztx) {
    int recwtcimenn = 3899;
    int ftdfa = 2183;
    int ualhfzl = 1337;
    int sxrjuiyhuf = 1065;
    int jdmxtjwazkxekm = 2011;
    int kvyqb = 2187;
    string rdawyxgma = "";
    double gawmprrhbfrnym = 29327;
    bool ufjhumzml = true;
    return false;
}

void spiynxx::rztbfbevqadwvestqwojij(double obburiirpcqj, bool mtxajsoe, string zzzntejevltana, string ydzthj, double eojxzny, bool opibcurogpzb, double yylzx, bool ygvchfriqrc, string solggsksjt, string anfhw) {

}

bool spiynxx::fxkdqqedrfr(string auplhmxipb, bool foaegyitc, int coiiqotat, int behiul) {
    string lmveqlq = "fahsirzrxrjg";
    int hjcrjwnkhlun = 1622;
    double dqulkvyuukiuvuv = 38614;
    bool gppsri = true;
    double kbuagpzwkk = 33263;
    bool bgflelgtyst = false;
    int afbtpuvdpegidu = 4140;
    if (string("fahsirzrxrjg") == string("fahsirzrxrjg")) {
        int gt;
        for (gt = 4; gt > 0; gt--) {
            continue;
        }
    }
    if (33263 == 33263) {
        int jzqhk;
        for (jzqhk = 76; jzqhk > 0; jzqhk--) {
            continue;
        }
    }
    return false;
}

string spiynxx::wxspdjtpnrqnc(double yuatkcwsnuqjjb, string ymonfjxveoauhf, double totlvvksqjfsh, int ngundkhd, double ueqbzexxhmgvb, bool zgppeqipp) {
    string oaozeabqkin = "htnutdtfpbcaabjdsyssudfphyrvmxrnzqayhkqwsawmgndxavnbjjwyteutebulj";
    bool zyqsjq = false;
    int doftfkhckf = 2631;
    int hcvitvfbbr = 175;
    bool tzcdfn = false;
    if (175 == 175) {
        int psexjkcmcx;
        for (psexjkcmcx = 56; psexjkcmcx > 0; psexjkcmcx--) {
            continue;
        }
    }
    return string("zqyqdhqntzcotzx");
}

int spiynxx::tesoqjvgcsvum(double qgajbahfsalbs, int ujngsmjfgi, int zzvaoaarbqrc, string iynsztsatrdwalt, int upcpveworgtuk, string vfoeffkdnbmmb, int ozplxocpr) {
    double enynyndzpz = 73608;
    int duckgeryjvwodh = 3881;
    int jcjzmgyxfxapuum = 1532;
    if (73608 == 73608) {
        int jnwpofjqg;
        for (jnwpofjqg = 84; jnwpofjqg > 0; jnwpofjqg--) {
            continue;
        }
    }
    if (1532 == 1532) {
        int tjejixgzg;
        for (tjejixgzg = 58; tjejixgzg > 0; tjejixgzg--) {
            continue;
        }
    }
    if (73608 != 73608) {
        int bc;
        for (bc = 43; bc > 0; bc--) {
            continue;
        }
    }
    return 72863;
}

int spiynxx::ozhrskizbvdzmsymmdma(string bobuxlcfmz, bool czwiwtrphseyq, string iaovjpjppwpp, string utrkazovffefx) {
    bool wxnneicupfusnl = true;
    int irarw = 2240;
    string ilcjjuzaqvmvdf = "qkqvvsagexoxknwnnllwkycnqadlwuzvnzxfsvvscemvpcrxfmxrjfwzizhxtvlajplsbwwpsb";
    double yifxccchjj = 18920;
    bool ifrrqzar = false;
    int nmyzjvjhqvfgidi = 3159;
    if (3159 == 3159) {
        int mcj;
        for (mcj = 69; mcj > 0; mcj--) {
            continue;
        }
    }
    if (string("qkqvvsagexoxknwnnllwkycnqadlwuzvnzxfsvvscemvpcrxfmxrjfwzizhxtvlajplsbwwpsb") == string("qkqvvsagexoxknwnnllwkycnqadlwuzvnzxfsvvscemvpcrxfmxrjfwzizhxtvlajplsbwwpsb")) {
        int vwasuljjrq;
        for (vwasuljjrq = 40; vwasuljjrq > 0; vwasuljjrq--) {
            continue;
        }
    }
    if (true != true) {
        int wucvivfpnc;
        for (wucvivfpnc = 80; wucvivfpnc > 0; wucvivfpnc--) {
            continue;
        }
    }
    if (string("qkqvvsagexoxknwnnllwkycnqadlwuzvnzxfsvvscemvpcrxfmxrjfwzizhxtvlajplsbwwpsb") != string("qkqvvsagexoxknwnnllwkycnqadlwuzvnzxfsvvscemvpcrxfmxrjfwzizhxtvlajplsbwwpsb")) {
        int jxsj;
        for (jxsj = 28; jxsj > 0; jxsj--) {
            continue;
        }
    }
    if (3159 != 3159) {
        int bbrgvyqjup;
        for (bbrgvyqjup = 90; bbrgvyqjup > 0; bbrgvyqjup--) {
            continue;
        }
    }
    return 12108;
}

void spiynxx::hmkeuceuvzdpbcyryjqioa(int ibdpmpcvf, bool gdgbw, int ttdvoiuju) {
    int hemmtomiedyxn = 557;
    double wfmuwghrrvozi = 17286;
    bool ayxwnuenggra = true;
    int vicjzquusme = 802;
    bool kwsmzxvdohww = false;
    if (557 != 557) {
        int qqmpttrkq;
        for (qqmpttrkq = 67; qqmpttrkq > 0; qqmpttrkq--) {
            continue;
        }
    }
    if (17286 != 17286) {
        int nfhoe;
        for (nfhoe = 19; nfhoe > 0; nfhoe--) {
            continue;
        }
    }

}

bool spiynxx::dwxtwvtdvdyv(double acjaiypjxfkwmf) {
    double gaccbogt = 20576;
    bool plsxjzr = true;
    string hbtvqtlw = "kxtraqcwxrxodnyztqqqbgvjzc";
    bool dmmrl = false;
    bool ndatdst = true;
    int hoyexxnbntxpju = 3374;
    int awpskucbocishv = 1316;
    string zdshitpc = "cuvesrjvssfiyhmxeheuzndbqkbcyjgllsqmmhhtcs";
    double iwsmr = 34390;
    if (false != false) {
        int fegpuyxnmp;
        for (fegpuyxnmp = 65; fegpuyxnmp > 0; fegpuyxnmp--) {
            continue;
        }
    }
    if (false == false) {
        int ggxdymh;
        for (ggxdymh = 39; ggxdymh > 0; ggxdymh--) {
            continue;
        }
    }
    if (3374 == 3374) {
        int fbmp;
        for (fbmp = 3; fbmp > 0; fbmp--) {
            continue;
        }
    }
    if (34390 != 34390) {
        int ztcna;
        for (ztcna = 44; ztcna > 0; ztcna--) {
            continue;
        }
    }
    return false;
}

bool spiynxx::mjirnbxqiefanbcaui(bool zkosm, double odpwuxin, string ickrrjygokc, int glwcnqlwvgjnbe, int qqfgmpo, string ldcqcgrdvo, bool yhtscwzhijbvtu, bool rgvymakysj, int bsxni) {
    return true;
}

double spiynxx::qwqlvzvinbyjyrfcwt(string uwlfp, bool ddzynqfzvwse, string qutyzvag, double hqqppnakiw, string irljrbc) {
    bool bjhcznuqhpf = false;
    bool zeujlf = false;
    string iqzahcfzfhpgw = "nxdnsyebcmzvzfikmbmpzlyqmkkxsakgatxopbmsbybumdnrozzesnvkbetieifnhodzyoqvghbbddwotidooankyacfuidgmlcv";
    bool wrzpsvnvt = false;
    if (false == false) {
        int hpk;
        for (hpk = 49; hpk > 0; hpk--) {
            continue;
        }
    }
    if (false == false) {
        int uplu;
        for (uplu = 63; uplu > 0; uplu--) {
            continue;
        }
    }
    return 8672;
}

int spiynxx::dwrpwdtrdcvwchdzckbvje(bool nrgdpcqrox, bool sqjqude, bool hmydqiqwlezp, double lrqcbzxgafph, double loyykbtewrc, double ztmugtj, string cwzqajfnyt, string iwpbdh, double tehozqchd) {
    bool stsbqtbs = false;
    bool dcnmyhdrrvykuzk = true;
    string klstagoacxulqz = "tnbncuunwegxysbvheikplytncykamqvgqpkxsbxuahxiyvygyhuhhierldmilbadylnfgruwrhhswvwdhflrtvjrmqfih";
    double tinlmbpy = 5837;
    bool mpwrbijycmei = true;
    double dxegfbkwuik = 6615;
    string eddenp = "cyiqmuhdwxcxvaqtkjjyprsdgnvwtrhfcwcahhmnvituniq";
    if (5837 != 5837) {
        int nchgkx;
        for (nchgkx = 76; nchgkx > 0; nchgkx--) {
            continue;
        }
    }
    if (string("tnbncuunwegxysbvheikplytncykamqvgqpkxsbxuahxiyvygyhuhhierldmilbadylnfgruwrhhswvwdhflrtvjrmqfih") == string("tnbncuunwegxysbvheikplytncykamqvgqpkxsbxuahxiyvygyhuhhierldmilbadylnfgruwrhhswvwdhflrtvjrmqfih")) {
        int pjcjlrqx;
        for (pjcjlrqx = 67; pjcjlrqx > 0; pjcjlrqx--) {
            continue;
        }
    }
    if (6615 != 6615) {
        int qyygb;
        for (qyygb = 91; qyygb > 0; qyygb--) {
            continue;
        }
    }
    if (string("cyiqmuhdwxcxvaqtkjjyprsdgnvwtrhfcwcahhmnvituniq") == string("cyiqmuhdwxcxvaqtkjjyprsdgnvwtrhfcwcahhmnvituniq")) {
        int nn;
        for (nn = 45; nn > 0; nn--) {
            continue;
        }
    }
    if (6615 == 6615) {
        int vusmhqdls;
        for (vusmhqdls = 77; vusmhqdls > 0; vusmhqdls--) {
            continue;
        }
    }
    return 46113;
}

bool spiynxx::cifgveqrrcqszzqouxavimtj(string zqccamnqso, int umbquw, double cuhpkvinfbbsn, int xwwmnmac, string rrsbhlxe, double jdtjpy, bool zglprat) {
    int kshlykadhjkuxlm = 2298;
    int xldvrfchzprvtl = 2772;
    if (2298 == 2298) {
        int oqxhqke;
        for (oqxhqke = 98; oqxhqke > 0; oqxhqke--) {
            continue;
        }
    }
    if (2772 == 2772) {
        int awbuv;
        for (awbuv = 13; awbuv > 0; awbuv--) {
            continue;
        }
    }
    if (2298 == 2298) {
        int xujir;
        for (xujir = 25; xujir > 0; xujir--) {
            continue;
        }
    }
    if (2298 == 2298) {
        int kdu;
        for (kdu = 3; kdu > 0; kdu--) {
            continue;
        }
    }
    return true;
}

void spiynxx::lmtoqchdpu(int huochfbwgvnfqzr, string hkrcg, string yftjko, int iefbm, string lmfgqgii, int lsrid, bool remny, double lmyjeoodjpu) {
    double kfzhqchfvgr = 15314;
    double ajshdublfglq = 22965;
    bool dcezkw = false;
    string fmktpodnncibgan = "wlotdelagfjlaolzeelmrrxzqdhayrsxtwccfkxgwwbdmhpfnhrttgvywnouovhbbukvganeww";
    bool isbmnbq = false;
    int eljubwvggmjvwj = 5444;
    string mfivnzbgkczbkp = "ruvvsehfqmnvqhtq";
    int bkweeidjziztyw = 108;
    bool jtbgumcbxtfpmq = true;
    if (22965 != 22965) {
        int cxpaha;
        for (cxpaha = 96; cxpaha > 0; cxpaha--) {
            continue;
        }
    }
    if (string("wlotdelagfjlaolzeelmrrxzqdhayrsxtwccfkxgwwbdmhpfnhrttgvywnouovhbbukvganeww") == string("wlotdelagfjlaolzeelmrrxzqdhayrsxtwccfkxgwwbdmhpfnhrttgvywnouovhbbukvganeww")) {
        int zoob;
        for (zoob = 44; zoob > 0; zoob--) {
            continue;
        }
    }
    if (false != false) {
        int ehwysp;
        for (ehwysp = 9; ehwysp > 0; ehwysp--) {
            continue;
        }
    }
    if (15314 == 15314) {
        int ijahevidnc;
        for (ijahevidnc = 55; ijahevidnc > 0; ijahevidnc--) {
            continue;
        }
    }

}

spiynxx::spiynxx() {
    this->qwqlvzvinbyjyrfcwt(string("wxrjmolmhafsixqjvtueueuuhrwyjmefmxjiwxdzje"), true, string("mnwmawgkgnvkdmlw"), 5671, string("xcfbbzdhv"));
    this->dwrpwdtrdcvwchdzckbvje(false, true, true, 4531, 16493, 4089, string("xjpmbffcttavrblximjzniktytdqrtcujqtpfcssnrzaikqnamwqjbeidtnoembgmpsvkmpjkxylpgf"), string("qd"), 48542);
    this->cifgveqrrcqszzqouxavimtj(string("zmgsvewsm"), 1120, 85422, 2902, string("ohonkdsxhwbgj"), 13611, false);
    this->lmtoqchdpu(4814, string("q"), string("jqwmzcahrggzcjsxbukbgeezqgtwabylpllfpmycvfivjpurnzpb"), 636, string("enfezhzgcurztgdojcnupxlwbtmevyyjirozwbhoausygjhmtjcgdlcreqlfkbbnqlabkxpqxcuucfmtcspgnlbhxearskewwmw"), 3508, false, 44483);
    this->iuqlgmrcpsv(18336, false, 22473, 12564, 154, 4515, 1);
    this->rztbfbevqadwvestqwojij(11246, false, string("utworunxbsdcpsrveciwmwtlnmcgqkstrohekftqdxqihw"), string("xopegzwfwcjafsgwwjecgvvytulrcqavuz"), 36445, true, 64970, false, string("uurfvjopzpqoxpxjqwnxyhfdsezhamqnrcgazgvfljakicvhdsbkmjszssrcbyfnrw"), string("xlgtgjymhmwvkujzeadqtiakfzi"));
    this->fxkdqqedrfr(string("xsqcogmkzydihi"), true, 324, 2829);
    this->wxspdjtpnrqnc(27133, string("slfpgjusfdfyfmsmidcdjnharrrutcoushrztuwa"), 24039, 3736, 1142, false);
    this->tesoqjvgcsvum(27235, 98, 1422, string(""), 2149, string("zixghajpfgxaucqgbfxpnhiahikqnmsjwohypbuivlslqverakjhdirnqxgxfhkuuoisltdypmjwgwxrk"), 1068);
    this->ozhrskizbvdzmsymmdma(string("zthiavexqjc"), true, string("ggdojshqtoxthhhggftikhuclgfbpicjglyqfpqeeworsgkybtcxjcgdgz"), string("uqwuccxkfhogszttnlukylwcvlehnmihrvjymmljuijiqmxxlgwolscsbvndz"));
    this->hmkeuceuvzdpbcyryjqioa(2139, false, 1740);
    this->dwxtwvtdvdyv(87411);
    this->mjirnbxqiefanbcaui(false, 9359, string("lmzblqrkfqzwbbmcnvliipcfulbsacllyfdkxqhsutfevclfhdjnorwppklmxxjynxxchzupqvkhbunpozlazjw"), 7770, 91, string("awdrihddkzegwvajjhwtxdmunq"), true, false, 1862);
    this->cnxdecptqsbgxphtiek();
    this->sirctpsttdnvkvltqvmdaxn(false, false, 3988, 77049, true, string("yycoyxnxvqoptelbfbmtmrmqeyaxzwfvpyoyesskflzrumxcznybrxqtxtxfwbtyhxabilsnylsrfcvmf"), string("ybimcbcaawqsjbjsfxovlkotvjogtyvxmrwzwovyfqgchayuyraoapp"), string(""), string("oulef"));
    this->dcbtuvozzxailbjsvlsnwd(string("sndslairuuhtf"));
}
