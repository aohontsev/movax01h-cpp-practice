// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#include "task_tracker.h"

#include <map>
#include <tuple>
#include <vector>

#include <gtest/gtest.h>

using namespace task_tracker;

class TeamTasksTest : public ::testing::Test {};

TEST_F(TeamTasksTest, GetPersonTasksInfo) {
  TeamTasks team_tasks;
  TasksInfo new_user_tasks = team_tasks.GetPersonTasksInfo("John Smith");
  EXPECT_EQ(new_user_tasks, TasksInfo{});
}

TEST_F(TeamTasksTest, AddNewTask) {
  std::string user_name = "John Smith";
  TeamTasks team_tasks;
  team_tasks.AddNewTask(user_name);

  TasksInfo user_tasks = team_tasks.GetPersonTasksInfo(user_name);
  EXPECT_EQ(user_tasks, TasksInfo({{TaskStatus::NEW, 1}}));
}

TEST_F(TeamTasksTest, PerformPersonTasks) {
  std::string user_name = "John Smith";
  TeamTasks team_tasks;

  team_tasks.AddNewTask(user_name);
  team_tasks.AddNewTask(user_name);
  team_tasks.AddNewTask(user_name);
  EXPECT_EQ(team_tasks.GetPersonTasksInfo(user_name),
            TasksInfo({{TaskStatus::NEW, 3}}));

  EXPECT_EQ(team_tasks.PerformPersonTasks(user_name, 1),
            std::make_tuple(TasksInfo({{TaskStatus::IN_PROGRESS, 1}}),
                            TasksInfo({{TaskStatus::NEW, 2}})));
  EXPECT_EQ(team_tasks.GetPersonTasksInfo(user_name),
            TasksInfo({{TaskStatus::NEW, 2}, {TaskStatus::IN_PROGRESS, 1}}));

  EXPECT_EQ(team_tasks.PerformPersonTasks(user_name, 2),
            std::make_tuple(TasksInfo({{TaskStatus::IN_PROGRESS, 2}}),
                            TasksInfo({{TaskStatus::IN_PROGRESS, 1}})));
  EXPECT_EQ(team_tasks.GetPersonTasksInfo(user_name),
            TasksInfo({{TaskStatus::IN_PROGRESS, 3}}));

  EXPECT_EQ(team_tasks.PerformPersonTasks(user_name, 0),
            std::make_tuple(TasksInfo(),
                            TasksInfo({{TaskStatus::IN_PROGRESS, 3}})));
  EXPECT_EQ(team_tasks.GetPersonTasksInfo(user_name),
            TasksInfo({{TaskStatus::IN_PROGRESS, 3}}));

  EXPECT_EQ(team_tasks.PerformPersonTasks(user_name, 3),
            std::make_tuple(TasksInfo({{TaskStatus::TESTING, 3}}),
                            TasksInfo()));
  EXPECT_EQ(team_tasks.GetPersonTasksInfo(user_name),
            TasksInfo({{TaskStatus::TESTING, 3}}));

  EXPECT_EQ(team_tasks.PerformPersonTasks(user_name, 3),
            std::make_tuple(TasksInfo({{TaskStatus::DONE, 3}}), TasksInfo()));
  EXPECT_EQ(team_tasks.GetPersonTasksInfo(user_name),
            TasksInfo({{TaskStatus::DONE, 3}}));
}

TEST_F(TeamTasksTest, BaseCase) {
  TeamTasks team_tasks;

  std::string person = "Alice";

  team_tasks.AddNewTasks(person, 5);
  EXPECT_EQ(team_tasks.PerformPersonTasks(person, 5),
            std::make_tuple(TasksInfo({{TaskStatus::IN_PROGRESS, 5}}),
                            TasksInfo()));
  EXPECT_EQ(team_tasks.PerformPersonTasks(person, 5),
            std::make_tuple(TasksInfo({{TaskStatus::TESTING, 5}}),
                            TasksInfo()));
  EXPECT_EQ(team_tasks.PerformPersonTasks(person, 1),
            std::make_tuple(TasksInfo({{TaskStatus::DONE, 1}}),
                            TasksInfo({{TaskStatus::TESTING, 4}})));
  team_tasks.AddNewTasks(person, 5);
  EXPECT_EQ(team_tasks.PerformPersonTasks(person, 2),
            std::make_tuple(TasksInfo({{TaskStatus::IN_PROGRESS, 2}}),
                            TasksInfo({{TaskStatus::NEW, 3},
                                       {TaskStatus::TESTING, 4}})));
  EXPECT_EQ(team_tasks.GetPersonTasksInfo(person),
            TasksInfo({{TaskStatus::NEW, 3},{TaskStatus::IN_PROGRESS, 2},
                       {TaskStatus::TESTING, 4},{TaskStatus::DONE, 1}}));
  EXPECT_EQ(team_tasks.PerformPersonTasks(person, 4),
            std::make_tuple(TasksInfo({{TaskStatus::IN_PROGRESS, 3},
                                       {TaskStatus::TESTING, 1}}),
                            TasksInfo({{TaskStatus::IN_PROGRESS, 1},
                                       {TaskStatus::TESTING, 4}})));
  EXPECT_EQ(team_tasks.GetPersonTasksInfo(person),
            TasksInfo({{TaskStatus::IN_PROGRESS, 4},{TaskStatus::TESTING,
                                                     5},
                       {TaskStatus::DONE, 1}}));
}
