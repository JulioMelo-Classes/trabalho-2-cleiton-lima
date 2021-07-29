#ifndef Usuario_H
#define Usuario_H

#include <iostream>

using namespace std;


class Usuario {
  private:
    
    int id; 
    string nome; 
    string email; 
    string senha; 

  public:
    Usuario(); //construtor
    Usuario(const int pid, const string pnome, const string pemail, const string psenha); 
    ~Usuario(); 

    int getId();
    string getNome(); 
    string getEmail(); 
    string getSenha();
};

#endif