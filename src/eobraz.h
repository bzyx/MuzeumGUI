#include <src/eksponatmuzealny.h>
#include <string>

#ifndef EOBRAZ_H
#define EOBRAZ_H

class EObraz : public EksponatMuzealny
{
public:
    EObraz(std::string nazwa, std::string opis, int rok);
    int szerokosc();
    int wysokosc();
    void setSzerokoscWysokosc(int, int);
    int id();
protected:
    int m_szerokosc;
    int m_wysokosc;
private:
    EObraz();
};

#endif // EOBRAZ_H
