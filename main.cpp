/****************************************************************************
**
** Copyright (C) 2011 Marcin Jabrzyk <marcin. jabrzyk@gmail. com>
** All rights reserved.
**
** This file is part of MuzeumGUI <marcin. jabrzyk@gmail. com>
**
** Ten utw�r jest dost�pny na licencji
** Creative Commons
** Uznanie autorstwa-U�ycie niekomercyjne-Na tych samych warunkach
** 3. 0 Unported.
**
** http://creativecommons. org/licenses/by-nc-sa/3. 0/
**
****************************************************************************/
/*!
  \author Marcin Jabrzyk
  \date 29. 06. 2011
  \mainpage Muzeum - Baza danych
  \section intro_sec Za�o�enia programu
ZAD.  8) Napisa� program - obiektow� baz� danych o eksponatach zgromadzonych
w muzeum.  Za�o�y�, �e zbiory muzealne zawieraj� takie eksponaty jak: obrazy,
rze�by, meble, przedmioty u�ytkowe, zabytkowe r�kopisy i starodruki.  Nale�y
umo�liwi� wprowadzanie danych, zapisywanie i odczytywanie z dysku.

WSKAZ�WKI i UWAGI:
- Ka�da grupa eksponat�w powinna by� reprezentowana przez odpowiedni� klas�
zapewniaj�c� takie us�ugi jak edycja danych zwi�zanych z obiektem danej klasy,
zapis i odczytywanie.
- Wszystkie klasy powinny zosta� wyprowadzone ze wsp�lnej klasy bazowej
Eksponat Muzealny.
- W pami�ci utworzy� struktur� dynamiczn� - list� zawieraj�ca elementy typu
Eksponat Muzealny.
\section idea Rozwi�zanie problemu
\subsection primaryIdea Wst�pny pomys�
Pocz�tkow program mia� zawiera� inn� hierahi� dzieczenia.  Klasy stardodruk i r�kopis, rze�ba i
przedmiot u�ytkowy mia�y mie� wsp�lnych przodk�w, kt�re dopiero dziedczy�y po klasie EksponatMuzealny.
Po konsultacji rozwi�zanie to zosta�o zamienione, na to �e ka�da klasa dziediczy bezpo�rednio po klasie
EksponatMuzealny.
\subsection makingOf Pomys� na rozwi�zanie
Program zarz�dzaj�cy muzeum wydawa� si� idealny do zastoswoania biblioteki graficznej w celu
wykonania przyjaznego i nowoczesnego interfejsu u�ytkownika.  Tak aby program nie stanowi� bariery
dla u�ytkownika.  Zdecydowa�em si� na u�ycie biblioteki Nokia Qt z powodu du�ej funkcjonalnos�i,
otwarto�ci i przyjemnej dla programisty sk�adni.
Program zosta� podzielony na 2 zasadnicze cz��i:
-klasy zwi�zane z niskopoziomowym odtwarzaniem rozk�adu hierchi klas, przechowywaniem danych
-klasy zwi�zane z manipulacj� danymi, wy�wietlaniem danych i reszt� interfejsu u�ytkownika
Program potrafi zapisywa� i odczytywa� dane z odpowiednio stworzonych plik�w XML.  Opr�cz tego
w katalogu z programem tworzony jest plik . ini zawieraj�cy ustawienia programu, a tak�e dodatkow�
strutktur� danych.
\subsection effects Wyniki
Podczas pisania progamu u�y�em IDE Qt Creator kt�re okaza�o si� bardzo wygodnym narz�dziem,
u�atwiaj�cym zarz�dzanie kodem przez git i tworzenie dokumentacji przez doxygen.
Uda�o mi si� zaimplementowa� wszystkie wymagane w specyfikacji funkcjonalno�ci.  Dodatkowo program
potrafi edytowa� dane, a tak�e istnieje mo�liwo�� rozszerzenia pocz�tkowo zdefiniownaej listy materia��w.
Stara�em si� aby zale�no��i dziedziczenia mi�dzy klasami by�y jak najmniejsze, a tak�e nie u�ywa�
publicznych zmiennnych w klasach.  Zamiast tego stosowa�em liczne getery i setety, a tak�e klasy
wykonane zgodnie z wzorcem singletona.  Postanowi�em wykorzysta� wzorzec MVC do prezentacji danych
u�ytkownikowi, dzi�ki temu sam proces bezpo�rednich operacji na danych by� bardzo prosty i mocno
oddzielony od interfejsu GUI.  Dodatkow� zalet� tego rozwi�zania jest bardzo du�a szybko�� prezentacji danych.
\section mozliwoscipr Mo�liwosci programu:
\subsection mozliwosci Funkcjonalno�ci programu:
- dodawanie/usuwanie/edycja zapisywanie i odczytywanie z pliku danych podzielonych na 6 grup tematycznych \n
- zapis w formacie XML pozwala na prost� wymian� danych z innymi aplikacjami \n
- rozszerzalna i nieulotna ilo�� materia��w \n
- du�a szybko�� dzia�ania nawet przy ogromnych ilo�ciach danych \n
- pe�na walidacja danych wprowadzanych do u�ytkownika przez u�ycie mi.  in.  wyra�e� regularnych \n
- podzia� kodu na cz�� graficzn� i przetwrzaj�c� pozwala na �atw� rozbudow� \n
- przyjemny dla u�ytkownika interfejs z podpowiadaniem w razie problem�w \n


\section test1 Instrukcja obs�ugi
- Po uruchomieniu programu pojawi si� nam okno w kt�rym b�dziemy mie� mo�liwo�� wczytania ostatnio u�ywanego
pliku (je�li ju� wcze�niej u�ywali�my programu), wczta� dowoln� baz� lub utworzy� now�.  Te same operacje mo�emy wykona� z menu Plik.
Mo�liwa jest opcja dodania nowych materia��w w menu Materia�y.
- Zak�adamy, �e wczytujemy plik z baz�.  Przechodzimy do g��wnego okna programu.
W centralnej cz�ci mamy podgl�d danych.  Dwukrotne klikni�cie na obiekcie w trybie "Wszyskie typy" otwiera perspektyw� edycji danych.   Teraz
mo�emy edytowa� dane.  �adne pole nie mo�e by� puste.  Nie mo�na zmieni� identyfikatora ani typu.
Wybieraj�c format daty b�dziemy musiali wpisa� dat� w spos�b taki jak w nawiasie opisuj�cym wybrany
format.  W przypadku pozostawienia niewype�nionego pola i pr�by zapisania, b��dne pole zostanie oznaczone
na czerwono.  Po najechaniu na niekt�re czerwone pola zostanie wy�wietlona wskaz�wka jaka powinna byc jego zawarto��.
- W panelu edycji jest mo�liwo�� usuni�cia rekordu przez wci�ni�cie przycisku Usu� (lub wci�ni�cia Del ).
- Panel dodawania jest podobny do panelu edycji.  Wymagane jest wybranie Typu obiektu, w zale�nosci od tego
zmieniaj� si� dost�pne pola.  W przypadku niewype�nienia jakiego� pola rekacja jest jak w panelu edycji
pole zostaje oznaczone na czerwono.
- W menu plik istnieje mo�liwo�� zapisania danych do wybranego pliku.  Standardowo pocz�tkowa scie�ka wskazuje
na katalog Moje Dokumenty.  Tworzenie nowej bazy lub otwarcie innej bez uprzedniego zapisania starej powoduje jej
utracenie.
- W menu Materia�y mamy mo�liwo�� dodania nowych materia��w, w przpadku pr�by dodania istsniej�cego
materia�u zostanie wy�wietlony odpowiedni komunikat.  Materia�y zostaj� zapisane do pliku podczas wychodzenia
z programu
- Do wi�kszo�ci opcji zostaly zdefiniowane skr�ty klawiszowe, kt�re mo�na odczyta� w menu programu.
*/

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
