/* Copyright (c) 2017-2024, Hans Erik Thrane */

/* !!! THIS FILE HAS BEEN AUTO-GENERATED !!! */

#pragma once

#include <magic_enum.hpp>

#include <fmt/format.h>

namespace roq {

//! Enumeration of option types
enum class OptionType : uint8_t {
  UNDEFINED = 0,
  CALL,
  PUT,
};

}  // namespace roq

template <>
struct fmt::formatter<roq::OptionType> {
  constexpr auto parse(format_parse_context &context) { return std::begin(context); }
  auto format(roq::OptionType const &value, format_context &context) const {
    using namespace std::literals;
    return fmt::format_to(context.out(), "{}"sv, magic_enum::enum_name(value));
  }
};
