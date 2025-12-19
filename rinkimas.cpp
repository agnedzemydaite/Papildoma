#include "url_funkcijos.h"
#include "ivedimas.h"
#include "rinkimas.h"

using std::regex;
using std::wifstream;
using std::locale;
using std::wistringstream;
using std::vector;
using std::wsmatch;

wstring zodzio_pertvarkymas(wstring zodis) {
    wstring rezultatas = L"";
    for (wchar_t c : zodis) {
        if (iswalpha(c)) {
            rezultatas += towlower(c);
        }
    }
    return rezultatas;
}


void radimas(map <wstring, pair<int, vector<int>>> & zodziai, vector <wstring> & url){
    
    wstring eilute;
    int eilutes_nr = 0;
    wregex url_israiska = url_israisku_nustatymas();
    
    string failas = failo_pavadinimo_iv();
    wifstream fin(failas);
    fin.imbue(locale());
    if (fin.is_open()) {
        while (getline(fin, eilute)) {
            eilutes_nr++;
            wistringstream wiss(eilute);
            wstring zodis;
            wsmatch match;
            
            while (wiss >> zodis) {
                if (regex_search(zodis, match, url_israiska)) {
                    url.push_back(match[0].str());
                }
                else {
                    wstring sutvarkytas_zodis = zodzio_pertvarkymas(zodis);
                    if (!sutvarkytas_zodis.empty()) {
                        zodziai[sutvarkytas_zodis].first++;
                        if (zodziai[sutvarkytas_zodis].second.empty() || zodziai[sutvarkytas_zodis].second.back() != eilutes_nr) {
                            zodziai[sutvarkytas_zodis].second.push_back(eilutes_nr);
                        }
                    }
                }
            }
        }
    }
    fin.close();
}
