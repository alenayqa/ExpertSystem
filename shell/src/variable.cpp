#include "shell/variable.hpp"

using namespace shell;

bool Variable::known() const
{
    return m_index != -1;
}

void Variable::set_index(int index)
{
    m_index = index;
}

std::string Variable::get_name() const
{
    return m_name;
}

std::string Variable::get_value()
{
    if (m_index == -1)
    {
        return "";
    }
    return m_domain[m_index];
}

int Variable::get_index() const
{
    return m_index;
}

std::ostream &operator<<(std::ostream &os, shell::Variable &variable)
{

    return os << variable.get_name() << ": " << variable.get_value();
}
