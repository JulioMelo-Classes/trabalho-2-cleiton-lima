#include "usuario.h"

using namespace std;


Usuario::Usuario() {
  id = 0;
  nome = "";
  email = "";
  senha = "";
}

Usuario::Usuario(const int pid, const string nome, const string pemail, const string psenha) {
  id = pid;
  nome = pnome;
  email = pemail;
  password = psenha;
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