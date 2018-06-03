// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#include "task_tracker.h"

#include <tuple>
#include <vector>

namespace task_tracker {

namespace {

void ClearFromEmptyStatuses(TasksInfo& tasks_info) {
  for (auto it = tasks_info.cbegin(); it != tasks_info.cend();) {
    if (it->second == 0)
      it = tasks_info.erase(it);
    else
      ++it;
  }
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

  for (auto it = updated_tasks.cbegin(); it != updated_tasks.cend(); ++it)
    user_tasks[it->first] = user_tasks[it->first] + it->second;

  ClearFromEmptyStatuses(user_tasks);
  ClearFromEmptyStatuses(updated_tasks);
  ClearFromEmptyStatuses(not_performed_tasks);

  not_performed_tasks.erase(TaskStatus::DONE);

  team_tasks_[person] = user_tasks;

  return {updated_tasks, not_performed_tasks};
}

} // namespace task_tracker
