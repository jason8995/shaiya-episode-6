#pragma once
#include <algorithm>
#include <limits>
#include <locale>
#include <ranges>
#include <string>
#include <string_view>
#include <type_traits>
#include "functional.hpp"

namespace ext {

    template<class Char, class UnaryPred>
    inline void ltrim_if(std::basic_string<Char>& str, UnaryPred pred)
    {
        str.erase(
            std::begin(str),
            std::find_if_not(std::begin(str), std::end(str), pred));
    }

    template<class Char, class UnaryPred>
    inline void rtrim_if(std::basic_string<Char>& str, UnaryPred pred)
    {
        str.erase(
            std::find_if_not(std::rbegin(str), std::rend(str), pred).base(),
            std::end(str));
    }

    template<class Char, class UnaryPred>
    inline void trim_if(std::basic_string<Char>& str, UnaryPred pred)
    {
        rtrim_if(str, pred);
        ltrim_if(str, pred);
    }

    template<class Char>
    inline void ltrim(std::basic_string<Char>& str, const std::locale& loc = std::locale())
    {
        ltrim_if(str, [&](const Char ch) {
            return std::isspace<Char>(ch, loc);
            });
    }

    template<class Char>
    inline void ltrim(std::basic_string<Char>& str, const Char ch)
    {
        ltrim_if(str, ext::unary_equal_to(ch));
    }

    template<class Char>
    inline void ltrim(std::basic_string<Char>& str, const Char* const ptr)
    {
        ltrim_if(str, [=](const Char ch) {
            return std::ranges::any_of(std::basic_string_view(ptr), ext::unary_equal_to(ch));
            });
    }

    template<class Char>
    inline void ltrim(std::basic_string<Char>& str, const std::basic_string_view<std::type_identity_t<Char>> view)
    {
        ltrim_if(str, [=](const Char ch) {
            return std::ranges::any_of(view, ext::unary_equal_to(ch));
            });
    }

    template<class Char>
    inline void rtrim(std::basic_string<Char>& str, const std::locale& loc = std::locale())
    {
        rtrim_if(str, [&](const Char ch) {
            return std::isspace<Char>(ch, loc);
            });
    }

    template<class Char>
    inline void rtrim(std::basic_string<Char>& str, const Char ch)
    {
        rtrim_if(str, ext::unary_equal_to(ch));
    }

    template<class Char>
    inline void rtrim(std::basic_string<Char>& str, const Char* const ptr)
    {
        rtrim_if(str, [=](const Char ch) {
            return std::ranges::any_of(std::basic_string_view(ptr), ext::unary_equal_to(ch));
            });
    }

    template<class Char>
    inline void rtrim(std::basic_string<Char>& str, const std::basic_string_view<std::type_identity_t<Char>> view)
    {
        rtrim_if(str, [=](const Char ch) {
            return std::ranges::any_of(view, ext::unary_equal_to(ch));
            });
    }

    template<class Char>
    inline void trim(std::basic_string<Char>& str, const std::locale& loc = std::locale())
    {
        trim_if(str, [&](const Char ch) {
            return std::isspace<Char>(ch, loc);
            });
    }

    template<class Char>
    inline void trim(std::basic_string<Char>& str, const Char ch)
    {
        trim_if(str, ext::unary_equal_to(ch));
    }

    template<class Char>
    inline void trim(std::basic_string<Char>& str, const Char* const ptr)
    {
        trim_if(str, [=](const Char ch) {
            return std::ranges::any_of(std::basic_string_view(ptr), ext::unary_equal_to(ch));
            });
    }

    template<class Char>
    inline void trim(std::basic_string<Char>& str, const std::basic_string_view<std::type_identity_t<Char>> view)
    {
        trim_if(str, [=](const Char ch) {
            return std::ranges::any_of(view, ext::unary_equal_to(ch));
            });
    }

    template<class Char, class UnaryPred>
    inline auto ltrim_copy_if(const std::basic_string<Char>& str, UnaryPred pred)
    {
        std::basic_string output(str);
        ltrim_if(output, pred);
        return output;
    }

    template<class Char, class UnaryPred>
    inline auto rtrim_copy_if(const std::basic_string<Char>& str, UnaryPred pred)
    {
        std::basic_string output(str);
        rtrim_if(output, pred);
        return output;
    }

    template<class Char, class UnaryPred>
    inline auto trim_copy_if(const std::basic_string<Char>& str, UnaryPred pred)
    {
        std::basic_string output(str);
        rtrim_if(output, pred);
        ltrim_if(output, pred);
        return output;
    }

