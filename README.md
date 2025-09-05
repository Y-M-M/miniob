#《数据库系统原理课程设计》

学院：	计算机（国家示范性软件）学院
班级：	2021211307/2021211308
姓名：	于孟孟/程嘉伟
学号：	2022211260/2022213794

 
1. 课程设计的目的、内容	6
2. 课程设计任务的整体介绍	6
2.1 数据库管理系统架构	6
2.2 采用的开发平台	7
2.3 总体的完成情况	7
1. 实现方案	7
3.1 date	7
3.1.1 题目	7
3.1.2 实现思路	8
3.1.3 实现方案	8
3.2 drop-table	10
3.2.1 题目	10
3.2.2 实现思路	10
3.2.3 实现方案	11
3.3 update	15
3.3.1 题目	15
3.3.2 实现思路	15
3.3.3 实现方案	15
3.4 aggregation-func	20
3.4.1 题目	20
3.4.2 实现思路	21
3.4.3 实现方案	21
3.5 like	22
3.5.1 题目	22
3.5.2 实现思路	22
3.5.3 实现方案	23
3.6 join-tables	24
3.6.1 题目	24
3.6.2 实现思路	24
3.6.3 实现方案	24
3.7 simple-sub-query	25
3.7.1 题目	25
3.7.2 实现思路	26
3.7.3 实现方案	26
3.8 function	30
3.8.1 题目	30
3.8.2 实现思路	30
3.8.3 实现方案	30
3.9 multi-index	33
3.9.1 题目	33
3.9.2 实现思路	33
3.9.3 实现方案	33
3.10 unique	38
3.10.1 题目	38
3.10.2 实现思路	38
3.10.3 实现方案	39
3.11 null	41
3.11.1 题目	41
3.11.2 实现思路	41
3.11.3 实现方案	42
3.12 update-select	45
3.12.1 题目	45
3.12.2 实现思路	45
3.12.3 实现方案	46
3.13 expression	47
3.13.1 题目	47
3.13.2 实现思路	48
3.13.3 实现方案	48
3.14 alias	49
3.14.1 题目	49
3.14.2 实现思路	49
3.14.3 实现方案	49
3.15 text	54
3.15.1 题目	54
3.15.2 实现思路	54
3.15.3 实现方案	55
3.16 order-by	57
3.16.1 题目	57
3.16.2 实现思路	57
3.16.3 实现方案	57
3.17 group-by	60
3.17.1 题目	60
3.17.2 实现思路	60
3.17.3 实现方案	60
3.18 create-view	63
3.18.1 题目	63
3.18.2 实现思路	64
3.18.3 实现方案	64
3.19 create-table-select	69
3.19.1 题目	69
3.19.2 实现思路	70
3.19.3 实现方案	70
3.20 complex-sub-query	72
3.20.1 题目	72
3.20.2 实现思路	72
3.20.3 实现方案	72
3.21 update-mvcc	73
3.21.1 题目	73
3.21.2 实现思路	74
3.21.3 实现方案	74
3.22 big-query	75
3.22.1 题目	75
3.22.2 实现方案	75
3.23 big-write	75
3.23.1 题目	75
3.23.2 实现方案	76
3.24 big-order-by	76
3.24.1 题目	76
3.24.2 实现方案	76
1. AI使用说明	76
2. 实践心得	76
3. 总结	77


## 1. 课程设计的目的、内容

本次课程设计基于MiniOB数据库，进行数据库管理系统的设计与实现，了解数据库并深入学习数据库内核。通过 MiniOB，使学生了解数据库内核模块的功能和协同关系，并具备一定的工程编码能力，例如内存管理、网络通信和磁盘 I/O 处理等。课程设计主要针对数据库管理系统进行内核修改、功能添加，最终实现一个具有核心功能的完整的数据库管理系统。

## 2. 课程设计任务的整体介绍

### 2.1 数据库管理系统架构
 
• 网络模块(NET Service)：负责与客户端交互，收发客户端请求与应答；                
• SQL解析(Parser)：将用户输入的SQL语句解析成语法树；               
• 语义解析模块(Resolver)：将生成的语法树，转换成数据库内部数据结构；          
• 查询优化(Optimizer)：根据一定规则和统计数据，调整/重写语法树。(部分实现)；               
• 计划执行(Executor)：根据语法树描述，执行并生成结果；             
• 存储引擎(Storage Engine)：负责数据的存储和检索；              
• 事务管理(MVCC)：管理事务的提交、回滚、隔离级别等。当前事务管理仅实现了MVCC模式，因此直接以MVCC展示；                
• 日志管理(Redo Log)：负责记录数据库操作日志；             
• 记录管理(Record Manager)：负责管理某个表数据文件中的记录存放；                 
• B+ Tree：表索引存储结构；              
• 会话管理：管理用户连接、调整某个连接的参数；               
• 元数据管理(Meta Data)：记录当前的数据库、表、字段和索引元数据信息；            
• 客户端(Client)：作为测试工具，接收用户请求，向服务端发起请求。              

### 2.2 采用的开发平台

