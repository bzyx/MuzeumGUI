
#include <QStringList>
#include <QString>
#include "emebel.h"

    std::string EMebel::getRodzaj(){
    }
    void EMebel::rodzaj(std::string){
    }
    EksponatMuzealny::Material EMebel::getMaterial(){
    }
    void EMebel::material(EksponatMuzealny::Material material){
    }
    EMebel::EMebel(std::string rodzaj,EksponatMuzealny::Material material ,
           std::string nazwa, bool wystawiony, std::string opis,
           std::string polozenie, int wartosc,
           Typ typ, FormatDaty formatDaty, std::string data){
    }
    EMebel::EMebel(){
    }
    QStringList EMebel::getAtrybuty(){
    }
    QStringList EMebel::getHeaders(){
    }
    EksponatMuzealny::r2f EMebel::saveElement(){
    }
    EMebel::~EMebel(){
    }
};
