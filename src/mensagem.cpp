#include <iostream>
#include "mensagem.h"

using namespace std;


Mensagem::Mensagem(string data, int id, string texto) {
    dataHora = data;
    enviadaPor = id;
    conteudo = texto;
}

Mensagem::~Mensagem() {}

string Mensagem::getDataHora() {
    return dataHora;
}

int Mensagem::getEnviadaPor() {
    return enviadaPor;
}

string Mensagem::getConteudo() {
    return conteudo;
}

/*! Copia os atributos da mensagem por referĂȘncia para a mensagem atual
         @param m referĂȘncia de objeto do tipo Mensagem.
         @return referĂȘncia para o objeto atual
*/
Mensagem& Mensagem::operator = (Mensagem const &msg) {
    dataHora = msg.dataHora;
    enviadaPor = msg.enviadaPor;
    conteudo = msg.conteudo;

    return *this;
}
