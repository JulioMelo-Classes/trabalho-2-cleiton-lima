#include <algorithm>
#include "servidor.h"
using namespace std;

Servidor::Servidor() {
  ownerId = 0;
  name = "";
  description = "";
  invitationCode = "";
}


Servidor::Servidor(const int pdonoId, const string pnome) {
  ownerId = pnodoId;
  name = pnome;
  description = "";
  invitationCode = "";
  memberIds.push_back(ownerId);
}

Servidor::~Servidor() {
}

int Servidor::getOwner() {
  return ownerId;
}

string Servidor::getName() {
  return name;
}

string Servidor::getDescription() {
  return description;
}

string Servidor::getInvitationCode() {
  return invitationCode;
}

vector<int> Servidor::getMemberIds() {
  return memberIds;
}

void Servidor::setDescription(const string desc) {
  description = desc;
}

void Servidor::setInvitationCode(const string code) {
  invitationCode = code;
}

void Servidor::addMember(const int id) {
  vector<int>::iterator it;
  it = find(memberIds.begin(), memberIds.end(), id);
  if (it == memberIds.end()) {
    memberIds.push_back(id);
  }
}

