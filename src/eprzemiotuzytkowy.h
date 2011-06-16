#include <src/eksponatmuzealny.h>
#include <string>

#ifndef EPRZEMIOTUZYTKOWY_H
#define EPRZEMIOTUZYTKOWY_H

/**
 * @brief
 * Klasa zarz�dzaj�ca obiektami u�ytkowymi
 */
class EPrzemiotUzytkowy : public EksponatMuzealny
{
private:
    std::string m_opisDzialania; /**< TODO */
    bool m_czyMoznaDotykac; /**< TODO */
public:
    /**
     * @brief
     * Zwraca opis dzia�ania przedmiotu
     */
    std::string getOpisDzialania();
    /**
     * @brief
     * Ustaiwa opis dzia�ania przedmiotu
     * @param opisDzialania
     */
    void opisDzialania(std::string opisDzialania);
    /**
     * @brief
     * Zwraca czy przemiot mo�e by� dotykany
     */
    bool getCzyMoznaDotykac();
    /**
     * @brief
     * Ustawia czy przemiot mo�e by� dotykany
     * @param czyMoznaDotykac
     */
    void czyMoznaDotykac(bool czyMoznaDotykac);
    /**
 * @brief
 * Pe�ny konstruktor opiszDzialania,czyMoznaDotykac + EksponatMuzealny
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
    EPrzemiotUzytkowy(std::string opisDzialania, bool czyMoznaDotykac,
                       std::string nazwa, bool wystawiony, std::string opis,
                       std::string polozenie, int wartosc,
                       Meta::Typ typ, FormatDaty formatDaty, std::string data
                       );
    /**
 * @brief
 * Konstruktor domy�lny
 */
    EPrzemiotUzytkowy();
    /**
     * @brief
     * Zwraca list� atrybut�w
     */
    QStringList getAtrybuty();
    /**
     * @brief
     * Zwraca nag��wki atrybut�w
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
    ~EPrzemiotUzytkowy();
};

#endif // EPRZEMIOTUZYTKOWY_H
