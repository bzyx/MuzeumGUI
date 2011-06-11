#include <src/eksponatmuzealny.h>
#include <string>

#ifndef EMEBEL_H
#define EMEBEL_H

/**
 * @brief
 * Klasa zarz¹daj¹ca obiekatami typu mebel
 */
class EMebel : public EksponatMuzealny
{
private:
    std::string m_rodzaj; /**< TODO */
    EksponatMuzealny::Material m_material; /**< TODO */
public:
    /**
     * @brief
     * Zwraca rodzaj jaki rodzaj mebla
     */
    std::string getRodzaj();
    /**
     * @brief
     * Ustawia rodzaj mebla
     * @param std::string
     */
    void rodzaj(std::string);
    /**
     * @brief
     * Zwraca rodzaj materialu z jakiego jest mebele
     */
    EksponatMuzealny::Material getMaterial();
    /**
     * @brief
     * Ustawia rodzaj materialu mebla
     * @param material
     */
    void material(EksponatMuzealny::Material material);
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
    EMebel(std::string rodzaj,EksponatMuzealny::Material material ,
           std::string nazwa, bool wystawiony, std::string opis,
           std::string polozenie, int wartosc,
           Typ typ, FormatDaty formatDaty, std::string data);
/**
 * @brief
 * Konstruktor domyslny
 */
    EMebel();
    /**
     * @brief
     * Zwraca atrybuty
     */
    QStringList getAtrybuty();
    /**
     * @brief
     * Zwraca nag³ówek atrybutów
     */
    QStringList getHeaders();
    /**
     * @brief
     * Rekord do zapisu
     */
    r2f saveElement();
    /**
     * @brief
     * Destruktor
     */
    ~EMebel();
};

#endif // EMEBEL_H
