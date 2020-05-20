#ifndef REGIZOR_H_INCLUDED
#define REGIZOR_H_INCLUDED
#include "persoana.h"

class regizor:public persoana{
    unsigned suma_fixa;
public:
    regizor();
    regizor(std::string,std::string,std::string,float,unsigned);
    unsigned get_suma_fixa()const;
    friend std::istream &operator>> (std::istream&,regizor&);
    void afisare();
    friend void n_regizori(std::vector<regizor*>&,int);
};

#endif // REGIZOR_H_INCLUDED
