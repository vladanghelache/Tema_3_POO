#ifndef FIRMADISTRIBUTIE_H_INCLUDED
#define FIRMADISTRIBUTIE_H_INCLUDED
#include<bits/stdc++.h>
#include "persoana.h"
#include "actor.h"
#include "regizor.h"
#include "film.h"

struct cmp{
    bool operator()(const auto&a,const auto&b)
    {
        return 1;
    }


};

template<class A>
class FirmaDistributie;

template <class A>
std::istream &operator>> (std::istream&,FirmaDistributie<A>&);

template<class A>
class FirmaDistributie
{
    unsigned nr_persoane;
    unsigned nr_actori;
    static unsigned nr_total_persoane;
    static unsigned nr_total_actori;
    std::vector<A> vect;

    static std::set<std::tuple<persoana,film,unsigned>,cmp> multime;
    std::vector<actor> vactori;
    static std::vector<actor> vallactori;
    std::vector<persoana> vpersoane;

public:

    FirmaDistributie();
    FirmaDistributie(std::vector<A>);
    FirmaDistributie(const FirmaDistributie&);

    void calcul_nr_persoane();
    void calcul_nr_actori();

    unsigned get_nr_persoane()const;
    unsigned get_nr_actori()const;
    std::vector<A> get_vect()const;


    static unsigned get_nr_total_persoane();
    static unsigned get_nr_total_actori();

    friend std::istream &operator>> <>(std::istream&,FirmaDistributie&);
    void afisare();
    static void afisare_multime();


};
template<>
class FirmaDistributie<actor>;

template <>
std::istream &operator>><actor> (std::istream& in,FirmaDistributie<actor>& f);

template<>
class FirmaDistributie<actor>
{
    unsigned nr_actori_princip;
    std::vector<actor> v_act;
    std::vector<actor> v_act_princ;
public:
    FirmaDistributie();
    FirmaDistributie(std::vector<actor>);
    FirmaDistributie(const FirmaDistributie&);
    unsigned get_nr_actori_princip()const;
    std::vector<actor> get_v_act()const;
    void calcul_nr_actori_princip();
    friend std::istream &operator>> <>(std::istream&,FirmaDistributie<actor>&);
    void afisare();
};

template<class A>
unsigned FirmaDistributie<A>::nr_total_persoane=0;
template<class A>
unsigned FirmaDistributie<A>::nr_total_actori=0;
template<class A>
std::vector<actor> FirmaDistributie<A>::vallactori={};
template<class A>
std::set<std::tuple<persoana,film,unsigned>,cmp> FirmaDistributie<A>::multime={};



template<class A>
FirmaDistributie<A>::FirmaDistributie():nr_persoane(0),nr_actori(0),vect() {}
template<class A>
FirmaDistributie<A>::FirmaDistributie(std::vector<A> vect):nr_persoane(0),nr_actori(0),vect(vect)
{
    calcul_nr_actori();
    calcul_nr_persoane();
}
template<class A>
FirmaDistributie<A>::FirmaDistributie(const FirmaDistributie<A>& f)
{
    nr_persoane=f.nr_persoane;
    nr_actori=f.nr_actori;
    for(auto&it:f.vect)
        vect.push_back(it);
}


template<class A>
void FirmaDistributie<A>::calcul_nr_actori()
{
    for(auto it:vect)
    {

        for(auto&pers:it.get_persoane())
        {

            if(actor* a=dynamic_cast<actor*>(pers))
            {
                bool ok=1;
                for(auto j:vactori)
                    if(j.get_cnp()==a->get_cnp())
                    {
                        ok=0;
                        break;
                    }
                if(ok==1)
                {

                    vactori.push_back(*a);
                    nr_actori++;
                }
                ok=1;
                for(auto j:vallactori)
                    if(j.get_cnp()==a->get_cnp())
                    {
                        ok=0;
                        break;
                    }
                if(ok==1)
                {
                    vallactori.push_back(*a);
                    nr_total_actori++;
                }
            }
        }
    }
}
template<class A>
void FirmaDistributie<A>::afisare_multime()
{
    for(auto it:multime)
    {
        std::cout<<std::get<0>(it).get_nume()<<" "<<std::get<1>(it).get_nume()<<" "<<std::get<2>(it)<<"\n";
    }
}
template<class A>
void FirmaDistributie<A>::calcul_nr_persoane()
{
    for(auto it:vect)
    {
        for(auto pers:it.get_persoane())
        {


            bool ok=1;
            for(auto j:vpersoane)
                if(j.get_cnp()==pers->get_cnp())
                {
                    ok=0;
                    break;
                }
            if(ok==1)
            {
                vpersoane.push_back(*pers);
                nr_persoane++;
            }

            ok=1;
            for(auto j:multime)
                if(std::get<0>(j).get_cnp()==pers->get_cnp())
                {
                    ok=0;
                    break;
                }
            if(ok==1)
            {

                nr_total_persoane++;
            }
            unsigned bonus=0;
            if(actor* a=dynamic_cast<actor*>(pers))
                bonus= it.get_incasari()* a->get_procent_bonus()/100;
            else if(regizor* r=dynamic_cast<regizor*>(pers))
                bonus=r->get_suma_fixa();
            std::tuple<persoana,film,unsigned> t=std::make_tuple(*pers,it,bonus);

            multime.insert(t);

        }
    }
}


template<class A>
unsigned FirmaDistributie<A>::get_nr_persoane()const
{
    return nr_persoane;
}
template<class A>
unsigned FirmaDistributie<A>::get_nr_actori()const
{
    return nr_actori;
}
template<class A>
std::vector<A> FirmaDistributie<A>::get_vect()const
{
    return vect;
}

template<class A>
unsigned FirmaDistributie<A>::get_nr_total_persoane()
{
    return nr_total_persoane;
}
template<class A>
unsigned FirmaDistributie<A>::get_nr_total_actori()
{
    return nr_total_actori;
}



template<class A>
std::istream &operator>> (std::istream& in,FirmaDistributie<A>& f)
{
    if(&in==&std::cin)
        std::cout<<"Introduceti numarul de obiecte: ";
    int n;
    in>>n;
    in.get();
    while(n--)
    {
        A a;
        in>>a;
        f.vect.push_back(a);
    }
    f.calcul_nr_actori();
    f.calcul_nr_persoane();
    return in;
}
template<class A>
void FirmaDistributie<A>::afisare()
{
    std::cout<<"Numarul de persoane implicate: "<<nr_persoane<<"\nNumarul de actori implicati: "<<nr_actori<<"\n"<<"Numarul total de persoane implicate: "<<nr_total_persoane<<"\nNumarul total de actori implicati: "<<nr_total_actori<<"\n";
    for(auto&it:vect)
    {
        std::cout<<"\n";
        it.afisare();
    }
}

#endif // FIRMADISTRIBUTIE_H_INCLUDED
