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

#ifndef MATERIAL_H
#define MATERIAL_H

#include <QString>
#include <QMap>
#include <QSettings>
/*!
 \brief
 Klasa zarz�dzaj�ca materia�ami.
 Zawiera w sobie map� kt�ra ka�demu QStringowi b�d�cemu nazw� materia�u przypisuje mu jego
 identyfikator. Ca�o�� mo�e by� zapisana do pliku. Eksponaty zawierac�ce materia� przechowuj�
 tylko jego identyfikator (int) zamiast pe�nej nazwy.
 Klasa jest singletonem.

 \class Material material.h "src/material.h"
*/
class Material
{
public:
    /*!
     \brief
     Zwraca instancj� klasy. Klasa jest singletonem.

     \fn getInstance
    */
    static Material& getInstance();
    /*!
     \brief
     Dodaje nowy typ materia�u do wewn�trzngego kontenera. Je�li wybrany materia� ju� istnieje
     nie dodaje go.

     \fn addMaterial
     \param name
    */
    void addMaterial(QString name);
    /*!
     \brief
     Zwraca nazw� materia�u dla zadanego klucza. W przypadku nie odnaleizienia po kluczy zwraca
     informacj� o nieznanym materiale.

     \fn nazwaForMatV
     \param material_key
    */
    static QString nazwaForMatV(int material_key);
    /*!
     \brief
     Zwraca identyfikator materia�u dla zadanej nazwy. W przypadku podania z�ej nazwy lub
     nie istniej�cej zwraca 0 - Nieznany Materia�.

     \fn valueForMatN
     \param name
    */
    static int valueForMatN(QString name);
    /*!
     \brief
     Odczytuje zapisane nazwy i identyfikatory materia��w
    jakie znajduj� si� w pliku z ustawieniami.

     \fn readFromFile
     \param file
    */
    void readFromFile(QSettings* file);
    /*!
     \brief
     Zapisuje nazwy i identyfikatory materia��w do zadanego pliku z ustawieniami.

     \fn saveToFile
     \param file
    */
    void saveToFile(QSettings* file);

    /*!
     \brief
     Zwraca liczb� materia��w zapisanych w wewn�trznym kontenerze.

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
     Zwraca wska�nik do wewn�trzej implementacji kontenera QMap. U�ycie mocno niezalecane.

     \fn getMap
    */
    QMap<QString,int>* getMap();
    QMap<QString,int> materialy; /*!< Wewn�trzna mapa przechowuje materia�y i ich identyfikatory */
    int lastMatnum; /*!< Przechowuje numer ostatnio dodanego materia�u. Nie musi by� static
                            poniewa� klasa jest sigletonem. */
/*!
 \brief
 Konstruktor domy�lny. Prywatny.

 \fn Material
*/
    Material();
/*!
 \brief
 Konstruktor kopiuj�cy. Prywatny. Nie zdefiniowany.

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
