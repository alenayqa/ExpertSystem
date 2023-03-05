#pragma once

#include <string>
#include <vector>
#include <iostream>
#include "shell/domain.hpp"

namespace shell
{
    enum class VariableType
    {
        REQUESTED,
        DEDUCED,
        HYBRID
    };

    class Variable
    {
    public:
        Variable() = default;
        Variable(const Variable &variable) = default;
        Variable &operator=(const Variable &variable) = default;
        Variable(Variable &&variable) = default;
        Variable &operator=(Variable &&variable) = default;

        /**
         * @brief Создание переменной
         * @param name Имя переменной
         * @param domain Домен
         * @param variable_type Тип переменной (запрашиваемая, выводимая, смешанный тип - VariableType::...)
         */
        template <typename TDomain = Domain>
        Variable(std::string name,
                 TDomain &&domain,
                 VariableType variable_type) : m_domain(std::forward<TDomain>(domain)),
                                               m_name(name),
                                               m_variable_type(variable_type)
        {
            m_index = -1;
        }

        std::string get_value();
        std::string get_name() const;
        int get_index() const;

        /**
         * @brief Метод, показывающий, известно ли значение переменной
         * @return true - если значение известно, false - иначе
         */
        bool known() const;

    private:
        // Индекс значения переменной в домене
        int m_index;

        Domain m_domain;
        std::string m_name;
        VariableType m_variable_type;
    };

}

std::ostream &operator<<(std::ostream &os, shell::Variable &variable);
