// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#include "utils.h"

namespace utils {

bool operator<(const Region &lhs, const Region &rhs) {
  return std::tie(lhs.std_name, lhs.parent_std_name, lhs.names,
                  lhs.population) <
         std::tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const std::vector<Region> &regions) {
  std::map<Region, int> regions_count;
  for (const Region &region : regions) {
    auto search = regions_count.find(region);
    if (search != regions_count.end()) {
      search->second = search->second + 1;
    } else {
      regions_count.insert(std::pair<Region, int>(region, 1));
    }
  }

  int max_count = 0;
  for (auto item : regions_count) {
    if (item.second > max_count)
      max_count = item.second;
  }
  return max_count;
}

} // namespace utils