    template<class Char>
    inline auto ltrim_copy(const std::basic_string<Char>& str, const std::locale& loc = std::locale())
    {
        return ltrim_copy_if(str, [&](const Char ch) {
            return std::isspace<Char>(ch, loc);
            });
    }

    template<class Char>
    inline auto ltrim_copy(const std::basic_string<Char>& str, const Char ch)
    {
        return ltrim_copy_if(str, ext::unary_equal_to(ch));
    }

    template<class Char>
    inline auto ltrim_copy(const std::basic_string<Char>& str, const Char* const ptr)
    {
        return ltrim_copy_if(str, [=](const Char ch) {
            return std::ranges::any_of(std::basic_string_view(ptr), ext::unary_equal_to(ch));
            });
    }

    template<class Char>
    inline auto ltrim_copy(const std::basic_string<Char>& str, const std::basic_string_view<std::type_identity_t<Char>> view)
    {
        return ltrim_copy_if(str, [=](const Char ch) {
            return std::ranges::any_of(view, ext::unary_equal_to(ch));
            });
    }

    template<class Char>
    inline auto rtrim_copy(const std::basic_string<Char>& str, const std::locale& loc = std::locale())
    {
        return rtrim_copy_if(str, [&](const Char ch) {
            return std::isspace<Char>(ch, loc);
            });
    }

    template<class Char>
    inline auto rtrim_copy(const std::basic_string<Char>& str, const Char ch)
    {
        return rtrim_copy_if(str, ext::unary_equal_to(ch));
    }

    template<class Char>
    inline auto rtrim_copy(const std::basic_string<Char>& str, const Char* const ptr)
    {
        return rtrim_copy_if(str, [=](const Char ch) {
            return std::ranges::any_of(std::basic_string_view(ptr), ext::unary_equal_to(ch));
            });
    }

    template<class Char>
    inline auto rtrim_copy(const std::basic_string<Char>& str, const std::basic_string_view<std::type_identity_t<Char>> view)
    {
        return rtrim_copy_if(str, [=](const Char ch) {
            return std::ranges::any_of(view, ext::unary_equal_to(ch));
            });
    }

    template<class Char>
    inline auto trim_copy(const std::basic_string<Char>& str, const std::locale& loc = std::locale())
    {
        return trim_copy_if(str, [&](const Char ch) {
            return std::isspace<Char>(ch, loc);
            });
    }

    template<class Char>
    inline auto trim_copy(const std::basic_string<Char>& str, const Char ch)
    {
        return trim_copy_if(str, ext::unary_equal_to(ch));
    }

    template<class Char>
    inline auto trim_copy(const std::basic_string<Char>& str, const Char* const ptr)
    {
        return trim_copy_if(str, [=](const Char ch) {
            return std::ranges::any_of(std::basic_string_view(ptr), ext::unary_equal_to(ch));
            });
    }

    template<class Char>
    inline auto trim_copy(const std::basic_string<Char>& str, const std::basic_string_view<std::type_identity_t<Char>> view)
    {
        return trim_copy_if(str, [=](const Char ch) {
            return std::ranges::any_of(view, ext::unary_equal_to(ch));
            });
    }

} // namespace ext

namespace ext {

    template<template<typename...> class Container, class Char>
    inline auto split(const std::basic_string<Char>& str, const std::basic_string_view<std::type_identity_t<Char>> sep, int max)
    {
        auto view = std::views::split(str, sep) | std::views::take(max);
        Container<std::basic_string<Char>> output;

        for (auto&& subrange : view)
        {
            output.insert(
                std::end(output), 
                std::basic_string<Char>(std::begin(subrange), std::end(subrange)));
        }

        return output;
    }

    template<template<typename...> class Container, class Char>
    inline auto split(const std::basic_string<Char>& str, const std::basic_string_view<std::type_identity_t<Char>> sep)
    {
        return split<Container>(str, sep, std::numeric_limits<int>::max());
    }

    template<template<typename...> class Container, class Char>
    inline auto split(const std::basic_string<Char>& str, const Char sep, int max)
    {
        return split<Container>(str, std::basic_string(1, sep), max);
    }

    template<template<typename...> class Container, class Char>
    inline auto split(const std::basic_string<Char>& str, const Char sep)
    {
        return split<Container>(str, std::basic_string(1, sep), std::numeric_limits<int>::max());
    }

    template<template<typename...> class Container, class Char>
    inline auto split(const std::basic_string<Char>& str, const Char* const sep, int max)
    {
        return split<Container>(str, std::basic_string_view(sep), max);
    }

    template<template<typename...> class Container, class Char>
    inline auto split(const std::basic_string<Char>& str, const Char* const sep)
    {
        return split<Container>(str, std::basic_string_view(sep), std::numeric_limits<int>::max());
    }

} // namespace ext
