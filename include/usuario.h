#ifndef Usuario_H
#define Usuario_H
//**< biblioteca padrão */
#include <iostream>

using namespace std;

/** Classe que representa o usuário do sistema */
class Usuario {
  private:
    int id; /**< ID do usuário */
    std::string nome; /**< Nome do usuário */
    std::string email; /**< Email do usuário */
    std::string senha; /**< Senha do usuário */

  public:
    Usuario(); /**< Construtor do usuário */
    Usuario(const int _id, const std::string _nome, const std::string _email, const std::string _senha); /**< Construtor parametrizado do usuário */
    ~Usuario();/**< Destrutor do usuário */

    int getId(); /**< pega o id do usuário */
    std::string getNome(); /**< pega o nome do usuário */
    std::string getEmail(); /**< pega o email do usuário */
    std::string getsenha(); /**< pega a senha do usuário */
};

#endif