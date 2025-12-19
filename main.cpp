#include "url_funkcijos.h"
#include "spausdinimas.h"
#include "ivedimas.h"

#include <iostream>
#include <string>
#include <fstream>

#include <map>
#include <locale>
#include <codecvt>
#include <sstream>

#include <regex>

#include <iomanip>

#include <cwctype>

using std::string;
using std::ifstream;
using std::cin;
using std::cout;
using std::endl;

using std::vector;
using std::map;
using std::pair;
using std::wstring;
using std::wifstream;
using std::codecvt_utf8;
using std::locale;
using std::wistringstream;

using std::wregex;
using std::regex_constants::icase;

using std::wofstream;
using std::setw;
using std::left;
using std::wcout;

wstring zodzio_pertvarkymas(wstring zodis);

int main(){
    locale::global(locale("en_US.UTF-8"));
    
    string failas = failo_pavadinimo_iv();
    wregex url_israiska = url_israisku_nustatymas();
    
    
    
    //zodziu skaiciavimas
    map <wstring, pair<int, vector<int>>> zodziai;
    vector <wstring> url;
    
    wstring eilute;
    int eilutes_nr = 0;

    wifstream fin(failas);
    fin.imbue(locale());
    if (fin.is_open()) {
        while (getline(fin, eilute)) {
            eilutes_nr++;
            wistringstream wiss(eilute);
            wstring zodis;
            std::wsmatch match;

            while (wiss >> zodis) {
                if (regex_search(zodis, match, url_israiska)) {
                        url.push_back(match[0].str());
                    }
                else {
                    wstring sutvarkytas_zodis = zodzio_pertvarkymas(zodis);
                    if (!sutvarkytas_zodis.empty()) {
                        zodziai[sutvarkytas_zodis].first++;
                        if (zodziai[sutvarkytas_zodis].second.empty() ||
                            zodziai[sutvarkytas_zodis].second.back() != eilutes_nr) {
                            zodziai[sutvarkytas_zodis].second.push_back(eilutes_nr);
                        }
                    }
                }
            }
        }
        fin.close();
    }
    
    spausd_zodz_f(zodziai);
    
    int pasirinkimas = 0;
    cout << "Kur norite, kad atspausdintų nuorodas?" << endl;
    cout << "1. Spausdinti i ekrana." << endl;
    cout << "2. Spausdinti i faila." << endl << endl;
    pasirinkimas = pasirink_iv(1, 2);
    
    if(pasirinkimas == 1) spausd_url_t(url);
    else if(pasirinkimas == 2) spausd_url_f(url);
    
    
    return 0;
}

wstring zodzio_pertvarkymas(wstring zodis) {
    wstring rezultatas = L"";
    for (wchar_t c : zodis) {
        if (iswalpha(c)) {
            rezultatas += towlower(c);
        }
    }
    return rezultatas;
}
