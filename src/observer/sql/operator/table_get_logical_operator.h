/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/12/07.
//
#pragma once

#include "sql/operator/logical_operator.h"
#include "storage/field/field.h"
#include "common/types.h"

/**
 * @brief 表示从表中获取数据的算子
 * @details 比如使用全表扫描、通过索引获取数据等
 * @ingroup LogicalOperator
 */
class TableGetLogicalOperator : public LogicalOperator
{
public:
  TableGetLogicalOperator(BaseTable *table, ReadWriteMode mode);
  TableGetLogicalOperator(BaseTable *table, std::string table_alias, ReadWriteMode mode);
  ~TableGetLogicalOperator() override = default;

  LogicalOperatorType type() const override { return LogicalOperatorType::TABLE_GET; }

  BaseTable    *table() const { return table_; }
  ReadWriteMode read_write_mode() const { return mode_; }

  void set_predicates(std::vector<std::unique_ptr<Expression>> &&exprs);
  auto predicates() -> std::vector<std::unique_ptr<Expression>> & { return predicates_; }

  std::string &table_alias() { return table_alias_; }

  std::vector<float> &base_vector() { return base_vector_; }
  void                set_base_vector(std::vector<float> base_vector) { base_vector_ = std::move(base_vector); }

  size_t limit() const { return limit_; }
  void   set_limit(size_t limit) { limit_ = limit; }

  Index *index() const { return index_; }
  void   set_index(Index *index) { index_ = index; }

  bool is_vector_scan() { return !base_vector_.empty(); }

private:
  BaseTable    *table_ = nullptr;
  std::string   table_alias_;
  ReadWriteMode mode_ = ReadWriteMode::READ_WRITE;

  // 与当前表相关的过滤操作，可以尝试在遍历数据时执行
  // 这里的表达式都是比较简单的比较运算，并且左右两边都是取字段表达式或值表达式
  // 不包含复杂的表达式运算，比如加减乘除、或者conjunction expression
  // 如果有多个表达式，他们的关系都是 AND
  std::vector<std::unique_ptr<Expression>> predicates_;

  // 向量索引参数
  Index             *index_ = nullptr;
  std::vector<float> base_vector_;  // 要比较的向量
  std::size_t        limit_;        // 输出多少个
};
