#include "text_query/query_result.h"
#include <ostream>

std::ostream& print(std::ostream& os, const QueryResult &qr) {
    os << qr.query_ << " occurs " << qr.lines_->size() << " times" << std::endl;

    for (auto num : *qr.lines_) {
        os << "\tline(line " << num + 1 << ")" << *(qr.file_->begin() + num) << std::endl;
    }
    return os;
}