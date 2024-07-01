#include <iostream>
#include "listes.h"
#include <string>
#include <fstream>
using namespace std;

LinkedList route1;
LinkedList route2;

string findRoadIntersection(Ville* r1 , Ville* r2)
{
     Ville *villeCourante =r1;
 while(villeCourante != NULL)
   {
    if(NULL!=route2.findFirstOccurrence(villeCourante->nom))
       {
           return villeCourante->nom;
       }
       else
        villeCourante=villeCourante->next;

   }
   return "Impossible";
}

int main()
{
    ifstream f ("Villes.in");

    string ville;
    while(f>>ville)
    {
     route1.add(ville);
        if(ville=="Rome")
            break;
    }

    while(f>>ville)
    {
     route2.add(ville);
        if(ville=="Rome")
            break;
    }

    f.close();
    ville = findRoadIntersection(route1.pfirst , route2.pfirst);
    if(ville!="Impossible")
        cout<<"le nom de la ville ou les 2 routes s'intersectent est : "<<ville;
    else
        cout<<"pas toutes les routes menent a Rome ";
}
