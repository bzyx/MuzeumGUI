#include <src/eksponatmuzealny.h>

#ifndef ESTARODRUK_H
#define ESTARODRUK_H

/**
 * @brief
 *
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
     *
     */
    std::string getAutor();
    /**
     * @brief
     *
     * @param autor
     */
    void autor(std::string autor);
    /**
     * @brief
     *
     */
    std::string getStreszczenie();
    /**
     * @brief
     *
     * @param streszczenie
     */
    void sterszczenie(std::string streszczenie);
    /**
     * @brief
     *
     */
    int getLiczbaStron();
    /**
     * @brief
     *
     * @param liczbaStron
     */
    void liczbaStron(int liczbaStron);
/**
 * @brief
 *
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
 *
 */
    EStarodruk();
    /**
     * @brief
     *
     */
    QStringList getAtrybuty();
    /**
     * @brief
     *
     */
    QStringList getHeaders();
    /**
     * @brief
     *
     */
    r2f saveElement();
    /**
     * @brief
     *
     */
    ~EStarodruk();
};

#endif // ESTARODRUK_H
