// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#include "utils.h"

#include <vector>

#include <gtest/gtest.h>

using namespace utils;

class FindMaxRepetitionCountTests : public ::testing::Test {};

TEST_F(FindMaxRepetitionCountTests, EmptyInput) {
  int count = FindMaxRepetitionCount({});
  EXPECT_EQ(count, 0);
}

TEST_F(FindMaxRepetitionCountTests, FirstExample) {
  int count = FindMaxRepetitionCount(
      {{"Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89},
       {"Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89},
       {"Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89},
       {"Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89},
       {"Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89}});
  EXPECT_EQ(count, 3);
}

TEST_F(FindMaxRepetitionCountTests, SecondExample) {
  int count = FindMaxRepetitionCount(
      {{"Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89},
       {"Russia",
        "Eurasia",
        {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
        89},
       {"Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
        89},
       {"Moscow",
        "Toulouse",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        89},
       {"Moscow",
        "Russia",
        {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
        31}});
  EXPECT_EQ(count, 1);
}
