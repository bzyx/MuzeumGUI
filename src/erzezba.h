#include <src/eksponatmuzealny.h>
#include <string>

#ifndef ERZEZBA_H
#define ERZEZBA_H

/**
 * @brief
 * Klasa zarz�dajaca obiektami typu Rze�ba
 */
class ERzezba : public EksponatMuzealny
{
private:
    std::string m_postac; /**< TODO */
    EksponatMuzealny::Material m_material; /**< TODO */
    float m_powierzchnia; /**< TODO */
public:
    /**
     * @brief
     * Zwraca nazwa postaci
     */
    std::string getPostac();
    /**
     * @brief
     * Ustawia nazw� postaci
     * @param postac
     */
    void postac(std::string postac);
    /**
     * @brief
     * Zwraca materia� z jakiego jest rze�ba
     */
    EksponatMuzealny::Material getMaterial();
    /**
     * @brief
     * Ustaiwa materia� z jakiego jest rze�ba
     * @param material
     */
    void material(EksponatMuzealny::Material material);
    /**
     * @brief
     * Zwraca jak du�� powierzchni� zajmuje rze�ba
     */
    float getPowierzchnia();
    /**
     * @brief
     * Ustawia powierzchni� jak� zajmuje rze�ba
     * @param powierzchnia
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
    ERzezba(std::string postac,
            EksponatMuzealny::Material material, float powierzchnia,
            std::string nazwa, bool wystawiony, std::string opis,
            std::string polozenie, int wartosc,
            Meta::Typ typ, FormatDaty formatDaty, std::string data);
    /**
 * @brief
 * Konsttruktor domy�lny
 */
    ERzezba();
    /**
     * @brief
     * Zwraca atrybuty
     */
    QStringList getAtrybuty();
    /**
     * @brief
     * Zwraca nag��wki kolumn
     */
    QStringList getHeaders();
    /**
     * @brief
     * Rekord do plkiku
     */
    r2f saveElement();
    /**
     * @brief
     * Destruktor
     */
    ~ERzezba();
};

#endif // ERZEZBA_H
