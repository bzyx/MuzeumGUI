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

/*! \mainpage Muzeum - Baza danych
 *
 * \section intro_sec Za�o�enia programu
 *
 * ZAD. 8) Napisa� program - obiektow� baz� danych o eksponatach zgromadzonych
 * w muzeum. Za�o�y�, �e zbiory muzealne zawieraj� takie eksponaty jak: obrazy,
 * rze�by, meble, przedmioty u�ytkowe, zabytkowe r�kopisy i starodruki. Nale�y
 * umo�liwi� wprowadzanie danych, zapisywanie i odczytywanie z dysku.

 * WSKAZ�WKI i UWAGI:
 * - Ka�da grupa eksponat�w powinna by� reprezentowana przez odpowiedni� klas�
 * zapewniaj�c� takie us�ugi jak edycja danych zwi�zanych z obiektem danej klasy,
 * zapis i odczytywanie.
 * - Wszystkie klasy powinny zosta� wyprowadzone ze wsp�lnej klasy bazowej
 * Eksponat Muzealny.
 * - W pami�ci utworzy� struktur� dynamiczn� - list� zawieraj�ca elementy typu
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
