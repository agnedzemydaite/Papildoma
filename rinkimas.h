#include <sstream>
#include <string>
#include <map>
#include <set>

using std::vector;
using std::string;
using std::map;
using std::pair;
using std::set;

//nustato ar zodyje yra bent viena raide
bool raide(const wstring& s);

//nustato ar zodyje visos raides didziosios
bool visos_did(const wstring& s);

//pertvarko zodi pagal reikalavimus
vector<wstring> zodzio_pertvarkymas(wstring zodis);

//randa zodzius ir nuorodas(url)
void radimas(map <wstring, pair<int, vector<int>>> & zodziai, std::set <wstring> & url, string & failas, wregex & url_israiska);

