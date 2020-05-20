#include "FirmaDistributie.h"


FirmaDistributie<actor>::FirmaDistributie():nr_actori_princip(0),v_act() {}

FirmaDistributie<actor>::FirmaDistributie(std::vector<actor> v):v_act(v),nr_actori_princip(0)
{
    calcul_nr_actori_princip();
}

FirmaDistributie<actor>::FirmaDistributie(const FirmaDistributie&f)
{
    nr_actori_princip=f.nr_actori_princip;
    for(auto&it:f.v_act)
        v_act.push_back(it);
}

unsigned FirmaDistributie<actor>::get_nr_actori_princip()const
{
    return nr_actori_princip;
}

std::vector<actor> FirmaDistributie<actor>::get_v_act()const
{
    return v_act;
}

void FirmaDistributie<actor>::calcul_nr_actori_princip()
{
    for(auto it:v_act)
        if(it.get_actor_principal())
    {

        bool ok=1;
        for(auto j:v_act_princ)
            if(j.get_cnp()==it.get_cnp())
            {
                ok=0;
                break;
            }
        if(ok==1)
        {
            v_act_princ.push_back(it);
            nr_actori_princip++;
        }
    }
}
template<>
std::istream &operator>> (std::istream& in,FirmaDistributie<actor>& f)
{
    if(&in==&std::cin)
        std::cout<<"Introduceti numarul de actori: ";
    int n;
    in>>n;
    in.get();
    while(n--)
    {
        actor a;
        in>>a;
        f.v_act.push_back(a);
    }
    f.calcul_nr_actori_princip();
    return in;
}

void FirmaDistributie<actor>::afisare()
{
    std::cout<<"Numarul de actori repartizati in roluri princiipale: "<<nr_actori_princip<<"\n";
    for(auto it:v_act)
        it.afisare();
}
