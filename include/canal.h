#ifndef CANAL_H
#define CANAL_H
#include <iostream>
#include <vector>
#include "mensagem.h"
#include "usuario.h"

enum tipocanal {
  TEXTO,

 class Canal {
  protected:
    std::string nome; /**< Nome do canal */
  public:
    canal(std::string _nome) { nome = _nome; } /**< Construtor parametrizado de canal */
    virtual ~canal() {} /**< Destrutor de canal */

    std::string getNome() { return nome; } /**< Retorna o nome */
  
    virtual tipocanal gettipo() = 0; 
    virtual void addMensagem(mensagem novaMensagem) = 0; 
    virtual std::string printMensages(std::vector<usuario> usuarios) = 0; 
    virtual std::vector<mensagem> getMensagens() = 0; 
  };


#endif   