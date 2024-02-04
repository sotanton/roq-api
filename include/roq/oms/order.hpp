/* Copyright (c) 2017-2024, Hans Erik Thrane */

#pragma once

#include "roq/api.hpp"

#include "roq/precision_2.hpp"

namespace roq {
namespace oms {

//! Order (state)
struct ROQ_PUBLIC Order final {
  uint8_t user_id = {};
  uint16_t stream_id = {};
  Account account;
  uint64_t order_id = {};
  Exchange exchange;
  Symbol symbol;
  Side side = {};
  PositionEffect position_effect = {};
  MarginMode margin_mode = {};
  double max_show_quantity = NaN;
  OrderType order_type = {};
  TimeInForce time_in_force = {};
  Mask<ExecutionInstruction> execution_instructions;
  std::chrono::nanoseconds create_time_utc = {};
  std::chrono::nanoseconds update_time_utc = {};
  Account external_account;
  ExternalOrderId external_order_id;
  ClOrdId client_order_id;
  OrderStatus order_status = {};
  double quantity = NaN;
  double price = NaN;
  double stop_price = NaN;
  double risk_exposure = NaN;
  double remaining_quantity = NaN;
  double traded_quantity = NaN;
  double average_traded_price = NaN;
  double last_traded_price = NaN;
  double last_traded_quantity = NaN;
  Liquidity last_liquidity = {};
  RoutingId routing_id;
  uint32_t max_request_version = {};
  uint32_t max_response_version = {};
  uint32_t max_accepted_version = {};
  Precision2 quantity_precision;
  Precision2 price_precision;
  UpdateType update_type = {};
  User user;
  uint32_t strategy_id = {};
};

}  // namespace oms
}  // namespace roq

template <>
struct fmt::formatter<roq::oms::Order> {
  constexpr auto parse(format_parse_context &context) { return std::begin(context); }
  auto format(roq::oms::Order const &value, format_context &context) const {
    using namespace std::literals;
    return fmt::format_to(
        context.out(),
        R"({{)"
        R"(user_id={}, )"
        R"(account="{}", )"
        R"(order_id={}, )"
        R"(exchange="{}", )"
        R"(symbol="{}", )"
        R"(side={}, )"
        R"(position_effect={}, )"
        R"(margin_mode={}, )"
        R"(max_show_quantity={}, )"
        R"(order_type={}, )"
        R"(time_in_force={}, )"
        R"(execution_instructions={}, )"
        R"(create_time_utc={}, )"
        R"(update_time_utc={}, )"
        R"(external_account="{}", )"
        R"(external_order_id="{}", )"
        R"(client_order_id="{}", )"
        R"(order_status={}, )"
        R"(quantity={}, )"
        R"(price={}, )"
        R"(stop_price={}, )"
        R"(risk_exposure={}, )"
        R"(remaining_quantity={}, )"
        R"(traded_quantity={}, )"
        R"(average_traded_price={}, )"
        R"(last_traded_price={}, )"
        R"(last_traded_quantity={}, )"
        R"(last_liquidity={}, )"
        R"(routing_id="{}", )"
        R"(max_request_version={}, )"
        R"(max_response_version={}, )"
        R"(max_accepted_version={}, )"
        R"(quantity_precision={}, )"
        R"(price_precision={}, )"
        R"(update_type={}, )"
        R"(user="{}", )"
        R"(strategy_id={})"
        R"(}})"sv,
        value.user_id,
        value.account,
        value.order_id,
        value.exchange,
        value.symbol,
        value.side,
        value.position_effect,
        value.margin_mode,
        value.max_show_quantity,
        value.order_type,
        value.time_in_force,
        value.execution_instructions,
        value.create_time_utc,
        value.update_time_utc,
        value.external_account,
        value.external_order_id,
        value.client_order_id,
        value.order_status,
        value.quantity,
        value.price,
        value.stop_price,
        value.risk_exposure,
        value.remaining_quantity,
        value.traded_quantity,
        value.average_traded_price,
        value.last_traded_price,
        value.last_traded_quantity,
        value.last_liquidity,
        value.routing_id,
        value.max_request_version,
        value.max_response_version,
        value.max_accepted_version,
        value.quantity_precision,
        value.price_precision,
        value.update_type,
        value.user,
        value.strategy_id);
  }
};
