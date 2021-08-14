#ifndef CANAL_H
#define CANAL_H
#include <iostream>
#include <vector>
#include "mensagem.h"
#include "usuario.h"

enum tipoCanal {
  TEXTO,
//classe que representa canal do concordo
 class Canal {
  protected:
    std::string nome; //<! Nome do canal
  public:
    Canal(std::string pnome) { nome = pnome; } //<! Construtor parametrizado de canal
    virtual ~Canal() {} //<! Destrutor de canal 

    std::string getNome() { return nome; } //<! Retorna o nome 
  
    virtual tipocanal gettipo() = 0; //<! metodo virtual responsavel por retornar o tipo do canal  
    virtual void addMensagem(mensagem novaMensagem) = 0;  //<! Método virtual que adiciona uma mensagem 
    virtual std::string printMensages(std::vector<Usuario> usuarios) = 0; //<! Método virtual que retorna as mensagens
    virtual std::vector<mensagem> getMensagens() = 0; //<! metodo virtual que deve retornar as mensagens do canal 
  };


#endif   
