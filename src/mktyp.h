#ifndef MKTYP_H
#define MKTYP_H
#include "src/muzeumkontener.h"
#include <vector>
#include <map>

/*!
 \brief

 \class MKTyp mktyp.h "src/mktyp.h"
*/
class MKTyp /*: public MK*/
{
public:
    /*!
     \brief

     \fn getInstance
    */
    static MKTyp& getInstance();
    /*!
     \brief

     \fn setTyp
     \param Meta::Typ
    */
    void setTyp(Meta::Typ);
    /*!
     \brief

     \fn operator []
     \param id
    */
    EksponatMuzealny* operator[] (int id);
    /*!
     \brief

     \fn getObjectFor
     \param Meta::Typ
     \param id
    */
    EksponatMuzealny* getObjectFor(Meta::Typ,int id);
    /*!
     \brief

     \fn count
     \param typ
    */
    int count(Meta::Typ typ);

    /*!
     \brief

     \fn updateMKTyp
    */
    void updateMKTyp();
private:

    Meta::Typ m_typ; /*!< TODO */
//    m_mebel vector<int>;
//    m_obraz  vector<int>;
//    m_przedmiotUzytkowy vector<int>;
//    m_rekopis vector<int>;
//    m_rzezba  vector<int>;
//    m_starodruk vector<int>;

    //typedef vector< int > vek;
    std::map<Meta::Typ,std::vector<int> > m_Types; /*!< TODO */

/*!
 \brief

 \fn MKTyp
*/
    MKTyp();
/*!
 \brief

 \fn MKTyp
 \param
*/
    MKTyp(const MKTyp&);
    /*!
     \brief

     \fn operator =
     \param
    */
    MKTyp& operator=(const MKTyp&);
};

#endif // MKTYP_H
