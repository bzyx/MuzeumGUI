/****************************************************************************
**
** Copyright (C) 2011 Marcin Jabrzyk <marcin.jabrzyk@gmail.com>
** All rights reserved.
**
** This file is part of MuzeumGUI <marcin.jabrzyk@gmail.com>
**
** Ten utwór jest dostêpny na licencji
** Creative Commons
** Uznanie autorstwa-U¿ycie niekomercyjne-Na tych samych warunkach
** 3.0 Unported.
**
** http://creativecommons.org/licenses/by-nc-sa/3.0/
**
****************************************************************************/

#include "meta.h"
#include <cstring>

Meta::Meta()
{
}

/*
  Bardzo proste statyczne funkcje obs³uguj¹ce konwersjê z i do odpowienich
  enum'ów zdefiniowanych w klasie Meta

*/
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
        return "Przedmiot U¿ytkowy";
    case 7:
        return "RzeŸba";
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
