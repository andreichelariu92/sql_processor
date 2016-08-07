#ifndef SQL_PROCESSOR_H
#define SQL_PROCESSOR_H

/**
  * \brief
  * The maximum number of connections that can
  * be made to the database.
  */
#define MAX_CONNECTIONS 8

/**
 * \brief SP_Init
 * Function that initializes the SQL PROCESSOR module.
 * This function must be called before any other function
 * of the module gets used.
 *
 * \return
 * 0 in case of success, otherwise an error code.
 */
int SP_Init();

/**
 * \brief SP_OpenDb
 * Opens a connection to an existing database.
 *
 * \param db_name
 * The name of the database.
 *
 * \return
 * A database identificator. This id can then be used
 * for SQL queries. At the end of the program, the coonection
 * to the database must be closed. If there is no database with
 * the given name, -1 is returned.
 */
int SP_OpenDb(const char* db_name);

/**
 * \brief SP_CloseDb
 * Closes the connection with the given id. If the id is -1, then
 * the function does nothing.
 *
 * \param dbId
 * The id of the database.
 *
 * \return
 * O on success, otherwise an error code.
 */
int SP_CloseDb(int dbId);

/**
 * \brief SP_Exec
 * Executes the given SQL statement and returns a pointer to
 * a character string that contains the result of the statement.
 *
 * \param dbId
 * The id of the database connection on which the statement will be
 * executed.
 *
 * \param statement
 * Pointer to a SQL statement stored as a C string. The client code
 * is responsible for the management of the C string.
 *
 * \return
 * Pointer to a C string that contains the result of the SQL statement.
 * If there was an error, then 0 is returned. The client code is
 * responsible for the management of the returned string.
 */
const char* SP_Exec(int dbId, const char* statement);
#endif // SQL_PROCESSOR_H
