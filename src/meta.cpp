#include "meta.h"

#include <cstring>
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

Meta::FormatDaty Meta::formatDatyNazwa(std::string formatDaty){
    if(!strcmp(formatDaty.c_str(),"wiek"))
        return Meta::w;
    if(!strcmp(formatDaty.c_str(),"r."))
        return Meta::r;
    if(!strcmp(formatDaty.c_str(),"mr."))
        return Meta::mr ;
    if(!strcmp(formatDaty.c_str(),"dmr."))
        return Meta::dmr;

        return Meta::NzF;
}

std::string Meta::b2s(bool b){
    if(b)
        return "Tak";
    else
        return "Nie";
}
bool Meta::s2b(std::string b){
    if(!strcmp(b.c_str(),"Tak"))
        return true;
    return false;
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
