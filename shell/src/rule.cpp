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

int Rule::size() const
{
    return m_required_variables.size();
}

bool Rule::known(int idx)
{
    return m_required_variables[idx]->known();
}

bool Rule::check_condition(int idx)
{
    bool success = m_required_variables[idx]->get_index() == m_conditions[idx];
    
    // Если нужно выполнить проверку на неравенство
    if (!m_positive_mask[idx])
    {
        success = !success;
    }
    return success;
}


const std::shared_ptr<Variable>& Rule::operator[](int idx)
{
    return m_required_variables[idx];
}

