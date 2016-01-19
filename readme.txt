-------------------------------------------------------------------------------------------------------
1. Autor projektu
-------------------------------------------------------------------------------------------------------
Imię i nazwisko: Radoslaw Nowak
Nr albumu: 261481

-------------------------------------------------------------------------------------------------------
2. Opis problemu
-------------------------------------------------------------------------------------------------------
Na półce są ułożone w przypadkowej kolejności pojemniki z atramentami w czterech kolorach: C, M, Y, K.
Należy je uporządkować za pomocą robota w taki sposób, aby od lewej do prawej strony półki znalazły się kolejno:
C, następnie M, następnie Y, a na końcu - K. Robot w jednym ruchu może pobrać jednocześnie dokldanie cztery
sąsiednie pojemniki z dowolnego miejsca na półce I przenieść je na prawa stronę, za wszystkie pojemniki,
a następnie dosunąć część pojemników w lewo, wypełniając lukę. Ułożyć plan pracy robota, dyktujący
w kolejnych ruchach, którą czwórkę pojemników przenieść na prawą stronę.

-------------------------------------------------------------------------------------------------------
3. Parametry aktywacji programu.
-------------------------------------------------------------------------------------------------------
Podawanie parametrów nie jest obowiązkowe przy uruchaminaniu programu,
w razie nie podania ich zostaną im przypisane wartości domyślne.

Lista parametrów:

-help
opis: Program wyswietla pomoc.

-table
opis: Program po skonczeniu swojego dzialania wyswietli tablice z czasami wykonania oraz liczba wykonanych ruchow.

-user
opis: Uzytkownik recznie wpisuje wektor, ktory bedzie sortowany.

-random
opis: Wektor ktory bedzie sortowany jest generowany przez genarator wartosci losowych.

-------------------------------------------------------------------------------------------------------
4. Metoda rozwiązania.
-------------------------------------------------------------------------------------------------------

-------------------------------------------------------------------------------------------------------
5. Pliki źródłówe.
-------------------------------------------------------------------------------------------------------

Benchmark.cpp, Benchmark.h - Klasa odpowiedzialna za tworzenie statystyk wykonania algorytmow.

Generator.cpp, Generator.h - Klasa ktora odpowiada za generowanie pseudolosowych wartosci wektora.

Shelf.cpp, Shelf.h - Klasa reprezentujaca polke. Posiada metody odpowiedzialne za sortowanie.

main.cpp - Funkcja main, odpowiadajaca za parsowanie argumentow wywolania programu oraz inicjacje Benchmarku.

-------------------------------------------------------------------------------------------------------
6. Założenia projektowe.
-------------------------------------------------------------------------------------------------------
