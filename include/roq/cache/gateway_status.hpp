/* Copyright (c) 2017-2022, Hans Erik Thrane */

#pragma once

#include "roq/api.hpp"

#include "roq/mask.hpp"

#include "roq/utils/update.hpp"

namespace roq {
namespace cache {

struct GatewayStatus final {
  GatewayStatus() = default;

  GatewayStatus(const GatewayStatus &) = delete;
  GatewayStatus(GatewayStatus &&) = default;

  void clear() {
    supported.reset();
    available.reset();
    unavailable.reset();
  }

  [[nodiscard]] bool operator()(const roq::GatewayStatus &gateway_status) {
    auto dirty = false;
    dirty |= utils::update(supported, gateway_status.supported);
    dirty |= utils::update(available, gateway_status.available);
    dirty |= utils::update(unavailable, gateway_status.unavailable);
    return dirty;
  }

  [[nodiscard]] bool operator()(const Event<roq::GatewayStatus> &event) { return (*this)(event.value); }

  template <typename Context>
  [[nodiscard]] roq::GatewayStatus convert(const Context &context) const {
    return {
        .account = context.account,
        .supported = supported,
        .available = available,
        .unavailable = unavailable,
    };
  }
  [[nodiscard]] roq::GatewayStatus convert() const {
    return {
        .account = {},
        .supported = supported,
        .available = available,
        .unavailable = unavailable,
    };
  }

  Mask<SupportType> supported;
  Mask<SupportType> available;
  Mask<SupportType> unavailable;
};

}  // namespace cache
}  // namespace roq
