#pragma once

#include "sql/operator/logical_operator.h"

class LimitLogicalOperator : public LogicalOperator
{
public:
  LimitLogicalOperator(int limit) : limit_(limit) {}

  LogicalOperatorType type() const override { return LogicalOperatorType::LIMIT; }

  int limit() const { return limit_; }

private:
  int limit_;
};