

#include "eobraz.h"

EObraz::EObraz(std::string nazwa, std::string opis, int rok):
    EksponatMuzealny(EksponatMuzealny::Obraz, nazwa, opis, rok)
{
}

int EObraz::szerokosc()
{
    return m_szerokosc;
}

int EObraz::wysokosc()
{
    return m_wysokosc;
}

int EObraz::id()
{
    return m_id;
}

void EObraz::setSzerokoscWysokosc(int s, int w)
{
    m_szerokosc = s;
    m_wysokosc = w;
}
