#include <string>

#ifndef EKSPONATMUZEALNY_H
#define EKSPONATMUZEALNY_H

class QStringList;
class QList;
class QPair;

typedef QList<QPair> r2f; //Record to file

class EksponatMuzealny
{
public:
    typedef enum {NieOkreslonoTypu=-1, Obraz=5, PrzedmiotUzytkowy,
                  Rzezba, Mebel, Rekopis, Starodruk } Typ;
    typedef enum {NieOkreslonoMaterialu=-1, Braz=5, Drewno, Gips,
                  Glina, Granit, Marmur, Metal, Mosiadz,
                  Piaskowiec, Srebro, Zloto } Material;
    typedef enum {w=5,r,mr,dmr} FormatDaty;

private:
    static int m_lastid;
    int m_id;
    std::string m_nazwa;
    bool m_wystawiony;
    std::string m_opis;
    std::string m_polozenie;
    int m_wartosc;
    Typ m_typ;
    FormatDaty m_FormatDaty;
    std::string m_data;
public:
    int getId();
    void id(int id);
    std::string getNazwa();
    void nazwa(std::string nazwa);
    bool getWystawiony();
    void wystawiony(bool wystawiony);
    std::string getOpis();
    void opis(std::string opis);
    std::string getPolozenie();
    void polozenie(std::string polozenie);
    int getWartosc();
    void wartosc(int wartosc);
    Typ getTyp();
    void typ(Typ typ);
    FormatDaty getFormatDaty();
    void formatDaty(FormatDaty formatDaty);
    std::string getData();
    void data(std::string data);

    EksponatMuzealny();
    EksponatMuzealny(std::string nazwa, bool wystawiony, std::string opis,
                     std::string polozenie, int wartosc,
                     Typ typ, FormatDaty formatDaty, std::string data);
    virtual QStringList getAtrybuty() =0;
    virtual QStringList getPodstawoweAtrybuty();
    virtual QStringList getHeaders() = 0;
    virtual QStringList getPodstawoweHeaders();
    virtual r2f* saveElement();

    virtual ~EksponatMuzealny();
};

#endif // EKSPONATMUZEALNY_H
