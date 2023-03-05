#include "shell/domain.hpp"

using namespace shell;

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
