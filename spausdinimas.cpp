#include "spausdinimas.h"

using std::map;
using std::wstring;
using std::vector;
using std::wofstream;
using std::locale;
using std::setw;
using std::left;
using std::endl;
using std::cout;
using std::wcout;

void spausd_zodz_f(map<wstring, pair<int, vector<int>>> & zodziai){
    wofstream fout("cross-reference_zodziu_lentele.txt");
    fout.imbue(locale());
    
    //atspausdiname antraste
    fout << setw(20) << left << L"Žodis" << L" | " << setw(7) << left << L"Kiekis" << L" | " << L"Eilutės" << endl;
    for(int i = 1; i <= 130; i++){
        fout << L"-";
    }
    fout << endl;

    //spausdiname zodziu rezultatus
    int n = 0, np = 0; // n - kiek skirtingu zodziu > 1 np - kiek is viso tokiu zodziu
    for (const auto &p : zodziai) {
        if (p.second.first > 1) {
            n++;
            wstring zodis = p.first;
            int kiekis = p.second.first;
            vector<int> eilutes = p.second.second;
            np += kiekis;
            fout << setw(20) << left << zodis << L" | " << setw(7) << left << kiekis << L" | ";
            
            for (int e : eilutes) {
                fout << e << L" ";
            }
            fout << endl;
        }
    }
    fout.close();
    cout << "Žodžių lentelė įrašyta į failą 'cross-reference_zodziu_lentele.txt'" << endl;
    cout << "Skirtingų žodžių, kurie pasikartoja daugiau nei vieną kartą buvo rasta: " << n << endl;
    cout << "Iš viso tokių žodžių buvo: " << np << endl << endl;
}

void spausd_url_f(vector <wstring> url){
    wofstream fout("url.txt");
    fout.imbue(locale());
    int nn = 0; // kiek nuorodu
    for(wstring u: url){
        nn++;
        fout << u << endl;
    }
    fout.close();
    cout << "Nuorodos įrašytos į failą 'url.txt'" << endl;
    cout << "Iš viso nuorodų buvo rasta: " << nn << endl;
}

void spausd_url_t(vector <wstring> url){
    wcout.imbue(locale());
    int nn = 0;
    cout << "Rastos nuorodos:" << endl;
    for(wstring u: url){
        nn++;
        wcout << u << endl;
    }
    cout << endl << "Iš viso nuorodų buvo rasta: " << nn << endl;
}



