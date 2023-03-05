#include "shell/domain.hpp"

using namespace shell;

void Domain::ask()
{
    for (int i = 0; i < m_values.size(); i++)
    {
        std::cout << i + 1 << ": " << m_values[i] << std::endl;
    }
}

int Domain::size() const
{
    return m_values.size();
}

std::string Domain::get_name() const
{
    return m_name;
}

std::string& Domain::operator[](int idx)
{
    return m_values[idx];
}

std::ostream &operator<<(std::ostream &os, const shell::Domain &domain)
{
    return os << domain.get_name();
}
