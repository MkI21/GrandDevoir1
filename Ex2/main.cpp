#include <iostream>
#include <queue>

using namespace std;

struct Commande {
    int t, d;
};

int main() {
    int N, T;
    cout << "nombre de commandes  :";
    cin >> N;
    cout<< "temps d'ouverture du restaurant : ";
    cin >> T;

    vector<Commande> commandes(N);


    for (int i = 0; i < N; i++) {
        cout << "Commande " << i+1 << " : ";
        cout<< "temps : "; cin >> commandes[i].t;
        cout<<"durees : "; cin >> commandes[i].d;
    }

    int tempsReel = 0;
    queue<Commande> queueCommandes;
    int dureeMax = 0;

    for (int i = 0; i < N; i++) {
        queueCommandes.push(commandes[i]);

        if (commandes[i].d > dureeMax) {
            dureeMax = commandes[i].d;
        }

        while (!queueCommandes.empty()) {
            Commande commandeEnCours = queueCommandes.front();
            int tempsTheorique = commandeEnCours.t + commandeEnCours.d;
            int tempsReelCompletion = max(commandeEnCours.t, tempsReel) + commandeEnCours.d;

            cout << "Commande " << i+1 << " temps d'attente theorique: " << tempsTheorique << " , temps reel: " << tempsReelCompletion << endl;

            tempsReel = max(tempsReel, commandeEnCours.t) + commandeEnCours.d;
            queueCommandes.pop();
        }

        if (i < N-1 && queueCommandes.empty() && tempsReel<commandes[i+1].t ) {
            cout << "Le restaurant est vide entre les temps " << tempsReel << " et " << commandes[i+1].t << endl;
        }
    }

    cout << "duree maximale des commandes : " << dureeMax << endl;



    if (tempsReel > T) {
        cout << "Le restaurant a ferme avant la completion de toutes les commandes" << endl;
    } else if (!queueCommandes.empty()) {
        cout << "Certaines commandes n'ont pas ete completees avant la fermeture" << endl;
    } else {
        cout <<"Toutes les commandes ont ete completees avant la fermeture du restaurant" << endl;
    }

    return 0;
}
