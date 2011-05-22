

#ifndef MUZEUMKONTENER_H
#define MUZEUMKONTENER_H

#include <deque>

#include <src/eksponatmuzealny.h>

typedef std::deque<EksponatMuzealny *> MKontener;
//TODO: Przerobi� t� klas� na SINGLETON

class MuzeumKontener : public EksponatMuzealny
{
public:
    MuzeumKontener();
    MKontener* GetInstance();
    void addItm(EksponatMuzealny *e);
private:
   static MKontener m_kontener;
};

#endif // MUZEUMKONTENER_H
