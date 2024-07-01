#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//liste simplement chainee

struct Ville
{ //structure pour le noeud de la liste; contient l'info de la liste et 2 pointeurs
    string nom;
    Ville  *next; //pointeur au noeud suivant

};


class LinkedList
{
    public:
        Ville  *pfirst; //pointeur au premier noeud
        Ville  *plast; //pointeur au dernier noeud


 void add(string x)
    {
        //ajoute info x sur la derniere position

        Ville *paux = new Ville ;

        paux->nom = x;
        paux->next = NULL;

        if (plast != NULL)
            plast->next = paux;

        plast = paux;

        if (pfirst == NULL)
            pfirst = plast;
    }


    Ville * findFirstOccurrence(string x)
    {
        //cherche le premier noeud qui contient info x
        Ville  *paux;

        paux = pfirst;

        while (paux != NULL)
        {
            if (paux->nom == x)
                return paux;
            paux = paux->next;
        }
        return NULL;
    }

    LinkedList()
    { //constructeur
        pfirst = plast = NULL;
    }
};
