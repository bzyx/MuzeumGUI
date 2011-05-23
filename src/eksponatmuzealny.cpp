

#include "eksponatmuzealny.h"

EksponatMuzealny::EksponatMuzealny()
{
    m_id = EksponatMuzealny::m_lastid++;
    m_typ = EksponatMuzealny::NieOkreslono;
    m_nazwa = "";
    m_opis = "";
    m_rok = 0;
}

int id()
{
    return m_id;
}

int nazwa()
{
    return m_nazwa;
}

EksponatMuzealny::Typ typ()
{
    return m_typ;
}
