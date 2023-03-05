#pragma once

#include <vector>
#include <string>

namespace shell
{
    class Domain
    {
    public:
        Domain() = default;
        Domain(const Domain &domain) = default;
        Domain(Domain &&domain) = default;
        Domain &operator=(const Domain &domain) = default;
        Domain &operator=(Domain &&domain) = default;

        /**
         * @brief Создание домена
         * @param name Имя домена
         * @param values Множество допустимых значений
         */
        template <typename TDomain = std::vector<std::string>>
        Domain(std::string name, TDomain &&values) : m_name(name),
                                                     m_values(std::forward<TDomain>(values))
        {
        }

        std::string get_name() const;
        std::string &operator[](int idx);

    private:
        std::string m_name;
        std::vector<std::string> m_values;
    };
}

std::ostream &operator<<(std::ostream &os, const shell::Domain &domain);
