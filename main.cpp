#include <iostream>
#include <fstream>
#include <vector>
#include "include/text_query/search.h"

int main() {
  // std::ifstream infile("/home/untcm/develop/data/word.txt");
  // search::runQueries(infile);
  using std::swap;
  int i = 1, j = 2;
  int *p1 = &i, *p2 = &j;
  swap(p1, p2);
  std::cout << "i=" << i << " j=" << j << std::endl;
  return 0;
}

void test() {
    std::vector<int> vec;
}