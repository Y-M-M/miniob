#include "storage/db/db.h"
#include "sql/stmt/show_index_stmt.h"

ShowIndexStmt::ShowIndexStmt(const std::string &table_name) : table_name_(table_name) {}

RC ShowIndexStmt::create(Db *db, const ShowIndexSqlNode &show_index, Stmt *&stmt)
{
  if (db->find_table(show_index.relation_name.c_str()) == nullptr) {
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }
  stmt = new ShowIndexStmt(show_index.relation_name);
  return RC::SUCCESS;
}
