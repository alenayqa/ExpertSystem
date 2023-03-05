#include "shell/rule.hpp"

using namespace shell;

bool Rule::deduces(std::shared_ptr<Variable> variable) const
{
    return m_target_variable == variable;
}
