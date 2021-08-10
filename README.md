

## Sobre

Concordo é um sistema em C++ similar ao Discord, operado através de comandos de uma única linha, desenvolvido como atividade 02 para a disciplina de Linguagem de Programação I do curso Bacharelado em Tecnologia da Informação.

Existe um executor que faz a interpretação dos comandos e executa o método correto no sistema.

## Como rodar?

```bash
# Clone o projeto
$ git clone https://github.com/JulioMelo-Classes/trabalho-2-cleiton-lima.git

## Entre na pasta
$ cd concordo

## Para executar

Com cmake:
```console
mkdir build
cd build
cmake ..
cmake --build .
```

## Para executar
Você pode rodar o sistema e em logo depois digitar os comandos seguidos de ENTER
```console
./concordo
```

Ou pode criar um arquivo de texto com uma lista de comandos (um por linha) e executar o sistema redirecionando esse arquivo como entrada padrão:
```console
./concordo < script_comandos.txt
```
#### **create-user**
Cadastra um novo usuário com as informações de nome, email e senha (caso não exista um usuário com o mesmo email). gera um ID automaticamente

_Exemplo de entrada/saída:_
```console
create-user pedrinhocasahshow@protonmail.com  Somoslindos123 pedrinCS
"Usuário criado"

create-user pedrinhocasashow@protonmail.com Somoslindos123 pedrinCS
"Usuário já existe!
```

#### **disconnect**
Desconecta o usuário atual do sistema, resetando as variáveis que armazenam o ID do usuário logado.

_Exemplo de entrada/saída:_
```console
disconnect
"Desconectando usuário pedrinhoCS.com"

disconnect
"Não está conectado"
```
#### **login**
Caso exista no sistema um usuário com o email e a senha inseridos, efetua o seu login, ou seja, altera a variável que armazena o ID do usuário logado.

_Exemplo de entrada/saída:_
```console
login pedrinhocasahshow.com SENHA_ERRADA
"Senha ou usuário inválidos!"

login pedrinhocasahshow.com somoslindos123
"Logado com pedrinhocasahshow.com"
```
#### **create-server**
Cria um novo servidor, caso não exista nenhum com o mesmo nome. Cadastra o usuário logado como o dono do servidor, que inicialmente não possui descrição nem código de convite. É necessário ter algum usuário logado.

_Exemplo de entrada/saída:_
```console
create-server contra-strike
"Não está conectado"

login pedrinhocasahshow.com Somoslindos123
"Logado com pedrinhocasahshow.com"
create-server contra-strike
"Servidor criado"

create-server contra-strike
"Servidor com esse nome ja existe"
```