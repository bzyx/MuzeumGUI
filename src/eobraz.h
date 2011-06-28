#include <src/eksponatmuzealny.h>
#include <string>

#ifndef EOBRAZ_H
#define EOBRAZ_H

/**
 * @brief
 * Klasa zarz¹dzaj¹ca eksponatami typu Obraz
 */
/*!
 \brief

 \class EObraz eobraz.h "src/eobraz.h"
*/
class EObraz : public EksponatMuzealny
{
private:
    float m_wysokosc; /**< TODO */ /*!< TODO */
    float m_szerokosc; /**< TODO */ /*!< TODO */
    std::string m_autor; /**< TODO */ /*!< TODO */
public:
    /**
     * @brief
     * Zwraca wyskokoœæ
     */
    /*!
     \brief

     \fn getWysokosc
    */
    float getWysokosc();
    /**
     * @brief
     * Ustawia wysokoœæ
     * @param w
     */
    /*!
     \brief

     \fn wysokosc
     \param w
    */
    void wysokosc(float w);
    /**
     * @brief
     * Zwraca szerokoœæ
     */
    /*!
     \brief

     \fn getSzerokosc
    */
    float getSzerokosc();
    /**
     * @brief
     * Ustawia szerokoœæ
     * @param s
     */
    /*!
     \brief

     \fn szerokosc
     \param s
    */
    void szerokosc(float s);
    /**
     * @brief
     * Zwraca autora
     */
    /*!
     \brief

     \fn getAutor
    */
    std::string getAutor();
    /**
     * @brief
     * Ustawia autora
     * @param autor
     */
    /*!
     \brief

     \fn autor
     \param autor
    */
    void autor(std::string autor);
    /**
 * @brief
 * Konstruktor pe³ny =
 * w,s,autor + EksponatMuzealny
 * @param w
 * @param s
 * @param autor
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

 \fn EObraz
 \param w
 \param s
 \param autor
 \param nazwa
 \param wystawiony
 \param opis
 \param polozenie
 \param wartosc
 \param Meta::Typ
 \param formatDaty
 \param data
*/
    EObraz(float w, float s, std::string autor,
           std::string nazwa, bool wystawiony, std::string opis,
           std::string polozenie, int wartosc,
           Meta::Typ, Meta::FormatDaty formatDaty, std::string data);
    /**
 * @brief
 * Konstruktor romyœlny
 */
/*!
 \brief

 \fn EObraz
*/
    EObraz();
    /**
     * @brief
     * Zwraca listê atrybutów z dodatkowymi
     * atrybutami
     */
    /*!
     \brief

     \fn getAtrybuty
    */
    QStringList getAtrybuty();
    /**
     * @brief
     * Zwraca heder z dodatkowymi kolumnami
     */
    /*!
     \brief

     \fn getHeaders
    */
    QStringList getHeaders();
    /**
     * @brief
     * Przygotowuje rekord do zapisu
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

     \fn ~EObraz
    */
    ~EObraz();
};

#endif // EOBRAZ_H
