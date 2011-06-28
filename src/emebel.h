#include <src/eksponatmuzealny.h>
#include <string>

#ifndef EMEBEL_H
#define EMEBEL_H

/**
 * @brief
 * Klasa zarz¹daj¹ca obiekatami typu mebel
 */
/*!
 \brief

 \class EMebel emebel.h "src/emebel.h"
*/
class EMebel : public EksponatMuzealny
{
private:
    std::string m_rodzaj; /**< TODO */ /*!< TODO */
    int m_material; /**< TODO */ /*!< TODO */
public:
    /**
     * @brief
     * Zwraca rodzaj jaki rodzaj mebla
     */
    /*!
     \brief

     \fn getRodzaj
    */
    std::string getRodzaj();
    /**
     * @brief
     * Ustawia rodzaj mebla
     * @param std::string
     */
    /*!
     \brief

     \fn rodzaj
     \param std::string
    */
    void rodzaj(std::string);
    /**
     * @brief
     * Zwraca rodzaj materialu z jakiego jest mebele
     */
    /*!
     \brief

     \fn getMaterial
    */
    int getMaterial();
    /**
     * @brief
     * Ustawia rodzaj materialu mebla
     * @param material
     */
    /*!
     \brief

     \fn material
     \param material
    */
    void material(int material);
/**
 * @brief
 * rodzaj,material + EksponatMuzealny
 * @param rodzaj
 * @param material
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

 \fn EMebel
 \param rodzaj
 \param material
 \param nazwa
 \param wystawiony
 \param opis
 \param polozenie
 \param wartosc
 \param typ
 \param formatDaty
 \param data
*/
    EMebel(std::string rodzaj,int material ,
           std::string nazwa, bool wystawiony, std::string opis,
           std::string polozenie, int wartosc,
           Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data);
/**
 * @brief
 * Konstruktor domyslny
 */
/*!
 \brief

 \fn EMebel
*/
    EMebel();
    /**
     * @brief
     * Zwraca atrybuty
     */
    /*!
     \brief

     \fn getAtrybuty
    */
    QStringList getAtrybuty();
    /**
     * @brief
     * Zwraca nag³ówek atrybutów
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

     \fn ~EMebel
    */
    ~EMebel();
};

#endif // EMEBEL_H
