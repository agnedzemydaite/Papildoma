#include "url_funkcijos.h"
#include "spausdinimas.h"
#include "ivedimas.h"
#include "rinkimas.h"

using std::locale;

int main(){
    
    locale::global(locale("en_US.UTF-8"));
    
    map <wstring, pair<int, vector<int>>> zodziai;
    set <wstring> url;
    
    wregex url_israiska = url_israisku_nustatymas();
    string failas = failo_pavadinimo_iv();
    
    radimas(zodziai, url, failas, url_israiska);
    spausd_zodz(zodziai);
    spausd_url(url);
    
    return 0;
}

