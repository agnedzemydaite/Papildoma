#include "url_funkcijos.h"

using std::vector;
using std::wifstream;
using std::wstring;
using std::wregex;
using std::regex_constants::icase;

wstring tld_saraso_sudarymas(){
    vector <wstring> tld;
    wifstream fin("url_visos.txt");
    wstring a;
    while (fin >> a) {
        tld.push_back(a);
    }
    fin.close();
    wstring tld_sablonas = L"(";
    for (size_t i = 0; i < tld.size(); ++i) {
        tld_sablonas += tld[i];
        if (i != tld.size() - 1) tld_sablonas += L"|";
    }
    tld_sablonas += L")";
    return tld_sablonas;
}

wregex url_israisku_nustatymas(){
    wstring tld_sablonas = tld_saraso_sudarymas();
    wregex url_israiska(LR"(((https?://|www\.)[^\s()<>]+)|(([a-zA-Z0-9.-]+\.)" + tld_sablonas + LR"((/[^\s()<>]*|(?![a-zA-Z0-9])))))", icase);
    return url_israiska;
}
