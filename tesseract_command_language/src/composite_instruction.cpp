#include <tesseract_command_language/composite_instruction.h>
#include <tesseract_command_language/plan_instruction.h>
#include <stdexcept>
#include <iostream>

namespace tesseract_planning
{
CompositeInstruction::CompositeInstruction(std::string profile, CompositeInstructionOrder order)
  : profile_(std::move(profile)), order_(order)
{
}

CompositeInstructionOrder CompositeInstruction::getOrder() const { return order_; }

int CompositeInstruction::getType() const { return type_; }

const std::string& CompositeInstruction::getDescription() const { return description_; }

void CompositeInstruction::setDescription(const std::string& description) { description_ = description; }

void CompositeInstruction::setProfile(const std::string& profile)
{
  profile_ = (profile.empty()) ? "DEFAULT" : profile;
}
const std::string& CompositeInstruction::getProfile() const { return profile_; }

void CompositeInstruction::setStartInstruction(Instruction instruction) { start_instruction_ = instruction; }

void CompositeInstruction::resetStartInstruction() { start_instruction_ = NullInstruction(); }

const Instruction& CompositeInstruction::getStartInstruction() const { return start_instruction_; }

Instruction& CompositeInstruction::getStartInstruction() { return start_instruction_; }

bool CompositeInstruction::hasStartInstruction() const { return (!isNullInstruction(start_instruction_)); }

void CompositeInstruction::print(std::string prefix) const
{
  std::cout << prefix + "Composite Instruction, Description: " << getDescription() << std::endl;
  std::cout << prefix + "--- Start Instruction, Description: " << start_instruction_.getDescription() << std::endl;
  std::cout << prefix + "{" << std::endl;
  for (const auto& i : *this)
    i.print(prefix + "  ");
  std::cout << prefix + "}" << std::endl;
}

}  // namespace tesseract_planning
