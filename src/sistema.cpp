#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>   
#include <ctime>       
#include <chrono>       
#include <typeinfo>

using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {
  load();
  vector<Usuario>::iterator it = usuarios.begin();
  // **< Verifica se já existe usuário */ 
  while (it != usuarios.end()) {
    if (it->getEmail() == email) {
  return "usuario ja existe";
}

string Sistema::login(const string email, const string senha) {
  load();
  vector<Usuario>::iterator it = usuarios.begin();
  //**<Verifica se existe usuário com esse email e senha*/
  while (it != usuarios.end()) {
    if (it->getEmail() == email) {
      if (it->getSenha() == senha) {
        //**< Informa ao sistema o id do usuário online*/
        loggedUsuarioId = it->getId();
        return "Logado com " + email;
      }
    }

    it++;
  }

  return "Senha ou usuário inválidos!";
}

string Sistema::disconnect(int id) {
    //**< Verifica se existe usuario logado/
  if (loggedUsuarioId == 0) {
    return "você Não está conectado";
  }
  vector<Usuario>::iterator it;
  //**< Obtem o usuario logado pelo id/
  int targetId = loggedUsuarioId;
  it = find_if(usuario.begin(), usuarios.end(), [targetId](Usuario usuario) {
    return targetId == usuario.getId();
  });

  //**< Desconecta o usuário atual/
  loggedUsuarioId = 0;

  //**< Reseta o servidor e canal que ele estava visualizando/
  connectedServidornome = "";
  connectedCanalnome = "";

  return "Desconectando usuário " + it->getEmail();
}

string Sistema::create_server(int id, const string nome) {
  return "create_server NÃO IMPLEMENTADO";
}

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
   load(); 
  // Verifica se existe usuario logado
  if (loggedUsuarioId == 0) {
    return "Não está conectado";
  }
  vector<Servidor>::iterator it;
  // verifica se ja ha um servidor com mesmo nome 
  it = find_if(servidores.begin(), servidores.end(), [nome](Servidor servidor) {
    return nome == servidor.getNome();
  });
  if (it != servidores.end()) {
    return "ja existe um servidor com  esse nome ";
  }

string Sistema::set_server_invite_code(int id, const string nome, const string codigo) {
  return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::list_servers(int id) {
  return "list_servers NÃO IMPLEMENTADO";
}

string Sistema::remove_server(int id, const string nome) {
  return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(int id, const string nome, const string codigo) {
  return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server(int id, const string nome) {
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants(int id) {
  return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels(int id) {
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(int id, const string nome) {
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(int id, const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel(int id) {
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(int id, const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages(int id) {
  return "list_messages NÃO IMPLEMENTADO";
}




/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
