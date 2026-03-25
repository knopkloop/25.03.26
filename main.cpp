#include "pe-vector.hpp"
#include <iostream>

using knk::Vector;

bool testConstructAndDestruct(const char ** pname)
{
  *pname = __func__;
  knk::Vector< int > v;
  return true;
}

bool testDefaultVectorIsEmpty(const char ** pname)
{
  *pname = __func__;
  Vector< int > v;
  return v.isEmpty();
}

int main()
{
  using test_t = bool(*)(const char **);
  test_t tests[] = {
    testConstructAndDestruct,
    testDefaultVectorIsEmpty
  };

  constexpr size_t count = sizeof(tests) / sizeof(test_t);
  for (size_t i = 0; i < count; ++i)
  {
    const char * testName = nullptr;
    bool r = tests[i](&testName);
    if (!r)
    {
      std::cout << "Failed: " << testName << "\n";
    }
  }
}
