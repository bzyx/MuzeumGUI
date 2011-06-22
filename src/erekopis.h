#include <src/eksponatmuzealny.h>
#include <string>

#ifndef EREKOPIS_H
#define EREKOPIS_H

/**
 * @brief
 * Klasa zarz�dzaj�ca obiektami typu Rekopis
 */
class ERekopis : public EksponatMuzealny
{
private:
    std::string m_autor; /**< TODO */
    bool m_czyZeskanowany; /**< TODO */
public:
    /**
     * @brief
     * Zweaca autora rekopisu
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
     * Zwraca czy rekopis by� ju� zeskanowany
     */
    bool getCzyZeskanowany();
    /**
     * @brief
     * Ustawia czy rekopis by� zeskanowany
     * @param czyZeskanowany
     */
    void czyZeskanowany(bool czyZeskanowany);

/**
 * @brief
 * autor, czyZeskanowany + EksponatMuzealny
 * @param autor
 * @param czyZeskanowany
 * @param nazwa
 * @param wystawiony
 * @param opis
 * @param polozenie
 * @param wartosc
 * @param typ
 * @param formatDaty
 * @param data
 */
    ERekopis(std::string autor, bool czyZeskanowany,
             std::string nazwa, bool wystawiony, std::string opis,
             std::string polozenie, int wartosc,
             Meta::Typ typ, Meta::FormatDaty formatDaty, std::string data);
/**
 * @brief
 * Konstruktor domy�lny
 */
    ERekopis();
    /**
     * @brief
     * Zwraca list� atrybut�w
     */
    QStringList getAtrybuty();
    /**
     * @brief
     * Zwraca nag��wek
     */
    QStringList getHeaders();
    /**
     * @brief
     * Element do pliku
     */
    r2f saveElement();
    /**
     * @brief
     * Destrukor
     */
    ~ERekopis();
};

#endif // EREKOPIS_H
