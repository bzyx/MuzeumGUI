#include <string>

#ifndef EKSPONATMUZEALNY_H
#define EKSPONATMUZEALNY_H



class EksponatMuzealny
{
public:
    typedef enum {NieOkreslono=-1, Obraz=5, PrzedmiotUzytkowy, Rzezba, Mebel, Rekopis, Starodruk } Typ;
    EksponatMuzealny();
    EksponatMuzealny(Typ typ, std::string nazwa, std::string opis, int rok);
    virtual int id();
    Typ typ();
    std::string nazwa();

protected:
    static int m_lastid;
    int m_id;
    Typ m_typ;
    std::string m_nazwa;
    //enum stan {EksonatMuzealny::Wystawiony, EksopantMuzealny::WMagazynie}
    std::string m_opis;
    int m_rok;

private:


};

#endif // EKSPONATMUZEALNY_H
