#include "regizor.h"


regizor::regizor():persoana(),suma_fixa(0){}
regizor::regizor(std::string nume,std::string cnp,std::string nume_film,float procent,unsigned suma_fixa):persoana(nume,cnp,nume_film,procent),suma_fixa(suma_fixa){}
 unsigned regizor::get_suma_fixa()const
{
    return suma_fixa;
}
std::istream &operator>> (std::istream& in,regizor& r)
{
    in>>((persoana&)r);
    if(&in==&std::cin)
        std::cout<<"Introduceti suma fixa: ";
    in>>r.suma_fixa;
    in.get();
    return in;
}
void regizor::afisare()
{
    persoana p=*this;
    p.afisare();
    std::cout<<"Suma fixa: "<<suma_fixa<<"\n";
}
void n_regizori(std::vector<regizor*>& v,int n)
{
    while(n)
     {
         regizor r;
         std::cin>>r;
         v.push_back(new regizor(r));
         n--;
     }
     for(auto&it:v)
        it->afisare();
}
