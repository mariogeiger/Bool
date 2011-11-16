#include "bool.h"

int table(std::string equ, std::vector<bool> &table, std::vector<char> &var)
{
    std::string tmp=equ;
    std::vector<char> valeures;
    if(var.size()==0)
    {
        for(int i=0 ; equ[i]!='\0' ; i++)
        {
            if(equ[i]>64 && equ[i]<91 || equ[i]>96 && equ[i]<123)
            {
                bool test_deja_exist=true;
                for(unsigned int j=0 ; j<var.size() ; j++) if(var[j]==equ[i]) test_deja_exist=false;

                if(test_deja_exist) {
                    var.push_back(equ[i]);
                    valeures.push_back('0');
                }
            }
        }
    }else{
        for(unsigned int i=0; i<var.size() ; i++)
        valeures.push_back('0');
    }

    do
    {
        for(int i=0; equ[i]!='\0'; i++)
        {
            int npi=-1;
            for(unsigned int j=0; j<var.size(); j++)
            {
                if(equ[i]==var[j]) npi=j;
            }
            if(npi!=-1)
            {
                tmp[i]=valeures[npi];
            }
        }

        int result=calculer(tmp);
        if(result==0) table.push_back(false);
        if(result==1) table.push_back(true);
        if(result==2) return 2;
        if(result==3) return 3;

    }while(plusun(valeures));
    return 0;
}

bool plusun(std::vector<char> &a) // 00101 +1
{
    for(int taille=a.size()-1; taille>=0; taille--)
    {
        if(a[taille]=='0')
        {
            a[taille]='1';
            return true;
        }
        else
        {
            a[taille]='0';
        }
    }
    return false;
}

bool plusunVar(std::vector<char> &base, std::vector<char> total, unsigned int taille)
{
//retourne true si réussi
//retourne false si immposible
    std::string tmp;
    for(unsigned int i=0; i<total.size(); i++) tmp.append(1,total[i]);
    std::vector<unsigned int> bas;
    for(unsigned int i=0; i<base.size(); i++) for(unsigned int j=0; j<tmp.size(); j++) if(base[i]==tmp[j]) bas.push_back(j);

    // return false ?
    bool f=true;
    if(bas.size()==taille)
    {
        //! Attention de ne pas mettre de unsigned sur le i !!
        for(int i=taille-1; i>=0; i--) if(bas[i]!=tmp.size()-(taille-i)) f=false;
        if(f) return false;
    }

    if(bas.size()==taille)
    {
        for(int i=taille-1; i>=0; i--)
        {
            if(bas[i]<tmp.size()-(taille-i))
            {
                bas[i]++;
                base.clear();
                for(unsigned int j=0; j<bas.size(); j++) base.push_back(tmp[bas[j]]);
                return true;
            }
            else
            {
                if(bas[i-1]+1<tmp.size()-(taille-i)) bas[i]=bas[i-1]+2;
            }
        }
    }
    else
    {
        base.clear();
        for(unsigned int i=0; i<taille; i++) base.push_back(tmp[i]);
        return true;
    }

    return false; // ne devrait jamais arriver !
}

int calculer(std::string calcul)
{
    int beg,n;
    while(parentaises(calcul, beg, n)==1)
    {
        int result=equation(calcul.substr(beg+1,n-1));
        if(result==0) calcul.replace(beg,n+1,"0");
        if(result==1) calcul.replace(beg,n+1,"1");
        if(result==3) return 3;
    }
    if(parentaises(calcul, beg, n)==0) return equation(calcul);
    return 2;
}

int parentaises(std::string calcul, int &beg, int &n)
{
    bool ouvert=false;
    for(unsigned int i=0; i<calcul.size(); i++)
    {
        if(calcul[i]=='(')
        {
            beg=i;
            ouvert=true;
        }
        if(calcul[i]==')')
        {
            if(!ouvert) return 2;
            n=i-beg;
            return 1;
        }
    }
    if(!ouvert) return 0;
    return 2;
}

