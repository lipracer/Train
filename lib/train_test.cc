#include "train_test.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>

std::vector<TestCaseFuncDef> gTestCases;

int main(int argc, char **argv) {
  for (auto &it : gTestCases) {
    std::cout << "[Test " << std::get<0>(it) << "] " << std::get<1>(it)
              << std::endl;
    std::get<2>(it)();
  }
  return 0;
}
