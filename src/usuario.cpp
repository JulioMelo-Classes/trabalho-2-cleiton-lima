#include "usuario.h"

using namespace std;


Usuario::Usuario() {
  id = 0;
  name = "";
  email = "";
  password = "";
}

Usuario::Usuario(const int pid, const string nome, const string pemail, const string psenha) {
  id = pid;
  name = pnome;
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