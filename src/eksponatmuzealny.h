#include <string>;

#ifndef EKSPONATMUZEALNY_H
#define EKSPONATMUZEALNY_H



class EksponatMuzealny
{
public:
    typedef enum {NieOkreslono=-1, Obraz=0, PrzedmiotUzytkowy, Rzezba, Mebel, Rekopis, Starodruk } Typ;
    EksponatMuzealny();
    int id();
    int nazwa();

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

int m_lastid = 0;

#endif // EKSPONATMUZEALNY_H
