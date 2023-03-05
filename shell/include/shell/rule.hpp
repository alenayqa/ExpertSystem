#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "shell/variable.hpp"

namespace shell
{
    class Rule
    {
    public:
        Rule() = default;
        Rule(const Rule &rule) = default;
        Rule(Rule &&rule) = default;
        Rule &operator=(const Rule &rule) = default;
        Rule &operator=(Rule &&rule) = default;

        /**
         * @brief Создание правила
         * @param required_variables вектор указателей на переменные для вывода
         * @param positive_mask вектор логических значений, отвечающий за сравнение на равенство или неравенство
         * @param conditions вектор индексов значений в доменах, с которыми сравниваются значения переменных
         * @param target_variable указатель на выводимую в правиле переменную
        */
        template <typename TRequired = std::vector<std::shared_ptr<Variable>>,
                  typename TPositive = std::vector<bool>,
                  typename TConditions = std::vector<int>>
        Rule(TRequired &&required_variables,
             TPositive &&positive_mask,
             TConditions &&conditions,
             std::shared_ptr<Variable> target_variable) : m_required_variables(std::forward<TRequired>(required_variables)),
                                                          m_positive_mask(std::forward<TPositive>(positive_mask)),
                                                          m_conditions(std::forward<TConditions>(conditions)),
                                                          m_target_variable(target_variable)
        {
        }

        /**
         * @brief Проверка, является ли переменная выводимой в этом правиле
         * @param variable указатель на переменную, которую нужно проверить
         * @return true - если переменная выводится в правиле, false - иначе
         */
        bool deduces(std::shared_ptr<Variable> variable) const;

    private:
        // Переменные, необходимые для вывода
        std::vector<std::shared_ptr<Variable>> m_required_variables;

        // Маска, отвечающая за пололожительность условий
        // (true, если сравнивается на равенство, false - иначе)
        std::vector<bool> m_positive_mask;

        // Индексы ответов в своих доменах,
        // т.е. если переменная имеет номер i, домен состоит из значений
        // {"x", "y", "z"} и проверяется равенство переменной на "y",
        // то m_conditions[i] равно 1 (1 - индекс "y" в домене)
        std::vector<int> m_conditions;

        // Переменная, которая выводится в правиле
        std::shared_ptr<Variable> m_target_variable;
    };
}