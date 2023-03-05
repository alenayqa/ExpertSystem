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
         * @param question Вопрос
         * @param domain Домен
         * @param variable_type Тип переменной (запрашиваемая, выводимая, смешанный тип - VariableType::...)
         */
        template <typename TDomain = Domain>
        Variable(std::string name,
                 TDomain &&domain,
                 VariableType variable_type,
                 std::string question = "") : m_name(name),
                                              m_domain(std::forward<TDomain>(domain)),
                                              m_variable_type(variable_type),
                                              m_question(question),
                                              m_index(-1)
        {
        }

        /**
         * @brief Метод, показывающий, известно ли значение переменной
         * @return true - если значение известно, false - иначе
         */
        bool known() const;

        /**
         * @brief Присвоить переменной значение из домена
         * @param index Индекс значения в домене
         */
        void set_index(int index);

        /**
         * @brief Задать вопрос
         */
        void ask();

        /**
         * @brief Определение количества значений в домене
         * @return Количество возможных значенией
         */
        int domain_size() const;

        std::string get_value();
        std::string get_name() const;
        int get_index() const;
        VariableType get_variable_type() const;

    private:
        // Индекс значения переменной в домене
        int m_index;

        Domain m_domain;
        std::string m_name;
        std::string m_question;
        VariableType m_variable_type;
    };

}

std::ostream &operator<<(std::ostream &os, shell::Variable &variable);
