#ifndef PTR_MESSAGE_H
#define PTR_MESSAGE_H

#include <memory>
#include <set>
#include <string>

class Folder;

class Message {
  friend class Folder;

public:
  explicit Message(const std::string &str = "") : contents_(str) {}

  Message(const Message &);

  ~Message();

  // 添加到folder
  bool SaveTo(Folder &);

  // 从folder删除message
  bool RemoveFrom(Folder &);

  Message& operator=(const Message &);

  void swap(Message &, Message &);

  bool AddFolder(Folder *);

  bool RemoveFolder(Folder *);

private:
  std::string contents_;
  std::set<Folder *> folders_;
  // 这个例子中，message和folder是独立的，也就是说不存在动态分配内存，
  // 所以不使用智能指针，因为folder不是我们自己分配的，当然
  // 不能我们来管理，只有contents才是自己的内存，而contents
  // 是值，也无需管理。这两个类的设计其实是有些问题的，问题是二者没有主次，我该
  // 何时删除，这两个类得
  // std::set<std::shared_ptr<Folder>> shared_folders_;
  // 添加本message到m的所有folder中
  bool AddToFolders(const Message &);
  // 从folders_中删除本message
  bool RemoveFromFolders();
};

#endif