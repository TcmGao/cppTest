#include "ptr/message.h"
#include "ptr/folder.h"
#include <map>

Message::Message(const Message &m)
    : contents_(m.contents_), folders_(m.folders_) {
  AddToFolders(m);
}

Message::~Message() {
  RemoveFromFolders();
}

bool Message::SaveTo(Folder &folder) {
  // 这里两个执行不是原子性，一旦后一个失败了，后果很严重
  folder.AddMsg(this);
  folders_.insert(&folder);
  return true;
}

bool Message::RemoveFrom(Folder &folder) {
  folders_.erase(&folder);
  folder.RemoveMsg(this);
  return true;
}

bool Message::AddToFolders(const Message &m) {
  for (auto f : m.folders_) {
    f->AddMsg(this);
  }
  return true;
}

bool Message::RemoveFromFolders() {
  auto it = folders_.begin();
  while (it != folders_.end()) {
    (*it)->RemoveMsg(this);
  }
  return true;
}

bool Message::AddFolder(Folder *f) {
  folders_.insert(f);
  return true;
}

bool Message::RemoveFolder(Folder *f) {
  folders_.erase(f);
  return true;
}

Message& Message::operator=(const Message &rhs) {
  // 从所有文件删除
  RemoveFromFolders();
  contents_ = rhs.contents_;
  folders_ = rhs.folders_;
  AddToFolders(rhs);
  return *this;
}

void Message::swap(Message &lhs, Message &rhs) {
  using std::swap;
  for (auto f : lhs.folders_) {
    f->RemoveMsg(&lhs);
  }
  for (auto f : rhs.folders_) {
    f->RemoveMsg(&rhs);
  }

  swap(lhs.contents_, rhs.contents_);
  swap(lhs.folders_, rhs.folders_);
  for (auto f : lhs.folders_) {
    f->AddMsg(&lhs);
  }
  for (auto f : rhs.folders_) {
    f->AddMsg(&rhs);
  }
}