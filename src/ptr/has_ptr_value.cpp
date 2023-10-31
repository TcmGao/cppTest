#include "ptr/has_ptr_value.h"
#include <string>

// HasPtrValue& HasPtrValue::operator=(const HasPtrValue &rhs) {
//   auto new_p = new std::string(*rhs.ps_);
//   delete ps_;
//   ps_ = new_p;
//   i_ = rhs.i_;
//   return * this;
// }

HasPtrValue &HasPtrValue::operator=(HasPtrValue rhs) {
  swap(*this, rhs);
  return *this;
}

HasPtrValue::~HasPtrValue() {
  delete ps_;
}


int main() {
  HasPtrValue h;
  const HasPtrValue h1;
  h = h1;
}

