#include <iostream>
#include "bool.h"

using namespace std;

int main()
{
    cout    << "caracteres autorises:" << endl
            << "01!&|^()" << endl
            << endl;
    string tmp;
    while(true)
    {
        cin >> tmp;
        switch (calculer(tmp))
        {
        case 0:
          cout << "faux" << endl;
          break;
        case 1:
          cout << "vrai" << endl;
          break;
        case 2:
          cout << "erreur de ()" << endl;
          break;
        case 3:
          cout << "erreur de !&|^" << endl;
          break;
        case 4:
          cout << "erreur de caracteres interdis" << endl;
          break;
        default:
          cout << "erreur inconue" << endl;
          break;
        }
        cout << endl;
    }
    return 0;
}
