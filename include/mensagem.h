#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <iostream>

/*
Cp 2 ok
*/
// Classe que representa uma mensagem de texto 
class Mensagem {
  private:
    std::string dataHora; //<! Data e hora do envio 
    int enviadaPor; //<! Id do usuário que enviou a mensagem 
    std::string conteudo; //<! Conteúdo da mensagem 
  public:
    /*! 
      Construtor da classe Mensagem
    */
    Mensagem(); //<! Construtor da mensagem 
    /*! Cria um construtor com parâmetros
          @param data representa a data de envio da mensagem
          @param id representa o identificador da mensagem
          @param texto representa o texto enviado na mensagem
          @return dados da mensagem
    */
    Mensagem(std::string pdata, int pid, std::string ptexto); //<! Construtor de parâmetros da mensagem 
    ~Mensagem(); //<! Destrutor da mensagem 

    std::string getDataHora(); //<! Retorna a data e a hora do envio da mensagem 
    int getEnviadaPor(); //<! Retorna o id do usuário que destinou a mensagem 
    std::string getConteudo(); //<! Retorna o conteúdo da mensagem 

    Mensagem& operator=(Mensagem const &msg); //<! Atribuição por sobrecarga de operador 
};

#endif
