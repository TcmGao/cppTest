#ifndef PTR_FOLDER_H
#define PTR_FOLDER_H

#include <set>
class Message;

class Folder {
public:
  Folder() = default;

  Folder(const Folder &);

  ~Folder();

  Folder& operator=(const Folder &);

  bool RemoveMsg(Message *);

  bool AddMsg(Message *);

  void swap(Folder &, Folder &);

private:
  std::set<Message *> msgs_;

  bool RemoveFromMsgs();

  bool AddToMsgs(const Folder &);
};

#endif