/**
 * @file taskflow_task_composer_future.cpp
 * @brief A taskflow task composer future implementation
 *
 * @author Levi Armstrong
 * @date August 18, 2020
 * @version TODO
 * @bug No known bugs
 *
 * @copyright Copyright (c) 2020, Southwest Research Institute
 *
 * @par License
 * Software License Agreement (Apache License)
 * @par
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * http://www.apache.org/licenses/LICENSE-2.0
 * @par
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <tesseract_task_composer/taskflow/taskflow_task_composer_future.h>

namespace tesseract_planning
{
TaskflowTaskComposerFuture::TaskflowTaskComposerFuture(
    std::shared_future<void> future,
    std::shared_ptr<const std::vector<std::unique_ptr<tf::Taskflow>>> container)
  : future_(std::move(future)), container_(std::move(container))
{
}

TaskflowTaskComposerFuture::~TaskflowTaskComposerFuture() = default;

void TaskflowTaskComposerFuture::clear()
{
  future_ = std::shared_future<void>();
  container_ = nullptr;
}

bool TaskflowTaskComposerFuture::valid() const { return future_.valid(); }

bool TaskflowTaskComposerFuture::ready() const
{
  return (future_.wait_for(std::chrono::seconds(0)) == std::future_status::ready);
}

void TaskflowTaskComposerFuture::wait() const { future_.wait(); }

std::future_status TaskflowTaskComposerFuture::waitFor(const std::chrono::duration<double>& duration) const
{
  return future_.wait_for(duration);
}

std::future_status
TaskflowTaskComposerFuture::waitUntil(const std::chrono::time_point<std::chrono::high_resolution_clock>& abs) const
{
  return future_.wait_until(abs);
}

TaskComposerFuture::UPtr TaskflowTaskComposerFuture::copy() const
{
  auto clone = std::make_unique<TaskflowTaskComposerFuture>();
  clone->future_ = future_;
  clone->container_ = container_;
  return clone;
}

}  // namespace tesseract_planning
