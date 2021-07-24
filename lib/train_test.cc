#include "train_test.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>

std::vector<TestCaseFuncDef> gTestCases;

int main(int argc, char **argv) {
  for (auto &it : gTestCases) {
    it();
  }
  return 0;
}
