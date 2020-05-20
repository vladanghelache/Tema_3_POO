#include "film.h"

film::film():nume(""),tip(""),durata(0),persoane(),incasari(0) {}
film::film(std::string nume,std::string tip,int durata,std::vector<persoana*> persoane,unsigned incasari):nume(nume),
    tip(tip),
    durata(durata),
    persoane(persoane),
    incasari(incasari) {}
film::film(const film& f)
{
    nume=f.nume;
    tip=f.tip;
    durata=f.durata;
    for(auto&it:f.persoane)
    {
        if(actor* a=dynamic_cast<actor*>(it))
        {

            persoane.push_back(new actor(*a));
        }
        else if(regizor* r=dynamic_cast<regizor*>(it))
        {
            persoane.push_back(new regizor(*r));
        }
        else
        {
            persoane.push_back(new persoana(*it));
        }
    }
    incasari=f.incasari;
}
film::~film()
{
    for(auto&it:persoane)
        delete it;
    persoane.clear();
}
film film::operator=(const film& f)
{
    if(this==&f)
        return *this;
    nume=f.nume;
    tip=f.tip;
    durata=f.durata;
    for(auto&it:persoane)
        delete it;
    persoane.clear();
    for(auto&it:f.persoane)
        if(actor* a=dynamic_cast<actor*>(it))
        {

            persoane.push_back(new actor(*a));
        }
        else if(regizor* r=dynamic_cast<regizor*>(it))
        {
            persoane.push_back(new regizor(*r));
        }
        else
        {
            persoane.push_back(new persoana(*it));
        }
    incasari=f.incasari;
    return *this;
}
std::string film::get_nume()const
{
    return nume;
}
std::string film::get_tip()const
{
    return tip;
}
int film::get_durata()const
{
    return durata;
}
std::vector<persoana*> film::get_persoane()const
{
    return persoane;
}
unsigned film::get_incasari()const
{
    return incasari;
}
std::istream &operator>> (std::istream& in,film& f)
{
    if(&in==&std::cin)
        std::cout<<"Introduceti numele filmului: ";
    getline(in,f.nume);
    if(&in==&std::cin)
        std::cout<<"Introduceti tipul filmului: ";
    getline(in,f.tip);
    if(&in==&std::cin)
        std::cout<<"Introduceti durata filmului: ";
    in>>f.durata;
    if(&in==&std::cin)
        std::cout<<"Introduceti incasarile filmului: ";
    in>>f.incasari;
    if(&in==&std::cin)
        std::cout<<"Introduceti numarul de persoane: ";
    int n;
    in>>n;
    in.get();
    while(n)
    {
        n--;
        if(&in==&std::cin)
            std::cout<<"Introduceti jobul (regizor, actor sau altceva): ";
        std::string job;
        in>>job;
        in.get();
        if(job=="actor")
        {
            actor a;
            in>>a;
            f.persoane.push_back(new actor(a));
        }
        else if(job=="regizor")
        {
            regizor r;
            in>>r;
            f.persoane.push_back(new regizor(r));
        }
        else
        {
            persoana p;
            in>>p;
            f.persoane.push_back(new persoana(p));
        }
    }
    return in;
}
void film::afisare()
{
    std::cout<<"Numele filmului: "<<nume<<"\nTipul filmului: "<<tip<<"\nDurata filmului: "<<durata<<"\nIncasarile filmului: "<<incasari<<"\n";
    std::cout<<"Persoanele participante:\n";
    for(auto&it:persoane)
    {
        if(actor* a=dynamic_cast<actor*>(it))
        {
            std::cout<<"Actor:\n";
            a->afisare();
        }
        else if(regizor* r=dynamic_cast<regizor*>(it))
        {
            std::cout<<"Regizor:\n";
            r->afisare();
        }
        else
        {
            std::cout<<"Staff:\n";
            it->afisare();
        }
    }
}
void n_filme(std::vector<film*>& v,int n)
{
    while(n)
    {
        film f;
        std::cin>>f;
        v.push_back(new film(f));
        n--;
    }
    for(auto&it:v)
        it->afisare();
}
