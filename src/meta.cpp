#include "meta.h"

Meta::Meta()
{
}

std::string Meta::nazwaFormatDaty(
    Meta::FormatDaty formatDaty){
    switch(formatDaty)
    {
    case 5:
        return "wiek";
    case 6:
        return "r.";
    case 7:
        return "mr.";
    case 8:
        return "dmr.";
    default:
        return "NieznayFormat";
    }
}


std::string Meta::b2s(bool b){
    if(b)
        return "Tak";
    else
        return "Nie";
}

std::string Meta::nazwaTypu(int typ){
    switch (typ)
    {
    case 5:
        return "Obraz";
    case 6:
        return "Przedmiot Uøytkowy";
    case 7:
        return "Rzeüba";
    case 8:
        return "Mebel";
    case 9:
        return "Rekopis";
    case 10:
        return "Starodruk";
    default:
        return "Nieznay typ";
    }
}
