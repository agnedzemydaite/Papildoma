#include "url_funkcijos.h"
#include "spausdinimas.h"
#include "ivedimas.h"
#include "rinkimas.h"

using std::locale;

int main(){
    
    locale::global(locale("en_US.UTF-8"));
    
    map <wstring, pair<int, vector<int>>> zodziai;
    vector <wstring> url;
    
    radimas(zodziai,url);
    spausd_zodz(zodziai);
    spausd_url(url);
    
    return 0;
}

