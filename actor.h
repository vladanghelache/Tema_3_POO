#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED
#include "persoana.h"

class actor: public persoana{
    bool actor_principal;
public:
    actor();
    actor(std::string,std::string,std::string,float,bool);
    unsigned get_procent_bonus()const;
     bool get_actor_principal()const;
    friend std::istream &operator>> (std::istream&,actor&);
    void afisare();
    friend void n_actori(std::vector<actor*>&,int);
};

#endif // ACTOR_H_INCLUDED
