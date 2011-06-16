#include <src/eksponatmuzealny.h>
#include <string>

#ifndef ERZEZBA_H
#define ERZEZBA_H

/**
 * @brief
 * Klasa zarzπdajaca obiektami typu Rzeüba
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
     * Ustawia nazwÍ postaci
     * @param postac
     */
    void postac(std::string postac);
    /**
     * @brief
     * Zwraca materia≥ z jakiego jest rzeüba
     */
    EksponatMuzealny::Material getMaterial();
    /**
     * @brief
     * Ustaiwa materia≥ z jakiego jest rzeüba
     * @param material
     */
    void material(EksponatMuzealny::Material material);
    /**
     * @brief
     * Zwraca jak duøπ powierzchniÍ zajmuje rzeüba
     */
    float getPowierzchnia();
    /**
     * @brief
     * Ustawia powierzchniÍ jakπ zajmuje rzeüba
     * @param powierzchnia
     */
    void powierchnia(float powierzchnia);

    /**
 * @brief
 * Konstruktor pe≥ny: postac, material, powierzchnia + EksponatMuzealny
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
 * Konsttruktor domyúlny
 */
    ERzezba();
    /**
     * @brief
     * Zwraca atrybuty
     */
    QStringList getAtrybuty();
    /**
     * @brief
     * Zwraca nag≥Ûwki kolumn
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
