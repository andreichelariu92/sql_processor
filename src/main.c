#include <stdio.h>

#include "src/sql_processor.h"
#include "src/simple_string.h"
#include "src/reference_counter.h"
int main()
{
        SP_Init();
        int db_id = SP_OpenDb("./test");
        printf("DB id = %d\n", db_id);
        SP_Exec(db_id, "SELECT * FROM test;");
        printf("%d\n", SP_CloseDb(2));

        /*
        struct simple_string* s1 = SS_Create("Salut ");
        struct simple_string* s2 = SS_Create("Andrei");

        SS_Append(s1, s2);
        printf("%s\n", SS_Get(s1));


        SS_Distroy(s1);
        SS_Distroy(s2);
        */
        return 0;
}
