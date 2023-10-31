#ifndef TEXT_QUERY_RESULT_H
#define TEXT_QUERY_RESULT_H

#include "text_query/text_query.h"
#include <memory>
#include <ostream>
#include <set>
#include <string>
#include <vector>

class QueryResult {
friend std::ostream& print(std::ostream&, const QueryResult&);

public:
  QueryResult(std::string s,
              std::shared_ptr<std::set<TextQuery::line_no_type>> p,
              std::shared_ptr<std::vector<std::string>> f)
      : query_(s), lines_(p), file_(f) {}

private:
  // 查询词
  std::string query_;
  // 行号集合
  std::shared_ptr<std::set<TextQuery::line_no_type>> lines_;
  // 文件
  std::shared_ptr<std::vector<std::string>> file_;
};
std::ostream &print(std::ostream &, const QueryResult &);

#endif