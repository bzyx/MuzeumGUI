

#include "eksponatmuzealny.h"
#include <iostream>
#include <sstream>

EksponatMuzealny::EksponatMuzealny()
{
    a="test";
    b=5;
    c='m';
}

EksponatMuzealny::EksponatMuzealny(int z)
{
    std::stringstream zz;
    zz <<z;
    a="test" + zz.str();
    b=z;
    c=z;
}
