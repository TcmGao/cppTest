#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <fstream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

class QueryResult;

class TextQuery {
    public:
    using line_no_type = std::vector<std::string>::size_type;

    TextQuery(std::ifstream&);

    QueryResult query(const std::string&); 

    private:
    // 输入文件，按行保存，下标即行号
    std::shared_ptr<std::vector<std::string>> file_;
    // 单词到行号的映射
    std::map<std::string, std::shared_ptr<std::set<line_no_type>>> word_map_;
};

#endif