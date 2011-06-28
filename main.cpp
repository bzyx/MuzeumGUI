/****************************************************************************
**
** Copyright (C) 2011 Marcin Jabrzyk <marcin.jabrzyk@gmail.com>
** All rights reserved.
**
** This file is part of MuzeumGUI <marcin.jabrzyk@gmail.com>
**
** Ten utw�r jest dost�pny na licencji
** Creative Commons
** Uznanie autorstwa-U�ycie niekomercyjne-Na tych samych warunkach
** 3.0 Unported.
**
** http://creativecommons.org/licenses/by-nc-sa/3.0/
**
****************************************************************************/
/*!
  \author Marcin Jabrzyk
  \date 29.06.2011
  \mainpage Muzeum - Baza danych
  \section intro_sec Za�o�enia programu
ZAD. 8) Napisa� program - obiektow� baz� danych o eksponatach zgromadzonych
w muzeum. Za�o�y�, �e zbiory muzealne zawieraj� takie eksponaty jak: obrazy,
rze�by, meble, przedmioty u�ytkowe, zabytkowe r�kopisy i starodruki. Nale�y
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
Pocz�tkow program mia� zawiera� inn� hierahi� dzieczenia. Klasy stardodruk i r�kopis, rze�ba i
przedmiot u�ytkowy mia�y mie� wsp�lnych przodk�w, kt�re dopiero dziedczy�y po klasie EksponatMuzealny.
Po konsultacji rozwi�zanie to zosta�o zamienione, na to �e ka�da klasa dziediczy bezpo�rednio po klasie
EksponatMuzealny.
\subsection makingOf Pomys� na rozwi�zanie
Program zarz�dzaj�cy muzeum wydawa� si� idealny do zastoswoania biblioteki graficznej w celu
wykonania przyjaznego i nowoczesnego interfejsu u�ytkownika. Tak aby program nie stanowi� bariery
dla u�ytkownika. Zdecydowa�em si� na u�ycie biblioteki Nokia Qt z powodu du�ej funkcjonalnos�i,
otwarto�ci i przyjemnej dla programisty sk�adni.
Program zosta� podzielony na 2 zasadnicze cz��i:
-klasy zwi�zane z niskopoziomowym odtwarzaniem rozk�adu hierchi klas, przechowywaniem danych
-klasy zwi�zane z manipulacj� danymi, wy�wietlaniem danych i reszt� interfejsu u�ytkownika
Program potrafi zapisywa� i odczytywa� dane z odpowiednio stworzonych plik�w XML. Opr�cz tego
w katalogu z programem tworzony jest plik .ini zawieraj�cy ustawienia programu, a tak�e dodatkow�
strutktur� danych.
\subsection effects Wyniki
Podczas pisania progamu u�y�em IDE Qt Creator kt�re okaza�o si� bardzo wygodnym narz�dziem,
u�atwiaj�cym zarz�dzanie kodem przez git i tworzenie dokumentacji przez doxygen.
Uda�o mi si� zaimplementowa� wszystkie wymagane w specyfikacji funkcjonalno�ci. Dodatkowo program
potrafi edytowa� dane, a tak�e istnieje mo�liwo�� rozszerzenia pocz�tkowo zdefiniownaej listy materia��w.
Stara�em si� aby zale�no��i dziedziczenia mi�dzy klasami by�y jak najmniejsze, a tak�e nie u�ywa�
publicznych zmiennnych w klasach. Zamiast tego stosowa�em liczne getery i setety, a tak�e klasy
wykonane zgodnie z wzorcem singletona. Postanowi�em wykorzysta� wzorzec MVC do prezentacji danych
u�ytkownikowi, dzi�ki temu sam proces bezpo�rednich operacji na danych by� bardzo prosty i mocno
oddzielony od interfejsu GUI. Dodatkow� zalet� tego rozwi�zania jest bardzo du�a szybko�� prezentacji danych.
\section mozliwosciIinstrukcja Mo�liwosci i instrukcja obs�ugi
\subsection mozliwosci Funkcjonalno�ci programu:
-dodawanie/usuwanie/edycja zapisywanie i odczytywanie z pliku danych podzielonych na 6 grup tematycznych \n
-zapis w formacie XML pozwala na prost� wymian� danych z innymi aplikacjami \n
-rozszerzalna i nieulotna ilo�� materia��w \n
-du�a szybko�� dzia�ania nawet przy ogromnych ilo�ciach danych \n
-pe�na walidacja danych wprowadzanych do u�ytkownika przez u�ycie mi. in. wyra�e� regularnych \n
-podzia� kodu na cz�� graficzn� i przetwrzaj�c� pozwala na �atw� rozbudow� \n
-przyjemny dla u�ytkownika interfejs z podpowiadaniem w razie problem�w
\subsection mozliwosci Instrukcja:
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
