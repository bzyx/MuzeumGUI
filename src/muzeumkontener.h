

#ifndef MUZEUMKONTENER_H
#define MUZEUMKONTENER_H

#include <deque>

#include <src/eksponatmuzealnymodel.h>

typedef std::deque<EksponatMuzealnyModel *> MKontener;


class MuzeumKontener : public EksponatMuzealnyModel
{
public:
    MKontener* GetInstance();
    void addItm(EksponatMuzealnyModel *e);
    void deleteAll();
private:
   /* Konstruktor jest prywatny, klasa jest widoczna jako
     singleton */
   MuzeumKontener();
   static MKontener m_kontener;

};

#endif // MUZEUMKONTENER_H
