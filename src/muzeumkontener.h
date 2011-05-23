

#ifndef MUZEUMKONTENER_H
#define MUZEUMKONTENER_H

#include <deque>

#include <src/eksponatmuzealnymodel.h>

typedef std::deque<EksponatMuzealnyModel *> MKontener;
//TODO: Przerobiæ t¹ klasê na SINGLETON

class MuzeumKontener : public EksponatMuzealnyModel
{
public:
    MuzeumKontener();
    MKontener* GetInstance();
    void addItm(EksponatMuzealnyModel *e);
private:
   static MKontener m_kontener;
};

#endif // MUZEUMKONTENER_H
