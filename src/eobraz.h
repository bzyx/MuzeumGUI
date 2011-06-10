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
     * Zwraca wyskoko��
     */
    float getWysokosc();
    /**
     * @brief
     * Ustawia wysoko��
     * @param w
     */
    void wysokosc(float w);
    /**
     * @brief
     * Zwraca szeroko��
     */
    float getSzerokosc();
    /**
     * @brief
     * Ustawia szeroko��
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
 * Konstruktor pe�ny =
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
 * Konstruktor romy�lny
 */
    EObraz();
    /**
     * @brief
     * Zwraca list� atrybut�w z dodatkowymi
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
