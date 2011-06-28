#include <src/eksponatmuzealny.h>
#include <string>

#ifndef EPRZEMIOTUZYTKOWY_H
#define EPRZEMIOTUZYTKOWY_H

/**
 * @brief
 * Klasa zarz¹dzaj¹ca obiektami u¿ytkowymi
 */
/*!
 \brief

 \class EPrzemiotUzytkowy eprzemiotuzytkowy.h "src/eprzemiotuzytkowy.h"
*/
class EPrzemiotUzytkowy : public EksponatMuzealny
{
private:
    std::string m_opisDzialania; /**< TODO */ /*!< TODO */
    bool m_czyMoznaDotykac; /**< TODO */ /*!< TODO */
public:
    /**
     * @brief
     * Zwraca opis dzia³ania przedmiotu
     */
    /*!
     \brief

     \fn getOpisDzialania
    */
    std::string getOpisDzialania();
    /**
     * @brief
     * Ustaiwa opis dzia³ania przedmiotu
     * @param opisDzialania
     */
    /*!
     \brief

     \fn opisDzialania
     \param opisDzialania
    */
    void opisDzialania(std::string opisDzialania);
    /**
     * @brief
     * Zwraca czy przemiot mo¿e byæ dotykany
     */
    /*!
     \brief

     \fn getCzyMoznaDotykac
    */
    bool getCzyMoznaDotykac();
    /**
     * @brief
     * Ustawia czy przemiot mo¿e byæ dotykany
     * @param czyMoznaDotykac
     */
    /*!
     \brief

     \fn czyMoznaDotykac
     \param czyMoznaDotykac
    */
    void czyMoznaDotykac(bool czyMoznaDotykac);
    /**
 * @brief
 * Pe³ny konstruktor opiszDzialania,czyMoznaDotykac + EksponatMuzealny
 * @param opisDzialania
 * @param czyMoznaDotykac
 * @param nazwa
 * @param wystawiony
 * @param opis
 * @param polozenie
 * @param wartosc
 * @param typ
 * @param formatDaty
 * @param data
 */
/*!
 \brief

 \fn EPrzemiotUzytkowy
 \param opisDzialania
 \param czyMoznaDotykac
 \param nazwa
 \param wystawiony
 \param opis
 \param polozenie
 \param wartosc
 \param typ
 \param formatDaty
 \param data
*/
    EPrzemiotUzytkowy(std::string opisDzialania, bool czyMoznaDotykac,
                       std::string nazwa, bool wystawiony, std::string opis,
                       std::string polozenie, int wartosc,
                       Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data
                       );
    /**
 * @brief
 * Konstruktor domyœlny
 */
/*!
 \brief

 \fn EPrzemiotUzytkowy
*/
    EPrzemiotUzytkowy();
    /**
     * @brief
     * Zwraca listê atrybutów
     */
    /*!
     \brief

     \fn getAtrybuty
    */
    QStringList getAtrybuty();
    /**
     * @brief
     * Zwraca nag³ówki atrybutów
     */
    /*!
     \brief

     \fn getHeaders
    */
    QStringList getHeaders();
    /**
     * @brief
     * Rekord do zapisu
     */
    /*!
     \brief

     \fn saveElement
    */
    r2f saveElement();
    /**
     * @brief
     * Destruktor
     */
    /*!
     \brief

     \fn ~EPrzemiotUzytkowy
    */
    ~EPrzemiotUzytkowy();
};

#endif // EPRZEMIOTUZYTKOWY_H
