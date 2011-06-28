/****************************************************************************
**
** Copyright (C) 2011 Marcin Jabrzyk <marcin.jabrzyk@gmail.com>
** All rights reserved.
**
** This file is part of MuzeumGUI <marcin.jabrzyk@gmail.com>
**
** Ten utwór jest dostêpny na licencji
** Creative Commons
** Uznanie autorstwa-U¿ycie niekomercyjne-Na tych samych warunkach
** 3.0 Unported.
**
** http://creativecommons.org/licenses/by-nc-sa/3.0/
**
****************************************************************************/
/*!
  \author Marcin Jabrzyk
  \date 29.06.2011
  \mainpage Muzeum - Baza danych
  \section intro_sec Za³o¿enia programu
ZAD. 8) Napisaæ program - obiektow¹ bazê danych o eksponatach zgromadzonych
w muzeum. Za³o¿yæ, ¿e zbiory muzealne zawieraj¹ takie eksponaty jak: obrazy,
rzeŸby, meble, przedmioty u¿ytkowe, zabytkowe rêkopisy i starodruki. Nale¿y
umo¿liwiæ wprowadzanie danych, zapisywanie i odczytywanie z dysku.

WSKAZÓWKI i UWAGI:
- Ka¿da grupa eksponatów powinna byæ reprezentowana przez odpowiedni¹ klasê
zapewniaj¹c¹ takie us³ugi jak edycja danych zwi¹zanych z obiektem danej klasy,
zapis i odczytywanie.
- Wszystkie klasy powinny zostaæ wyprowadzone ze wspólnej klasy bazowej
Eksponat Muzealny.
- W pamiêci utworzyæ strukturê dynamiczn¹ - listê zawieraj¹ca elementy typu
Eksponat Muzealny.
\section idea Rozwi¹zanie problemu
\subsection primaryIdea Wstêpny pomys³
Pocz¹tkow program mia³ zawieraæ inn¹ hierahiê dzieczenia. Klasy stardodruk i rêkopis, rzeŸba i
przedmiot u¿ytkowy mia³y mieæ wspólnych przodków, które dopiero dziedczy³y po klasie EksponatMuzealny.
Po konsultacji rozwi¹zanie to zosta³o zamienione, na to ¿e ka¿da klasa dziediczy bezpoœrednio po klasie
EksponatMuzealny.
\subsection makingOf Pomys³ na rozwi¹zanie
Program zarz¹dzaj¹cy muzeum wydawa³ siê idealny do zastoswoania biblioteki graficznej w celu
wykonania przyjaznego i nowoczesnego interfejsu u¿ytkownika. Tak aby program nie stanowi³ bariery
dla u¿ytkownika. Zdecydowa³em siê na u¿ycie biblioteki Nokia Qt z powodu du¿ej funkcjonalnosæi,
otwartoœci i przyjemnej dla programisty sk³adni.
Program zosta³ podzielony na 2 zasadnicze czêœæi:
-klasy zwi¹zane z niskopoziomowym odtwarzaniem rozk³adu hierchi klas, przechowywaniem danych
-klasy zwi¹zane z manipulacj¹ danymi, wyœwietlaniem danych i reszt¹ interfejsu u¿ytkownika
Program potrafi zapisywaæ i odczytywaæ dane z odpowiednio stworzonych plików XML. Oprócz tego
w katalogu z programem tworzony jest plik .ini zawieraj¹cy ustawienia programu, a tak¿e dodatkow¹
strutkturê danych.
\subsection effects Wyniki
Podczas pisania progamu u¿y³em IDE Qt Creator które okaza³o siê bardzo wygodnym narzêdziem,
u³atwiaj¹cym zarz¹dzanie kodem przez git i tworzenie dokumentacji przez doxygen.
Uda³o mi siê zaimplementowaæ wszystkie wymagane w specyfikacji funkcjonalnoœci. Dodatkowo program
potrafi edytowaæ dane, a tak¿e istnieje mo¿liwoœæ rozszerzenia pocz¹tkowo zdefiniownaej listy materia³ów.
Stara³em siê aby zale¿noœæi dziedziczenia miêdzy klasami by³y jak najmniejsze, a tak¿e nie u¿ywaæ
publicznych zmiennnych w klasach. Zamiast tego stosowa³em liczne getery i setety, a tak¿e klasy
wykonane zgodnie z wzorcem singletona. Postanowi³em wykorzystaæ wzorzec MVC do prezentacji danych
u¿ytkownikowi, dziêki temu sam proces bezpoœrednich operacji na danych by³ bardzo prosty i mocno
oddzielony od interfejsu GUI. Dodatkow¹ zalet¹ tego rozwi¹zania jest bardzo du¿a szybkoœæ prezentacji danych.
\section mozliwosciIinstrukcja Mo¿liwosci i instrukcja obs³ugi
\subsection mozliwosci Funkcjonalnoœci programu:
-dodawanie/usuwanie/edycja zapisywanie i odczytywanie z pliku danych podzielonych na 6 grup tematycznych \n
-zapis w formacie XML pozwala na prost¹ wymianê danych z innymi aplikacjami \n
-rozszerzalna i nieulotna iloœæ materia³ów \n
-du¿a szybkoœæ dzia³ania nawet przy ogromnych iloœciach danych \n
-pe³na walidacja danych wprowadzanych do u¿ytkownika przez u¿ycie mi. in. wyra¿eñ regularnych \n
-podzia³ kodu na czêœæ graficzn¹ i przetwrzaj¹c¹ pozwala na ³atw¹ rozbudowê \n
-przyjemny dla u¿ytkownika interfejs z podpowiadaniem w razie problemów
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
