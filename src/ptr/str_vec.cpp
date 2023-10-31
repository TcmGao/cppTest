#include "ptr/str_vec.h"
#include <cstddef>
#include <memory>
#include <string>

void StrVec::PushBack(const std::string &s) {
  CheckNAlloc();
  // 构造s的副本
  new (first_free_++) std::string(s);
}

std::pair<std::string *, std::string *>
StrVec::AllocNCopy(const std::string *begin, const std::string *end) {
  auto data = alloc_.allocate(end - begin);
  return {data, std::uninitialized_copy(begin, end, data)};
}

bool StrVec::Free() {
  // 操作指针需要小心,空指针啥也不干
  if (elements_) {
    for (auto p = first_free_; p != elements_;) {
      (--p)->~basic_string<char>();
    }
    elements_->~basic_string<char>();
  }
  return true;
}

StrVec::StrVec(const StrVec &s) {
  auto new_data = AllocNCopy(s.begin(), s.end());
  elements_ = new_data.first;
  first_free_ = cap_ = new_data.second;
}

StrVec::StrVec(StrVec &&s) noexcept
    : elements_(s.elements_), first_free_(s.first_free_), cap_(s.cap_) {
  s.elements_ = s.first_free_ = s.cap_ = nullptr;
}

StrVec::~StrVec() { Free(); }

StrVec &StrVec::operator=(const StrVec &s) {
  auto new_data = AllocNCopy(s.begin(), s.end());
  Free();
  elements_ = new_data.first;
  first_free_ = cap_ = new_data.second;
  return *this;
}

StrVec &StrVec::operator=(StrVec &&s) {
  if (this != &s) {
    Free();
    elements_ = s.elements_;
    first_free_ = s.elements_;
    cap_ = s.cap_;
    s.elements_ = s.first_free_ = s.cap_ = nullptr;
  }
  return *this;
}

bool StrVec::Reallocate() {
  auto new_capacity = Size() ? 2 * Size() : 1;
  // 分配新内存
  auto new_data = alloc_.allocate(new_capacity);
  auto dest = new_data;
  for (auto iter = begin(); iter != end();) {
    new (dest++) std::string(std::move(*iter++));
  }
  Free();
  elements_ = new_data;
  first_free_ = dest;
  cap_ = elements_ + new_capacity;
  return true;
}