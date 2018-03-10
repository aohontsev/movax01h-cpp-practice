// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#include "blocks.h"

#include <string>
#include <vector>

#include <gtest/gtest.h>

class BlocksTests : public ::testing::Test {};

TEST_F(BlocksTests, CreateBlock) {
  blocks::Block block(10, 20, 30, 5);
  EXPECT_EQ(block.GetMass(), 10 * 20 * 30 * 5);
}

TEST_F(BlocksTests, CreateEmptyBlock) {
  blocks::Block block(0, 0, 0, 0);
  EXPECT_EQ(block.GetMass(), 0);
}

TEST_F(BlocksTests, GetMaxBlockMass) {
  blocks::Block block(10000, 10000, 10000, 100);
  EXPECT_EQ(block.GetMass(), 100000000000000ll);
}

class SumMassBlocksTests : public ::testing::Test {};

TEST_F(SumMassBlocksTests, GetMaxSum) {
  std::vector<blocks::Block> input_blocks;
  for (int i = 0; i < 100000; ++i)
    input_blocks.push_back(blocks::Block(10000, 10000, 10000, 100));
  EXPECT_EQ(blocks::GetSumMassBlocks(input_blocks), 10000000000000000000ull);
}
