#ifndef CANAL_H
#define CANAL_H
#include <iostream>
#include <vector>
#include "mensagem.h"
#include "usuario.h"

enum channelType {
  TEXTO,

 class Canal {
  protected:
    std::string nome; /**< Nome do canal */
  public:
    canal(std::string _nome) { nome = _nome; } /**< Construtor parametrizado de canal */
    virtual ~canal() {} /**< Destrutor de canal */

    std::string getNome() { return nome; } /**< Retorna o nome */

  };


#endif   