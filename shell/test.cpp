#include <iostream>
#include <vector>

#include "shell/variable.hpp"
#include "shell/domain.hpp"

int main()
{
    std::vector<std::string> v = {"a", "b", "c"};

    shell::Domain dom1("dom1", v);
    shell::Domain dom2("dom2", std::move(v));
    shell::Domain dom3("dom3", {"x", "y", "z"});

    std::cout << dom1 << std::endl;
    std::cout << dom2 << std::endl;
    std::cout << dom3 << std::endl;

    shell::Variable var1("var1", std::move(dom1), shell::VariableType::REQUESTED);
}