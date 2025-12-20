#include "url_funkcijos.h"
#include "ivedimas.h"
#include "rinkimas.h"

using std::regex;
using std::wifstream;
using std::locale;
using std::wistringstream;
using std::vector;
using std::wsmatch;

bool visos_did(const wstring& s){
    bool did_raide = false;
    for (wchar_t c : s) {
        if (iswalpha(c)) {
            did_raide = true;
            if (iswlower(c)) return false;
        }
    }
    return did_raide;
}

bool raide(const wstring& s){
    for (wchar_t c : s) {
        if (iswalpha(c)) return true;
    }
    return false;
}

vector<wstring> zodzio_pertvarkymas(wstring zodis){
    vector<wstring> rezultatas;
    wstring laikinas = L"";
    
    
    for(wchar_t c : zodis) {
        if(iswalnum(c)) laikinas += c;
        else{
            if (!laikinas.empty()) {
                if(raide(laikinas)){
                    if (!visos_did(laikinas)) {
                        for (auto &lc : laikinas) lc = towlower(lc);
                    }
                    rezultatas.push_back(laikinas);
                }
                laikinas = L"";
            }
        }
    }
    if(!laikinas.empty() && raide(laikinas)){
        if (!visos_did(laikinas)) {
            for (auto &lc : laikinas) lc = towlower(lc);
        }
        rezultatas.push_back(laikinas);
    }
    
    return rezultatas;
}


void radimas(map <wstring, pair<int, vector<int>>> & zodziai, set <wstring> & url, string & failas, wregex & url_israiska){
    
    wstring eilute;
    int eilutes_nr = 0;
    
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
                    wstring rasta_nuoroda = match[0].str();
                    while (!rasta_nuoroda.empty() && !iswalnum(rasta_nuoroda.back()) && rasta_nuoroda.back() != L'/'){
                        rasta_nuoroda.pop_back();
                    }
                    url.insert(rasta_nuoroda);
                }
                else {
                    vector<wstring> sutvarkyti = zodzio_pertvarkymas(zodis);
                    for (const wstring& s : sutvarkyti) {
                        if (!s.empty()) {
                            zodziai[s].first++;
                            if (zodziai[s].second.empty() || zodziai[s].second.back() != eilutes_nr) zodziai[s].second.push_back(eilutes_nr);
                        }
                    }
                    
                }
            }
        }
    }
    fin.close();
}
