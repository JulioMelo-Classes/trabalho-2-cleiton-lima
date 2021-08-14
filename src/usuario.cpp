#include "usuario.h"

using namespace std;

/*!incializa os atributos id, nome, email e senha com valores nulos*/
Usuario::Usuario() {
  id = 0;
  nome = "";
  email = "";
  senha = "";
}
/*! Inicializador de  atributos com os valores do parâmetro */
Usuario::Usuario(const int pid, const string nome, const string pemail, const string psenha) {
  id = pid;
  nome = pnome;
  email = pemail;
  senha = psenha;
}

Usuario::~Usuario() {
}

int Usuario::getId() {
  return id;
}

string Usuario::getNome() {
  return nome;
}

string Usuario::getEmail() {
  return email;
}

string Usuario::getSenha() {
  return senha;
}
