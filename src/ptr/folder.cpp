#include "ptr/folder.h"
#include "ptr/message.h"

Folder::Folder(const Folder &f) : msgs_(f.msgs_) {
  AddToMsgs(f);
}

Folder::~Folder() {
  RemoveFromMsgs();
}

bool Folder::AddToMsgs(const Folder &f) {
  for (auto m : f.msgs_) {
    m->AddFolder(this);
  }
  return true;
}

bool Folder::RemoveFromMsgs() {
  for (auto m : msgs_) {
    m->RemoveFolder(this);
  }
  return true;
}

bool Folder::AddMsg(Message *m) {
  msgs_.insert(m);
  return true;
}

bool Folder::RemoveMsg(Message *m) {
  msgs_.erase(m);
  return true;
}

void Folder::swap(Folder &lhs, Folder &rhs) {
  using std::swap;
  for (auto m : lhs.msgs_) {
    m->RemoveFolder(&lhs);
  }
  for (auto m : rhs.msgs_) {
    m->RemoveFolder(&rhs);
  }
  swap(lhs.msgs_, rhs.msgs_);
  for (auto m : lhs.msgs_) {
    m->AddFolder(&lhs);
  }
  for (auto m : rhs.msgs_) {
    m->AddFolder(&rhs);
  }
}