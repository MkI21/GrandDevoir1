#include <iostream>
#include <stack>
#include <fstream>

using namespace std;
bool matrice[100][100];

bool aParle(int a, int b)
{
    return matrice[a][b];
}

int trouver_cible(int n)
{
    stack<int> pile;

    int cible1, cible2, c;

    for (int i = 0; i < n; i++)
        {
            pile.push(i);
        }

        while (pile.size() >= 2)
        {
            cible1 = pile.top();
            pile.pop();
            cible2 = pile.top();
            pile.pop();

            if (aParle(cible1, cible2))
            {
                pile.push(cible2);
            }
            else
            {
                pile.push(cible1);
            }
        }

        c = pile.top();


       for (int i = 0; i < n; i++)
    {
        if ( aParle(c,i) || i!=c && !aParle(i,c) )
             return -1;
    }


   return c;


}

int main()
{
    ifstream f("matrice.in");
    int n;
    f >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            f >> matrice[i][j];
        }
    }
    f.close();

    int cible = trouver_cible(n);
    if (cible == -1)
    {
        cout << "homer a skip" << endl;
    }
    else
    {
        cout << "homer c'est lui : " << cible << endl;
    }

    return 0;
}
