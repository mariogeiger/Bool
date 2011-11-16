#include <iostream>
#include <string>
#include <vector>
#include "bool.h"

using namespace std;

int main()
{
    while(true)
    {
        string txt;
        string tmp;
        cin>>txt;
        tmp=txt;
        vector<char> inconues;
        vector<char> valeures;

        for(int i=0 ; txt[i]!='\0' ; i++)
        {
            if(txt[i]>64 && txt[i]<91 || txt[i]>96 && txt[i]<123)
            {
                bool nep=true;
                for(int j=0 ; j<inconues.size() ; j++)
                {
                    if(inconues[j]==txt[i]) nep=false;
                }
                if(nep) {
                    inconues.push_back(txt[i]);
                    valeures.push_back('0');
                }
            }
        }

        for(int i=0; i<inconues.size(); i++)
        {
            cout << inconues[i];
        }
        cout << " S" << endl;

        do
        {
            for(int i=0; i<valeures.size(); i++)
            {
                cout << valeures[i];
            }
            for(int i=0; txt[i]!='\0'; i++)
            {
                int npi=-1;
                for(int j=0; j<inconues.size(); j++)
                {
                    if(txt[i]==inconues[j]) npi=j;
                }
                if(npi!=-1)
                {
                    tmp[i]=valeures[npi];
                }
            }

            cout << " " << calculer(tmp) << endl;
        }while(plusun(valeures));

        cout << endl;
        inconues.clear();
        valeures.clear();
    }
}
