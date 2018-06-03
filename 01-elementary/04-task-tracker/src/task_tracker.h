// Copyright (c) 2018.
// Author: Anton Okhontsev <anton.ohontsev@gmail.com>

#ifndef MOVAX01H_CPP_PRACTICE_ELEMENTARY_TASK_TRACKER_TASK_TRACKER_H_
#define MOVAX01H_CPP_PRACTICE_ELEMENTARY_TASK_TRACKER_TASK_TRACKER_H_

#include <iostream>
#include <map>
#include <tuple>
#include <utility>

namespace task_tracker {

enum class TaskStatus {
  NEW,
  IN_PROGRESS,
  TESTING,
  DONE
};

typedef std::map<TaskStatus, int> TasksInfo;

// The TeamTasks class, which allows storing statistics on the statuses of
// tasks of the development team.
class TeamTasks {
 public:
  // Get tasks status statistics of a particular developer
  const TasksInfo& GetPersonTasksInfo(const std::string& person);

  // Add a new task (in the status NEW) for a particular developer.
  void AddNewTask(const std::string& person);

  // Add a new tasks (in the status NEW) for a particular developer.
  void AddNewTasks(const std::string& person, const int& count);

  // Update statuses for this number of tasks for a specific developer.
  // Let's consider all the tasks of the developer person.
  // Order them by status: first all tasks in the status NEW, then all tasks
  // in the status IN_PROGRESS and, finally, tasks in the status TESTING.
  // Consider the first tasks_count of tasks and translate each of them to
  // the next status in accordance with the natural order:
  // NEW → IN_PROGRESS → TESTING → DONE.
  // We return a tuple of two elements: information about the statuses of the
  // updated tasks (including those that turned out to be DONE status) and
  // information about the statuses of other tasks that were not performed.
  std::tuple<TasksInfo, TasksInfo> PerformPersonTasks(const std::string& person,
                                                      int task_count);

 private:
  // Map of developer name and his tasks.
  std::map<std::string, TasksInfo> team_tasks_;
};

} // namespace task_tracker

#endif // MOVAX01H_CPP_PRACTICE_ELEMENTARY_TASK_TRACKER_TASK_TRACKER_H_
