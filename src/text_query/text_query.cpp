#include "text_query/text_query.h"
#include "text_query/query_result.h"
#include <fstream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

TextQuery::TextQuery(std::ifstream &is) : file_(new std::vector<std::string>) {
    std::string text;
    while (std::getline(is, text)) {
        // 保存文件当前行
        file_->push_back(text);
        line_no_type n = file_->size() - 1;
        std::istringstream line_is(text);
        // 分词
        std::string word;
        while (line_is >> word) {
            // 不存在则添加一项，符合map下标操作的特性
            auto &lines = word_map_[word];
            if (!lines) { // 第一次遇见word时，lines为自动初始化的值，需要重置
                lines.reset(new std::set<line_no_type>);
            }
            lines->insert(n);
        }

    }
}

QueryResult TextQuery::query(const std::string & str) {
    static std::shared_ptr<std::set<TextQuery::line_no_type>> nodata(new std::set<TextQuery::line_no_type>);
    
    auto loc = word_map_.find(str);
    if (loc == word_map_.end()) {
        // 没找到就返回一个空集合
        return QueryResult(str, nodata, file_);
    } else {
        return QueryResult(str, loc->second, file_);
    }
}