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
         * @param required_variables Вектор указателей на переменные для вывода
         * @param positive_mask Вектор логических значений, отвечающий за сравнение на равенство или неравенство
         * @param conditions Вектор индексов значений в доменах, с которыми сравниваются значения переменных
         * @param target_variable Указатель на выводимую в правиле переменную
         * @param setindex Индекс, устанавливаемый в переменную при выполнении условия
         */
        template <typename TRequired = std::vector<std::shared_ptr<Variable>>,
                  typename TPositive = std::vector<bool>,
                  typename TConditions = std::vector<int>>
        Rule(TRequired &&required_variables,
             TPositive &&positive_mask,
             TConditions &&conditions,
             std::shared_ptr<Variable> target_variable,
             int setindex) : m_required_variables(std::forward<TRequired>(required_variables)),
                             m_positive_mask(std::forward<TPositive>(positive_mask)),
                             m_conditions(std::forward<TConditions>(conditions)),
                             m_target_variable(target_variable),
                             m_setindex(setindex)
        {
        }

        /**
         * @brief Проверка, является ли переменная выводимой в этом правиле
         * @param variable указатель на переменную, которую нужно проверить
         * @return true - если переменная выводится в правиле, false - иначе
         */
        bool deduces(std::shared_ptr<Variable> variable) const;

        /**
         * @brief Подтверждает выполнение условия и означивает целевую переменную
         */
        void confirm();

        /**
         * @brief Получение количества условий в правиле
         * @return Количество условий
         */
        int size() const;

        /**
         * @brief Проверка, означена ли переменная с указанным индексом
         * @param idx Индекс переменной
         * @return true - если переменная означена, false - иначе
         */
        bool known(int idx);

        /**
         * @brief Проверка выполнения условия под указанным номером
         * @param idx Номер условия
         * @return true - если условие выполнено, false - иначе
         */
        bool check_condition(int idx);

        const std::shared_ptr<Variable>& operator[](int idx);

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

        // Индекс, устанавливаемый в переменную при выполнении всех условий
        int m_setindex;
    };
}