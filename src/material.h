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

#ifndef MATERIAL_H
#define MATERIAL_H

#include <QString>
#include <QMap>
#include <QSettings>
/*!
 \brief
 Klasa zarz¹dzaj¹ca materia³ami.
 Zawiera w sobie mapê która ka¿demu QStringowi bêd¹cemu nazw¹ materia³u przypisuje mu jego
 identyfikator. Ca³oœæ mo¿e byæ zapisana do pliku. Eksponaty zawierac¹ce materia³ przechowuj¹
 tylko jego identyfikator (int) zamiast pe³nej nazwy.
 Klasa jest singletonem.

 \class Material material.h "src/material.h"
*/
class Material
{
public:
    /*!
     \brief
     Zwraca instancjê klasy. Klasa jest singletonem.

     \fn getInstance
    */
    static Material& getInstance();
    /*!
     \brief
     Dodaje nowy typ materia³u do wewnêtrzngego kontenera. Jeœli wybrany materia³ ju¿ istnieje
     nie dodaje go.

     \fn addMaterial
     \param name
    */
    void addMaterial(QString name);
    /*!
     \brief
     Zwraca nazwê materia³u dla zadanego klucza. W przypadku nie odnaleizienia po kluczy zwraca
     informacjê o nieznanym materiale.

     \fn nazwaForMatV
     \param material_key
    */
    static QString nazwaForMatV(int material_key);
    /*!
     \brief
     Zwraca identyfikator materia³u dla zadanej nazwy. W przypadku podania z³ej nazwy lub
     nie istniej¹cej zwraca 0 - Nieznany Materia³.

     \fn valueForMatN
     \param name
    */
    static int valueForMatN(QString name);
    /*!
     \brief
     Odczytuje zapisane nazwy i identyfikatory materia³ów
    jakie znajduj¹ siê w pliku z ustawieniami.

     \fn readFromFile
     \param file
    */
    void readFromFile(QSettings* file);
    /*!
     \brief
     Zapisuje nazwy i identyfikatory materia³ów do zadanego pliku z ustawieniami.

     \fn saveToFile
     \param file
    */
    void saveToFile(QSettings* file);

    /*!
     \brief
     Zwraca liczbê materia³ów zapisanych w wewnêtrznym kontenerze.

     \fn count
    */
    int count();
    /*!
     \brief
     Destruktor

     \fn ~Material
    */
    ~Material();
private:
    /*!
     \brief
     Zwraca wskaŸnik do wewnêtrzej implementacji kontenera QMap. U¿ycie mocno niezalecane.

     \fn getMap
    */
    QMap<QString,int>* getMap();
    QMap<QString,int> materialy; /*!< Wewnêtrzna mapa przechowuje materia³y i ich identyfikatory */
    int lastMatnum; /*!< Przechowuje numer ostatnio dodanego materia³u. Nie musi byæ static
                            poniewa¿ klasa jest sigletonem. */
/*!
 \brief
 Konstruktor domyœlny. Prywatny.

 \fn Material
*/
    Material();
/*!
 \brief
 Konstruktor kopiuj¹cy. Prywatny. Nie zdefiniowany.

 \fn Material
 \param
*/
    Material(Material& );
    /*!
     \brief
     Operator przypisania. Prywatny. Nie zdefiniowany.

     \fn operator =
     \param
    */
    Material& operator=(Material&);
};

#endif // MATERIAL_H
