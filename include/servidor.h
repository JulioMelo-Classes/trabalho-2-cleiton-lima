#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;


class Servidor {
  private:
    int donoId; 
    string nome;
    string description; 
    string invitationCode; 
    vector<int> membroIds;
  public:
    Servidor(); 
    Servidor(const int pdonoId, const string pnome);  
    ~Servidor(); 

    int getDono(); 
    string getNome(); 
    string getDescription();

    string getInvitationCode(); 
    
    vector<int> getMembrosIds(); 
    

    void setDescription(const string desc); 
    void setInvitationCode(const string code); 
    
    void addMembro(const int id); 
};

#endif