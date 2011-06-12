

#include "estarodruk.h"

std::string EStarodruk::getAutor();
void EStarodruk::autor(std::string autor);
std::string EStarodruk::getStreszczenie();
void EStarodruk::sterszczenie(std::string streszczenie);
int EStarodruk::getLiczbaStron();
void EStarodruk::liczbaStron(int liczbaStron);
EStarodruk::EStarodruk(std::string autor, std::string streszczenie, int liczbaStron,
       std::string nazwa, bool wystawiony, std::string opis,
       std::string polozenie, int wartosc,
       Typ typ, FormatDaty formatDaty, std::string data);
EStarodruk::EStarodruk();
QStringList EStarodruk::getAtrybuty();
QStringList EStarodruk::getHeaders();
EksponatMuzealny::r2f EStarodruk::saveElement();
EStarodruk::~EStarodruk();
