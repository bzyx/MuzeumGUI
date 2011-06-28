#include <src/eksponatmuzealny.h>
#include <string>

#ifndef ESTARODRUK_H
#define ESTARODRUK_H

/**
 * @brief
 * Klasa zarz�dzaj�ca obiekatmi typu Starodruk
 */
/*!
 \brief

 \class EStarodruk estarodruk.h "src/estarodruk.h"
*/
class EStarodruk : public EksponatMuzealny
{
private:
    std::string m_autor; /**< TODO */ /*!< TODO */
    std::string m_streszczenie; /**< TODO */ /*!< TODO */
    int m_liczbaStron; /**< TODO */ /*!< TODO */
public:
    /**
     * @brief
     * Zwraca autora starodruku
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
     * Zwraca kr�tkie streszczenie starodruku
     */
    /*!
     \brief

     \fn getStreszczenie
    */
    std::string getStreszczenie();
    /**
     * @brief
     * Ustawia kr�tkie streszczenie starordruku
     * @param streszczenie
     */
    /*!
     \brief

     \fn sterszczenie
     \param streszczenie
    */
    void sterszczenie(std::string streszczenie);
    /**
     * @brief
     * Zwraca liczb� stron starodruku
     */
    /*!
     \brief

     \fn getLiczbaStron
    */
    int getLiczbaStron();
    /**
     * @brief
     * Ustawia liczb� stron w starodruku
     * @param liczbaStron
     */
    /*!
     \brief

     \fn liczbaStron
     \param liczbaStron
    */
    void liczbaStron(int liczbaStron);
/**
 * @brief
 * augtor, streszczenie, liczba stron + EksponatMuzealny
 * @param autor
 * @param streszczenie
 * @param liczbaStron
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

 \fn EStarodruk
 \param autor
 \param streszczenie
 \param liczbaStron
 \param nazwa
 \param wystawiony
 \param opis
 \param polozenie
 \param wartosc
 \param typ
 \param formatDaty
 \param data
*/
    EStarodruk(std::string autor, std::string streszczenie, int liczbaStron,
           std::string nazwa, bool wystawiony, std::string opis,
           std::string polozenie, int wartosc,
           Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data);
/**
 * @brief
 * Konstrutkor domy�lny
 */
/*!
 \brief

 \fn EStarodruk
*/
    EStarodruk();
    /**
     * @brief
     * Zwraca list� atrybut�w
     */
    /*!
     \brief

     \fn getAtrybuty
    */
    QStringList getAtrybuty();
    /**
     * @brief
     * Zwraca nag��wki listy atrybut�w
     */
    /*!
     \brief

     \fn getHeaders
    */
    QStringList getHeaders();
    /**
     * @brief
     * Przygotowanie rekordu do zapisu
     */
    /*!
     \brief

     \fn saveElement
    */
    r2f saveElement();
    /**
     * @brief
     * Destrutkor
     */
    /*!
     \brief

     \fn ~EStarodruk
    */
    ~EStarodruk();
};

#endif // ESTARODRUK_H
