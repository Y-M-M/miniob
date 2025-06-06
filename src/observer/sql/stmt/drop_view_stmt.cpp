#include "drop_view_stmt.h"
#include "event/sql_debug.h"

RC DropViewStmt::create(Db *db, const DropViewSqlNode &drop_view, Stmt *&stmt)
{
  stmt = new DropViewStmt(drop_view.relation_name);
  sql_debug("drop view statement: view name %s", drop_view.relation_name.c_str());
  return RC::SUCCESS;
}
