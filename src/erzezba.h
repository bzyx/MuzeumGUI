#include <src/eksponatmuzealny.h>
#include <string>

#ifndef ERZEZBA_H
#define ERZEZBA_H

/**
 * @brief
 * Klasa zarz�dajaca obiektami typu Rze�ba
 */
/*!
 \brief

 \class ERzezba erzezba.h "src/erzezba.h"
*/
class ERzezba : public EksponatMuzealny
{
private:
    std::string m_postac; /**< TODO */ /*!< TODO */
    int m_material; /**< TODO */ /*!< TODO */
    float m_powierzchnia; /**< TODO */ /*!< TODO */
public:
    /**
     * @brief
     * Zwraca nazwa postaci
     */
    /*!
     \brief

     \fn getPostac
    */
    std::string getPostac();
    /**
     * @brief
     * Ustawia nazw� postaci
     * @param postac
     */
    /*!
     \brief

     \fn postac
     \param postac
    */
    void postac(std::string postac);
    /**
     * @brief
     * Zwraca materia� z jakiego jest rze�ba
     */
    /*!
     \brief

     \fn getMaterial
    */
    int getMaterial();
    /**
     * @brief
     * Ustaiwa materia� z jakiego jest rze�ba
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
     * Zwraca jak du�� powierzchni� zajmuje rze�ba
     */
    /*!
     \brief

     \fn getPowierzchnia
    */
    float getPowierzchnia();
    /**
     * @brief
     * Ustawia powierzchni� jak� zajmuje rze�ba
     * @param powierzchnia
     */
    /*!
     \brief

     \fn powierchnia
     \param powierzchnia
    */
    void powierchnia(float powierzchnia);

    /**
 * @brief
 * Konstruktor pe�ny: postac, material, powierzchnia + EksponatMuzealny
 * @param postac
 * @param material
 * @param powierzchnia
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

 \fn ERzezba
 \param postac
 \param material
 \param powierzchnia
 \param nazwa
 \param wystawiony
 \param opis
 \param polozenie
 \param wartosc
 \param typ
 \param formatDaty
 \param data
*/
    ERzezba(std::string postac,
            int material, float powierzchnia,
            std::string nazwa, bool wystawiony, std::string opis,
            std::string polozenie, int wartosc,
            Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data);
    /**
 * @brief
 * Konsttruktor domy�lny
 */
/*!
 \brief

 \fn ERzezba
*/
    ERzezba();
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
     * Zwraca nag��wki kolumn
     */
    /*!
     \brief

     \fn getHeaders
    */
    QStringList getHeaders();
    /**
     * @brief
     * Rekord do plkiku
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

     \fn ~ERzezba
    */
    ~ERzezba();
};

#endif // ERZEZBA_H
