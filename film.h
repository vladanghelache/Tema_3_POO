#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED
#include <bits/stdc++.h>
#include "persoana.h"
#include "actor.h"
#include "regizor.h"

class film{
    std::string nume;
    std::string tip;
    int durata;
    std::vector<persoana*> persoane;
    unsigned incasari;
public:
    film();
    film(std::string,std::string,int,std::vector<persoana*>,unsigned);
    film(const film&);
    ~film();
    film operator=(const film&);
    std::string get_nume()const;
    std::string get_tip()const;
    int get_durata()const;
    std::vector<persoana*> get_persoane()const;
    unsigned get_incasari()const;
    friend std::istream &operator>> (std::istream&,film&);
    void afisare();
    friend void n_filme(std::vector<film*>&,int);

};


#endif // FILM_H_INCLUDED
