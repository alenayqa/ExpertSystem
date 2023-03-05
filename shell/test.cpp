#include <iostream>
#include <vector>

#include "shell/variable.hpp"
#include "shell/domain.hpp"
#include "shell/rule.hpp"
#include "shell/deduce_engine.hpp"

int main()
{

    std::vector<std::string> input_values = {"a", "b"};
    std::vector<std::string> output_values = {"aa", "ab", "ba", "bb"};

    shell::Domain input_domain("input domain", std::move(input_values));
    shell::Domain output_domain("output domain", std::move(output_values));

    std::shared_ptr<shell::Variable> x =
        std::make_shared<shell::Variable>("x",
                                          input_domain,
                                          shell::VariableType::REQUESTED,
                                          "Какое значение первой переменной?");

    std::shared_ptr<shell::Variable> y =
        std::make_shared<shell::Variable>("y",
                                          input_domain,
                                          shell::VariableType::REQUESTED,
                                          "Какое значение второй переменной?");

    std::shared_ptr<shell::Variable> z =
        std::make_shared<shell::Variable>("z",
                                          output_domain,
                                          shell::VariableType::DEDUCED);

    shell::Rule R1({x, y},
                   {1, 1},
                   {0, 0},
                   z,
                   0);

    shell::Rule R2({x, y},
                   {1, 1},
                   {0, 1},
                   z,
                   1);

    shell::Rule R3({x, y},
                   {1, 1},
                   {1, 0},
                   z,
                   2);

    shell::Rule R4({x, y},
                   {1, 1},
                   {1, 1},
                   z,
                   3);

    shell::DeduceEngine deduce_engine({R1, R2, R3, R4}, z);
    deduce_engine.deduce();

    std::cout << z->get_value() << std::endl;
}