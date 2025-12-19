#include "ivedimas.h"

#include <map>
#include <string>
#include <vector>
#include <locale>
#include <fstream>
#include <iostream>

using std::map;
using std::wstring;
using std::vector;
using std::pair;

//spausdinimas zodziu lenteles i faila
void spausd_zodz(map<wstring, pair<int, vector<int>>> & zodziai);

//Spausdinimas url i faila
void spausd_url_f(vector <wstring> url);

//Spausdinimas url i ekrana
void spausd_url_t(vector <wstring> url);

//Spausdina url pagal pasirinkima
void spausd_url(vector <wstring> url);


