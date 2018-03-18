// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#ifndef MOVAX01H_CPP_PRACTICE_ELEMENTARY_TEMPERATURE_TEMPERATURE_H_
#define MOVAX01H_CPP_PRACTICE_ELEMENTARY_TEMPERATURE_TEMPERATURE_H_

#include <vector>

namespace temperature {

double GetAverageValueFromArray(const std::vector<int>& array);

std::vector<int> GetValuesAboveAverage(const std::vector<int>& array);

std::vector<int> GetIndexesAboveAverage(const std::vector<int>& array);

} // namespace temperature

#endif  // MOVAX01H_CPP_PRACTICE_ELEMENTARY_TEMPERATURE_TEMPERATURE_H_
