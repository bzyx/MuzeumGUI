#include <src/eksponatmuzealny.h>
#include <string>

#ifndef EOBRAZ_H
#define EOBRAZ_H

/**
 * @brief
 *
 */
class EObraz : public EksponatMuzealny
{
private:
    float m_wysokosc; /**< TODO */
    float m_szerokosc; /**< TODO */
    std::string m_autor; /**< TODO */
public:
    /**
     * @brief
     * Zwraca wyskokoœæ
     */
    float getWysokosc();
    /**
     * @brief
     * Ustawia wysokoœæ
     * @param w
     */
    void wysokosc(float w);
    /**
     * @brief
     * Zwraca szerokoœæ
     */
    float getSzerokosc();
    /**
     * @brief
     * Ustawia szerokoœæ
     * @param s
     */
    void szerokosc(float s);
    /**
     * @brief
     * Zwraca autora
     */
    std::string getAutor();
    /**
     * @brief
     * Ustawia autora
     * @param autor
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
    EObraz(float w, float s, std::string autor,
           std::string nazwa, bool wystawiony, std::string opis,
           std::string polozenie, int wartosc,
           Typ typ, FormatDaty formatDaty, std::string data);
/**
 * @brief
 * Konstruktor romyœlny
 */
    EObraz();
    /**
     * @brief
     * Zwraca listê atrybutów z dodatkowymi
     * atrybutami
     */
    QStringList getAtrybuty();
    /**
     * @brief
     * Zwraca heder z dodatkowymi kolumnami
     */
    QStringList getHeaders();
    /**
     * @brief
     * Przygotowuje rekord do zapisu
     */
    r2f saveElement();
    /**
     * @brief
     * Destruktor
     */
    ~EObraz();
};

#endif // EOBRAZ_H
