#include "ivedimas.h"

#include <map>
#include <string>
#include <vector>
#include <locale>
#include <fstream>
#include <iostream>
#include <set>

using std::map;
using std::wstring;
using std::vector;
using std::pair;
using std::set;

//spausdinimas zodziu lenteles i faila
void spausd_zodz(map<wstring, pair<int, vector<int>>> & zodziai);

//Spausdinimas url i faila
void spausd_url_f(set <wstring> url);

//Spausdinimas url i ekrana
void spausd_url_t(set <wstring> url);

//Spausdina url pagal pasirinkima
void spausd_url(set <wstring> url);


