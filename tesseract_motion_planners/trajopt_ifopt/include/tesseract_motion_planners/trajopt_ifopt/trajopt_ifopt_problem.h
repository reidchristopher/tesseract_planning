/**
 * @file trajopt_ifopt_problem.h
 * @brief
 *
 * @author Levi Armstrong
 * @date June 18, 2020
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
#ifndef TESSERACT_MOTION_PLANNERS_TRAJOPT_IFOPT_PROBLEM_H
#define TESSERACT_MOTION_PLANNERS_TRAJOPT_IFOPT_PROBLEM_H

#include <tesseract_common/macros.h>
TESSERACT_COMMON_IGNORE_WARNINGS_PUSH
#include <vector>
#include <memory>
TESSERACT_COMMON_IGNORE_WARNINGS_POP

#include <tesseract_environment/environment.h>
#include <trajopt_ifopt/variable_sets/joint_position_variable.h>
#include <trajopt_sqp/sqp_callback.h>

namespace tesseract_planning
{
enum class TrajOptIfoptTermType
{
  CONSTRAINT,
  SQUARED_COST,
  ABSOLUTE_COST
};

struct TrajOptIfoptProblem
{
  // LCOV_EXCL_START
  EIGEN_MAKE_ALIGNED_OPERATOR_NEW
  // LCOV_EXCL_STOP

  trajopt_sqp::SQPParameters opt_info;

  // These are required for Tesseract to configure Descartes
  tesseract_environment::Environment::ConstPtr environment;
  tesseract_scene_graph::SceneState env_state;

  // Kinematic Objects
  tesseract_kinematics::JointGroup::ConstPtr manip;

  std::vector<trajopt_sqp::SQPCallback::Ptr> callbacks;

  trajopt_sqp::QPProblem::Ptr nlp;
  std::vector<trajopt_ifopt::JointPosition::ConstPtr> vars;
};

}  // namespace tesseract_planning
#endif  // TESSERACT_MOTION_PLANNERS_TRAJOPT_IFOPT_PROBLEM_H