int equation(std::string calcul)
{
    for(int i=0; i<calcul.size(); i++)
    {
        if(calcul[i]=='!')
        {
            if(calcul[i+1]=='!') calcul.replace(i,2,"");
            else if(calcul[i+1]=='0') calcul.replace(i,2,"1");
            else if(calcul[i+1]=='1') calcul.replace(i,2,"0");
            else return 3;
            i=-1;
        }
    }
    for(int i=0; i<calcul.size(); i++)
    {
        if(calcul[i]=='&')
        {
            if(calcul[i-1]=='0' && calcul[i+1]=='0') calcul.replace(i-1,3,"0");
            else if(calcul[i-1]=='0' && calcul[i+1]=='1') calcul.replace(i-1,3,"0");
            else if(calcul[i-1]=='1' && calcul[i+1]=='0') calcul.replace(i-1,3,"0");
            else if(calcul[i-1]=='1' && calcul[i+1]=='1') calcul.replace(i-1,3,"1");
            else return 3;
            i=-1;
        }
    }
    for(int i=0; i<calcul.size(); i++)
    {
        if(calcul[i]=='|')
        {
            if(calcul[i-1]=='0' && calcul[i+1]=='0') calcul.replace(i-1,3,"0");
            else if(calcul[i-1]=='0' && calcul[i+1]=='1') calcul.replace(i-1,3,"1");
            else if(calcul[i-1]=='1' && calcul[i+1]=='0') calcul.replace(i-1,3,"1");
            else if(calcul[i-1]=='1' && calcul[i+1]=='1') calcul.replace(i-1,3,"1");
            else return 3;
            i=-1;
        }
        if(calcul[i]=='^')
        {
            if(calcul[i-1]=='0' && calcul[i+1]=='0') calcul.replace(i-1,3,"0");
            else if(calcul[i-1]=='0' && calcul[i+1]=='1') calcul.replace(i-1,3,"1");
            else if(calcul[i-1]=='1' && calcul[i+1]=='0') calcul.replace(i-1,3,"1");
            else if(calcul[i-1]=='1' && calcul[i+1]=='1') calcul.replace(i-1,3,"0");
            else return 3;
            i=-1;
        }
    }
    if(calcul.size()!=1) return 3;
    if(calcul[0]=='0') return 0;
    if(calcul[0]=='1') return 1;
    return 3;//grosse erreur !
}

std::string simple(std::string brut)
{

    std::vector<bool> i_table;
    std::vector<char> i_var;
    if(table(brut, i_table, i_var)) return "!";

    std::vector<bool> filtre;
    std::vector<bool> filtreb;
    filtre=i_table;
    filtreb=filtre;

    std::string calculFinal;
    std::vector<int> efficaFinal;

    std::vector<bool> a_table;
    std::vector<char> a_var;

    bool nfiltre=true;
// 1
    a_table.clear();
    table("1", a_table, i_var);

    bool ok=true;
    bool okFiltre=false;
    for(unsigned int j=0; j<i_table.size(); j++)
    {
        if(a_table[j] & !i_table[j])
        {
            ok=false;
            j=i_table.size();
        }
        if(a_table[j] & filtreb[j]) okFiltre=true;
    }
    if(ok & okFiltre)
    {
        int effica=0;
        for(unsigned int j=0; j<i_table.size(); j++)
        {
            if(a_table[j]) filtre[j]=false;
            if(a_table[j]&filtreb[j]) effica++;
        }
        efficaFinal.push_back(effica);
        nfiltre=false;
        for(unsigned int j=0; j<filtre.size(); j++) if(filtre[j]) nfiltre=true;
        if(calculFinal.size()==0) calculFinal="1";
        else calculFinal.append("|1");
    }

    filtreb=filtre;


    for(unsigned int i=1; i<=i_var.size() && nfiltre;)
    {

        if(!plusunVar(a_var, i_var, i))
        {
            filtreb=filtre;
            i++;
        }
        else
        {
            std::vector<char> a_bool;
            for(unsigned int j=0; j<i; j++) a_bool.push_back('0');

            do
            {
                std::string a_calcul="";
                if(a_bool[0]=='0'){
                    a_calcul.append("!");
                    a_calcul.append(1, a_var[0]);
                }
                else a_calcul.append(1, a_var[0]);

                for(unsigned int j=1; j<i; j++)
                {
                    if(a_bool[j]=='0'){
                        a_calcul.append("&!");
                        a_calcul.append(1, a_var[j]);
                    }
                    else{
                        a_calcul.append("&");
                        a_calcul.append(1, a_var[j]);
                    }
                }

                a_table.clear();
                table(a_calcul, a_table, i_var);

                bool ok=true;
                bool okFiltre=false;
                for(unsigned int j=0; j<i_table.size(); j++)
                {
                    if(a_table[j] & !i_table[j])
                    {
                        ok=false;
                        j=i_table.size();
                    }
                    if(a_table[j] & filtreb[j]) okFiltre=true;
                }
                if(ok & okFiltre)
                {
                    int effica=0;
                    for(unsigned int j=0; j<i_table.size(); j++)
                    {
                        if(a_table[j]) filtre[j]=false;
                        if(a_table[j]&filtreb[j]) effica++;
                    }
                    efficaFinal.push_back(effica);
                    nfiltre=false;
                    for(unsigned int j=0; j<filtre.size(); j++) if(filtre[j]) nfiltre=true;
                    if(calculFinal.size()==0) calculFinal=a_calcul;
                    else calculFinal.append("|"+a_calcul);
                }
            }while(plusun(a_bool) && nfiltre);
        }
    }


    if(calculFinal.size()==0) calculFinal="0";

    while(correction(calculFinal, efficaFinal));
    return calculFinal;
}

