#ifndef META_H
#define META_H
#include <string>
class Meta
{
public:
    typedef enum {NieOkreslonoTypu=-1, Obraz=5, PrzedmiotUzytkowy,
                  Rzezba, Mebel, Rekopis, Starodruk } Typ;

    typedef enum {w=5,r,mr,dmr} FormatDaty;
    static std::string nazwaFormatDaty(Meta::FormatDaty formatDaty);
    static std::string b2s(bool b);
    static std::string nazwaTypu(int typ);
private:
    Meta();
};

#endif // META_H
