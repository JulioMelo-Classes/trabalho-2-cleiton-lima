#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <iomanip>   
#include <ctime>       
#include <chrono>       
#include <typeinfo>

using namespace std;
using std::chrono::system_clock; //<! classe sistema de relogio 

//<! Obtém a data e hora atual
struct tm* currentTime() {
	time_t tt =  system_clock::to_time_t(system_clock::now());
	return localtime(&tt);

	/** Converte string para inteiro */
int stringToInt(string s) {
  int i;
  stringstream sstream(s);
  sstream >> i;
  return i;
}

//<! Percorre a lista de servidores liberando a memória alocada para os seus canais
Sistema::~Sistema() {
  for (size_t i = 0; i < servidores.size(); ++i) {
    vector<Canal*> canais = servidores[i].getCanais();
    for (size_t j = 0; j < canais.size(); ++j) {
      delete canais[j];
    }
  }
}

bool Sistema::logar(int idUsuario) {
  if(usuariosLogados.find(idUsuario) == usuariosLogados.end() ?  false :  true);
};

//<! Executa os métodos que salvam os dados nos arquivos txt */
void Sistema::salvar() {
  salvarUsuarios();
  salvarServidores();
}
	
  //<! Imprime no arquivo users.txt a quantidade de usuários, seguida dos atributos de cada usuário do sistema
  void Sistema::salvarUsuarios() {
  ofstream arquivoUsuario("users.txt");
  //<! Verifica se o arquivo foi aberto
  if (!arquivoUsuario) {
    cerr << "O arquivo não foi aberto" << endl;
    exit(1);
  } else {
    //<! Imprime a quantidade de usuários
    arquivoUsuario << usuarios.size() << endl;
    //<! Percorre o vetor de usuários imprimindo seus atributos no arquivo
    for (auto it = usuarios.begin(); it != usuarios.end(); ++it) {
      arquivoUsuario << it->getId() << endl;
      arquivoUsuario << it->getNome() << endl;
      arquivoUsuario << it->getEmail() << endl;
      arquivoUsuario << it->getSenha() << endl;
    }

    //<! Fecha o arquivo
    arquivoUsuario.close();
  }
}
//<! Imprime no arquivo servidores.txt as informações de cada servidor do sistema 
void Sistema::salvarServideores() {
  ofstream arquivoServidor("servers.txt");
  //<! Verifica se o arquivo foi aberto
  if (!arquivoServidor) {
    cerr << "O arquivo não foi aberto" << endl;
    exit(1);
  } else {
    //<! Imprime a quantidade de servidores
    arquivoServidor << servidores.size() << endl;

    //<! Percorre o vetor de servidores
    for (auto it = servidores.begin(); it != servidores.end(); ++it) {
     arquivoServidor << it->getDono() << endl;
     arquivoServidor << it->getNome() << endl;
     arquivoServidor << it->getDescricao() << endl;
     arquivoServidor << it->getCodigoConvite() << endl;

      vector<int> idsMembro = it->getIdsMembro();
      salvararquivo << idsMembro.size() << endl;
      //<! Imprime os ids dos usuários participantes
      for (auto id = idsMembro.begin(); id != idsMembro.end(); ++id) {
        salvararquivo << *id << endl;
      }

      vector<Canal*> canais = it->getCanais();
      arquivoServidor << canais.size() << endl;
      //<! Imprime os atributos dos canais
      for (auto c = canais.begin(); c != canais.end(); ++c) {
        salvararquivo << (*c)->getNome() << endl;
        string tipe = (*c)->getTipo() == TEXTO ? "TEXTO" : "VOZ";
        salvararquivo << tipe << endl;

        //<! Imprime a quantidade de mensagens
        vector<Mensagem> mensagens = (*c)->getMensagens();
        salvararquivo << mensagens.size() << endl;
        //<! Imprime os atributos de cada mensagem
        for (auto m = mensagens.begin(); m != mensagens.end(); ++m) {
          salvararquivo << m->getEnviadaPor() << endl;
          salvararquivo << m->getDataHora() << endl;
          salvararquivo << m->getConteudo() << endl;
        }
      }
    }

    //<! Fecha o arquivo
    salvararquivo.close();
  }
}
	
	
// COMANDOS 
string Sistema::sair() {
  return "Saindo...";
}

string  Sistema::create_user (const string email, const string senha, const string nome) {
  load(); 
  vector<Usuario>::iterator it = usuarios.begin();
  //<! Verifica se já existe usuário com mesmos dados de email e retorna caso se ele exista 
  while (it != usuarios.end()) {
    if (it->getEmail() == email) {
      return "usuario ja existe";
    }
    it++;
  }
  //<! Gera um id de forma automática de acordo como tamanho do vetor
  int id = usuarios.size() + 1;
 

  //<! Cria um usuário novo adicionando-o no fim do vetor
  Usuario newUsuario(id, nome, email, senha);
  usuarios.push_back(newUsuario);
  save();
  return "O usuário foi criado";
}


string Sistema::login(const string email, const string senha) {
  load();
  vector<Usuario>::iterator it = usuarios.begin();
  //<! Verifica se existe usuário com esses mesmos dados de email e senha
  while (it != usuarios.end()) {
    if (it->getEmail() == email) {
      if (it->getSenha() == senha) {
        /*! Informa ao sistema o id do usuário online */
        loggedUsuarioId = it->getId();
        return "Logado com " + email;
      }
    }
    it++;
  }
  return "Seu Usuário ou senha estão inválidos por favor tente novamente!";
}

string Sistema::disconnect(int id) {
  //<!erifica se existe usuario logado
  if (loggedUsuarioId == 0) {
    return "Você não está conectado";
  }
  vector<Usuario>::iterator it;
  //<!obtem usuario logado pelo id
  int targetId = loggedUsuarioId;
  it = find_if(usuario.begin(), usuarios.end(), [targetId](Usuario usuario) {
    return targetId == usuario.getId();
  });

   //<!Desconecta o usuário atual 
  loggedUsuarioId = 0;

 //<! Reseta o servidor e canal que ele estava visualizando */
  connectedServidornome = "";
  connectedCanalnome = "";

  return "Desconectando usuário " + it->getEmail();
}

string Sistema::create_server(int id, const string nome)  { 
  load(); 
 //<! Verifica se existe usuario logado 
  if (loggedUsuarioId == 0) {
    return "Não está conectado";
  }
  vector<Servidor>::iterator it;
 //<! verifica se ja ha um servidor com mesmo nome caso não exista inicia criação de um. 
  it = find_if(servidores.begin(), servidores.end(), [nome](Servidor servidor) {
    return nome == servidor.getNome();
  });
  if (it != servidores.end()) {
    return "ja existe um servidor com  esse nome ";
  }

string Sistema::set_server_desc(int id, const string nome, const string descricao) {
  load();
 //<! Verifica se há usuário existente logado 
  if (loggedUsuarioId == 0) return "Não conectado"; 

  vector<Servidor>::iterator it;

  //<! Verifica se há um servidor com o dito nome 
  it = find_if(servidores.begin(), servidores.end(), [nome](Servidor servidor)) {
    return name = servidor.getNome();
  });

  if (it == servidores.end()) {
    return "Servidor " + nome + " não encontrado";
  }

   //<! Verifica se o usuário que está logado é dono do servidor 
  if (it->getDono() != loggedUsuarioId) {
    return "Você não criou este servidor, portanto não pode alterá-lo";
  }

   //<! Se tudo ocorrer bem, altera a descrição do servidor 
  it->setDescricao(descricao);
  save();
  return "A descrição do servidor " + name + " foi alterada";

  
}

string  Sistema::set_server_invite_code (const string nome, const string codigo) {
  load(); 
   //<! Verifica se existe usuario logado 
  if (loggedIdUsuario == 0) {
    return "voçê Não está conectado ;(";
  }
  vector<Servidor>::iterator it;
   //<! Verifica se existe um servidor com esse nome 
  it = find_if(servidores.begin(), servidores.end(), [nome](Servidor servidor) {
    return nome == servidor.getNome();
  });
  if (it == servidores.end()) {
    return "Servidor '" + nome + "' não encontrado";
  }
   //<! Verifica se o usuário logado é o dono do servidor 
  if (it->getDono() != loggedIdUsuario) {
    return "Você não tem permissão para alterar o código de convite de um servidor que não foi criado por você solicite ao propietarios do servidor autrização ";
  }
   //<! Se está de acordo sera passado um código
  if (codigo.length() > 0) {
    it->setCodigodeConvite(codigo);
    save();
    return "Código de convite do servidor '" + nome +"' modificado!";
  }
   //<! Caso não tenha um código no comando */
  it->setCodigodeConvite("");
  save();
  return "Código de convite do servidor '" + nome +"' removido!";
}

/*! Percorre a lista de servidores imprimindo seus nomes num objeto ostringstream e retorna a conversão para string.
      @return uma string contendo a lista que possui todos os servidores do sistema. 
 */
string Sistema::remove_server(int id, const string nome) {
	load();
  //<! Verifica se existe usuario logado
  if (loggedUsuarioId == 0) {
    return "Não está conectado";
  }
  vector<Servidor>::iterator it;
  //<! Verifica se existe um servidor com esse nome
  it = find_if(servidores.begin(), servidores.end(), [name](Servidor servidor) {
    return nome == server.getNome();
  });
  if (it == servidores.end()) {
    return "o Servidor '" + nome + "' não encontrado";
  }
  //<! Verifica se o usuário logado é o dono
  if (it->getDono() != loggedUsuarioId) {
    return "Você não é dono(a) do servidor meu amiguinho(a) '" + name + "'";
  }
  //<! Se estiver tudo ok, remove o servidor do vector
  servidores.erase(it);
  save();
  return " o Servidor '" + nome + "' foi removido";
}
	
string Sistema::list_servers(int id ) {
return "list_servers NÃO IMPLEMENTADO";	
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
