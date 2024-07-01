dans le header "liste.h" j'ai declare une structure pour la ville qui a donc le nom de la ville et le pointeur de la prochaine ville
puis la classe LinkedList (liste chainee) 
la fonction "add" pour ajouter des villes et la fonction "findFirstOccurrence" pour trouver le nom de la ville qu'on recherche

dans le code principale on declare 2 listes (1 pour chaque route) puis la fonction findRoadIntersection qui a pour but de trouver la ville ou s'intersectent les 2 routes, donc simplement on utilise findFirstOccurence pour regarder si la ville courante de la 1er liste correspond a celle de la 2eme sinon on passe a la ville suivante, si la fin on ne trouve aucune ville en commun findRoadIntersection retourne le string "Impossible"

dans main on lit a partir du fichier "Villes.in" les villes jusqu'a qu'on arrive a la ville "Rome" puis on utilise la fonction findRoadIntersection, si la ville que retourne la fonction ne s'appelle pas "Impossible" elle affichera donc le nom de la ville ou s'intersectent les 2 routes sinon elle affiche un message d'erreur


Pour utiliser le code il suffit d'ecrire les villes une par une pour chacune des routes dans le fichier "Villes.in" puis d'executer le code 