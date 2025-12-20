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
using std::set;

void spausd_zodz(map<wstring, pair<int, vector<int>>> & zodziai){
    wofstream fout("cross-reference_zodziu_lentele.txt");
    fout.imbue(locale());
    
    //atspausdiname antraste
    fout << setw(25) << left << L"Žodis" << L" | " << setw(7) << left << L"Kiekis" << L" | " << L"Eilutės" << endl;
    
    //spausdiname zodziu rezultatus
    int n = 0, np = 0; // n - kiek skirtingu zodziu > 1 np - kiek is viso tokiu zodziu
    for (const auto &p : zodziai) {
        if (p.second.first > 1) {
            n++;
            wstring zodis = p.first;
            int kiekis = p.second.first;
            vector<int> eilutes = p.second.second;
            np += kiekis;
            fout << setw(25) << left << zodis << L" | " << setw(7) << left << kiekis << L" | ";
            
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

void spausd_url_f(set <wstring> url){
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

void spausd_url_t(set <wstring> url){
    wcout.imbue(locale());
    int nn = 0; // kiek nuorodu
    cout << "Rastos nuorodos:" << endl;
    for(wstring u: url){
        nn++;
        wcout << u << endl;
    }
    cout << endl << "Iš viso nuorodų buvo rasta: " << nn << endl;
}

void spausd_url(set <wstring> url){
    int pasirinkimas = 0;
    cout << "Kur norite, kad atspausdintų nuorodas?" << endl;
    cout << "1. Spausdinti i ekrana." << endl;
    cout << "2. Spausdinti i faila." << endl << endl;
    pasirinkimas = pasirink_iv(1, 2);
    
    if(pasirinkimas == 1) spausd_url_t(url);
    else if(pasirinkimas == 2) spausd_url_f(url);
}

