// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#include "task_tracker.h"

#include <tuple>
#include <vector>

namespace task_tracker {

namespace {

void ClearFromEmptyStatuses(TasksInfo& tasks_info) {
  std::vector<TaskStatus> empty_statuses;
  for (auto item : tasks_info) {
    if (item.second == 0)
      empty_statuses.push_back(item.first);
  }

  for (auto item : empty_statuses)
    tasks_info.erase(item);
}

} // namespace

const TasksInfo& TeamTasks::GetPersonTasksInfo(const std::string& person) {
  return team_tasks_[person];
}

void TeamTasks::AddNewTask(const std::string& person) {
  team_tasks_[person][TaskStatus::NEW]++;
};

void TeamTasks::AddNewTasks(const std::string& person, const int& count) {
  team_tasks_[person][TaskStatus::NEW] =
      team_tasks_[person][TaskStatus::NEW] + count;
};

std::tuple<TasksInfo, TasksInfo>
TeamTasks::PerformPersonTasks(const std::string& person, int task_count) {
  TasksInfo user_tasks = team_tasks_[person];
  TasksInfo updated_tasks;

  while (task_count > 0) {
    if (user_tasks[TaskStatus::NEW] > 0) {
      user_tasks[TaskStatus::NEW]--;
      updated_tasks[TaskStatus::IN_PROGRESS]++;
    } else if (user_tasks[TaskStatus::IN_PROGRESS] > 0) {
      user_tasks[TaskStatus::IN_PROGRESS]--;
      updated_tasks[TaskStatus::TESTING]++;
    } else if (user_tasks[TaskStatus::TESTING] > 0) {
      user_tasks[TaskStatus::TESTING]--;
      updated_tasks[TaskStatus::DONE]++;
    } else {
      break;
    }
    --task_count;
  }

  TasksInfo not_performed_tasks = user_tasks;

  for (auto item : updated_tasks)
    user_tasks[item.first] = user_tasks[item.first] + item.second;

  ClearFromEmptyStatuses(user_tasks);
  ClearFromEmptyStatuses(updated_tasks);
  ClearFromEmptyStatuses(not_performed_tasks);

  not_performed_tasks.erase(TaskStatus::DONE);

  team_tasks_[person] = user_tasks;

  return {updated_tasks, not_performed_tasks};
}

} // namespace task_tracker
