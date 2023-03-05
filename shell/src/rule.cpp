#include "shell/rule.hpp"

using namespace shell;

bool Rule::deduces(std::shared_ptr<Variable> variable) const
{
    return m_target_variable == variable;
}

void Rule::confirm()
{
    m_target_variable->set_index(m_setindex);
}
