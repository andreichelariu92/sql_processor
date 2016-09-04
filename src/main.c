#include <stdio.h>
#include <stdlib.h>

#include "src/sql_processor.h"
#include "src/simple_string.h"
#include "src/reference_counter.h"
int main()
{
        SP_Init();
        int db_id = SP_OpenDb("./test");
        printf("DB id = %d\n", db_id);
        const char* res = SP_Exec(db_id, "SELECT * FROM lost_opportunities o WHERE o.day=\"2016-09-03\"");

        printf("QUERY RESULT\n %s", res);

        free(res);
        SP_CloseDb(db_id);
        return 0;
}
