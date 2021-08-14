#include <sstream>
#include "canalTexto.h"

using namespace std;

CanalTexto::CanalTexto(string nome) : Canal(nome) {
}

CanalTexto::~CanalTexto() {
}

canalTipo CanalTexto::getTipo() {
  return TEXTO;
}

vector<Mensagem> CanalTexto::getMensagens() {
  return mensagens;
}

/*! Adiciona uma nova mensagem ao fim da lista.
       @param novaMensagem objeto contendo as informações da mensagem
*/
void CanalTexto ::addMensagem(Mensagem novaMensagem) {
  mensagens.push_back(novaMensagem);
}

/*! Percorre a lista de mensagens imprimindo os atributos num objeto ostringstream e retorna sua conversão para string.
       @param users lista de usuários para obter o nome pelo id
       @return string com a lista de mensagens
 */
string CanalTexto ::printMensagens(vector<Usuario> usuarios) {
  if (mensagens.size() > 0) {
    ostringstream output;

    for (auto it = mensagems.begin(); it != mensagens.end(); ++it) {
      string nome = usuarios[it->getEnviadopor() - 1].getNome();
      string data = it->getDataHora();
      string conteudo = it->getConteudo();

      output << nome << "<" << data << ">: " << conteudo << endl;
    }

    return output.str();
  }
  return "Sem mensagens no momento para exibir"; 
}
