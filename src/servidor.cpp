#include <algorithm>
#include "servidor.h"
using namespace std;

//<! Inicializa os atributos donoId, nome, descrição, codigodeConvite com valores nulos
Servidor::Servidor() {
  donoId = 0;
  nome = "";
  descricao = "";
  codigodeConvite = "";
}


Servidor::Servidor(const int pdonoId, const string pnome) {
  donoId = pnodoId;
  nome = pnome;
  descricao = "";
  codigodeConvite = "";
  memberIds.push_back(ownerId);
}

Servidor::~Servidor() {
}

int Servidor::getDono() {
  return donoId;
}

string Servidor::getNome() {
  return nome;
}

string Servidor::getDescricao() {
  return descricao;
}

string Servidor::getCodigodeConvite() {
  return codigodeConvite;
}

vector<int> Servidor::getIdsMembro() {
  return idsMembro;
}

vector<Canal*> Servidor::getCanais() {
  return canais;
}

void Servidor::setDescricao(const string desc) {
  descricao = desc;
}

void Servidor::setCodigodeConvite(const string codigo) {
  codigodeconvite = codigo;
}

void Servidor::addMembro(const int id) {
  vector<int>::iterator it;
  it = find(idsMembro.begin(), idsMembro.end(), id);
  if (it == idsMembro.end()) {
    idsMembro.push_back(id);
  }
}
/*! Adiciona ao final da lista de canais o ponteiro para o canal passado por parâmetro
     @param newChannel ponteiro para canal.
*/
void Servidor::addCanal(Canal* novoCanal) {
  canais.push_back(novoCanal);
}
