/**
 * @file trajopt_default_solver_profile.cpp
 * @brief
 *
 * @author Levi Armstrong
 * @date December 13, 2020
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

#include <tesseract_motion_planners/trajopt/profile/trajopt_default_solver_profile.h>

namespace tesseract_planning
{
void TrajOptDefaultSolverProfile::apply(trajopt::ProblemConstructionInfo& pci) const
{
  pci.basic_info.convex_solver = convex_solver;
  pci.basic_info.convex_solver_config = convex_solver_config;
  pci.opt_info = opt_info;
  pci.callbacks = callbacks;
}

tinyxml2::XMLElement* TrajOptDefaultSolverProfile::toXML(tinyxml2::XMLDocument& /*doc*/) const { return nullptr; }

}  // namespace tesseract_planning
