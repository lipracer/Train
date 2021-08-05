#ifndef TRAIN_TEST_H
#define TRAIN_TEST_H

#include <functional>
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>

using TestCaseFuncDef =
    std::tuple<std::string, std::string, std::function<void(void)>>;

extern std::vector<TestCaseFuncDef> gTestCases;

struct TestCaseRegister {
  TestCaseRegister(const std::string &ClassStr, const std::string &CaseStr,
                   std::function<void(void)> func) {
    gTestCases.emplace_back(ClassStr, CaseStr, func);
  }
};

#define LL_FUNCTION_NAME(Class, Name) Class##Name
#define LL_CONCAT_TOKEN(name, cc) name##cc
#define UNIQUE_REG_NAME(counter) LL_CONCAT_TOKEN(REG_TEST_CASE, counter)

#define DECL_TEST_CASE_FUNC(Class, Name)                                       \
  extern void LL_FUNCTION_NAME(Class, Name)(void)

#define TEST(Class, Name)                                                      \
  DECL_TEST_CASE_FUNC(Class, Name);                                            \
  \
TestCaseRegister UNIQUE_REG_NAME(__COUNTER__)(#Class, #Name,                   \
                                              LL_FUNCTION_NAME(Class, Name));  \
  \
void LL_FUNCTION_NAME(Class, Name)(void)

#define EXPECT_EQ(lhs, rhs) std::euqal_to(lhs, rhs)

template <typename T, typename Alloc>
std::ostream &operator<<(std::ostream &os, const std::vector<T, Alloc> &vec) {
  std::stringstream ss;
  ss << "[";
  for (auto it : vec) {
    ss << it << ",";
  }
  if (!vec.empty()) {
    ss.seekp(-1, std::ios::cur);
  }
  ss << "]";
  return os << ss.str();
}

#endif // TRAIN_TEST_H
