#include "persoana.h"

persoana::persoana():cnp(""),nume(""),nume_film(""),procent(0) {}
persoana::persoana(std::string cnp,std::string nume,std::string nume_film, float procent):cnp(cnp),nume(nume),nume_film(nume_film),procent(procent) {}
persoana::~persoana()
{
    nume.clear();
    nume_film.clear();
    cnp.clear();
}
std::string persoana::get_nume()const
{
    return nume;
}
inline std::string persoana::get_nume_film()const
{
    return nume_film;
}
inline float persoana::get_procent()const
{
    return procent;
}
 std::string persoana::get_cnp()const
{
    return cnp;
}
std::istream &operator>> (std::istream& in,persoana& p)
{
    if(&in==&std::cin)
        std::cout<<"Introduceti numele: ";
    getline(in,p.nume);
    bool ok=true;
    while(ok==true)
    {
        try
        {
            ok=false;
            if(&in==&std::cin)
                std::cout<<"Introduceti CNP-ul: ";
            getline(in,p.cnp);

            if(p.cnp.size()!=13)
                throw p.cnp.size();
        }
        catch (unsigned int a)
        {
            ok=true;
            std::cout<<"CNP-ul introdus este gresit\n";
        }
    }
    if(&in==&std::cin)
        std::cout<<"Introduceti numele filmului: ";
    getline(in,p.nume_film);
    if(&in==&std::cin)
        std::cout<<"Introduceti procentul: ";
    in>>p.procent;
    in.get();

    return in;
}
void persoana::afisare()
{
    std::cout<<"Nume: "<<nume<<"\nCNP: "<<cnp<<"\nNume film: "<<nume_film<<"\nProcent: "<<procent<<"%\n";
}
void n_persoane(std::vector<persoana*> &v, int n)
{
    while(n)
    {
        persoana p;
        std::cin>>p;
        v.push_back(new persoana (p));
        n--;
    }
    for(auto&it:v)
        it->afisare();

}
