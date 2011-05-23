

#include "muzeumkontener.h"

MuzeumKontener::MuzeumKontener()
{
}

MKontener* MuzeumKontener::GetInstance()
{
    return &m_kontener;
}

void MuzeumKontener::addItm(EksponatMuzealnyModel* e)
{
    m_kontener.push_back(e);
}

MKontener MuzeumKontener::m_kontener;
