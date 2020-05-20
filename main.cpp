#include<bits/stdc++.h>
#include "persoana.h"
#include "actor.h"
#include "regizor.h"
#include "film.h"
#include "FirmaDistributie.h"

using namespace std;

int main()
{

    FirmaDistributie<film> f;
    cin>>f;
    f.afisare();
    FirmaDistributie<film>::afisare_multime();

    FirmaDistributie<actor> a;
    cin>>a;
    a.afisare();
    FirmaDistributie<film>::afisare_multime();
    return 0;
}
