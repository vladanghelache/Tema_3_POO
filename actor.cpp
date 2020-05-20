#include "actor.h"

actor::actor():persoana(),actor_principal(false) {}
actor::actor(std::string nume,std::string cnp,std::string nume_film,float procent,bool actor_principal):persoana(nume,cnp,nume_film,procent),actor_principal(actor_principal) {}
unsigned actor::get_procent_bonus()const
{
    if(actor_principal==true)
        return 10;
    else return 0;
}
bool actor::get_actor_principal()const
{
    return actor_principal;
}
std::istream &operator>> (std::istream& in, actor&a)
{
    in>>((persoana&)a);
    char r;
    bool ok=true;
    while (ok==true)
    {
        try
        {
            ok=false;
            if(&in==&std::cin)
                std::cout<<"Actorul este personaj principal (y=yes / n=no): ";


            in>>r;
            if(r!='y' && r!='n')
                throw r;

        }
        catch (char r)
        {
            std::cout<<"Raspunsul '"<<r<<"' este necorespunzator\n";
            ok=true;
        }
    }
    if(r=='y')
        a.actor_principal=true;
    else
        a.actor_principal=false;
    in.get();
    return in;
}
void actor::afisare()
{
    persoana p=*this;
    p.afisare();
    if(actor_principal==true)
        std::cout<<"Actorul joaca un rol principal\n";

}
void n_actori(std::vector<actor*>& v,int n)
{
    while(n)
     {
         actor a;
         std::cin>>a;
         v.push_back(new actor(a));
         n--;
     }
     for(auto&it:v)
        it->afisare();
}
