#ifndef HEADER_BOOL
#define HEADER_BOOL

#include <string>
#include <vector>

int table(std::string equ, std::vector<bool> &table, std::vector<char> &var);
bool plusun(std::vector<char> &a);
bool plusunVar(std::vector<char> &base, std::vector<char> total, unsigned int taille);
int parentaises(std::string calcul, int &beg, int &n);
int equation(std::string calcul);
int calculer(std::string calcul);
std::string simple(std::string brut);
bool correction(std::string &calcul, std::vector<int> &eff);
int oupos(std::string a, int p);
std::string enleve(std::string calcul, int n);
std::string simple(std::vector<bool> i_table, std::vector<char> i_var);

#endif
