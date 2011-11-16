//#define __DEBUG__
#include <iostream>
#include "bool.h"

char __db = '┌';
char __bg = '┐';
char __hd = '└';
char __hg = '┘';
char __dbg = '┬';
char __hdg = '┴';
char __hdb = '├';
char __hbg = '┤';
char __dg = '─';
char __hb = '│';
char __hdbg = '┼';

using namespace std;

int comptechar(string texte);

int main()
{
    while(true)
    {
        string tmp_var;
        cout<<"variables: ";
        cin >> tmp_var;
        vector<char> a;
        vector<char> i_var;
        char separateur1=__hb; //-77;
        char separateur2=__dg; //-60;
        char separateur3=__hdg; //-63;
        char separateur4=__dbg; //-62;
        cout<<__db; //(char)-38;
        for(int i=0; tmp_var[i]!='\0'; i++) cout<<separateur2;
        cout<<separateur4<<separateur2<</*(char)-65*/__bg<<endl<<separateur1;
        for(int i=0; tmp_var[i]!='\0'; i++){
            a.push_back('0');
            i_var.push_back(tmp_var[i]);
            cout<<tmp_var[i];
        }

        cout<<separateur1<<"S"<<endl;

        vector<char> a_table;
        do
        {
            cout<<separateur1;
            for(unsigned int i=0; i<a.size(); i++) cout<<a[i];
            cout<<separateur1;
            char tmp;
            cin>>tmp;
            if(tmp=='0' || tmp=='1') a_table.push_back(tmp);
            else a_table.push_back('x');
        }while(plusun(a));
        cout<<__hdb; //(char)-61;
        for(int i=0; tmp_var[i]!='\0'; i++) cout<<separateur2;
        cout<<separateur3<<separateur2<<separateur2;

        vector<char> inconues;
        for(unsigned int i=0; i<a_table.size(); i++) if(a_table[i]=='x') inconues.push_back('0');

        //Remplacement des x !
        vector<string> solutions; //contient les solutions
        int nbrou=-1;
        do
        {
            vector<bool> tmp_table;

            int x=0;
            for(unsigned int i=0; i<a_table.size(); i++)
            {
                if(a_table[i]=='0') tmp_table.push_back(false);
                else if(a_table[i]=='1') tmp_table.push_back(true);
                else
                {
                    if(inconues[x]=='0') tmp_table.push_back(false);
                    else tmp_table.push_back(true);
                    x++;
                }
            }
            #ifdef __DEBUG__
            cout<<"(";
            for(int i=0; i<tmp_table.size(); i++) cout<<tmp_table[i];
            cout<<")"<<endl;
            #endif
            // tmp_table contient la table de bool !
            string tmps=simple(tmp_table, i_var);
            int nbr=-1;
            int i=0;
            do
            {
                i=oupos(tmps,i+1);
                nbr++;
            }while(i!=0);

            if(nbrou==-1) nbrou=nbr;
            if(nbr==nbrou) solutions.push_back(tmps);

            else if(nbr<nbrou)
            {
                nbrou=nbr;
                solutions.clear();
                solutions.push_back(tmps);
            }

            if(inconues.size()>2 && inconues[0]=='1')
            {
                bool affiche=true;
                for(unsigned int i=1; i<inconues.size(); i++) if(inconues[i]=='1') affiche=false;
                if(affiche) cout<<(char)-85; // 1/2
            }
            if(inconues.size()>3 && inconues[0]=='0' && inconues[1]=='1')
            {
                bool affiche=true;
                for(unsigned int i=2; i<inconues.size(); i++) if(inconues[i]=='1') affiche=false;
                if(affiche) cout<<(char)-84; // 1/4
            }
        }while(plusun(inconues));
        cout<<endl;

        //SUPPRIMONS LES LONGUES !! :)
        int nchar=-1;
        for(int i=0; i<solutions.size(); i++)
        {
            int nbr=comptechar(solutions[i]);
            if(nchar==-1) nchar=nbr;
            if(nbr<nchar)
            {
                nchar=nbr;
                i=-1;
            }
            else if(nbr>nchar)
            {
                solutions.erase(solutions.begin()+i);
                i=-1;
            }
        }
        char logo=16;
        for(unsigned int i=0; i<solutions.size()-1; i++) cout<<(char)-61<<logo<<" S= "<<solutions[i]<<endl;
        cout<</*(char)-64*/__hd<<logo<<" S= "<<solutions[solutions.size()-1]<<endl;

        cout<<endl;
    }
    return 0;
}

int comptechar(string texte)
{
    int n=0;
    for(unsigned int i=0; i<texte.size(); i++) if(texte[i]!='!') n++;
    return n;
}
