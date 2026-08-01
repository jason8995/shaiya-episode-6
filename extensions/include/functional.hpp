#pragma once

namespace ext {

    template<class T>
    struct unary_equal_to
    {
        explicit unary_equal_to(const T& rhs)
            : m_rhs(rhs)
        {
        }

        template<class U>
        constexpr bool operator()(const U& lhs) const
        {
            return lhs == m_rhs;
        }

    private:

        T m_rhs;
    };

} // namespace ext
