#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "sql_processor.h"

#include <sqlite3.h>

/************************ Module variables *************************************/

/**
 * \brief SP_Initialized
 * Flag that specifies if the module has been initialized or not.
 */
static int SP_Initialized = 0;
/**
 * \brief SP_ConnectionCount
 * Module variable that holds the current number of active connections.
 */
static int SP_ConnectionCount = 0;

/**
 * \brief SP_Connections
 * Module variable that holds all the active connections.
 */
static sqlite3* SP_Connections[MAX_CONNECTIONS];

/************************ Private functions *************************************/
static const char* appendString(const char** first,
                                int* sizeFirst,
                                const char* after)
{
        const int availableChars = *sizeFirst - (strlen(*first) + 1);

}

/************************ Public functions *************************************/
int SP_Init()
{
        memset(SP_Connections, 0, sizeof(sqlite3*)*MAX_CONNECTIONS);
        SP_Initialized = 1;
        return 0;
}

int SP_OpenDb(const char * db_name)
{
        int ret = sqlite3_open_v2(db_name,
                                  &SP_Connections[SP_ConnectionCount],
                                  SQLITE_OPEN_READWRITE,
                                  NULL);

        if (ret) {
                /*clear any address set by the SQLITE engine*/
                SP_Connections[SP_ConnectionCount] = 0;
                return -1;
        }
        else {
                return (SP_ConnectionCount++);
        }
}

int SP_CloseDb(int dbId)
{
        if (dbId < 0 || dbId >= MAX_CONNECTIONS){
                return 0;
        }

        SP_ConnectionCount--;

        sqlite3* db = SP_Connections[dbId];
        return sqlite3_close(db);
}

const char* SP_Exec(int dbId, const char *statement)
{
        if (dbId < 0 || dbId >= MAX_CONNECTIONS) {
                return 0;
        }

        /*compile the statement*/
        sqlite3_stmt* compiledStatement;
        sqlite3_prepare_v2(SP_Connections[dbId],
                           statement,
                           -1,/*go to the first NULL terminator*/
                           &compiledStatement,
                           0);
        if (compiledStatement == 0){
                return 0;
        }

        /*parse the result and build the response string*/
        const int colCount = sqlite3_column_count(compiledStatement);
        while (sqlite3_step(compiledStatement) == SQLITE_ROW) {
                int colIdx = 0;
                for (colIdx = 0; colIdx < colCount; ++colIdx) {
                        printf("%s ", sqlite3_column_text(compiledStatement, colIdx));
                }

                printf("\n");
        }

        return 0;
}
