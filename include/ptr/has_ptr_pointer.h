#ifndef PTR_HAS_PTR_POINTER_H
#define PTR_HAS_PTR_POINTER_H

#include <cstddef>
#include <functional>
#include <iostream>

class HasPtrPointer {
public:
  HasPtrPointer(const std::string &s = std::string())
      : ps_(new std::string(s)), i_(0), use_(new std::size_t(1)) {}
  HasPtrPointer(const HasPtrPointer &);

  HasPtrPointer& operator=(const HasPtrPointer &);

  ~HasPtrPointer();

private:
  std::string *ps_;
  int i_;
  std::size_t *use_;
};

#endif