#ifndef META_H
#define META_H
#include <string>
/*!
 \brief

 \class Meta meta.h "src/meta.h"
*/
class Meta
{
public:
    /*!
     \brief

     \enum
    */
    typedef enum {NieOkreslonoTypu=-1, Obraz=5, PrzedmiotUzytkowy,
                  Rzezba, Mebel, Rekopis, Starodruk } Typ; /*!< TODO */

    /*!
     \brief

     \enum
    */
    typedef enum {NzF=-1,w=5,r,mr,dmr} FormatDaty;
    /*!
     \brief

     \fn nazwaFormatDaty
     \param formatDaty
    */
    static std::string nazwaFormatDaty(Meta::FormatDaty formatDaty);
    /*!
     \brief

     \fn formatDatyNazwa
     \param formatDaty
    */
    static Meta::FormatDaty formatDatyNazwa(std::string formatDaty);
    /*!
     \brief

     \fn b2s
     \param b
    */
    static std::string b2s(bool b);
    /*!
     \brief

     \fn s2b
     \param b
    */
    static bool s2b(std::string b);
    /*!
     \brief

     \fn nazwaTypu
     \param typ
    */
    static std::string nazwaTypu(int typ);
private:
/*!
 \brief

 \fn Meta
*/
    Meta();
};

#endif // META_H
