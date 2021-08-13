#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <vector>
#include <string>
#include <iostream>
#include <canal.h>


// Classe que representa servidores do concordo 
class Servidor {
  private:
    int donoId; //<! Id do dono do servidor 
    std::string nome; //<! Nome do servidor 
    std::string description; //<! Descrição do servidor 
    std::string invitationCode; //<! Código de invite para entrar no servidor 
    std::vector<int> membroIds; //<! Lista de Id's que constam no servidor 
    std::vector<Canal*> canais; //<! Listagem dos ponteiros para os canais do servidor 
  public:
    /*! 
      Construtor da classe Servidor
    */
    Servidor(); //<! Construtor da classe Servidor 
    /*! Cria um construtor com parâmetros
          @param pdonoId representa o Id do dono do servidor
          @param pnome o nome passado na criação do novo servidor
          @return dados do servidor
    */
    Servidor(const int pdonoId, const std::string pnome); //<! Construtor parametrizado da classe Servidor 
    /*! Destrutor da classe Servidor */
    ~Servidor(); //<! Destrutor da classe Servidor

    int getDono(); //<! Obtém o Id do dono do servidor 
    std::string getNome(); //<! Obtém o nome do servidor 
    std::string getDescricao(); //<! Obtém a descrição do servidor 
    std::string getCodigoConvite(); //<! Obtém o código de convite do servidor 
    std::vector<int> getMembrosIds(); //<! Obtém a listagem dos Id's dos usuários presentes no servidor 
    
    void setDescricao(const std::string desc); //<! Adiciona a descrição do servidor
    void setCodigoConvite(const std::string code); //<! Adiciona o código de convite 
    
    void addMembro(const int id); //<! Adiciona um Id de membro na listagem 
    void addCanal(Canal* novoCanal); //<! Adiciona um novo canal na listagem 
};

#endif