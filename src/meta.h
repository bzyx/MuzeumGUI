#ifndef META_H
#define META_H

class Meta
{
public:
    typedef enum {NieOkreslonoTypu=-1, Obraz=5, PrzedmiotUzytkowy,
                  Rzezba, Mebel, Rekopis, Starodruk } Typ;

    typedef enum {w=5,r,mr,dmr} FormatDaty;
    Meta();
};

#endif // META_H
