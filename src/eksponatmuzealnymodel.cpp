

#include "eksponatmuzealnymodel.h"
#include <iostream>
#include <sstream>

EksponatMuzealnyModel::EksponatMuzealnyModel()
{
    a="test";
    b=5;
    c='m';
}

EksponatMuzealnyModel::EksponatMuzealnyModel(int z)
{
    std::stringstream zz;
    zz <<z;
    a="test" + zz.str();
    b=z;
    c=z;
}
