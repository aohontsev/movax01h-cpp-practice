// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#include "temperature.h"

#include <string>
#include <vector>

#include <gtest/gtest.h>

class TemperatureTests : public ::testing::Test {};

TEST_F(TemperatureTests, GetAverageValueFromArray) {
  std::vector<int> input = {1, 2, 3, 4};
  double output = 2.5;
  EXPECT_EQ(temperature::GetAverageValueFromArray(input), output);

  input = {-100000000, 0, 100000000};
  double output2 = 0;
  EXPECT_EQ(temperature::GetAverageValueFromArray(input), output2);

  std::vector<int> big_input(1000000, 100000000);
  double output3 = 100000000;
  EXPECT_EQ(temperature::GetAverageValueFromArray(big_input), output3);
}

TEST_F(TemperatureTests, GetValuesAboveAverage) {
  std::vector<int> input = {1, 2, 3, 4};
  std::vector<int> output = {3, 4};
  EXPECT_EQ(temperature::GetValuesAboveAverage(input), output);

  input = {-10, 9, -1, 0, 1};
  output = {9, 0, 1};
  EXPECT_EQ(temperature::GetValuesAboveAverage(input), output);

  input = {0};
  output = {};
  EXPECT_EQ(temperature::GetValuesAboveAverage(input), output);
}

TEST_F(TemperatureTests, GetIndexesAboveAverage) {
  std::vector<int> input = {1, 2, 3, 4};
  std::vector<int> output = {2, 3};
  EXPECT_EQ(temperature::GetIndexesAboveAverage(input), output);

  input = {0};
  output = {};
  EXPECT_EQ(temperature::GetIndexesAboveAverage(input), output);

  input = {};
  output = {};
  EXPECT_EQ(temperature::GetIndexesAboveAverage(input), output);

  input = {-100000000, 0, 1000000000};
  output = {2};
  EXPECT_EQ(temperature::GetIndexesAboveAverage(input), output);

  std::vector<int> big_input(1000000, 5);
  big_input.insert(big_input.begin(), 8);
  big_input.insert(big_input.begin() + 500000, 9);
  big_input.push_back(10);
  output = {0, 500000, 1000002};
  EXPECT_EQ(temperature::GetIndexesAboveAverage(big_input), output);
}
