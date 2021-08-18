#ifndef CANAL_TEXTO_H
#define CANAL_TEXTO_H

#include <vector>
#include "mensagem.h"
#include "canal.h"

/*
Cp2 ok
*/
// classe representante de canaltexto 
class CanalTexto : public Canal {
  private:
    std::vector<Mensagem> mensagens; //<! vetor que Lista de mensagens de texto. 
  public:
    CanalTexto(std::string nome); //<! Constructor de CanalTexto 
    ~CanalTexto(); //<! Destrutor de CanalTexto

    tipoCanal  getTipo(); //<!retorna qual tipo de canal
    std::vector<Mensagem> getMensagens(); //<! retorna o vetor de mensagens

    void addMensagem(Mensagem novaMensagem); //<! Adiciona uma nova mensagem a lista
    std::string printMensagens(std::vector<Usuario> usuarios); //<! Retorna a lista de mensagens formatadas em string
    
};

#endif
