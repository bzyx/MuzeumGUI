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

#include <src/eksponatmuzealny.h>
#include <string>

#ifndef EREKOPIS_H
#define EREKOPIS_H
/*!
 \brief
 Klasa zarz�dzaj�ca obiektami typu Rekopis

 \class ERekopis erekopis.h "src/erekopis.h"
*/
class ERekopis : public EksponatMuzealny
{
private:
    std::string m_autor; /*!< Autor r�kopisu */
    bool m_czyZeskanowany; /*!< Czy r�kopis zosta� zeskanowany */
public:
    /*!
     \brief
     Zwraca autora r�kopisu

     \fn getAutor
    */
    std::string getAutor();
    /*!
     \brief
     Ustwia autora r�kopisu

     \fn autor
     \param autor
    */
    void autor(std::string autor);
    /*!
     \brief
     Zwraca czy rekopis by� ju� zeskanowany

     \fn getCzyZeskanowany
    */
    bool getCzyZeskanowany();
    /*!
     \brief
     Ustawia czy rekopis by� zeskanowany

     \fn czyZeskanowany
     \param czyZeskanowany
    */
    void czyZeskanowany(bool czyZeskanowany);
/*!
 \brief
 Konstruktor z wszyskimi parametrami: autor, czyZeskanowany + EksponatMuzealny

 \fn ERekopis
 \param autor
 \param czyZeskanowany
 \param nazwa
 \param wystawiony
 \param opis
 \param polozenie
 \param wartosc
 \param typ
 \param formatDaty
 \param data
*/
    ERekopis(std::string autor, bool czyZeskanowany,
             std::string nazwa, bool wystawiony, std::string opis,
             std::string polozenie, int wartosc,
             Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data);
/*!
 \brief
 Konstruktor domy�lny

 \fn ERekopis
*/
    ERekopis();
    /*!
     \brief
     Zwraca list� atrybut�w

     \fn getAtrybuty
    */
    QStringList getAtrybuty();
    /*!
     \brief
     Zwraca nazwy atrybut�w

     \fn getHeaders
    */
    QStringList getHeaders();
    /*!
     \brief
     Rekord do pliku

     \fn saveElement
    */
    r2f saveElement();
    /*!
     \brief
     Destrukor

     \fn ~ERekopis
    */
    ~ERekopis();
};

#endif // EREKOPIS_H
