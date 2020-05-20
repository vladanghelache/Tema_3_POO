#ifndef PERSOANA_H_INCLUDED
#define PERSOANA_H_INCLUDED
#include<bits/stdc++.h>

class persoana
{
protected:
    std::string cnp;
    std::string nume;
    std::string nume_film;
    float procent;
public:
    persoana();
    persoana(std::string,std::string,std::string,float);
    virtual ~persoana();
    inline float get_procent()const;
     std::string get_nume()const;
    inline std::string get_nume_film()const;
    std::string get_cnp()const;
    friend std::istream &operator>> (std::istream&,persoana&);
    virtual void afisare();
    friend void n_persoane(std::vector<persoana*>&,int);
};

#endif // PERSOANA_H_INCLUDED
