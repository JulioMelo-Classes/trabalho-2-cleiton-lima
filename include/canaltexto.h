#ifndef CANALTEXTO_H
#define CANALTEXTO_H
#include <iostream>
#include <vector>
#include "mensagem.h"
#include "usuario.h"

enum canalType {
  TEXT,
  VOICE
};

/** Classe que representa canal */
class canal {
  protected:
    std::string nome; /**< Nome do canal */
  public:
    canal(std::string _nome) { nome =_nome; } /**< Construtor parametrizado de canal */
    virtual ~canal() {} /**< Destrutor de canal */

    std::string getnome() { return nome; } /**< Retorna o nome */

    virtual canalType getType() = 0; /**< Método virtual que retorna o tipo do canal */
    virtual void addMensagem (mensagem newmensagem) = 0; /**< Método virtual que adiciona uma mensagem */
    virtual std::string printMensagem(std::vector<usuario> usuarios) = 0; /**< Método virtual que retorna as mensagens formatadas na string */
    virtual std::vector<mensagem> getMensagens() = 0; /**< Método virtual que retorna as mensagens */
};


#endif