# Žodžių skaičiavimo ir nuorodų radimo programa

## Programos tikslas
Programa iš tekstinio failo suranda žodžius kurie pasikartoja daugiau nei 1 kartą, randą kiek kartų žodis buvo panaudotas ir kuriose eilutėse. Taip pat programa suranda nuorodas paminėtas tekste.

Surastų žodžių duomenys atspausdinami į tekstinį failą, o nuorodų duomenys į failą arba ekraną.

### Žodžių radimas
- Tekstinė eilutė laikoma žodžiu, jei joje yra bent viena raidė.
- Jei žodis sudarytas vien iš didžiųjų raidžių jis laikomas atskiru žodžiu.
- Jei tekstinėje eilutėje raides/skaičius skiria koks nors kitoks simbolis (pvz.: `/`, `[`, `(`) tai eilutė padalinama į du atskirus žodžius (pvz.: `labas/labas` -> gausime žodį _labas_, kuris kartojasi du kartus).

### Nuorodų radimas
eilutė laikoma nuoroda, jei ji atitinka šias formas:
- pilna forma: `" https://www.pavyzdys.lt/`, `http://www.pavyzdys.lt`.
- sutrumpinta forma:  `www.pavyzdys.xyz`, `pavyzdys.xyz`.
  - Visos programoje galimos TLD yra faile [TLD sąrašas](url_visos.txt).

## Programos veikimas (detaliau)
- Programa paprašo įvesti failo pavadinimą: `Iveskite failo pavadinimą: `.
- Programa suranda žodžius ir įveda gautus rezultatus į tekstinį failą 'cross-reference_zodziu_lentele.txt'.
- Programa paprašo vartotojo pasirinkti ar rastas nuorodas išvesti į ekraną ar į failą ir pateikia rezultatus.

Taip pat nurodoma, kiek žodžių ir nuorodų buvo rastą.

## Klaidų tikrinimas
- Programa tikrina tekstinio failo ir pasirinkimo įvestis.
- Jei padaryta klaida, programa prašo įvesti kol įvestis bus teisinga.

## Įdiegimo instrukcija

### Reikalavimai
- C++ kompiliatorius (C++20 versija)
- CMake (3.25 ar naujesnė versija)
- make – kompiliavimo ir vykdomojo failo generavimo įrankis
- Git - paskirstytos versijų kontrolės sistema
  
### Programos įdiegimo žingsniai:
1. Įsitikinkite, kad kompiuteryje turite C++ kompiliatorių, cmake, make ir git, jei neturite - įsidiekite.
2. Atsidarykite komandinę eilutę (terminalą) savo kompiuteryje ir įveskite šias komandas:
  - `git clone https://github.com/agnedzemydaite/papildoma.git`
  - `cd papildoma`
  - jei norite naudoti savo tekstinį failą įdekite jį į katalogą 'papildoma' ir tęskite tolimesnius žingsnius.
3. Sukurkite katalogą, kuriame bus generuojami "build" failai:
  - `mkdir build`
  - `cd build`
4. Kompiliuokite projektą:
  - `cmake ..`
  - `cmake --build .`
5. Paleiskite programą:
  - `./Zodziai`
6. (Pasirinktinai) Jei norite iš naujo sukompiliuoti nuo nulio:
  - Ištrinkite build katalogą: `rm -rf build`
  - Ir pakartokite ankstesnius žingsnius (nuo 2 punkto).
