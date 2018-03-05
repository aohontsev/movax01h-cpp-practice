// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#include "temperature.h"

namespace temperature {

double GetAverageValueFromArray(const std::vector<int> &array) {
  long sum = 0;
  for (const int &item : array)
    sum += item;
  return 1.0 * sum / array.size();
}

std::vector<int> GetValuesAboveAverage(const std::vector<int> &array) {
  double average_temperature = GetAverageValueFromArray(array);
  std::vector<int> values;
  for (int i = 0; i < array.size(); i++) {
    if (array[i] > average_temperature)
      values.push_back(array[i]);
  }
  return values;
}

std::vector<int> GetIndexesAboveAverage(const std::vector<int> &array) {
  double average_temperature = GetAverageValueFromArray(array);
  std::vector<int> indexes;
  for (int i = 0; i < array.size(); i++) {
    if (array[i] > average_temperature)
      indexes.push_back(i);
  }
  return indexes;
}

} // namespace temperature
