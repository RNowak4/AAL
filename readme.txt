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

-stepByStep
opis: Program pokazuje przykladowe rozwiazanie krok po kroku

-------------------------------------------------------------------------------------------------------
4. Metoda rozwiązania.
-------------------------------------------------------------------------------------------------------
Po krótce omówione metody rozwiązania. Szczegółowy opis w dokmentacji końcowej.

Pierwsza metoda polega na kolejnym sortowaniu kolorów - począwszy od "C", a końcyzwszy na "M".
Polega na kolejnym znajdowaniu następnych pojemników sortowanego koloru i przenoszeniu ich na
koniec zbioru pojemników posortowanych a następnie powiększeniu tego zbioru o 1.

Druga metoda różni się tym od pierwszej, że najpierw szukamy czwórek koloru sortowanego
i takie czwórki przenosimy na koniec zbioru pojemników posortowanych. Jeśli w zbiorze
pojemników nieposortowanych nie ma już szukanych czwórek, to kontynuujemy sortowanie
metodą pierwszą.

Trzecia metoda polega na tworzeniu między pojemnikami koloru sortowanego przestrzeni złożonych
z pojemników kolorów innych w liczbie będącej wielokrotnością 4. Następnie przenosimy czwórkami
pojemniki kolorów innych na koniec zbioru pojemników nieposortowanych. Po wykonaniu takiego działania,
na początku wektora pojemników znajdują się same pojemniki koloru sortowanego. Iterację algorytmu kończy
powięszenie strefy pojemników posortowanych.

Wszystkie algorytmy mają złożoność O(n^3), natomiast algorytm trzeci, dla takich samych danych,
jest znacznie szybszy niz dwa pozostale.
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
