// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#ifndef MOVAX01H_CPP_PRACTICE_ELEMENTARY_TUPLES_AND_PAIRS_UTILS_H_
#define MOVAX01H_CPP_PRACTICE_ELEMENTARY_TUPLES_AND_PAIRS_UTILS_H_

#include <iostream>
#include <map>

namespace utils {

enum class Lang { DE, FR, IT };

struct Region {
  std::string std_name;
  std::string parent_std_name;
  std::map<Lang, std::string> names;
  int64_t population;
};

bool operator<(const Region &lhs, const Region &rhs);

int FindMaxRepetitionCount(const std::vector<Region> &regions);

} // namespace utils

#endif // MOVAX01H_CPP_PRACTICE_ELEMENTARY_TUPLES_AND_PAIRS_UTILS_H_
