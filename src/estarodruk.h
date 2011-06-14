#include <src/eksponatmuzealny.h>
#include <string>

#ifndef ESTARODRUK_H
#define ESTARODRUK_H

/**
 * @brief
 * Klasa zarz¹dzaj¹ca obiekatmi typu Starodruk
 */
class EStarodruk : public EksponatMuzealny
{
private:
    std::string m_autor; /**< TODO */
    std::string m_streszczenie; /**< TODO */
    int m_liczbaStron; /**< TODO */
public:
    /**
     * @brief
     * Zwraca autora starodruku
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
     * Zwraca krótkie streszczenie starodruku
     */
    std::string getStreszczenie();
    /**
     * @brief
     * Ustawia krótkie streszczenie starordruku
     * @param streszczenie
     */
    void sterszczenie(std::string streszczenie);
    /**
     * @brief
     * Zwraca liczbê stron starodruku
     */
    int getLiczbaStron();
    /**
     * @brief
     * Ustawia liczbê stron w starodruku
     * @param liczbaStron
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
    EStarodruk(std::string autor, std::string streszczenie, int liczbaStron,
           std::string nazwa, bool wystawiony, std::string opis,
           std::string polozenie, int wartosc,
           Typ typ, FormatDaty formatDaty, std::string data);
/**
 * @brief
 * Konstrutkor domyœlny
 */
    EStarodruk();
    /**
     * @brief
     * Zwraca listê atrybutów
     */
    QStringList getAtrybuty();
    /**
     * @brief
     * Zwraca nag³ówki listy atrybutów
     */
    QStringList getHeaders();
    /**
     * @brief
     * Przygotowanie rekordu do zapisu
     */
    r2f saveElement();
    /**
     * @brief
     * Destrutkor
     */
    ~EStarodruk();
};

#endif // ESTARODRUK_H
