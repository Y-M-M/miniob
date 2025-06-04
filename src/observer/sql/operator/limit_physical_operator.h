#include "sql/operator/physical_operator.h"
#include "sql/expr/tuple.h"
#include <functional>
#include <queue>

class LimitPhysicalOperator : public PhysicalOperator
{
public:
  LimitPhysicalOperator(int limit) : limit_(limit) {}

  virtual ~LimitPhysicalOperator() = default;

  PhysicalOperatorType type() const override { return PhysicalOperatorType::LIMIT; }

  int limit() const { return limit_; }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  Tuple *current_tuple() override;

private:
  int pos_ = 0;
  int limit_;
};
