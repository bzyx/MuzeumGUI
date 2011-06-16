#ifndef MKTYP_H
#define MKTYP_H
#include "src/muzeumkontener.h"
#include <vector>
#include <map>

class MKTyp /*: public MK*/
{
public:
    static MKTyp& getInstance();
    void setTyp(Meta::Typ);
    EksponatMuzealny* operator[] (int id);
     EksponatMuzealny* getObjectFor(Meta::Typ,int id);

    void updateMKTyp();
private:

    Meta::Typ m_typ;
//    m_mebel vector<int>;
//    m_obraz  vector<int>;
//    m_przedmiotUzytkowy vector<int>;
//    m_rekopis vector<int>;
//    m_rzezba  vector<int>;
//    m_starodruk vector<int>;

    //typedef vector< int > vek;
    std::map<Meta::Typ,std::vector<int> > m_Types;

    MKTyp();
    MKTyp(const MKTyp&);
    MKTyp& operator=(const MKTyp&);
};

#endif // MKTYP_H
