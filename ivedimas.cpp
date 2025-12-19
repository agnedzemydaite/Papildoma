#include "ivedimas.h"

using std::cout;
using std::cin;
using std::string;
using std::ifstream;
using std::endl;

string failo_pavadinimo_iv(){
    string failas;
    while(true){
        cout << "Iveskite failo pavadinimą: ";
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
    return failas;
}

bool arskaicius(string i){
    for(char ch : i){
        if(!isdigit(ch)) return false;
    }
    return true;
}

int pasirink_iv(int min_r, int max_r){
    string x;
    int pasirinkimas;
    cin.ignore();
    while(true){
        cout << "Iveskite savo pasirinkima: ";
        getline(cin, x);
        
        if(!arskaicius(x) || x.empty()){
            cout << "Padarete klaida, bandykite is naujo" << endl;
            continue;
        }
        
        pasirinkimas = stoi(x);
        
        if(pasirinkimas <min_r || pasirinkimas > max_r){
            cout << "Padarete klaida, bandykite is naujo" << endl;
            continue;
        }
        
        return pasirinkimas;
    }
}


