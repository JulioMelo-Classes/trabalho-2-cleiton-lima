#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <iostream>

/** Classe que representa uma mensagem de texto */
class Mensagem {
  private:
    std::string dataHora; /**< Data e hora do envio */
    int enviadaPor; /**< Id do usuário que enviou a mensagem */
    std::string conteudo; /**< Conteúdo da mensagem */
  public:
    Mensagem(); /**< Construtor da mensagem */
    Mensagem(std::string data, int id, std::string texto); /**< Construtor de parâmetros da mensagem */
    ~Mensagem(); /**< Destrutor da mensagem */

    std::string getDataHora(); /**< Retorna a data e a hora do envio da mensagem */
    int getEnviadaPor(); /**< Retorna o id do usuário que destinou a mensagem */
    std::string getConteudo(); /**< Retorna o conteúdo da mensagem */

    Mensagem& operator=(Mensagem const &msg); /** Atribuição por sobrecarga de operador */
};

#endif
