#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>
#include "shell/rule.hpp"
#include "shell/variable.hpp"
#include "shell/domain.hpp"

namespace shell
{
    class DeduceEngine
    {
    public:
        DeduceEngine() = default;
        DeduceEngine(const DeduceEngine &deduce_engine) = default;
        DeduceEngine &operator=(const DeduceEngine &deduce_engine) = default;
        DeduceEngine(DeduceEngine &&deduce_engine) = default;
        DeduceEngine &operator=(DeduceEngine &&deduce_engine) = default;

        /**
         * @brief Создание механизма логического вывода
         * @param rules Вектор правил
         * @param target_variable Указатель на целевую переменную
         */
        template <typename TRules = std::vector<Rule>>
        DeduceEngine(TRules &&rules,
                     std::shared_ptr<Variable> target_variable) : m_rules(std::forward<TRules>(rules)),
                                                                  m_target_variable(target_variable)
        {
        }

        /**
         * @brief Вывод целевой переменной
         * @return true - если переменная была выведена, false - иначе
         */
        bool deduce()
        {
            recursive_deduce(m_target_variable);
            return m_target_variable->known();
        }

    private:
        bool check_rule(Rule& rule);
        bool recursive_deduce(std::shared_ptr<Variable> target);

        std::vector<Rule> m_rules;
        std::shared_ptr<Variable> m_target_variable;
    };
}