bool correction(std::string &calcul, std::vector<int> &eff)
{
    std::vector<bool> i_table;
    std::vector<char> i_var;
    table(calcul, i_table, i_var);

    if(eff.size()<2) return false;

    for(int j=1; j<=eff[0]; j++)
    {
        for(unsigned int k=0; k<eff.size(); k++)
        {
            if(eff[k]==j)
            {
                std::vector<bool> a_table;
                std::string tmp=enleve(calcul, k);

                table(tmp, a_table, i_var);

                bool identique=true;
                for(unsigned int i=0; i<i_table.size(); i++)
                {
                    if(i_table[i]^a_table[i]) identique=false;
                }
                if(identique)
                {
                    eff.erase(eff.begin()+k);
                    calcul=tmp;
                    return true;
                }
            }
        }
    }

    return false;
}

int oupos(std::string a, int p)
{
    for(int i=p; a[i]!='\0'; i++) if(a[i]=='|') return i;
    return 0;
}

std::string enleve(std::string calcul, int n)
{
    if(n==0)
    {
        return calcul.substr(oupos(calcul,0)+1);
    }
    else
    {
        int p=oupos(calcul, 0);
        for(int i=1; i<n; i++) p=oupos(calcul, p+1);

        std::string tmp=calcul.substr(0,p);
        p=oupos(calcul, p+1);
        if(p!=0) tmp.append(calcul.substr(p));
        return tmp;
    }
}

std::string simple(std::vector<bool> i_table, std::vector<char> i_var)
{
    std::vector<bool> filtre;
    std::vector<bool> filtreb;
    filtre=i_table;
    filtreb=filtre;

    std::string calculFinal;
    std::vector<int> efficaFinal;

    std::vector<bool> a_table;
    std::vector<char> a_var;

    bool nfiltre=true;
// 1
    a_table.clear();
    table("1", a_table, i_var);

    bool ok=true;
    bool okFiltre=false;
    for(unsigned int j=0; j<i_table.size(); j++)
    {
        if(a_table[j] & !i_table[j])
        {
            ok=false;
            j=i_table.size();
        }
        if(a_table[j] & filtreb[j]) okFiltre=true;
    }
    if(ok & okFiltre)
    {
        int effica=0;
        for(unsigned int j=0; j<i_table.size(); j++)
        {
            if(a_table[j]) filtre[j]=false;
            if(a_table[j]&filtreb[j]) effica++;
        }
        efficaFinal.push_back(effica);
        nfiltre=false;
        for(unsigned int j=0; j<filtre.size(); j++) if(filtre[j]) nfiltre=true;
        if(calculFinal.size()==0) calculFinal="1";
        else calculFinal.append("|1");
    }

    filtreb=filtre;


    for(unsigned int i=1; i<=i_var.size() && nfiltre;)
    {
        if(!plusunVar(a_var, i_var, i))
        {
            filtreb=filtre;
            i++;
        }
        else
        {
            std::vector<char> a_bool;
            for(unsigned int j=0; j<i; j++) a_bool.push_back('0');

            do
            {
                std::string a_calcul="";
                if(a_bool[0]=='0'){
                    a_calcul.append("!");
                    a_calcul.append(1, a_var[0]);
                }
                else a_calcul.append(1, a_var[0]);

                for(unsigned int j=1; j<i; j++)
                {
                    if(a_bool[j]=='0'){
                        a_calcul.append("&!");
                        a_calcul.append(1, a_var[j]);
                    }
                    else{
                        a_calcul.append("&");
                        a_calcul.append(1, a_var[j]);
                    }
                }

                a_table.clear();
                table(a_calcul, a_table, i_var);

                bool ok=true;
                bool okFiltre=false;
                for(unsigned int j=0; j<i_table.size(); j++)
                {
                    if(a_table[j] & !i_table[j])
                    {
                        ok=false;
                        j=i_table.size();
                    }
                    if(a_table[j] & filtreb[j]) okFiltre=true;
                }
                if(ok & okFiltre)
                {
                    int effica=0;
                    for(unsigned int j=0; j<i_table.size(); j++)
                    {
                        if(a_table[j]) filtre[j]=false;
                        if(a_table[j]&filtreb[j]) effica++;
                    }
                    efficaFinal.push_back(effica);
                    nfiltre=false;
                    for(unsigned int j=0; j<filtre.size(); j++) if(filtre[j]) nfiltre=true;
                    if(calculFinal.size()==0) calculFinal=a_calcul;
                    else calculFinal.append("|"+a_calcul);
                }
            }while(plusun(a_bool) && nfiltre);
        }
    }


    if(calculFinal.size()==0) calculFinal="0";

    while(correction(calculFinal, efficaFinal));
    return calculFinal;
}
