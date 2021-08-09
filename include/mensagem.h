#ifndef MENSAGEM_H
#define MENSAGEM_H

#include <istream>

/** Classe que representa um mensagem de texto */
class mensagem {
  private:
    std::string dateTime; /**< Data e hora do envio */
    int sentBy; /**< ID do usuário que enviou a mensagem */
    std::string content; /**< Conteúdo da mensagem */
  public:

    std::string getDateTime(); 
    int getSentBy(); 
    std::string getContent(); 

    Mensagem& operator= (Mensagem const &m); /** sobrecarga operador destruição */
};


#endif
