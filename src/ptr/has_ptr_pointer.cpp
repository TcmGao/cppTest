#include "ptr/has_ptr_pointer.h"

HasPtrPointer::HasPtrPointer(const HasPtrPointer &p)
    : ps_(p.ps_), i_(p.i_), use_(p.use_) {
  ++*use_;
}

HasPtrPointer& HasPtrPointer::operator=(const HasPtrPointer &rhs) {
  ++*rhs.use_;
  if (--*use_ == 0) {
    delete ps_;
    delete use_;
  }
  ps_ = rhs.ps_;
  i_ = rhs.i_;
  use_ = rhs.use_;
  return *this;
}

HasPtrPointer::~HasPtrPointer() {
  if (--*use_ == 0) {
    delete ps_;
    delete use_;
  }
}