

#ifndef MUZEUMKONTENER_H
#define MUZEUMKONTENER_H

#include <deque>

#include <src/eksponatmuzealny.h>

typedef std::deque<EksponatMuzealny *> MKontener;
//TODO: Przerobiæ t¹ klasê na SINGLETON

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
