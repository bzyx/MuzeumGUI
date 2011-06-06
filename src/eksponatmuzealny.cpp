

#include "eksponatmuzealny.h"

int EksponatMuzealny::m_lastid = 0;

EksponatMuzealny::EksponatMuzealny()
{
    //m_id = EksponatMuzealny::m_lastid;
    // m_lastid++;
    m_typ = EksponatMuzealny::NieOkreslonoTypu;
    m_nazwa = "";
    m_opis = "";
}

EksponatMuzealny::EksponatMuzealny(Typ typ, std::string nazwa, std::string opis, int rok)
{
    m_id = EksponatMuzealny::m_lastid++;
    m_typ = typ;
    m_nazwa = std::string(nazwa);
    m_opis = std::string(opis);
    m_rok = rok;
}

int EksponatMuzealny::id()
{
    return m_id;
}

std::string EksponatMuzealny::nazwa()
{
    return m_nazwa;
}

EksponatMuzealny::Typ EksponatMuzealny::typ()
{
    return m_typ;
}
