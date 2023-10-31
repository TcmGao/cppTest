#include "text_query/query_result.h"
#include "text_query/text_query.h"
#include "text_query/search.h"
#include <fstream>
#include <iostream>

namespace search {

void runQueries(std::ifstream &infile) {
  // infile 是要处理的文件
  TextQuery tq(infile);
  // 读取输入单词
  while (true) {
    std::cout << "enter word to look for, or q to quit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q") {
      break;
    }
    // print
    print(std::cout, tq.query(s));
  }
}
} // namespace search