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

/*! \mainpage Muzeum - Baza danych
 *
 * \section intro_sec Za³o¿enia programu
 *
 * ZAD. 8) Napisaæ program - obiektow¹ bazê danych o eksponatach zgromadzonych
 * w muzeum. Za³o¿yæ, ¿e zbiory muzealne zawieraj¹ takie eksponaty jak: obrazy,
 * rzeŸby, meble, przedmioty u¿ytkowe, zabytkowe rêkopisy i starodruki. Nale¿y
 * umo¿liwiæ wprowadzanie danych, zapisywanie i odczytywanie z dysku.

 * WSKAZÓWKI i UWAGI:
 * - Ka¿da grupa eksponatów powinna byæ reprezentowana przez odpowiedni¹ klasê
 * zapewniaj¹c¹ takie us³ugi jak edycja danych zwi¹zanych z obiektem danej klasy,
 * zapis i odczytywanie.
 * - Wszystkie klasy powinny zostaæ wyprowadzone ze wspólnej klasy bazowej
 * Eksponat Muzealny.
 * - W pamiêci utworzyæ strukturê dynamiczn¹ - listê zawieraj¹ca elementy typu
 * Eksponat Muzealny.
 *
 * \section install_sec Installation
 *
 * \subsection step1 Step 1: Opening the box
 *
 * etc...
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
