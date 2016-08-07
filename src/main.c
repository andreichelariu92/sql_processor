#include <stdio.h>

#include "sql_processor.h"
int main()
{
        SP_Init();
        int db_id = SP_OpenDb("./test");
        printf("DB id = %d\n", db_id);
        SP_Exec(db_id, "SELECT * FROM test;");
        printf("%d\n", SP_CloseDb(2));
        return 0;
}