1. github仓库
[Ymm的minob](https://github.com/Y-M-M/miniob)
2. gitpod Version: 20250524.309
3. vscode 版本: 1.100.2 (Universal)

### 2.3 总体的完成情况

全部题目均通过
 
1. 实现方案
针对每一题目，详细阐述自己的设计方案、优化方法与具体实现，可以适当展示核心代码

## 3.1 date      

### 3.1.1 题目  

在现有功能上实现日期类型字段。
当前已经支持了 int、 char、 float 类型，在此基础上实现 date 类型的字段。
date 测试可能超过 2038 年 2 月，也可能小于 1970 年 1 月 1 号。注意处
理非法的 date 输入，需要返回 FAILURE。
这道题目需要从词法解析开始，一直调整代码到执行阶段，还需要考虑
DATE 类型数据的存储。
注意：
- 需要考虑 date 字段作为索引时的处理，以及如何比较大小;
- 这里没有限制日期的范围，需要处理溢出的情况。
- 需要考虑闰年。

### 3.1.2 实现思路
该DATE类型的实现采用整数存储方案，将日期统一表示为YYYYMMDD格式的整数值以优化存储空间和比较效率。系统通过扩展Value类添加专门的日期操作方法，在词法分析阶段识别日期字符串后，语法分析阶段将其转换为Value对象，最终在运行时调用日期解析函数进行字符串到整数的转换，并严格验证日期的合法性（包括闰年处理和各月份天数校验）。类型系统限制不合理的类型转换，仅允许直接获取原始整数值或格式化为标准YYYY-MM-DD字符串输出。比较操作直接基于整数值实现高效排序，而输入输出过程自动处理字符串与整数表示之间的双向转换，确保用户始终以标准日期格式交互，同时内部维持紧凑的存储结构。整个设计在保持类型安全性和数据正确性的前提下，兼顾了存储效率、运算性能和用户体验。
### 3.1.3 实现方案
1.	在src/observer/common/value.h和value.cpp中，添加新的class DateType，并为value类添加函数get_date(), set_date()等函数，用于完成对date字段的操作，将date的字符串转换成int来存储
```c++
void Value::set_date(int val)
{
  reset();
  attr_type_        = AttrType::DATES;
  value_.int_value_ = val;
  length_           = sizeof(val);
}
```
2. 类型转换限制：
￮ 直接获取 DATE 的 int 值（get_int()）会返回原始存储值
￮ 但尝试将 DATE 转换为 float 或 boolean 时会输出警告
3. 输入处理
￮	在词法分析阶段，日期字符串（如 "2023-01-01"）会被识别为 SSS token（字符串）
￮	在语法分析阶段，通过 的规则转换为 Value 对象
￮	最终在运行时（如 INSERT 或 UPDATE 时）调用日期解析函数将字符串转换为整数
4.	输出处理
在 to_string() 方法中，DATE 类型会通过 DataType::type_instance() 调用对应的格式化函数转换为可读字符串
```C++
RC DateType::to_string(const Value &val, string &result) const
{
  // 提取年、月、日
  int year  = val.value_.int_value_ / 10000;        // 获取年份
  int month = (val.value_.int_value_ / 100) % 100;  // 获取月份
  int day   = val.value_.int_value_ % 100;          // 获取日期

  // 使用字符串流构建结果字符串
  std::ostringstream oss;
  oss << std::setw(4) << std::setfill('0') << year << '-' << std::setw(2) << std::setfill('0') << month << '-'
      << std::setw(2) << std::setfill('0') << day;

  // 将结果赋值给 result
  result = oss.str();
  return RC::SUCCESS;
}
```
5.	比较操作
通过 DataType::type_instance()->compare() 实现，实际是按整数比较
6.	检查日期是否合法（考虑闰年）
通过parser_date()函数和check_date函数，检查日期是否合法，考虑闰年
```C++
bool check_date(int y, int m, int d)
{
  // 定义每个月的天数
  static int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  // 判断是否为闰年
  bool leap = (y % 400 == 0) || (y % 100 != 0 && y % 4 == 0);
  // 检查年份、月份和日期的合法性
  return (y > 0 && y <= 9999) && (m > 0 && m <= 12) &&
         (d > 0 && d <= (mon[m] + (m == 2 && leap ? 1 : 0)));  // 2月如果是闰年则加1天
}

RC parse_date(const char *str, int &result)
{
  int y, m, d;
  if (sscanf(str, "%d-%d-%d", &y, &m, &d) != 3) {
    return RC::INVALID_ARGUMENT;
  }
  if (!check_date(y, m, d)) {
    return RC::INVALID_ARGUMENT;
  }
  result = y * 10000 + m * 100 + d;
  return RC::SUCCESS;
}
```
## 3.2 drop-table 
### 3.2.1 题目
实现删除表(drop table)，清除表相关的资源。
当前 MiniOB 支持建表与创建索引，但是没有删除表的功能。
在实现此功能时，除了要删除所有与表关联的数据，不仅包括磁盘中的文件，还包括内存中的索引等数据。
删除表的语句为 drop table table-name
### 3.2.2 实现思路
为了实现drop table的功能，我参考了create table调用了哪些接口，创建了哪些元文件，然后试图找到或创建删除它们的对应接口，如元组、索引等。类似于实现建表的逆过程。然后，我自底向上查看实现sql语句的各个关键文件，添加drop table的相应内容。函数内需要删除table的元数据文件、index文件、data文件，然后还需要回收bufferpool中该文件对应的页，成功的话再将该table的tableMeta从Db类中删除。
### 3.2.3 实现方案
1.	语法解析文件yacc_sql.y需要增加drop table的识别。需要创建drop table的语法解析树，并在type、command_wrapper加入drop_table_stmt。初始的Miniob文件已有解析，无需添加。
```C++
  /** type 定义了各种解析后的结果输出的是什么类型。类型对应了 union 中的定义的成员变量名称 **/
  %type <sql_node>            drop_table_stmt
  
  command_wrapper:
   | drop_table_stmt 
  
  drop_table_stmt:    /*drop table 语句的语法解析树*/
    DROP TABLE ID {
      $$ = new ParsedSqlNode(SCF_DROP_TABLE);
      $$->drop_table.relation_name = $3;
      free($3);
    };
```
2.	其次更改parse_defs.h。在表示SQL语句类型的SqlCommandFlag、表示SQL语句的ParsedSqlNode中加入drop table的枚举，再加入描述一个drop table语句的结构体DropTableSqlNode。
```C++
/**
 * @brief 表示一个SQL语句的类型
 * @ingroup SQLParser
 */
enum SqlCommandFlag
{
...
  SCF_DROP_TABLE,
...
}

/**
 * @brief 表示一个SQL语句
 * @ingroup SQLParser
 */
class ParsedSqlNode
{
...
  DropTableSqlNode    drop_table;
...
}

/**
 * @brief 描述一个drop table语句
 * @ingroup SQLParser
 */
struct DropTableSqlNode
{
...
  std::string relation_name;  ///< 要删除的表名
...
};
```
3.	之后进入SQL语义阶段。在stmt.cpp的DDL（数据定义语言）识别中加入DROP TABLE，因为它操作的是数据库的结构或元数据，属于DDL的一种。再在RC Stmt::create_stmt()中加入对语句的识别，创建一个drop table stmt。
```C++
bool stmt_type_ddl(StmtType type)
{
  switch (type) {
    case StmtType::CREATE_TABLE:
    case StmtType::DROP_TABLE:
    case StmtType::DROP_INDEX:
    case StmtType::CREATE_INDEX: {
      return true;
    }
  }
  ...
}

RC Stmt::create_stmt(Db *db, ParsedSqlNode &sql_node, Stmt *&stmt)
{
  stmt = nullptr;
...
  switch (sql_node.flag) {
    case SCF_DROP_TABLE: {
      return DropTableStmt::create(db, sql_node.drop_table, stmt);
    }
  }
}
```
4.	接着实现drop table stmt的具体内容。创建drop_table_stmt.cpp/.h，其中DropTableStmt::create()接口用于创建DropTableStmt 实例。
```
RC DropTableStmt::create(Db *db, const DropTableSqlNode &drop_table, Stmt *&stmt)
{
  stmt = new DropTableStmt(drop_table.relation_name);
  sql_debug("drop table statement: table name %s", drop_table.relation_name.c_str());
  return RC::SUCCESS;
}
```
5.	在执行阶段的command_executor.cpp添加对DropTableStmt的识别，确保drop table的执行。
```C++
RC CommandExecutor::execute(SQLStageEvent *sql_event)
{
    case StmtType::DROP_TABLE: {
      DropTableExecutor executor;
      rc = executor.execute(sql_event);
    } break;
}
```
6.	创建对应的drop_table_executor.cpp。它确保stmt类型正确，从 sql_event中提取stmt并转换为 DropTableStmt，获取数据库对象，最后调用具体的drop_table() 方法。
```C++
RC DropTableExecutor::execute(SQLStageEvent *sql_event)
{
  Stmt    *stmt    = sql_event->stmt();
  Session *session = sql_event->session_event()->session();
  ASSERT(stmt->type() == StmtType::DROP_TABLE,
      "drop table executor can not run this command: %d",
      static_cast<int>(stmt->type()));
  auto *drop_table_stmt = dynamic_cast<DropTableStmt *>(stmt);
  const char *table_name = drop_table_stmt->table_name().c_str();
  RC          rc         = session->get_current_db()->drop_table(table_name);
  return rc;
}
```
7.	最后，在数据库对象层、表对象层实现具体的删除。我们在db.cpp中加入RC Db::drop_table(const char *table_name)，它会调用表对象的 drop() 方法，在内存层移除表对象。在底层的table.cpp也加入数据库层需要的RC Table::drop()，实现了表元数据文件、数据文件、索引文件的删除。
```C++
RC Table::drop()
{
...
  auto       table_name = name();
  //找到元文件并删除
  auto       path = table_meta_file(base_dir_.c_str(), table_name);
  if (!filesystem::remove(path, ec)) {
...
  }
  //找到数据文件并删除
  path = table_data_file(base_dir_.c_str(), table_name);
  if (!filesystem::remove(path, ec)) {
...
  }
  auto index_num = table_meta_.index_num();
  //遍历索引并删除
  for (int i = 0; i < index_num; ++i) {
...
    path            = table_index_file(base_dir_.c_str(), table_name, index_name);
    if (!filesystem::remove(path, ec)) {
...
    }
  }

  return RC::SUCCESS;
}
```
## 3.3 update
### 3.3.1 题目
实现更新行数据的功能。
当前实现 update 单个字段即可。现在 MiniOB 具有 insert 和 delete 功能，在此基础上实现更新功能。可以参考 insert_record 和 delete_record 的实现。目前仅能支持单字段 update 的语法解析，但是不能执行。需要考虑带条件查询的更新，和不带条件的更新，同时需要考虑带索引时的更新。
### 3.3.2 实现思路
和drop table相似，我先参考了流程相似的insert和delete的逻辑，然后在主要的执行阶段中加入update需要的接口。在各个阶段中，要添加这些对象的链路。总体来说，我们实现update的方法是层层调用update接口，在底层直接将更新的值memcpy到内存中。中间还涉及了B+树索引表项的删除和新建。
### 3.3.3 实现方案
由于源代码的yacc_sql.y和parse_def.h已有update的相关内容，这部分逻辑可以等到实现复杂update语句（以及子查询）再更新。
1.	在stmt.cpp加入update的内容：识别到SCF_UPDATE后，调用Create创建UpdateStmt。
```C++
RC Stmt::create_stmt(Db *db, ParsedSqlNode &sql_node, Stmt *&stmt)
{
  stmt = nullptr;
  switch (sql_node.flag) {
    case SCF_UPDATE: {
      return UpdateStmt::create(db, sql_node.update, stmt);
    }
    default: {
      LOG_INFO("Command::type %d doesn't need to create statement.", sql_node.flag);
    } break;
  }
  return RC::UNIMPLEMENTED;
}
```
2.	为此，新建update_stmt.cpp/.h，将解析器产出的UpdateSqlNode转化为语义分析结果UpdateStmt。
```C++
/**
 * @brief 更新语句
 * @ingroup Statement
 */
class UpdateStmt : public Stmt
{
public:
  UpdateStmt() = default;
  UpdateStmt(BaseTable *table, std::vector<FieldMeta> field_metas, std::vector<std::unique_ptr<Expression>> values,
      FilterStmt *filter_stmt);

  StmtType type() const override { return StmtType::UPDATE; }

  BaseTable                                *table() const { return table_; }
  std::vector<FieldMeta>                   &field_metas() { return field_metas_; }
  std::vector<std::unique_ptr<Expression>> &values() { return values_; }
  FilterStmt                               *filter_stmt() const { return filter_stmt_; }

  static RC create(Db *db, UpdateSqlNode &update_sql, Stmt *&stmt);

private:
  BaseTable                               *table_ = nullptr;
  std::vector<FieldMeta>                   field_metas_;
  std::vector<std::unique_ptr<Expression>> values_;
  FilterStmt                              *filter_stmt_ = nullptr;
};
```
3.	和drop table不同，update不通过执行器实现功能，而是产生物理/逻辑计划再执行。在logical_operator.h的LogicalOperatorType中加入UPDATE，创建update_logical_operator.cpp/.h；同理在physical_operator.h的PhysicalOperatorType加入UPDATE，创建update_physical_operator.cpp/.h。核心函数RC open(Trx *trx)用于收集所有需要更新的记录， 获取表达式的值再调用事务的更新接口trx_->update_record执行更新。若更新失败，调用 rollback() 函数回滚成功的更新。
```c++
RC UpdatePhysicalOperator::open(Trx *trx)
{
  RC rc = child->open(trx);
  while (OB_SUCC(rc = child->next())) {
    Tuple *tuple = child->current_tuple();
...
    }
  child->close();
...
  Record new_record;
  for (Record &old_record : records_) {
...
    auto rollback_old_record = old_record.clone();
    auto rollback_new_record = new_record.clone();
    rc                       = trx_->update_record(table_, old_record, new_record);
    if (rc != RC::SUCCESS) {
      rollback();
      return rc;
    } else {
      log_records.emplace_back(rollback_old_record, rollback_new_record);
    }
}
```
4.	事务（包括MVCC和真空事务）均调用table的update_record实现更新。

```c++
RC VacuousTrx::update_record(BaseTable *table, Record &old_record, Record &new_record)
{
  return table->update_record(old_record, new_record);
}
```

5.	此后我们创建了base_table.cpp/.h，为表提供统一的抽象接口，包括打开/插入/删除/更新等。这有助于我们对table.cpp的更新。定义了虚函数 virtual RC update_record()。
```c++
class BaseTable
{
public:
  virtual ~BaseTable() = default;

  Db              *db() const { return db_; }
  TableType        type() const { return table_meta_.table_type(); }
  int32_t          table_id() const { return table_meta_.table_id(); }
  const TableMeta &table_meta() const { return table_meta_; }
  const char      *name() const { return table_meta_.name(); }

......

  virtual RC update_record(const Record &old_record, const Record &new_record) = 0;
  virtual RC get_record(const RID &rid, Record &record)                        = 0;
  virtual RC drop() = 0;
  virtual RC sync() = 0;

protected:
  Db             *db_ = nullptr;
  string          base_dir_;
  TableMeta       table_meta_{};
  DiskBufferPool *data_buffer_pool_ = nullptr;  /// 数据文件关联的buffer pool
};
```
6.	在table.cpp，创建函数RC Table::update_record(const Record &old_record, const Record &new_record)，用来实现实现BaseTable::update_record接口。它的主要功能并非直接更新数据，而是删除旧索引项并插入新索引项，最后再更新数据记录本体，调用更低层的 RecordFileHandler的更新接口。索引的插入、删除通过BplusTreeHandler的insert_entry、delete_entry实现。
```c++
RC Table::update_record(const Record &old_record, const Record &new_record)
{
  RC rc = RC::SUCCESS;
  // 维护索引，先删除后插入
  for (Index *index : indexes_) {
    rc = index->delete_entry(old_record.data(), &old_record.rid());
    ASSERT(RC::SUCCESS == rc,
           "failed to delete entry from index. table name=%s, index name=%s, rid=%s, rc=%s",
           name(), index->index_meta().name(), old_record.rid().to_string().c_str(), strrc(rc));
  }
  // 尝试插入
  rc = insert_entry_of_indexes(new_record.data(), new_record.rid());
  // 出现重复键
  if (rc != RC::SUCCESS) {
    // 因为有些索引还没有插入，删除失败不应该报错
    RC delete_entry_of_indexes_rc = delete_entry_of_indexes(new_record.data(), new_record.rid(), false);
    if (RC::SUCCESS != delete_entry_of_indexes_rc) {
      LOG_WARN("failed to rollback index data when insert index entries failed. table name=%s, rc=%s", name(), strrc(delete_entry_of_indexes_rc));
      return delete_entry_of_indexes_rc;
    }
    return rc;
  }
  // 最后更新记录
  rc = record_handler_->update_record(new_record.data(), &new_record.rid());
  return rc;
}
```
7.	record_manager.cpp分三层实现了update的底层逻辑。顶层扫描器的RCRecordFileScanner::update_current()在扫描记录过程中更新当前的记录，调用文件处理器的RecordFileHandler::update_record()；文件处理器的update_record按 RID 访问页面并更新记录，创建页处理器RecordPageHandler，再调用页级的update_record。RowRecordPageHandler::update_record() 用memcpy将用户传入的数据复制到内存页中，实现了真正的数据更新。
```C++
RC RecordFileScanner::update_current(const Record &record)
{
  if (record.rid() != next_record_.rid()) {
    return RC::INVALID_ARGUMENT;
  }
  return record_page_handler_->update_record(record.rid(), record.data());
}

RC RecordFileHandler::update_record(const char *data, const RID *rid)
{
  RC rc = RC::SUCCESS;
  unique_ptr<RecordPageHandler> record_page_handler(RecordPageHandler::create(storage_format_));
......
  rc = record_page_handler->update_record(*rid, data);
  record_page_handler->cleanup();
  return rc;
}

RC RowRecordPageHandler::update_record(const RID &rid, const char *data)
{
......
    char *record_data = get_record_data(rid.slot_num);
    if (record_data == data) {
      // nothing to do
    } else {
      memcpy(record_data, data, page_header_->record_real_size);
    }

    RC rc = log_handler_.update_record(frame_, rid, data);
......
}
```
## 3.4 aggregation-func
### 3.4.1 题目
1.	题目描述：
实现聚合函数 max/min/count/avg/sum。
聚合函数会遍历所有相关的行数据做相关的统计，并输出结果。
可能出现如select id, count(age) from t; 这样的聚合和单个字段混合的测试语句，返回 FAILURE。
当前题目是简单题目，所以测试用例中不会包含一些比较复杂的处理，比如表达式。但是有些数据类型会有隐式转换，比如 avg 计算整数类型时，结果会是浮点数。
注意处理语义处理时的异常场景，比如:
查询不存在的字段；
查询空字段；
3.4.2 实现思路
这道题的实现思路可以总结为：首先在词法分析阶段将MAX、MIN、AVG、COUNT、SUM等聚合函数识别为普通标识符(ID)，然后在语法分析阶段通过func_expr规则将其处理为UnboundFunctionExpr表达式。接着需要完善聚合算子的实现，参照现有的CountAggregator和AvgAggregator，补充实现SumAggregator、MaxAggregator和MinAggregator等聚合算子，其中特别要注意AvgAggregator需要进行隐式类型转换，通过重载evaluate函数将结果转换为浮点数。最后在处理混合字段查询时，在logical_plan_generator阶段通过create_group_by_plan对查询表达式进行类型检查，确保聚合字段和单个字段不能混合出现，除非单个字段是GROUP BY子句中的分组依据，从而保证查询语义的正确性。整个实现过程涉及词法分析、语法分析、算子实现和查询计划生成等多个环节的协同工作。
3.4.3 实现方案
1.	词法分析阶段，将MAX, MIN, AVG, COUNT, SUM识别为ID
2.	语法分析阶段，作为unboundfunctionexpr来处理(作为聚合函数)，被识别为expression
```
func_expr:
    ID LBRACE expression_list RBRACE
    {
        $$ = new UnboundFunctionExpr($1, std::move(*$3));
        $$->set_name(token_name(sql_string, &@$));
    }
    ;
    ```
3.	完善算子的部分
仿照CountAggregator和AvgAggregator，完善SumAggregator, MaxAggregator和MinAggregator
4.	聚合和单个字段混合的测试语句
在logical_plan_generator的时候实现，对于select_stmt，一定要会调用create_group_by_plan，在其中会对query_expressions_做类型检查，聚合字段和单个字段不能混合出现，除非单个字段是group by中的分组依据
5.	avg的隐式类型转换
在class AvgAggregator中进行，通过重载evaluate函数完成。
```c++
RC evaluate(Value &result) override
  {
    if (count_ > 0) {
      Value avg = value_;
      avg       = Value(avg.get_float() / static_cast<float>(count_));
      result    = avg;
    } else {
      result = Value(NullValue());
    }
    return RC::SUCCESS;
  }
  ```
3.5 like
3.5.1 题目
1.	题目描述：
like 操作符是数据库中字符串查找非常常用的功能能，用于在 WHERE子句中搜索符合一定格式的字段。
当前 MiniOB 中已经有条件查询的能力，需要扩展 like 相关的语法解析、查询匹配功能。
'%'用于匹配零个到多个任意字符（英文单引号“'”除外）， '_'用于匹配一个任意字符（英文单引号“'”除外）。
当前只需要考虑 char 类型的字段即可（当前 MiniOB 支持 int, float 和 char类型字段）。
3.5.2 实现思路
这道题的实现思路主要围绕SQL中LIKE和NOT LIKE操作的完整支持展开。首先在词法分析阶段添加对LIKE关键词的识别，使其能够被正确解析为特定token。然后在语法分析层面将LIKE和NOT LIKE作为新的比较运算符(CompOp)处理，在枚举类型中添加LIKE_OP和NOT_LIKE_OP两种操作类型，使其能够像其他比较运算符一样参与表达式构建。在语义处理部分，LIKE操作被集成到where子句的表达式体系中，通过comp_value实现具体的匹配逻辑。核心匹配功能在Value类的LIKE方法中实现，该方法将SQL风格的通配符(%和_)转换为正则表达式(分别对应.*和.)，然后利用C++标准库的regex_match进行模式匹配，NOT LIKE则通过取反LIKE的结果实现。整个实现过程确保了类型安全，通过断言确保操作数必须是字符串类型，同时保持了与现有表达式体系的兼容性，使得LIKE操作可以自然地融入SQL查询的各个部分。
3.5.3 实现方案
1.	词法分析部分添加对like关键词的识别
2.	语法分析部分，将like和not like作为一个新的comp_op来使用，同时也在parse_defs中声明
```c++
enum CompOp
{
  ...
  LIKE_OP,        ///< "like"
  NOT_LIKE_OP,    ///< "not like"
  ...
};
```
3.	where子句的类型，也用expression代替，故like也在expression中，通过comp_value实现
```c++
if (comp_ == LIKE_OP || comp_ == NOT_LIKE_OP) {
    ASSERT(left.is_str() && right.is_str(), "LIKE ONLY SUPPORT STRING TYPE!");
    result = comp_ == LIKE_OP ? left.LIKE(right) : !left.LIKE(right);
    return rc;
  }
```
```C++
bool Value::LIKE(const Value &other) const
{
  const std::string  left_str  = this->get_string();
  const std::string &right_str = other.get_string();

  // 将 SQL 通配符转换为正则表达式
  std::string regex_str = std::regex_replace(right_str, std::regex("%"), ".*");
  regex_str             = std::regex_replace(regex_str, std::regex("_"), ".");

  std::regex regex_pattern(regex_str);
  return std::regex_match(left_str, regex_pattern);
}
```
3.6 join-tables
3.6.1 题目
实现 INNER JOIN 功能，需要支持 join 多张表。
当前已经支持多表查询的功能，这里主要工作是语法扩展，并考虑数据量比较大时如何处理。
注意带有多条 on 条件的 join 操作。
3.6.2 实现思路
实现 INNER JOIN 功能的核心思路是围绕语法扩展和表达式整合展开的。首先在词法分析阶段识别 INNER 和 JOIN 关键字，为多表连接提供基础语法支持；然后在语法分析阶段进行语法扩展，将参与连接的表名存储在 relations 结构中，并将 ON 连接条件作为表达式存入 conditions。对于复杂的多条件场景，系统会将多个 JOIN 条件和 WHERE 条件通过 AND 逻辑连接整合成一个统一的 ConjunctionExpr 表达式树，确保条件处理的完整性和一致性。在查询处理流程中，首先在 select_stmt 创建阶段合并处理 INNER JOIN 条件和 WHERE 子句条件，形成统一的查询条件表达式；随后在优化器阶段，系统会依次生成逻辑计划、物理计划，最终执行物理计划获取结果。整个实现特别考虑了大数据量场景下的处理需求，通过表达式树的构建和优化器阶段的处理，确保多表连接查询既能满足功能需求，又能保持良好的性能表现，特别是支持带有多条 ON 条件的复杂 JOIN 操作。
3.6.3 实现方案
1.	统一整合成expression类来处理，构建expression树
2.	词法分析阶段，能够识别inner和join这两个关键字
3.	语法分析阶段，拓展语法
     将所有的连接表名存储到relations中，将ON条件存入conditions表达式，如果有where子句，将JOIN条件和WHERE条件用AND连接，构建一个新的expression(ConjunctionExpr)
```C++
struct SelectSqlNode
{
  std::vector<std::unique_ptr<Expression>> expressions;        ///< 查询的表达式
  std::vector<RelationNode>                relations;          ///< 查询的表
  std::unique_ptr<Expression>              conditions;         ///< 查询条件，使用AND串联起来多个条件
  std::vector<std::unique_ptr<Expression>> group_by;           ///< group by clause
  std::vector<OrderBySqlNode>              order_by;           ///< attributes in order clause
  std::unique_ptr<Expression>              having_conditions;  ///< having
  std::unique_ptr<LimitSqlNode>            limit;
};
```
4.	在select_stmt的create阶段，将innerjoin的条件与where子句的条件合并处理
5.	之后在optimizer阶段，生成逻辑计划、生成物理计划，之后执行物理计划，获得结果
## 3.7 simple-sub-query
### 3.7.1 题目
1.	题目描述：
简单子查询。此功能是对基础查询功能的一个扩充，使数据库 SQL 的能力更加丰富。
这里需要支持的功能包括但不限于：
•	支持简单的 IN(NOT IN)语句，不涉及基本类型转换。注意 NOT IN语句面对 NULL 时的特殊性。
•	支持简单的 EXISTS(NOT EXISTS)语句。
•	支持与子查询结果做比较运算。 注意子查询结果为多行的情况。
•	支持子查询中带聚合函数。
•	子查询中不会与主查询做关联。这也是简单子查询区分于复杂子查询的地方。
•	表达式中可能存在不同类型值比较。
2.	提示：
词法和语法解析阶段，需要处理对子查询语句的识别，主要是 in 和 exists关键词。这里建议同样将子查询整合成 expression 类。查询陈述阶段（stmt类）和算子阶段，同样的，也要保持 expression 类形成的树结构。注意NULL、唯一查询结果与多查询结果的不同处理，他们支持的运算并不相同。例如单查询结果对多查询结果支持 in 语句，而对单查询结果则要报错。这里有很多细节。
### 3.7.2 实现思路
为实现本题，需要实现查询的嵌套结构、IN和NOT IN的识别、与子查询结果做比较运算等功能。原始代码没有subquery相关的内容，因此我们需要从语法解析开始实现，加入子查询表达式，之后修改expression、select等部分。
### 3.7.3 实现方案
1.	首先，在yacc_sql.y加入子查询表达式的内容。我们定义了sub_query_expr的规则，以括号包围一个常规的select_stmt，并将SubQueryExpr 纳入expression类型。
```C++
/** type 定义了各种解析后的结果输出的是什么类型。类型对应了 union 中的定义的成员变量名称 **/
%type <expression>          sub_query_expr

expression:
    | sub_query_expr {
      $$ = $1; // SubQueryExpr
    }

sub_query_expr:
    LBRACE select_stmt RBRACE
    {
      $$ = new SubQueryExpr($2->selection);
    }
    ;
```
2.	表达式绑定将SQL语句中的表达式从语法树节点转换成能执行的内部表达式对象。我们在表达式绑定阶段的expression_binder.cpp修改了入口函数RC ExpressionBinder::bind_expression() 。当它发现当前表达式是SUBQUERY类型时，调用子查询专用函数bind_subquery_expression()处理。
```C++
RC ExpressionBinder::bind_expression(unique_ptr<Expression> &expr, vector<unique_ptr<Expression>> &bound_expressions)
{
......
  switch (expr->type()) {
    case ExprType::SUBQUERY: {
      return bind_subquery_expression(expr, bound_expressions);
    } break;
......
}
```
3.	ExpressionBinder::bind_subquery_expression(）是子查询表达式绑定的核心，它调用 generate_select_stmt将 SelectSqlNode 转换为 SelectStmt，再将 SelectStmt 转换为 LogicalOperator 树，将逻辑计划转换为物理执行单元，最后将绑定完成的表达式加入到 bound_expressions 向量中。
```C++
RC ExpressionBinder::bind_subquery_expression(
    std::unique_ptr<Expression> &expr, std::vector<std::unique_ptr<Expression>> &bound_expressions)
{
  RC   rc            = RC::SUCCESS;
  auto subquery_expr = dynamic_cast<SubQueryExpr *>(expr.get());
  rc = subquery_expr->generate_select_stmt(context_.get_db(), context_.table_map());
  rc = subquery_expr->generate_logical_oper();
  rc = subquery_expr->generate_physical_oper();
  bound_expressions.emplace_back(std::move(expr));
  return rc;
}
```
4.	在expression.h，定义了作为表达式子类的子查询表达式。具有open()接口、get_value()接口等内容。
```C++
class SubQueryExpr : public Expression
{
public:
  RC   open(Trx *trx, const Tuple &tuple);
...
  RC get_value(const Tuple &tuple, Value &value) override;
...
  ExprType type() const override;
  AttrType value_type() const override;

private:
...
};
```
5.	expression.cpp的ComparisonExpr::get_value( )中，增加对子查询的判断。使用匿名函数open_subquery，判断一个表达式是否是子查询。如是，就执行open() 启动子查询的执行过程。用这个函数处理左值left_/右值right_是子表达式的情况。然后用defer确保函数返回前自动调用 close() 释放子查询资源。
```C++
  auto open_subquery = [&tuple](const std::unique_ptr<Expression> &expr, SubQueryExpr *&subquery_expr) -> RC {
    if (expr->type() == ExprType::SUBQUERY) {
      subquery_expr = dynamic_cast<SubQueryExpr *>(expr.get());
      RC rc         = subquery_expr->open(nullptr, tuple);  // Open the subquery expression (pass nullptr for now)
    }
    return RC::SUCCESS;
  };
...
    // Check and open the left subquery expression if it exists
  rc = open_subquery(left_, left_subquery_expr);
...
  // Check and open the right subquery expression if it exists
  rc = open_subquery(right_, right_subquery_expr);
...
  DEFER(if (nullptr != left_subquery_expr) left_subquery_expr->close();
      if (nullptr != right_subquery_expr) right_subquery_expr->close(););
```
遇到子查询表达式时，调用其 open函数打开子查询执行环境；通过物理操作算子执行子查询，调用 SubQueryExpr::get_value 获取子查询返回的结果。
```
if (expr->type() == ExprType::SUBQUERY) {
  subquery_expr = dynamic_cast<SubQueryExpr *>(expr.get());
  rc = subquery_expr->open(nullptr, tuple);
}
```
7.	关于IN和NOT IN的实现，首先在yacc_sql.y的比较运算符comp_op中定义它们的语法规则：
```c++
comp_op:
    | IN { $$ = IN_OP; }
    | NOT IN { $$ = NOT_IN_OP; }
    ;
```
8.	语义结构定义文件parse_def.h中也添加了IN、NOT IN对应的比较运算符
```C++
enum CompOp
{
  IN_OP,          ///< "in (sub query)"
  NOT_IN_OP,      ///< "not in (sub query)"
};
```
9.	在expression.cpp中的RC ComparisonExpr::get_value()中，函数将判断运算符是否为IN_OP 或 NOT_IN_OP。若是，在左值为null时，比较结果就是 false。之后，设置默认的比较结果，IN默认false，NOT IN默认true。遍历右值列表，IN 情况下一旦 left_value == right_value，就返回 true；NOT IN 情况下一旦遇到 null/相等，就返回 false，两者逻辑相反。
```C++
RC ComparisonExpr::get_value(const Tuple &tuple, Value &value)
{
......
  // Handle IN and NOT IN operations
  if (comp_ == IN_OP || comp_ == NOT_IN_OP) {
    if (left_value.is_null()) {
      value.set_boolean(false);
      return RC::SUCCESS;
    }
    // 比较表达式的结果，如果进入 while 循环且没有提前退出，那么结果即为该值
    bool res = comp_ == NOT_IN_OP;
    rc = right_->get_value(tuple, right_value);
    ...
    else {
      while (RC::SUCCESS == (rc = right_->get_value(tuple, right_value))) {
        if (right_value.is_null()) {
          // 对于 not in，一边有 null 就为假
          if (comp_ == NOT_IN_OP) {
...
          }
        } else if (left_value.compare(right_value) == 0) {
...
        }
      }
    }
    value.set_boolean(res);
    ...
  }
}
```
## 3.8 function
### 3.8.1 题目
实现一些常见的函数，包括 length、round 和 date_format。
函数是 SQL 中常见功能之一。这些函数除了用在查询字段上，还可能会出现在条件语句中，作为查询数据过滤条件之一。
为了简化，仅考虑上述三种函数即可，其中 length 只考虑 char 类型， round只考虑 float 类型， date_format 只考虑 date 类型，遇到其他的数据类型返回 FAILURE 即可
### 3.8.2 实现思路
为了实现这些函数，首先需要识别它们的语法结构。之后，构造一类函数表达式，由expression调用下层接口获取它们的变量值、操作类型，并调用相应的函数功能。最终我们实现了如返回字符串长度的length、取整小数的round和将日期转换为某一格式的date_format函数。
### 3.8.3 实现方案
1.	首先，在yacc_sql.y增加函数表达式的语法分析规则。等价于解析func_name(expr1, expr2, ..., exprN)的语句格式
```C++

func_expr:
    ID LBRACE expression_list RBRACE
    {
        $$ = new UnboundFunctionExpr($1, std::move(*$3));
        $$->set_name(token_name(sql_string, &@$));
    }
    ;
```
2.	新建文件builtin.h，其中定义了 NormalFunctionType 枚举，用于标识支持的内置函数类型，并声明了每个函数的接口。在对应的builtin.cpp中，我们定义了具体的RC length()，RC round()实现方法。length将判断参数大小是否为1，类型是否为字符串，然后调用to_string的方法得到长度。round确定参数是纯小数/有整数的小数后，视情况进行四舍五入/银行家舍入。RC date_format()的实现略为复杂，它首先判断参数是否是合法的日期形式，然后调用get_year_month_day，提取到value携带的年月日，根据date/char类型采取不同的提取方法。
```C++
RC length(const vector<Value> &args, Value &result)
{
...
  int length = static_cast<int>(args[0].to_string().size());
  result     = Value(length);
...
}

RC round(const vector<Value> &args, Value &result)
{
  float number;
  int   decimals = 0;  // 默认四舍五入为整数
  ...
  // 获取整数部分和小数部分
  double integer_part;
  double fractional_part = std::modf(scaledNumber, &integer_part);
  // 如果小数部分刚好是 0.5，进行银行家舍入
  if (fractional_part == 0.5 || fractional_part == -0.5) {
  ...
  result = Value(static_cast<float>(round));
  return RC::SUCCESS;
  }
}

RC get_year_month_day(const Value &value, int &year, int &month, int &day)
{
  if (value.attr_type() == AttrType::DATES) {
    // 提取年、月、日（假设日期格式为YYYYMMDD）
...
  }

  if (value.attr_type() == AttrType::CHARS) {
    // 日期格式假设为 '2019-9-17' 或 '2019-09-17'
...
  }
  //过滤非法日期
  if (!check_date(year, month, day)) {
    return RC::ERROR_DATE;
  }
}

RC date_format(const vector<Value> &args, Value &result)
{
  int year, month, day;
  RC  rc = get_year_month_day(args[0], year, month, day);
  ...
  // 遍历格式字符串，并替换格式符
  for (size_t i = 0; i < fmt.length(); ++i) {
    if (fmt[i] == '%' && i + 1 < fmt.length()) {
      switch (fmt[i + 1]) {
      ...
      }
      ++i;  // 跳过格式符的下一个字符
    } 
  result = Value(str.c_str());
  return RC::SUCCESS;
  }
}
```
3.	expression.h中定义了NormalFunctionExpr类，它是 SQL 普通函数的表达式节点。expression.h则处理这些普通函数调用，在执行阶段将参数取值，调用对应的builtin函数。type_from_string将函数名字符串转为enum值 ，get_value从元组中获取每个参数值，并调用对应的内置函数,实现它们的具体功能。
```c++
RC NormalFunctionExpr::type_from_string(const char *type_str, NormalFunctionType &type)
{
  check_type("month", NormalFunctionType::MONTH);
  check_type("year", NormalFunctionType::YEAR);
  check_type("date_format", NormalFunctionType::DATE_FORMAT);
......
  return RC::INVALID_ARGUMENT;
}

RC NormalFunctionExpr::get_value(const Tuple &tuple, Value &result)
{
......
  switch (type_) {
    case NormalFunctionType::LENGTH: return builtin::length(args_values_, result);
    case NormalFunctionType::ROUND: return builtin::round(args_values_, result);
    case NormalFunctionType::DATE_FORMAT: return builtin::date_format(args_values_, result);
......
  }
  return RC::INTERNAL;
}
```
## 3.9 multi-index
### 3.9.1 题目
多字段索引功能。即一个索引中同时关联了多个字段。比如 `CREATE INDEX i_1_12 ON multi_index(col1,col2);`。
此功能除了需要修改语法分析，还需要调整 B+树相关的实现，帮助同学们增加 B+树数据存储知识的理解。
### 3.9.2 实现思路
为了实现多重索引，索引的结构和涉及索引的操作都需要调整，主要是将索引接收的单属性参数改为属性向量参数，添加配套的遍历操作。
### 3.9.3 实现方案
1.	我们首先修改了语法分析的部分。yacc_sql.y中，在定义各种数据类型的union中加入index_attr_list，它是字符串向量，用来支持多个字段的索引。在type中也做出了对应的修改。
```C++
/** union 中定义各种数据类型，真实生成的代码也是union类型，所以不能有非POD类型的数据 **/
%union {
  std::vector<std::string> *                 index_attr_list;
}
/** type 定义了各种解析后的结果输出的是什么类型。类型对应了 union 中的定义的成员变量名称 **/
%type <index_attr_list>     attr_list

attr_list:
    ID
    {
      $$ = new std::vector<std::string>; // 创建一个新的 vector
      $$->emplace_back($1); // 将列名加入 vector
      free($1);
    }
    ;
```

2.	之后，更改create_index_stmt的语法树。原先的语法树只支持一个字段的索引，现使其能够接收多字段的attr_list。
```c++
create_index_stmt:
    CREATE opt_unique INDEX ID ON ID LBRACE attr_list RBRACE
    {
      $$ = new ParsedSqlNode(SCF_CREATE_INDEX);
      CreateIndexSqlNode &create_index = $$->create_index;
      create_index.unique = $2; // 用 opt_unique 的返回值来确定是否 UNIQUE
      create_index.index_name = $4;
      create_index.relation_name = $6;
      create_index.attribute_name.swap(*$8); // $8 是 vector<string> 类型
      delete $8; // 释放指针
      free($4);
      free($6);
    }
    ;
```
3.	向上修改parse_defs.h。相似的，原来的CreateIndexSqlNode只接受单个属性值，现在使其能接受属性值向量。此外，定义了show index的语义，以便在调试时查看表中的索引。
```C++
/**
 * @brief 描述一个create index语句
 * @ingroup SQLParser
 * @details 创建索引时，需要指定索引名，表名，字段名。
 * 正常的SQL语句中，一个索引可能包含了多个字段，这里仅支持一个字段。
 */
struct CreateIndexSqlNode
{
  bool                     unique;               ///< unique index
  std::string              index_name;           ///< Index name
  std::string              relation_name;        ///< Relation name
  std::vector<std::string> attribute_name;       ///< Attribute name
  VectorIndexConfig        vector_index_config;  ///< 向量索引还有一些额外参数
};


/**
 * @brief 描述一个show index语句
 * @ingroup SQLParser
 */
struct ShowIndexSqlNode
{
  std::string relation_name;  ///< Relation name
};
```


4.	修改实现索引元数据的index_meta。在原先index_meta.h存储索引名name_、字段名field_的基础上进行修改，使其存储字段向量。此外，存储字段总长度fields_total_len_、字段偏移值fields_offset_，便于遍历所有字段。加入函数void make_entry_from_record(),用来从一条record中抽取出entry的所有字段值。
```C++
  void make_entry_from_record(char *entry, const char *record)
  {
    for (size_t i = 0; i < fields_.size(); i++) {
      auto &field = fields_[i];
      memcpy(entry + fields_offset_[i], record + field.offset(), field.len());
    }
  }

private:
...
  int               fields_total_len_ = 0;
  vector<int>       fields_offset_;
  vector<FieldMeta> fields_;
...
```
5.	index_meta.cpp也做了修改。索引初始化函数IndexMeta::init()接收新的参数，并且计算所有字段组成的复合键的总长度，存到fields_total_len_。修改IndexMeta::to_json()，使其递归序列化所有fields_。
```C++
RC IndexMeta::init(const char *name, IndexType index_type, const vector<FieldMeta> &fields, bool unique)
{
  ...
  fields_total_len_ = 0;
  fields_           = fields;
  ...
  for (auto &field : fields) {
    fields_offset_.emplace_back(fields_total_len_);
    fields_total_len_ += field.len();
  }
  return RC::SUCCESS;
}

void IndexMeta::to_json(Json::Value &json_value) const
{
......
  for (const auto &field : fields_) {
    Json::Value field_json;
    field.to_json(field_json);
    fields_json.append(field_json);
  }
......
  for (const auto &offset : fields_offset_) {
    offsets_json.append(offset);
  }
  json_value["fields_offset"] = offsets_json;
}
```
6.	下面需要更改bplus_tree.h的内容，以支持多重索引。首先改变键值比较器类KeyComparator：初始化函数void init(const IndexMeta &index)由于索引元数据结构的更新，使用for (const auto &i : index.fields())以遍历多个字段。比较函数attr_comparator_(v1, v2)目前支持多字段循环比较。
```C++
/**
 * @brief 键值比较(BplusTree)
 * @details BplusTree的键值除了字段属性，还有RID，是为了避免属性值重复而增加的。
 * @ingroup BPlusTree
 */
class KeyComparator
{
public:
  void init(const IndexMeta &index)
  {
    index_ = index;
    for (const auto &i : index.fields()) {
    ...
    }
  }

  int compare_key(const char *v1, const char *v2) const
  {
......
    for (size_t i = 0; i < field_number; i++) {
      int   offset = fields_offset[i];
      auto &field  = index_.fields()[i];
......
      int result = attr_comparator_[i](v1 + offset, v2 + offset);
    }
    return 0;
  }
......
private:
  IndexMeta              index_;
  vector<AttrComparator> attr_comparator_;
};
```

7.	之后修改BplusTreeHandler类。BplusTreeHandler::create不再接收单个属性的attr_type,attr_length，而是接收支持多个值的IndexMeta &index。移除了  RC destroy()，避免误删重要索引，同时不让B+树负责磁盘删除，通过元数据管理模块统一删除。成员变量新增了IndexMeta。
```c++
class BplusTreeHandler
{
  RC create(LogHandler &log_handler, BufferPoolManager &bpm, const char *file_name, const IndexMeta &index);
  RC create(LogHandler &log_handler, DiskBufferPool &buffer_pool, const IndexMeta &index);
......
    /**
   * 关闭句柄indexHandle对应的索引文件
   */
  RC close();
protected:
......
  IndexMeta       index_meta_;
```
8.	同时更改bplus_tree.cpp。BplusTreeHandler::create使用 attr_types[] 数组代替单一 attr_type，BplusTreeScanner::open中，旧代码仅支持单字段的 CHARS 类型处理，且构造的key仅包含单字段和 RID。改为根据传入的key字节串，结合 RID 生成完整多字段 key。添加了IndexFileHeader::init，用于初始化 IndexFileHeader。
## 3.10 unique
### 3.10.1 题目
实现唯一索引功能。
唯一索引是指一个索引上的数据都不是重复的。支持使用简单的 SQL 创建索引：create unique index。
注意：需要支持多列的唯一索引。为了简化场景，不考虑在已有重复数据的列上建立唯一索引的情况。
需要考虑数据插入、数据更新等场景。此功能主要涉及到 B+树与语法解析方面的模块。
### 3.10.2 实现思路
UNIQUE词条在原始代码中没有语法解析，且和索引高度相关。因此，我们添加它的语法语义定义，在索引相关函数中加入unique参数，并在用到索引的多数地方加入唯一索引的检测，以及是否唯一的判断。判断不单独实现，二是在插入索引表项时检测。
### 3.10.3 实现方案
1. 首先在词法分析文件lex_sql.l加入对UNIQUE的识别，返回对应的token。
```C++
UNIQUE              RETURN_TOKEN(UNIQUE);
```
2.	其次，在yacc_sql.y的type加入opt_unique，声明它的语义值类型为 <unique>。新建语法单元opt_unique，如果有UNIQUE返回true，空则返回false。修改create index stmt的识别模式，在index字段前设置opt_unique。处理create index语句时，根据unique的可选值判断是否为唯一索引。
```C++
%type <unique>              opt_unique

opt_unique:
    UNIQUE { $$ = true; }
    | /* 空 */ { $$ = false; }
    ;

create_index_stmt:
    CREATE opt_unique INDEX ID ON ID LBRACE attr_list RBRACE
    {
      create_index.unique = $2; // 用 opt_unique 的返回值来确定是否 UNIQUE
    }
```
3.	在parse_defs.h也对索引创建的sql节点修改，bool unique用于标识索引的唯一性。
```C++
struct CreateIndexSqlNode
{
  bool                     unique;               ///< unique index
  std::string              index_name;           ///< Index name
......
};
```
4.	之后修改创建索引的执行阶段逻辑。create_index_executor.cpp中的CreateIndexExecutor::execute()将解析阶段识别出的 unique 标志从 CreateIndexStmt 传递给 Table::create_index()。
```C++
if (create_index_stmt->index_type() == IndexType::BPlusTreeIndex) {
  return table->create_index(
......
      create_index_stmt->unique()          // 是否 UNIQUE
  );
}
```
5.	接着在table.cpp的Table::create_index添加bool unique参数，它将 unique 传入了IndexMeta::init()。
```C++
RC Table::create_index(
    Trx *trx, IndexType index_type, const vector<FieldMeta> &field_meta, const char *index_name, bool unique)
{
  if (common::is_blank(index_name)) {
    LOG_INFO("Invalid input arguments, table name is %s, index_name is blank or attribute_name is blank", name());
    return RC::INVALID_ARGUMENT;
  }
  IndexMeta new_index_meta;
  RC rc = new_index_meta.init(index_name, index_type, field_meta, unique);
......
```
6.	在索引元数据文件index_meta.cpp中也加入对unique的传递。初始化函数RC IndexMeta::init接收unique参数，传递给index_meta.h定义的private变量unique_。
```C++
RC IndexMeta::init(const char *name, IndexType index_type, const vector<FieldMeta> &fields, bool unique)
{
  ...
  unique_           = unique;
  ...
}
```
7.	最后更改bplus_tree_index.cpp的插入函数BplusTreeIndex::insert_entry。函数首先生成一个entry，当检测到索引元数据是唯一索引时，调用BplusTreeHandler::get_entry，查找索引的元数据中是否存在相同的表项。若返回不为空，说明和unique冲突，报错。否则正常调用 indexhandler的insert_entry执行插入。它实现了对唯一性的判断。
```C++
RC BplusTreeIndex::insert_entry(const char *record, const RID *rid)
{
  char *entry = index_meta_.make_entry_from_record(record);
  if (index_meta_.unique()) {
    list<RID> entries;
    RC        rc = index_handler_.get_entry(entry, index_meta_.fields_total_len(), entries);
    if (OB_FAIL(rc)) {
      return rc;
    }
    if (!entries.empty()) {
      return RC::RECORD_DUPLICATE_KEY;
    }
  }
  return index_handler_.insert_entry(entry, rid);
}
```
## 3.11 null
### 3.11.1 题目
NULL 是数据库的一个基本功能。
表字段可以有 NULL 属性，表示此字段是否允许为 NULL 值。NULL 在做数值运算、逻辑比较时，都有特殊的含义，同时在做聚合运算(count/avg等）都需要做不同的处理。与 2022 年的赛题不同，我们不再使用 nullable关键字，而与常见的数据库保持一致，使用 NULL 关键字，不区分大小写。比如 create table t(id int null, name char not null);，其中字段 id 可以为 NULL 值，而 name 字段不允许为 NULL 值。
注意：
•	NULL 与任何数值比较，结果都是 false。
•	NULL 用例非常基础，它出现在许多其它用例中。
### 3.11.2 实现思路
NULL是一种广义上的数据类型，但是更像附着在某一数据类型上的特性。为了实现它，需要给字段设置是否可空的标志位，同时也需正确处理null值的插入、涉及null的比较操作。
### 3.11.3 实现方案
1.	首先在词法、语法分析阶段加入null的定义。在lex_sql.l加入对NULL的识别：
```C++
NULL                                    RETURN_TOKEN(NULL_T);
```
2.	在parse_defs.h的比较运算符加入IS/IS NOT，以判断某个值是否为NULL。

```C++
  IS_OP,          ///< "is (null)"
  IS_NOT_OP,      ///< "is not (null)"
```

3.	在yacc_sql.y添加关于非空限制的语法单元nullable_constraint。它在为空/识别到NULL时为false，识别到NOT NULL时为true。在属性定义attr_def中加入对非空的判断。如果有非空约束，使用字段最后1字节存放它的标志。
```
attr_def:
    ID type LBRACE NUMBER RBRACE nullable_constraint
    {
      ......
      $$->nullable = $6;
      if ($$->nullable) {
        $$->length++;
      }
      free($1);
    }
    | ID type nullable_constraint
    {
      ......
      $$->nullable = $3;  // 处理NULL/NOT NULL
      if ($$->nullable) {
        $$->length++;
      }
      free($1);
    }
    ;

nullable_constraint:
    NOT NULL_T
    {
      $$ = false;  // NOT NULL 对应的可空性为 false
    }
    | NULL_T
    {
      $$ = true;  // NULL 对应的可空性也为 true
    }
    | /* empty */
    {
      $$ = true;  // 默认情况为 NULL
    }
    ;
```
4.	在value.h的Value类中加入is_null_成员变量来标识该值是否为NULL，作为外部接口is_null()的返回值；加入设置接口set_null，用于手动标记NULL;在data_type.cpp的DataType类静态数组type_instances_中，列举了系统支持的所有类型的单例实例，加入了NullType。
```C++
array<unique_ptr<DataType>, static_cast<int>(AttrType::MAXTYPE)> DataType::type_instances_ = {
    make_unique<DataType>(AttrType::UNDEFINED),
...
    make_unique<NullType>(),
...
};
```
5.	attr_type.h的所有字段类型的枚举列表中也需要添加NULL。

```
enum class AttrType
{
  UNDEFINED,
......
  NULLS,     ///< 空字段
......
};
```
6.	之后，新建null_type.cpp/.h，具体实现作为datatype子类的nulltype。compare()函数只返回 -1，表明NULL<任何值；to_string()把 NULL 值序列化为字符串的“NULL”；cast_to()函数定义了NULL可以转换为任意类型，但值仍然是 NULL。
```C++
class NullType : public DataType
{
public:
  NullType() : DataType(AttrType::NULLS) {}
  ~NullType() override {}
  int compare(const Value &left, const Value &right) const override;
  RC to_string(const Value &val, string &result) const override;
  RC cast_to(const Value &val, AttrType type, Value &result, bool allow_type_promotion = true) const override;
};
```
7.	修改expression.cpp的ComparisonExpr::compare_value，加入对NULL的判断。对于col IS NULL/col IS NOT NULL，将判断它是否为空；如果在=/</>等一般比较中存在NULL，固定返回false，因为null无法被比较。
```C++
RC ComparisonExpr::compare_value(const Value &left, const Value &right, bool &result) const
{
...
  if (comp_ == IS_OP) {
    if (right.attr_type() != AttrType::NULLS) {
      return RC::NOT_NULL_AFTER_IS;
    }
    result = left.is_null();
    return RC::SUCCESS;
  }
  if (left.is_null() || right.is_null()) {
    result = false;
    return RC::SUCCESS;
  }
}
...
```
8.	在表元数据文件table_meta.cpp的初始化函数TableMeta::init()中，初始化表内每个字段的时候为其附加nullable()；初始化表内属性的时候，调用具有nullable参数的FieldMeta::init()
```c++
    for (size_t i = 0; i < trx_fields->size(); i++) {
......
        field_meta.is_mutable();
        field_offset += field_meta.len();
    }
  for (size_t i = 0; i < attributes.size(); i++) {
......
        attr_info.nullable,
        attr_info.mutable_;
  }
```
9.	继续更改表元数据文件field_meta。成员变量中加入nullable_，传入初始化函数RC FieldMeta::init；加入FieldMeta::nullable()传递是否为NULL的判断；构造函数加入bool nullable参数。修改表基类base_table.cpp的记录插入函数BaseTable::make_record。插入每个value时，判断当前字段传入的值是否为 NULL。如果是 NULL但该字段非空，报错；否则，添加NULL的标记。
```C++
RC BaseTable::make_record(int value_num, const Value *values, Record &record)
{
    ......
  for (int i = 0; i < value_num && OB_SUCC(rc); i++) {
    ......
    // 判断是否在 NOT NULL 字段设置 NULL 值
    if (value.is_null()) {
      if (!field->nullable()) {
        return RC::NOT_NULLABLE_VALUE;
      }
      record_data[field->offset() + field->len() - 1] = '1';
    }
    ......
  }
}
```
## 3.12 update-select 
### 3.12.1 题目
更新查询选中的行数据。
此功能作为基础 update 功能的扩展，需要实现复杂查询语句基础上的更新操作，使 update 功能更加完善。
功能描述：更新字段的值为通过 SELECT 子查询得到的结果。子查询可能是普通的查询，也可能会带有聚合函数。
### 3.12.2 实现思路
这道题的实现思路围绕扩展UPDATE语句使其支持基于子查询的复杂更新操作展开，通过将SET子句中的右值统一抽象为表达式(expression)来实现功能扩展，使得更新值既可以是普通表达式也可以是包含聚合函数的子查询。在语法分析阶段，通过修改语法规则将SET子句的右值定义为expression类型，并保留原有的表达式处理机制，使得子查询能够自然地融入现有框架。在物理执行层面，UpdatePhysicalOperator通过动态类型识别和处理子查询表达式，严格验证子查询结果必须为单行单列，并集成类型检查和转换机制确保数据一致性，同时采用先收集所有待更新记录再批量处理的策略保证原子性。事务处理方面通过维护包含新旧值的日志记录支持回滚操作，与MVCC机制协同工作，在更新失败时能够正确回滚已修改的数据。整个实现充分利用了现有的表达式处理和算子框架，通过表达式类型的统一抽象和运行时处理，使得普通更新和基于子查询的更新共享相同的处理流程，在保证功能完整性的同时维持了系统的简洁性和扩展性。
### 3.12.3 实现方案
1.	语法分析阶段，update_stmt中set_clauses子句中，右值类型设定为expression，而expression中可以包含子查询(update-select)，也可以是普通表达式
```
set_clause:
      ID EQ expression
    {
      $$ = new SetClauseSqlNode;
      $$->field_name = $1;
      $$->value = std::unique_ptr<Expression>($3);
      free($1);
    }
    ;
```

```
struct SetClauseSqlNode
{
  std::string                 field_name;  ///< 更新的字段
  std::unique_ptr<Expression> value;       ///< 更新的值
};
```
2.	updte_stmt中，将select子查询与其他expression一起处理，不作修改
a.	原因：已经在expression_binder中实现了对SUBQUERY类型的expression类型的处理
b.	类型检查被延后, 为了允许表达式是子查询或变量，需要运行时计算类型
3.	UpdateLogicalOperator在原先的update的基础上无需修改
4.	UpdatePhysicalOperator 增加对子查询的支持
a.	子查询表达式处理
▪	代码中明确检查了 value_expr->type() == ExprType::SUBQUERY，识别出子查询表达式
▪	通过 dynamic_cast<SubQueryExpr *> 获取子查询表达式对象
▪	调用 sub_query_expr->open() 和 sub_query_expr->close() 来执行子查询
b.	子查询结果验证
▪	确保子查询只返回单行单列的结果（标准 SQL 对 UPDATE 子查询的要求）
c.	值处理流程
▪	对每个字段的值表达式（包括子查询）调用 get_value() 获取实际值
▪	对子查询结果进行类型检查和转换
▪	处理 NULL 值情况（包括检查非空约束）
d.	事务集成(题目update-mvcc)
▪	通过 trx_->update_record() 执行实际的更新操作
▪	维护 log_records 用于回滚（包含旧值和新值）
▪	提供 rollback() 方法在出错时撤销已做的更新
e.	类型安全
▪	对子查询返回的值进行严格的类型检查
▪	支持类型转换（但禁止非目标类型的类型提升）
▪	检查值长度是否符合字段定义
f.	注意
i.	会先收集所有待更新的记录，而不是一边遍历一边更新，保证更新操作的原子性
ii.	单独计算子查询的值(确保子查询只返回单行结果)，之后再进行更新操作，和普通update进行相同的处理
## 3.13 expression 
### 3.13.1 题目
实现表达式功能。
各种表达式运算是 SQL 的基础，有了表达式，才能使用 SQL 描述丰富的应用场景。
这里的表达式仅考虑算数表达式，可以参考现有实现的 calc 语句，可以参考 表达式解析 ，在 SELECT 语句中实现。
如果有些表达式运算结果有疑问，可以在 MySQL 中执行相应的 SQL，然后参考 MySQL 的执行即可。比如一个数字除以 0，应该按照 NULL 类型的数字来处理。
当然为了简化，这里只有数字类型的运算。
### 3.13.2 实现思路
这道题的实现思路是：首先在语法分析阶段构建表达式树，将SELECT语句中的条件（conditions）从ConditionSqlNode类转换为Expression类，从而统一表达式处理逻辑；接着修改FilterStmt的构造函数，使其基于Expression而非ConditionSqlNode构建；然后重构谓词逻辑算子（predicate_logical_operator）和物理算子（predicate_physical_operator），在物理算子中调用Expression已实现的get_value等功能完成运算。通过表达式抽象层整合算术运算、聚合、子查询等场景，利用表达式树统一处理运算优先级和类型转换（如除零返回NULL），最终实现支持数字类型运算的表达式功能，同时为其他SQL功能提供简洁的基础架构。
### 3.13.3 实现方案
1.	在语法分析阶段构建expression树(已实现)
2.	将select中的conditions从ConditionSqlNode类转换成expression类
```
struct SelectSqlNode
{
  std::vector<std::unique_ptr<Expression>> expressions;        ///< 查询的表达式
  std::vector<RelationNode>                relations;          ///< 查询的表
  std::unique_ptr<Expression>              conditions;         ///< 查询条件，使用AND串联起来多个条件
  std::vector<std::unique_ptr<Expression>> group_by;           ///< group by clause
  std::vector<OrderBySqlNode>              order_by;           ///< attributes in order clause
  std::unique_ptr<Expression>              having_conditions;  ///< having
  std::unique_ptr<LimitSqlNode>            limit;
};
```
3.	修改FilterStmt的构造函数，从由ConditionSqlNode构造，转换成由Expression构造
4.	构建predicate_logical_operator和predicate_physical_operator，在physical_operator中调用expression中已经实现的功能，完成get_value等操作
## 3.14 alias 
### 3.14.1 题目
实现字段、表别名的功能。
别名功能看起来不是数据库的必备功能，但是它可以极大地方便我们使用。比如美化或简化数据结构的输出、优化查询语句的编写。
表和列可以临时取别名，在打印结果时表和字段都打印别名（如果有）。
在查询时能够使用表的别名访问表的字段。两个表的别名在同一层查询中不能重复，子查询里面和外面的表的别名可以重复。列的别名只需要支持查询结果显示，不需要考虑使用别名进行运算和比较，也不考虑列的别名重复。
### 3.14.2 实现思路
别名有两种定义方式，一种需要as，一种直接定义。同时，别名在表、列都有应用。为此需要更改它们的语法结构。此外，在涉及”名字“的地方（表和列的操作），需要给别名设置和名字相似的接口，并在匹配名字时优先考虑别名。
### 3.14.3 实现方案
1.	在yacc_sql.y加入alias的语法单元，若为空则返回null，若为as ID/ID的形式，返回别名字符串。表达式的expression_list中，对于单个或者用逗号分隔的多个表达式别名，如果存在 alias，就设置别名。关系的rel_list同理，语法分析识别每个关系的别名，保存在RelationNode。
```
expression_list:
...
    | expression alias
    {
      $$ = new std::vector<std::unique_ptr<Expression>>;
      if (nullptr != $2) {
        $1->set_alias($2);
      }
...
    }
    | expression alias COMMA expression_list
    {
...
      if (nullptr != $2) {
        $1->set_alias($2);
      }
...
    }
    ;
    
    alias:
    /* empty */ {
      $$ = nullptr;
    }
    | ID {
      $$ = $1;
    }
    | AS ID {
      $$ = $2;
    }

rel_list:
    relation alias {
...
      if(nullptr!=$2){
        $$->emplace_back($1,$2);
        free($2);
      }
    }
    | relation alias COMMA rel_list {
...
      if(nullptr!=$2){
        $$->insert($$->begin(), RelationNode($1,$2));
        free($2);
      }
...
    }
    ;
```
    
    
2.	parse_def.h定义了RelationNode：一个关系节点由表名+表别名构成，表别名可为空。
```
/**
 * @brief 描述一个relation的节点
 */
struct RelationNode
{
  RelationNode(std::string relation_, std::string alias_) : relation(std::move(relation_)), alias(std::move(alias_)) {}
  explicit RelationNode(std::string relation_) : relation(std::move(relation_)) {}
  std::string relation;  ///< 查询的表
  std::string alias;     ///< 该表的别名 (may be NULL)
};
```

3.	修改select_stmt.cpp的逻辑：在SelectStmt::create中先初始化一个别名表，用于获取表中每个关系的别名。若别名不为空， 建立 alias->table 的映射，设置 BinderContext处理别名。
```C++
RC SelectStmt::create(Db *db, SelectSqlNode &select_sql, Stmt *&stmt,
    const std::unordered_map<std::string, BaseTable *> &parent_table_map)
{
  std::vector<std::string>           tables_alias(select_sql.relations.size());
  for (size_t i = 0; i < select_sql.relations.size(); i++) {
    BaseTable *table = db->find_table(table_name);
    // 建立别名
    auto &table_alias = select_sql.relations[i].alias;
    if (!table_alias.empty()) {
      const auto &success = temp_map.emplace(table_alias, table);
    ...
      temp_map.emplace(table_name, table);

    tables_alias[i] = table_alias;
    tables.emplace_back(table);
    binder_context.add_table(table);
    }
        ...
    binder_context.set_alias(tables_alias);
    binder_context.set_tables(&table_map);
    binder_context.set_default_table(default_table);
  }
}
```
4.	在expression_binder的BinderContext类中加入别名有关的接口。has_tables_alias()检查是否存在表别名，alias()获取上下文中的表别名，set_alias(std::string alias)将别名列表设置进上下文。
```C++
class BinderContext
{
public:
  bool has_tables_alias() { return !tables_alias_.empty(); }
  const std::vector<std::string> &alias() { return tables_alias_; }
  void set_alias(std::vector<std::string> alias) { tables_alias_ = std::move(alias); }
private:
...
  std::vector<std::string>                      tables_alias_;
...
};
```
5.	此外，表达式基类 Expression 提供了alias_ 及相关设置、判断函数，作用与上述接口相似。子类FieldExpr有接口set_table_alias(std::string table_alias)和成员变量table_alias_。set_table_alias应用于多个physical_operator中。
```C++
class Expression
{
...
  virtual const char *alias() const { return alias_.c_str(); }
  bool                has_alias() const { return !alias_.empty(); }
  virtual void        set_alias(std::string alias) { alias_ = std::move(alias); }

}
class FieldExpr : public Expression
{
  void set_table_alias(std::string table_alias) { table_alias_ = std::move(table_alias); }
private:
  Field       field_;
  std::string table_alias_;
};
```
6.	改进tuple_cell.cpp 中的 TupleCellSpec 构造函数，使其初始化包含别名的列信息。
```C++
TupleCellSpec::TupleCellSpec(const char *table_name, const char *field_name, const char *alias)
{
...
  if (alias) {
    alias_ = alias;
  }
  init_hash();
}
TupleCellSpec::TupleCellSpec(const char *alias)
{
  if (alias) {
    alias_ = alias;
  }
  init_hash();
}

TupleCellSpec::TupleCellSpec(const string &alias) : alias_(alias) {
 init_hash(); 
}
```
7.	tuple.h中的TupleSchema类加入了接收alias的append_cell()，RowTuple类加入了set_table_alias以设置表别名。更改在一行数据查找指定字段值的find_cell()函数，优先判断别名是否匹配。
```C++
class TupleSchema
{
  void append_cell(const char *alias) { append_cell(TupleCellSpec(alias)); }
}

class RowTuple : public Tuple
{
  void set_table_alias(std::string &alias) { table_alias_ = std::move(alias); }
  RC find_cell(const TupleCellSpec &spec, Value &cell) const override
  {
    if (!common::is_blank(alias)) {
      if (0 != strcmp(alias, table_alias_.c_str())) {
        return RC::NOTFOUND;
      }
    }
    if (0 != strcmp(table_name, table_->name())) {
      return RC::NOTFOUND;
    }
    ...
    Tuple *copy() const override
    {
    ...
        copy->table_alias_ = table_alias_;
        return copy;
    }
    private:
    ...
    std::string              table_alias_;
    }
}
```
8.	最后，在涉及别名的一些物理算子的构造函数中加入alias参数，加入设置别名/获取别名的接口，使别名在各用例得到应用。
## 3.15 text
### 3.15.1 题目
实现文本字段。
在数据库中，我们会有存储超大数据的需求，比如在数据库中存放网页。
这里考虑使用 text 字段，存放超大数据。参考 mysql 的实现， text 字段的最大长度为 65535 个字节，插入超出这个长度的数据就报错。
这里除了需要实现语法解析，还需要考虑如何在存储引擎中存放超长字段，扩展 record_manager，以支持超过一页的数据。
注意：这里接受的最大长度与 2022 年不同。
### 3.15.2 实现思路
类似date、null，text也是一种数据类型。创建新数据类型的流程我们已较为熟悉，但它的特殊之处在于超出Miniob页大小的空间。因此，需要一种合理的存储/复制方式。
### 3.15.3 实现方案
1.	从lex_sql.l出发，加入TEXT和TEXT_T的映射；yacc_sql.y在type中加入TEXT_T与TEXT属性的关联，attr_def则给予TEXTS的数据类型65535的长度。尽管如此，TEXTS的操作会避免完整的复制操作，减少多余数据的转移。
```
type:
    ...
    | TEXT_T     { $$ = static_cast<int>(AttrType::TEXTS);  }
    ;

   
    else if ($$->type == AttrType::TEXTS) {
            $$->length = 65535;}
```
2.	在data_type.cpp的DataType类静态数组type_instances_中加入
```C++
array<unique_ptr<DataType>, static_cast<int>(AttrType::MAXTYPE)> DataType::type_instances_ = {
...
    make_unique<TextType>(),
...
};
```

3.	attr_type.h的属性类型枚举AttrType也需要添加TEXTS,和null的实现过程类似。
```
enum class AttrType
{
...
  TEXTS,     ///< text 超长字段
...
};
```
4.	新建text_type.cpp/.h，实现texttype。text_type.cpp和多数属性一样，具有比较、转换类型、转为字符串的接口。
```C++
/**
 * @brief 固定长度的字符串类型
 * @ingroup DataType
 */
class TextType : public DataType
{
public:
...
  int compare(const Value &left, const Value &right) const override;
  RC cast_to(const Value &val, AttrType type, Value &result, bool allow_type_promotion = true) const override;
  RC set_value_from_str(Value &val, const string &data) const override;
  RC to_string(const Value &val, string &result) const override;
};
```
5.	在value.cpp中加入针对TEXTS的Value::borrow_text，能够将一个CHAR类型的字符串当作TEXT类型来使用，直接借用其内存指针，以避免拷贝。此外，它也检测长度是否大于65535的上限。
```C++
RC Value::borrow_text(const Value &v)
{
  ASSERT(v.attr_type() != AttrType::TEXTS, "Only text type can be borrowed! ");
  if (v.length_ > 65535) {
    return RC::VALUE_TOO_LONG;
  }
  reset();
  attr_type_            = AttrType::TEXTS;
  value_.pointer_value_ = v.value_.pointer_value_;
  length_               = v.length_;
  return RC::SUCCESS;
}
```
6.	接下来修改base_table.cpp。把字段值写入到记录中的BaseTable::set_value_to_record定义了要复制的长度copy_len和等于value长的data_len。对于TEXTS，只拷贝实际的value长度。BaseTable::make_record根据多值生成记录，当字段类型是TEXTS，value类型是字符串时，使用value.h的borrow函数避免拷贝。
```
if (field->type() != value.attr_type()) {
  if (field->type() == AttrType::TEXTS && value.attr_type() == AttrType::CHARS) {
    rc = real_value.borrow_text(value);
  }
}
```
3.16 order-by
3.16.1 题目
实现排序功能。
排序也是数据库的一个基本功能，就是将查询的结果按照指定的字段和顺序进行排序。
3.16.2 实现思路
这道题的实现思路是在MiniOB数据库中实现排序功能，主要通过添加Order by逻辑算子和物理算子来完成。首先在词法分析阶段识别关键字，语法分析阶段将order-by子句解析为OrderBySqlNode结构体，包含排序表达式和升降序标志。在select_stmt的create函数中处理order-by子句，绑定表达式并存储排序信息。然后构建OrderByLogicalOperator逻辑算子来存储排序表达式、方向和类型标识。物理算子OrderByPhysicalOperator负责实际排序执行，在open()时获取所有下级数据存入优先队列，并根据ORDER BY规则进行多字段排序（支持ASC/DESC混合排序），使用自定义优先队列比较函数实现内存中的排序，最后通过next()接口按排序顺序逐行返回结果。整个实现基于火山模型，采用阻塞式排序方式，先收集所有数据再排序输出。
3.16.3 实现方案
1.	词法分析阶段添加对关键字的识别
2.	语法分析阶段，select语句中，添加对order-by子句的识别，将其解析为OrderBySqlNode
```
struct OrderBySqlNode
{
  std::unique_ptr<Expression> expr;
  bool                        is_asc;  ///< 默认true 为升序
};
```
3.	在select_stmt的create函数中，添加对order-by子句的处理，对每一个expression进行bind_expression，并将所有需要排序的表达式和排序方向存储在select_stmt中
```C++
vector<unique_ptr<Expression>> order_by_expressions;
  for (OrderBySqlNode &unit : select_sql.order_by) {
    RC rc = expression_binder.bind_expression(unit.expr, order_by_expressions);
    if (OB_FAIL(rc)) {
      LOG_INFO("bind expression failed. rc=%s", strrc(rc));
      return rc;
    }
  }

  std::vector<OrderBySqlNode> order_by_;
  order_by_.reserve(order_by_expressions.size());
  for (size_t i = 0; i < order_by_expressions.size(); i++) {
    order_by_.push_back({std::move(order_by_expressions[i]), select_sql.order_by[i].is_asc});
  }
```
4.	构建逻辑算子OrderByLogicalOperator
核心功能
￮	存储 order by 信息
▪	排序表达式
▪	排序方向（升序 asc 或降序 desc ）
▪	这些信息存储在 std::vector<OrderBySqlNode> order_by_  中。
￮	提供访问接口
▪	ordorder_by() 方法返回排序规则的引用，允许执行器（如 PhysicalOperator）获取排序信息。
￮	标识逻辑算子类型
▪	type() 方法返回 LogicalOperatorType::ORDER_BY，用于在执行计划中识别这是一个排序算子。
5.	构建物理算子
核心功能
￮	排序执行
▪	输入：fetch_and_sort_tables() 在 open() 时调用，会先遍历所有下级数据，存入优先队列。
▪	排序：根据 ORDER BY 子句的规则对所有数据进行排序。
▪	输出：按排序后的顺序逐行返回结果。
￮	支持多字段排序
▪	支持 ORDER BY col1 ASC, col2 DESC 这种多字段混合排序。
▪	每个排序字段可以独立指定升序（ASC）或降序（DESC）。
￮	内存排序
▪	使用 优先队列（std::priority_queue） 实现内存中的排序。
▪	适用于数据量较小的场景（大数据量可能需要外部排序）。
6.	排序方法
优先队列
自定义优先队列的比较函数，实现多字段排序
```C++
OrderByPhysicalOperator::OrderByPhysicalOperator(vector<OrderBySqlNode> order_by) : order_by_(std::move(order_by))
{
  order_and_field_line = order_list([this](const order_line &cells_a, const order_line &cells_b) -> bool {
    auto  order_size   = order_by_.size();
    auto &order_line_a = cells_a.first;
    auto &order_line_b = cells_b.first;
    assert(order_line_a.size() == order_size);
    assert(order_line_b.size() == order_size);
    assert(order_by_.size() == order_size);

    for (size_t i = 0; i < order_size; i++) {
      auto &a      = order_line_a[i];
      auto &b      = order_line_b[i];
      auto  result = a.compare(b);
      auto  is_asc = order_by_[i].is_asc;
      if (result < 0) {
        // a < b
        return !is_asc;
      } else if (result > 0) {
        // a > 0
        return is_asc;
      }
    }
    return true;
  });
}
```
## 3.17 group-by
### 3.17.1 题目
实现数据分组功能。
分组功能也是数据库的基本功能之一，目的是为了方便用户查询数据结果，按照一定条件进行分组，方便分析数据。
按照一个或多个字段对查询结果分组，group by 中的聚合函数不要求支持表达式。
需要支持 having 子句，因为聚合函数不能出现在 where 后面，所以增加having 子句用于筛选分组后的数据。不过 having 只和聚合函数一起出现。
注意需要考虑分组字段为 null 的情况。
### 3.17.2 实现思路
这道题的实现思路是在MiniOB数据库中实现分组功能（GROUP BY）及其HAVING子句的支持。首先在词法分析阶段添加对GROUP BY和HAVING关键字的识别，语法分析阶段将GROUP BY和HAVING子句解析为表达式存储在SelectSqlNode中。在构建select_stmt时，处理GROUP BY表达式并绑定到上下文，同时对HAVING子句创建过滤条件（类似WHERE子句处理）。接着构建GroupByLogicalOperator逻辑算子来存储分组表达式和聚合表达式，并标识算子类型。物理算子HashGroupByPhysicalOperator负责实际分组执行，采用哈希分组策略：在open()阶段遍历下层算子的所有数据，通过find_group()查找或创建分组（处理NULL值情况），并用aggregate()更新聚合状态（如SUM/AVG等）；遍历完成后计算各分组的聚合结果，并通过next()逐个返回分组数据。HAVING算子的实现类似于谓词过滤，放置在执行计划最外层对分组结果进行筛选。整个过程基于火山模型，先收集并分组所有数据，再计算聚合结果并应用HAVING条件输出。
### 3.17.3 实现方案
1.	词法分析阶段，添加对group, having等关键字的支持
2.	语法分析阶段，添加opt_having和group_by子句，均以expression的形式存储在SelectSqlNode中
```
select_stmt:
    SELECT expression_list FROM rel_list where group_by opt_having opt_order_by opt_limit
    ...
```
3.	构建select_stmt的时候，添加对groupby和having的处理(对having子句的处理和对where子句的处理基本一致)
```
vector<unique_ptr<Expression>> group_by_expressions;
  for (unique_ptr<Expression> &expression : select_sql.group_by) {
    RC rc = expression_binder.bind_expression(expression, group_by_expressions);
    if (OB_FAIL(rc)) {
      LOG_INFO("bind expression failed. rc=%s", strrc(rc));
      return rc;
    }
  }
```
```
FilterStmt *having_filter_stmt = nullptr;
  rc                             = FilterStmt::create(
      db, default_table, binder_context.alias(), &table_map, select_sql.having_conditions, having_filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct having filter stmt");
    return rc;
  }
```
4.	逻辑算子
￮	构造函数：接收 分组表达式和聚合表达式
￮	访问方法：
▪	group_by_expressions(): 获取分组表达式
▪	aggregate_expressions(): 获取聚合表达式
￮	类型标识方法：
▪	type(): 返回逻辑操作符类型为 GROUP_BY
▪	get_op_type(): 返回操作类型为 LOGICALGROUPBY
5.	物理算子 HashGroupByPhysicalOperator
核心方法解析
(1) 构造函数
```
HashGroupByPhysicalOperator(vector<unique_ptr<Expression>> &&group_by_exprs, vector<Expression *> && expressions);
```
▪	作用：初始化分组表达式和聚合表达式。
▪	参数：
•	group_by_exprs：GROUP BY 的列（如 department）。
•	expressions：聚合函数（如 AVG(salary)）。
(2) open()
```
RC open(Trx *trx);
```
▪	执行流程：
1.	打开子算子：获取输入数据。
2.	遍历输入元组：
￮	调用 find_group() 查找或创建分组。
￮	调用 aggregate() 更新聚合状态。
3.	计算最终结果：遍历所有分组，调用 evaluate() 生成聚合结果。
4.	初始化迭代器：准备输出结果。
(3) next()
```
RC next();
```
▪	作用：逐个返回分组结果。
▪	逻辑：
•	首次调用返回第一个分组，后续调用移动迭代器。
•	结束时返回 RC::RECORD_EOF。
(4) current_tuple()
```
Tuple *current_tuple();
```
▪	作用：返回当前分组的聚合结果（CompositeTuple 包含分组键和聚合值）。
(5) find_group()
```
RC find_group(const Tuple &child_tuple, GroupType *&found_group);
```
▪	作用：根据输入元组的分组键查找或创建分组。
▪	流程：
1.	计算当前元组的分组键值（如 department 列的值）。
2.	线性查找（暂用线性查找）
￮	若找到匹配分组，返回该分组。
￮	若未找到，创建新分组并初始化聚合器。
分组聚合流程
以查询 SELECT department, AVG(salary) FROM employees GROUP BY department 为例：
a.	初始化：
▪	group_by_exprs_ = [department 列表达式]。
▪	aggregate_expressions_ = [AVG(salary)]。
b.	处理元组：
▪	输入元组 ("HR", 5000)：
•	计算分组键 "HR"，创建新分组。
•	调用 aggregate() 更新 AVG(salary) 的聚合器。
▪	输入元组 ("HR", 7000)：
•	找到现有 "HR" 分组，继续累积 AVG(salary)。
c.	输出结果：
▪	对 "HR" 分组调用 evaluate()，计算 AVG(salary) = 6000。
▪	返回结果元组 ("HR", 6000)。
6.	分组字段为null的情况
放在value的比较中，统一处理
## 3.18 create-view
### 3.18.1 题目
实现视图功能。
视图是数据库的基本功能之一。视图可以极大地方便数据库的使用。视图，顾名思义，就是一个能够自动执行查询语句的虚拟表。不过视图功能也非常复杂，需要考虑视图更新时如果更新实体表。
如果视图对应了单张表，并且没有虚拟字段，更新视图，即更新了实体表。
如果实体表中某些字段不在视图中，那此字段的结果应该是 NULL 或默认值。如果视图中包含虚拟字段，比如通过聚合查询的结果，或者视图关联了多张表，他的更新规则就变得复杂起来。在这些场景中，同学们可以参考 MySQL 的实现方案。
### 3.18.2 实现思路
这道题的实现思路是通过将视图作为虚拟表来处理，在数据库系统中建立视图的元数据管理机制。首先在词法和语法分析阶段添加对CREATE VIEW、DROP VIEW等语句的支持，解析视图定义时存储原始SELECT语句和列名信息。系统将视图视为一种特殊表，继承自基础表类，但实际不存储数据，而是保存视图定义的SQL语句和关联的基表信息。对于可更新视图的判断，通过检查是否包含多表连接、聚合函数、计算列等条件来标记视图的mutable属性。在执行层面，创建专门的CreateViewExecutor和DropViewExecutor来处理视图操作，其中创建视图时会解析并存储SELECT语句，删除视图则复用drop_table逻辑。对于DML操作，在执行前会检查视图是否可更新，包括验证是否包含连接、派生字段等限制条件，确保只有符合单表、无虚拟列等条件的视图才能进行修改操作。系统通过在TableMeta中增加mutable标记来管理视图的更新权限，并处理视图插入时的默认值填充问题，最终实现了视图作为虚拟表的基本功能，包括查询和有限的数据更新能力。
### 3.18.3 实现方案
1.	词法分析阶段，添加对view等关键字的支持
2.	语法分析阶段，添加对view进行操作的相关语句的支持
```
drop_view_stmt:
      DROP VIEW ID
    {
      $$ = new ParsedSqlNode(SCF_DROP_VIEW);
      $$->drop_view.relation_name = $3;
      free($3);
    }
    ;
```
```
C++
create_view_stmt:
      CREATE VIEW ID AS select_stmt
    {
      $$ = new ParsedSqlNode(SCF_CREATE_VIEW);
      CreateViewSqlNode &create_view = $$->create_view;
      create_view.relation_name = $3;
      create_view.create_view_select = std::make_unique<SelectSqlNode>(std::move($5->selection));
      free($3);
    }
    | CREATE VIEW ID LBRACE attr_list RBRACE AS select_stmt
    {
      $$ = new ParsedSqlNode(SCF_CREATE_VIEW);
      CreateViewSqlNode &create_view = $$->create_view;
      create_view.relation_name = $3;
      create_view.attribute_names = std::move(*$5);
      create_view.create_view_select = std::make_unique<SelectSqlNode>(std::move($8->selection));
      free($3);
    }
    ;
```
在parse_defs.h中创建CreateViewSqlNode，用于解析create语句；
视图中的attr也用AttrInfoSqlNode存储，在AttrInfoSqlNode中增加成员变量bool mutable = true，用于标记该字段是否可以插入修改；默认可插入修改；
3.	executor中，创建drop_view_executor
调用数据库对象的删除接口执行删除操作；
4.	拓展其他语句的功能，支持view
a.	insert_stmt, delete_stmt, update_stmt
i.	视图插入权限检查
```
if (table->type() == TableType::View) {
  if (!table->is_mutable()) {
    LOG_ERROR("The target table %s of the INSERT is not insertable-into", table->name());
    return RC::READ_ONLY_VIEW_INSERT_ERROR; // 只读视图禁止插入
  }
}
```
•	关键支持：通过 is_mutable() 检查视图是否可写
•	业务意义：实现 WITH CHECK OPTION 类似功能，阻止向不可更新视图插入数据
ii.	连接视图限制
```
auto view = dynamic_cast<View*>(table);
if (view->has_join()) {
  LOG_ERROR("Can not insert into join view '%s.%s' without fields list", db->name(), table->name());
  return RC::JOIN_VIEW_INSERT_ERROR; // 含JOIN的视图禁止插入
}
```
•	关键支持：通过 has_join() 检测视图是否包含多表连接
•	业务意义：遵守SQL标准对连接视图的插入限制（因无法确定实际修改的基表）
iii.	表达式字段检查
```
for (auto &field_meta : *field_metas) {
  if (!field_meta.is_mutable()) {
    LOG_ERROR("Column '%s' is not insertable", field_meta.name());
    return RC::EXPRESSION_FIELD_NOT_INSERTABLE; // 表达式生成的列禁止插入
  }
}
```
•	关键支持：检查视图列是否包含派生字段（如聚合函数、计算列）
•	业务意义：确保视图只包含可直接映射到基表物理列的字段
iv.	字段列表处理
```
if (!inserts.attr_names.empty()) {
  // 处理指定列名的插入语法（INSERT INTO view(col1,col2)...）
  for (int i = 0; i < inserts.attr_names.size(); ++i) {
    auto field_meta = table_meta.field(attr_name.c_str());
    // ...字段存在性检查...
  }
}
```
•	关键支持：允许通过属性名列表指定插入列
•	业务意义：支持部分列插入语法，适配视图可能只暴露基表部分列的场景
v.	空值处理机制
```
for (auto &value : values) {
  value.set_null(); // 初始化未指定列为NULL
}
```
•	关键支持：对未指定的视图列自动填充NULL
•	业务意义：符合SQL标准对视图插入的默认值处理要求
b.	create_index_stmt
禁止对视图创建索引
5.	增加create_view_stmt
功能概述
a.	CreateViewStmt类：表示一个创建视图的语句，继承自基础的Stmt类。
▪	存储视图名称、属性列名和对应的SELECT语句
▪	提供访问这些信息的接口方法
▪	标记语句类型为CREATE_VIEW
b.	create函数：静态工厂方法，用于创建CreateViewStmt对象
▪	解析CreateViewSqlNode中的信息
▪	验证视图定义的合法性
▪	创建最终的语句对象
6.	storage阶段
创建基类base_table，再创建派生类table和view，table用于处理普通table，view用于处理视图；
将select_sql_存储到view中；
在table_meta中增加字段mutable_，记录是否可通过视图修改
class View
```
std::string                              select_sql_;   // 持久化，运行时也只能存解析后的 sql，因为涉及独占资源的移动
std::vector<BaseTable *>                 tables_;       // 可能含视图和基表，所以要在所有表都加载好再处理
std::vector<std::pair<BaseTable *, int>> field_index_;  // 视图的 field 对应 哪个物理表和对应的 field idx
```
a.	只读视图
非field的表达式都是只读视图
包含聚合函数、groupby, having的是只读视图
b.	数据持久化，存储在文件中
6.	Executor
a.	create_view_executor
i.	获取创建视图的基本信息
```
auto create_view_stmt = static_cast<CreateViewStmt *>(stmt);
auto table_name = create_view_stmt->table_name().c_str();
auto select_stmt = create_view_stmt->select_stmt();
```
•	table_name：视图的名称
•	select_stmt：视图背后的查询语句（经过语法和语义分析）
•	注意：这里 select_stmt 是已分析好的语法树
ii.	提取原始 SQL 中 AS SELECT ... 部分
```
auto select_sql = extract_select_sql(sql_event->sql());
```
•	这一步把原始 SQL 字符串中 AS 后面的内容提取出来。
•	extract_select_sql() 会保留原始大小写（用于以后还原视图定义），虽然搜索时转换为小写进行匹配。
iii.	注册视图（核心逻辑）
```
rc = session->get_current_db()->create_table(
    table_name,
    std::move(create_view_stmt->attr_names()),
    std::move(select_sql),
    select_stmt,
    StorageFormat::ROW_FORMAT);
```
虽然看起来在调用 create_table()，但这实际上是把视图当作一种“特殊表”注册到数据库元信息中。
•	attr_names：视图的列名
•	select_sql：原始 SQL，用于记录和信息展示
•	select_stmt：可用于后续查询时复用解析好的语法树
•	ROW_FORMAT：虽然是视图，不存储数据，但仍可能使用这个字段作为元信息的一部分（可忽略）
这说明系统中视图被建模为一个特殊类型的“表”对象，区别在于它不存数据，而是持有一个查询语句。
b.	drop_view_executor
i.	从当前数据库中删除一个视图对象的元信息（逻辑上移除视图定义），实质上是调用底层的 drop_table() 来完成。
ii.	获取视图名称
```
auto *drop_view_stmt = dynamic_cast<DropViewStmt *>(stmt);
const char *table_name = drop_view_stmt->table_name().c_str();
```
•	提取视图名称。
•	DropViewStmt 是解析阶段提取的结构体，封装了 DROP VIEW 的目标视图名。
iii.	删除视图元信息
```
RC rc = session->get_current_db()->drop_table(table_name);
```
这里的重点是：视图在系统中是以“特殊表”的形式存在的，所以删除视图时直接复用了删除表的函数 drop_table()。
系统层面：
•	create_table(...) 用于注册视图（见你前面 CreateViewExecutor 的代码）
•	drop_table(...) 用于移除该注册项
所以，这里的 drop_table 实际也可以处理视图，只要数据库层能判断并正确处理逻辑表。
## 3.19 create-table-select
### 3.19.1 题目
复制表。
复制表并不是数据库中常用的功能，但是可以极大的方便我们测试与运维。其基本功能是在建表时通过select语句，直接创建出一张新的表，新表的结构通过 select 语句推导出来，数据会直接导入到新表中。
### 3.19.2 实现思路
这道题的实现思路是通过扩展语法分析来识别CREATE TABLE语句中的SELECT子句，并将其存储到create_table_select中，从而支持通过SELECT语句直接创建新表并导入数据。具体来说，首先在语法分析阶段处理多种CREATE TABLE语法形式，包括显式定义列和通过SELECT语句推导列结构的情况，将相关信息存储在CreateTableSqlNode结构体中。当检测到create_table_select存在时，执行逻辑会跳过常规的执行计划生成，转而直接处理：首先检查是否有显式指定的列定义，如果没有则从SELECT语句的查询表达式中推导出列定义（对于字段表达式使用原字段元信息，其他表达式则使用表达式自身的名称、类型等信息），接着创建目标表，然后执行SELECT查询生成逻辑计划和物理计划，通过物理执行器遍历查询结果并将每一行数据插入到新创建的表。
### 3.19.3 实现方案
1.	拓展语法分析，识别create中的select子句，存储到create_table_select中
```
create_table_stmt:    /*create table 语句的语法解析树*/
    CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format AS select_stmt
    {
        $$ = create_table_sql_node($3, $5, $6, $8, $10);
    }
    | CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format select_stmt
    {
        $$ = create_table_sql_node($3, $5, $6, $8, $9);
    }
    | CREATE TABLE ID LBRACE attr_def attr_def_list RBRACE storage_format
    {
        $$ = create_table_sql_node($3, $5, $6, $8, nullptr);
    }
    | CREATE TABLE ID storage_format AS select_stmt
    {
        $$ = create_table_sql_node($3, nullptr, nullptr, $4, $6);
    }
    | CREATE TABLE ID storage_format select_stmt
    {
      $$ = create_table_sql_node($3, nullptr, nullptr, $4, $5);
    }
    ;
```
```
struct CreateTableSqlNode
{
  std::string                    relation_name;        ///< Relation name
  std::vector<AttrInfoSqlNode>   attr_infos;           ///< attributes
  std::string                    storage_format;       ///< storage format
  std::unique_ptr<SelectSqlNode> create_table_select;  ///< create table select
};
```
2.	create_table_stmt中，也增加对子查询的处理，转换成select_stmt存储
3.	Create table语句不会生成执行计划，而是在executor中直接执行
当检测到 create_table_stmt->create_table_select_stmt() 存在时，就会执行 create-table-select 的逻辑：
a.	获取属性信息：
▪	首先检查是否有显式指定的列定义 (attr_infos)
▪	如果没有，则从 SELECT 语句的查询表达式中推导出列定义
▪	对于字段表达式 (FieldExpr)，使用原字段的元信息
▪	对于其他表达式，使用表达式的名称、类型和长度等信息
b.	创建表：
rc = session->get_current_db()->create_table(table_name, attr_infos, create_table_stmt->storage_format());
c.	执行查询并插入数据：
▪	生成逻辑计划 (LogicalPlanGenerator::create)
▪	生成物理计划 (PhysicalPlanGenerator::create)
▪	打开物理计划执行器 (physical_oper->open)
▪	遍历查询结果 (physical_oper->next)
▪	为每一行数据创建记录并插入到新表中
## 3.20 complex-sub-query
### 3.20.1 题目
1.	题目描述：
实现复杂子查询功能。
复杂子查询是简单子查询的升级。与其最大的不同就在于子查询中会跟复查询联动。注意需要考虑查询条件中带有聚合函数的情况。
2.	提示：
在复杂子查询中，要注意子查询和复查询的联动。也就是说，子查询作为单独的查询语句运行时，是要报错的。
一个简单的处理方法是，利用 static 关键字，加入静态局部变量，对复查询中行指针进行维护。子查询在确认需要联动查询之后，通过维护的复查询结果完成计算。
### 3.20.2 实现思路
复杂子查询需要考虑子查询与复查询联动的情况。经过对代码的分析，我发现关联子查询本质上是由外表驱动内表进行子查询，即对外表的每一行数据都进行一次子查询。由于简单子查询已经实现，我们的代码在语法上已支持子表间的嵌套，需要解决的是让子表使用外表的字段。如果子表能访问外表的tuple，问题就解决了。
### 3.20.3 实现方案
1.	注意到谓词物理算子的PredicatePhysicalOperator::next()函数，它从子算子中读取tuple，判断是否满足过滤条件。expression.cpp的get_value被用于进行比较。根据元组tp，它判断当前 tuple 是否满足谓词条件，将结果输出到value。
```
Plain Text
    rc = expression_->get_value(*tp, value);
    if (rc != RC::SUCCESS) {
      return rc;
    }
```
2.	在实现简单子查询修改的Expression::get_value() 中，当前 tuple作为参数被传递。借此，在子表使用open()的时候可以传给它元组。为此需要在物理算子添加接口。在physical_operator.h加入成员变量parent_tuple用于子查询。修改physical_operator.cpp，加入set_parent_tuple()，将当前的外层 tuple 绑定到整个物理算子树的每一个节点，递归地向所有子算子传播。
```C++
const Tuple *parent_tuple_ = nullptr; 

void PhysicalOperator::set_parent_tuple(const Tuple *tuple)
{
  parent_tuple_ = tuple;
  for (auto &child : children_) {
    child->set_parent_tuple(tuple);
  }
}
```
3.	继续修改之前定义的子查询表达式，调用之前定义的物理算子接口。
```
RC SubQueryExpr::open(Trx *trx, const Tuple &tuple)
{
  RC rc = RC::SUCCESS;
  physical_oper_->set_parent_tuple(&tuple);  //将当前tuple传入子算子
  rc = physical_oper_->open(trx);
  return rc;
}
```
这样，谓词的算子执行表达式的时候，表达式可以获取外部表的tuple，实现了复杂子查询的功能。
## 3.21 update-mvcc
### 3.21.1 题目
实现 MVCC 中的更新功能。
事务是数据库的基本功能，此功能希望同学们补充 MVCC （多版本并发控制）的 update 功能。这里主要考察不同连接同时操作数据库表时的问题。
事务管理在 MiniOB 并没有完善的实现，比如原子性提交、持久化、垃圾回收等。如果有兴趣的同学，可以给 MiniOB 提交 PR。
注意：
•	测试多连接，但不会测试多并发（即程序是串行执行的）；
•	启动 observer 程序时，需要增加`-t mvcc参数 ，比如 ./bin/observer -f ../etc/observer.ini -s miniob.sock -t mvcc`
•	测试过程中如果遇到官方代码自有的 BUG，请修复它，也欢迎提 PR。
### 3.21.2 实现思路
这道题的实现思路是在 UpdatePhysicalOperator 中增强 MVCC（多版本并发控制）的更新功能，确保事务的隔离性和原子性。核心在于通过事务对象 trx_ 间接执行更新操作（trx_->update_record()），而非直接修改数据，使事务系统能够在内部管理记录的不同版本。更新过程中，系统会维护一个 log_records 向量，记录每一条记录的旧值和新值，以便在发生错误时进行回滚（rollback()），即逆向执行所有更新操作，恢复原始数据。同时，代码处理了记录的 RID（Record ID）和基本 RID，表明系统支持多版本管理，确保并发事务能读取到适当的数据版本。此外，更新操作采用批处理方式，先收集所有待更新记录再统一执行，保证原子性——要么全部成功提交，要么全部回滚，避免部分更新导致的数据不一致。若更新中途失败，系统会立即触发回滚，确保事务的完整性。整体上，该方案通过事务日志、版本控制和原子性回滚机制，实现了 MVCC 的更新功能，适用于多连接（尽管串行执行）场景下的数据一致性维护。
### 3.21.3 实现方案
主要在UpdatePhysicalOperator中增加功能
1.	事务处理集成
￮	代码中通过 Trx *trx 参数将更新操作与事务系统集成
￮	所有更新操作都通过事务对象 trx_ 来执行 (trx_->update_record())
￮	这表明更新操作是在事务上下文中进行的，这是 MVCC 的基础
2.	更新操作的事务性
￮	更新操作不是直接修改数据，而是通过事务对象来执行：
￮	rc = trx_->update_record(table_, old_record, new_record);
￮	这种间接调用允许事务系统在内部实现 MVCC 机制
3.	回滚机制
￮	实现了完整的 rollback() 功能
￮	维护了 log_records 向量来记录所有更新前的旧记录和更新后的新记录
￮	vector<pair<Record, Record>> log_records;
￮	回滚时会逆向执行所有更新操作：
￮	rc = trx_->update_record(table_, rollback_new_record, rollback_old_record);
4.	原子性保证
￮	在更新过程中如果出现错误，会立即回滚所有已完成的更新：
￮	if (rc != RC::SUCCESS) {LOG_WARN("failed to update record: %s", strrc(rc));rollback();return rc;}
5.	记录版本管理
￮	代码中处理了记录的 RID (Record ID) 和基本 RID
￮	record.set_base_rids(tuple->base_rids());
￮	这表明系统可能维护了记录的不同版本，这是 MVCC 的核心概念
6.	批量更新的事务性
代码先收集所有要更新的记录，然后再执行更新，种批处理方式确保所有更新要么全部成功，要么全部回滚
## 3.22 big-query
### 3.22.1 题目
实现大数据量的更新与查询功能。
当前要求实现的大部分功能都是 SQL 相关的小数据量。这里考察大数据量的插入、更新与查询能力，同学们可能需要优化存储引擎、查询内存的使用。
这里会测试 1 到 3 张表，每张表有几千条数据。在插入数据工作完成后，会抽取一定量的数据做更新操作，然后进行数据抽查。
### 3.22.2 实现方案
本题需要实现大批量的数据插入、查询与更新。由于查询相关的代码结构良好，没有过多冗余操作，未经优化便通过了本题。
## 3.23 big-write
### 3.23.1 题目
实现大量数据的增删改查功能。
与 big-query 类似，这里考察大量数据的增删改查。同学们需要优化存储引擎、内存使用等，并确保程序稳定可靠。
对提前创建完成的表，做随机的增删改操作，然后通过查询校验数据是否有问题。
### 3.23.2 实现方案
完成前面的工作之后，本题即通过了，未做其他修改。
## 3.24 big-order-by
### 3.24.1 题目
大数据量的排序功能。
在内存有限的情况下，实现大数据量的排序，需要优化内存使用。注意，测试数据和数据量具备一定的随机性。
注意：order by 的查询语句，需要在大概 3 分钟内完成，并且第一条数据输出要在 10 秒以内（会有一定误差）。
有三四张表，每张表的数据量在 20 左右，所有表在一起做笛卡尔积查询，并且对每个字段都会做 order by 排序。通常这么大的数据量不能在短时间内排序完成，所以需要考虑优化数据的存放和拉取。
### 3.24.2 实现方案
在order-by中采用优先队列(priority_queue)的方式排序，本题直接通过，未做其他修改。

1. AI使用说明
本次课程设计部分使用AI大模型作为辅助工具。完成项目的过程中，我们借助了大语言模型解释原始代码中用到的C++语法、库函数。遭遇难以分析的编译错误时，有限使用了大模型查找不易发现的漏洞。报告撰写阶段，用自己的理解搭配大模型总结代码功能。尽管AI简化了代码阅读难度，省去了部分总结工作，但Miniob的功能实现由我们亲手完成。
1. 实践心得
本次课程设计中，由于是在已有的代码架构上修改，我们不能使用自己熟悉的方式实现数据库的功能。这迫使我们深入了解C++和yacc DSL，某种程度上重温了编译原理的知识。为了通过测试用例，也必须了解各类SQL语法，上学期的数据库系统原理为此打下了基础。miniob的结构给了我很多启发，一次sql查询涉及语法解析，创建物理/逻辑算子或调用执行器，最后才实际地访问表、元组、索引、字段的元数据。这和我学习数据库时想当然地将查询理解为“遍历查找”有很大出入。然而，项目过大的体量、C++知识的欠缺以及官网模糊的教程对完成课程设计构成了不小的挑战。在逐渐理解陌生的语法，阅读日志分析查询到底经过了哪些部分的代码后，项目才真正开始有进展。
在完成所有题目的过程中，我发现前面遗留的隐患，很有可能会在做后面的题的时候暴露出来；实现不同功能的时候所涉及的代码都在相互影响。这使我深刻的意识到，大型项目中每个细节都举足轻重；在进行修改时，必须深刻领会所修改部分起到的作用，明白它会产生哪些影响，在修改完成后应及时做充分的测试；在需要完成多个功能时，应汇总所有需要完成的任务，合理安排顺序，避免在做后面的题目的时候，前面的题目都要重新修改的问题。
1. 总结
本次课程设计，我们基于一个简易MiniOB数据库系统，通过扩展其内核功能实现了一个具备完整核心功能的数据库管理系统。项目从词法分析、语法解析到存储引擎、查询优化等层面进行了全方位改造，最终实现了包括数据类型扩展、SQL功能增强、事务支持、性能优化等数项拓展功能。
系统采用模块化设计，包含网络通信、SQL解析、查询优化、执行引擎、存储管理、事务处理等核心组件。通过本次实践，我们深入理解了数据库内核各模块的协同工作机制，掌握了B+树索引、火山模型执行引擎、表达式处理等关键技术，并提升了大型C++项目的工程实践能力。
项目所有功能均已通过平台测试，代码已提交至GitHub仓库[Ymm的miniob](https://github.com/Y-M-M/miniob)，开发环境基于Gitpod、Docker和VSCode。在实现过程中，我们特别注重代码的可扩展性和健壮性，为每个功能模块设计了清晰的接口和测试用例。

