/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

#include "common/lang/comparator.h"
#include "common/lang/sstream.h"
#include "common/log/log.h"
#include "common/type/integer_type.h"
#include "common/value.h"

int IntegerType::compare(const Value &left, const Value &right) const
{
  ASSERT(left.attr_type() == AttrType::INTS, "left type is not integer");
  ASSERT(right.attr_type() == AttrType::INTS || right.attr_type() == AttrType::FLOATS, "right type is not numeric");
  if (right.attr_type() == AttrType::INTS) {
    return common::compare_int((void *)&left.value_.int_value_, (void *)&right.value_.int_value_);
  }
  if (right.attr_type() == AttrType::FLOATS) {
    float left_val  = left.get_float();
    float right_val = right.get_float();
    return common::compare_float((void *)&left_val, (void *)&right_val);
  }
  return INT32_MAX;
}

RC IntegerType::add(const Value &left, const Value &right, Value &result) const
{
  result.set_int(left.get_int() + right.get_int());
  return RC::SUCCESS;
}

RC IntegerType::subtract(const Value &left, const Value &right, Value &result) const
{
  result.set_int(left.get_int() - right.get_int());
  return RC::SUCCESS;
}

RC IntegerType::multiply(const Value &left, const Value &right, Value &result) const
{
  result.set_int(left.get_int() * right.get_int());
  return RC::SUCCESS;
}

RC IntegerType::negative(const Value &val, Value &result) const
{
  result.set_int(-val.get_int());
  return RC::SUCCESS;
}

RC IntegerType::set_value_from_str(Value &val, const string &data) const
{
  RC           rc = RC::SUCCESS;
  stringstream deserialize_stream;
  deserialize_stream.clear();  // 清理stream的状态，防止多次解析出现异常
  deserialize_stream.str(data);
  int int_value;
  deserialize_stream >> int_value;
  if (!deserialize_stream || !deserialize_stream.eof()) {
    rc = RC::SCHEMA_FIELD_TYPE_MISMATCH;
  } else {
    val.set_int(int_value);
  }
  return rc;
}

RC IntegerType::to_string(const Value &val, string &result) const
{
  result = std::to_string(val.get_int());
  return RC::SUCCESS;
}

int IntegerType::cast_cost(AttrType type)
{
  if (type == AttrType::INTS)
    return 0;  // INT -> INT
  if (type == AttrType::FLOATS)
    return 1;  // INT -> FLOAT
  if (type == AttrType::BOOLEANS)
    return 1;        // INT -> BOOL (非严格转换)
  return INT32_MAX;  // 不支持转换
}

RC IntegerType::cast_to(const Value &val, AttrType type, Value &result, bool allow_type_promotion) const
{
  switch (type) {
    case AttrType::INTS: {
      result.set_int(val.get_int());
    } break;
    case AttrType::FLOATS: {
      // 整数转浮点数，直接转换为浮点数，不考虑溢出
      result.set_float(static_cast<float>(val.get_int()));
    } break;
    case AttrType::BOOLEANS: {
      // 0 为 false，其他为 true
      result.set_boolean(val.get_int() != 0);
    } break;
    case AttrType::CHARS: {
      // 数字转字符串，不带符号，不考虑长度溢出
      int         int_val = val.get_int();
      std::string str     = int_val < 0 ? std::to_string(-int_val) : std::to_string(int_val);
      result.set_string(str.c_str());  // 设置字符串结果
      break;
    } break;
    default: return RC::UNSUPPORTED;  // 不支持的转换
  }
  return RC::SUCCESS;
}
