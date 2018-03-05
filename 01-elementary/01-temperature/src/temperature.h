// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#ifndef TEMPERATURE_HANDLER_H_
#define TEMPERATURE_HANDLER_H_

#include <vector>

namespace temperature {

double GetAverageValueFromArray(const std::vector<int>& array);

std::vector<int> GetValuesAboveAverage(const std::vector<int>& array);

std::vector<int> GetIndexesAboveAverage(const std::vector<int>& array);

} // namespace temperature

#endif // TEMPERATURE_HANDLER_H_