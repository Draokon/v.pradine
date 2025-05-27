# v.pradine
**v_01**  
*Programa leidžia:*  
Iš meniu pasirinkti norimą atlikti darbą.   
Ranka įvesti studento vardą ir pavardę, parašyti jo pažymius ir pasirinkus suskaičiuoti medianą arba vidurkį.  
Pasirinkti kiek pažymių studentas turės ir juos automatiškai sugeneruoti.  
Pasirinkus „Baigti darbą" lentelės pavidalu parodo ranka įvestus arba sugeneruotus duomenis.  



**v0.4**

Papildyta:
- Failų generatoriaus funkcionalumu,
- Studentų skirstymas į dvi kategorijas,(Studentai padalijami į 2 grupes:
- "vargsiukai": galutinis balas < 5.0
- "kietiakiai": galutinis balas >= 5.0 )
- Spartos tyrimas, testavimo sistema su 5 skirtingo dydžio failais
- Spartos rezultatai.

### 1. Failų generavimas
Sugeneruoti failai su atsitiktiniais studentų įrašais (vardai "VardasNR1" ir pan.):
- 1 000
- 10 000
- 100 000
- 1 000 000
- 10 000 000

Kiekviename įraše: vardas, pavardė, 7 atsitiktiniai namų darbų pažymiai ir 1 egzamino pažymėjimas.

### 3. Veikimo spartos matavimas

#### Tyrimas 1: Failų kūrimas
 failo atidarymas, įrašymas, uždarymas (be vektorių).

#### Tyrimas 2: Duomenų apdorojimas
- Nuskaitymas iš failo.
- Studentų skirstymas į dvi kategorijas.
- Išvedimas į du naujus failus.

#### Tyrimas 3: Visos programos veikimo laikas
Pilnas matavimas nuo pradžios iki pabaigos (failo nuskaitymas + skirstymas + išvedimas).

## • Spartos rezultatai (3 testai, vidurkis)
#rezultatas nr1:
![image](https://github.com/user-attachments/assets/6aa1b640-346c-4bd9-9445-00dabbb1b708)
#rezultatas nr2:
![image](https://github.com/user-attachments/assets/4f12764b-d7bb-4cda-b252-0599031e90a1)
#rezultatas nr.3:
![image](https://github.com/user-attachments/assets/d8388ede-5a1b-4bc5-a9d2-2db58b50f097)


# -Vidurkis:
| Įrašų skaičius| Failo kūrimas | Nuskaitymas | Rusiavimas  | Išvedimas | Is Viso  |
|----------------------------------------------------------------------------------|
| 1 000         | 0.137 s       | 0.018 s     | 0.001s      | 0.007s    | 0.027s   |
| 10 000        | 0.720 s       | 0.051s      | 0,007s      | 0.020s    | 0.082s   |
| 100 000       | 0.727 s       | 0.397s      | 0.054s      | 0.194s    | 0.647s   |
| 1 000 000     | 1.577 s       | 5.413s      | 0.565s      | 5.559s    | 11.578s  |
| 10 000 000    | 42.82 s       | 69.542s     | 16.800s     | 50.933s   | 139.947s |


## • Paleidimas
//g++ FailuGenmain.cpp Lib.cpp Fileproc.cpp Filegen.cpp -o main 
//main.exe
---

