#ifndef PTR_STR_VEC_H
#define PTR_STR_VEC_H

#include <cstddef>
#include <memory>
#include <string>
#include <utility>
class StrVec {
public:
  StrVec() : elements_(nullptr), first_free_(nullptr), cap_(nullptr) {}
  StrVec(const StrVec &);
  StrVec(StrVec &&) noexcept;
  StrVec &operator=(const StrVec &);
  StrVec &operator=(StrVec &&);
   ~StrVec();
  void PushBack(const std::string &s);
  size_t Size() const { return first_free_ - elements_; }
  size_t Capacity() const { return cap_ - elements_; }
  std::string *begin() const { return elements_; }
  std::string *end() const { return first_free_; }

private:
  // 分配元素
  static std::allocator<std::string> alloc_;
  // 首元素地址
  std::string *elements_;
  // 第一个空闲空间地址
  std::string *first_free_;
  // 尾空间之后的位置
  std::string *cap_;

  // 检查
  bool CheckNAlloc();
  // 拷贝
  std::pair<std::string *, std::string *> AllocNCopy(const std::string *begin,
                                                     const std::string *end);
  // 释放空间
  bool Free();
  // 重新分配
  bool Reallocate();
};

#endif