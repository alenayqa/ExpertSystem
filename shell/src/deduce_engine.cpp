#include "shell/deduce_engine.hpp"

using namespace shell;

bool DeduceEngine::check_rule(Rule &rule)
{
    for (int i = 0; i < rule.size(); i++)
    {
        if (!rule.known(i))
        {
            // Рекурсивный вывод значения переменной
            if (!recursive_deduce(rule[i]))
            {
                // Если вывести переменную не получилось
                return false;
            }
        }
        // Если условие не выполняется
        if (!rule.check_condition(i))
        {
            return false;
        }
    }

    return true;
}

bool DeduceEngine::recursive_deduce(std::shared_ptr<Variable> target)
{
    if (target->known())
    {
        return true;
    }

    if (target->get_variable_type() == VariableType::REQUESTED)
    {

        int idx;
        do
        {
            target->ask();
            std::cin >> idx;
        } while (idx < 1 || idx > target->domain_size());

        target->set_index(idx - 1);
        return true;
    }
    else
    {

        for (auto &rule : m_rules)
        {
            // Проверка, что правило выводит требуемую переменную
            if (!rule.deduces(target))
            {
                continue;
            }

            if (check_rule(rule))
            {
                // Успешный вывод переменной и ее означивание
                rule.confirm();
                return true;
            }
        }
    }
    // Переменная не была выведена
    return false;
}