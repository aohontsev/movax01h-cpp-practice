// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#include "main.cc"

#include <gtest/gtest.h>

class MainFuncTest : public ::testing::Test {};

TEST_F(MainFuncTest, CorrectStream) {
  std::istringstream str("01/01/18 02/01/18 15/01/18 19/05/18 31/12/18");
  EXPECT_EQ(main_func(&str), MainFuncExitCodes::SUCCESS);
}

TEST_F(MainFuncTest, MinimumStream) {
  std::istringstream str("01/01/18 31/12/18");
  EXPECT_EQ(main_func(&str), MainFuncExitCodes::SUCCESS);
}

TEST_F(MainFuncTest, ReverseStream) {
  std::istringstream str("31/12/18 19/05/18 15/01/18 02/01/18 01/01/18");
  EXPECT_EQ(main_func(&str), MainFuncExitCodes::INPUT_STREAM_IS_NOT_SORTED);
}

TEST_F(MainFuncTest, EmptyStream) {
  std::istringstream str("");
  EXPECT_EQ(main_func(&str), MainFuncExitCodes::INPUT_STREAM_IS_EMPTY);
}

TEST_F(MainFuncTest, IncorrectStream) {
  std::istringstream str("\n%\\$");
  EXPECT_EQ(main_func(&str), MainFuncExitCodes::BOUNDARY_VALUE_NOT_FOUND);
}

TEST_F(MainFuncTest, WithoutEndingValueStream) {
  std::istringstream str("01/01/18 02/01/18 15/01/18 19/05/18");
  EXPECT_EQ(main_func(&str), MainFuncExitCodes::BOUNDARY_VALUE_NOT_FOUND);
}

TEST_F(MainFuncTest, WithoutStartingValueStream) {
  std::istringstream str("02/01/18 15/01/18 19/05/18 31/12/18");
  EXPECT_EQ(main_func(&str), MainFuncExitCodes::BOUNDARY_VALUE_NOT_FOUND);
}
