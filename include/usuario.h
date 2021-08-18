#ifndef Usuario_H
#define Usuario_H
#include <iostream>


// Classe que representa o usuário do sistema 
class Usuario {
  private:
    int id; //<! Id do usuário 
    std::string nome; //<! Nome do usuário 
    std::string email; //<! Email do usuário 
    std::string senha; //<! Senha do usuário 
  public:
    /*! 
      Construtor da classe Usuario
    */
    Usuario(); //<! Construtor do usuário 
    /*! Cria um construtor parametrizado 
          @param pid representa o Id do usuário
          @param pnome representa o nome do usuário
          @param pemail representa o email do usuário
          @param psenha representa a senha do usuário
    */
    Usuario(const int pid, const std::string pnome, const std::string pemail, const std::string psenha); //<! Construtor parametrizado do usuário 
    ~Usuario();//<! Destrutor do usuário 

    int getId(); //<! pega o id do usuário 
    std::string getNome(); //<! pega o nome do usuário 
    std::string getEmail(); //<! pega o email do usuário 
    std::string getsenha(); //<! pega a senha do usuário 
};

#endif