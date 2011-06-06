

#include "eobraz.h"

EObraz::EObraz(std::string nazwa, std::string opis, int rok)
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

void EObraz::setSzerokoscWysokosc(int s, int w)
{
    m_szerokosc = s;
    m_wysokosc = w;
}
