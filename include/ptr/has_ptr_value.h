#ifndef PTR_HAS_PTR_VALUE
#define PTR_HAS_PTR_VALUE

#include <iostream>

/* class action as value
 * 
 */
class HasPtrValue {
public:
  HasPtrValue(const std::string &s = std::string())
      : ps_(new std::string(s)), i_(0) {}
  HasPtrValue(const HasPtrValue &p) : ps_(new std::string(*p.ps_)), i_(p.i_) {}

  // HasPtrValue& operator=(const HasPtrValue &);
  
  HasPtrValue& operator=(HasPtrValue);

  ~HasPtrValue();

  inline void swap(HasPtrValue &lhs, HasPtrValue &rhs) {
    using std::swap;
    swap(lhs.ps_, rhs.ps_);
    swap(lhs.i_, rhs.i_);
  }

private:
  std::string *ps_;
  int i_;
};

#endif