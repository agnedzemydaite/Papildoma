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


bool arURL(wstring zodis);
wstring zodzio_pertvarkymas(wstring zodis);

int main(){
    locale::global(locale("en_US.UTF-8"));
    wcout.imbue(locale());
    string failas; //failo pavadinimas
    
    //failo pavadimo ivedimas
    while(true){
        cout << "Iveskite failo pavadinima: ";
        cin >> failas;
        ifstream fin(failas);
        if (!fin) {
                cout << "Nepavyko atidaryti failo." << endl;
        }
        else{
            break;
        }
        fin.close();
    }
    
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

            while (wiss >> zodis) {
                if (arURL(zodis)) {
                    url.push_back(zodis);
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
    
    int n = 0;
    int np = 0;
    
    wofstream fout("zodziu lentele.txt");
    fout.imbue(locale());
    
        fout << setw(20) << left << L"Žodis" << L" | " << setw(10) << left << L"Kiekis" << L" | " << L"Eilutės" << endl;
        fout << L"--------------------------------------------------------------" << endl;

        for (const auto &p : zodziai) {

            if (p.second.first > 0) {
                n++;
                wstring zodis = p.first;
                int kiekis = p.second.first;
                vector<int> eilutes = p.second.second;
                np += kiekis;
                fout << setw(20) << left << zodis << L" | " << setw(10) << left << kiekis << L" | ";
                
                for (int e : eilutes) {
                    fout << e << L" ";
                }
                fout << endl;
            }
        }
    fout.close();
    cout << n;
    cout << endl <<np << endl;
    
//    for (const auto &p : zodziai) {
//        if (p.second.first > 1) {
//            wstring zodis = p.first;
//            int kiekis = p.second.first;
//            vector<int> eilutes = p.second.second;
//            wcout << zodis << L" " << kiekis << L" " << endl;
//        }
//    }
    
    int nn = 0;
    wofstream fout1("url.txt");
    for(wstring u: url){
        nn++;
        wcout << u << endl;
    }
    cout << nn << endl;
    
    
    
    
    
    return 0;
}

bool arURL(wstring zodis){
    wregex urlformatas(LR"((https?:\/\/|www\.)[^\s]+|[\w\-]+\.[a-z]{2,6}(\/.*)?)", icase);
    return regex_search(zodis, urlformatas);
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
