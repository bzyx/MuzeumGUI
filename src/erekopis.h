#include <src/eksponatmuzealny.h>
#include <string>

#ifndef EREKOPIS_H
#define EREKOPIS_H

/**
 * @brief
 * Klasa zarz¹dzaj¹ca obiektami typu Rekopis
 */
/*!
 \brief

 \class ERekopis erekopis.h "src/erekopis.h"
*/
class ERekopis : public EksponatMuzealny
{
private:
    std::string m_autor; /**< TODO */ /*!< TODO */
    bool m_czyZeskanowany; /**< TODO */ /*!< TODO */
public:
    /**
     * @brief
     * Zweaca autora rekopisu
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
     * Zwraca czy rekopis by³ ju¿ zeskanowany
     */
    /*!
     \brief

     \fn getCzyZeskanowany
    */
    bool getCzyZeskanowany();
    /**
     * @brief
     * Ustawia czy rekopis by³ zeskanowany
     * @param czyZeskanowany
     */
    /*!
     \brief

     \fn czyZeskanowany
     \param czyZeskanowany
    */
    void czyZeskanowany(bool czyZeskanowany);

/**
 * @brief
 * autor, czyZeskanowany + EksponatMuzealny
 * @param autor
 * @param czyZeskanowany
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
/**
 * @brief
 * Konstruktor domyœlny
 */
/*!
 \brief

 \fn ERekopis
*/
    ERekopis();
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
     * Zwraca nag³ówek
     */
    /*!
     \brief

     \fn getHeaders
    */
    QStringList getHeaders();
    /**
     * @brief
     * Element do pliku
     */
    /*!
     \brief

     \fn saveElement
    */
    r2f saveElement();
    /**
     * @brief
     * Destrukor
     */
    /*!
     \brief

     \fn ~ERekopis
    */
    ~ERekopis();
};

#endif // EREKOPIS_H
