#ifndef META_H
#define META_H

class Meta
{
public:
    typedef enum {NieOkreslonoTypu=-1, Obraz=5, PrzedmiotUzytkowy,
                  Rzezba, Mebel, Rekopis, Starodruk } Typ;
    Meta();
};

#endif // META_H
