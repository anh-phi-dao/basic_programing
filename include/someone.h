#ifndef SOMEONE_H
#define SOMEONE_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

#define INFORMAL -1

/**
 * @brief: if informal_income="tuytam" or "henxui" formal_income_vnd=INFORMAL
 *         if formal_income_vnd>=0 informal_income=NULL
 */
typedef struct money
{
    char *informal_income;
    int formal_income_vnd;
} income_t;

typedef struct people someone_t;

/**
 * @brief: 3 types of people including "anxin", "antrom", "congnhan"
 *          income and action are based on what kind of person are you
 */
struct people
{
    income_t income;
    char *type;
    char *(*action)(someone_t *person);
    char state;
};

/**
 * @brief: this enum is for generating random type of person
 */
enum
{
    AN_XIN,
    AN_TROM,
    CONG_NHAN,
};

/**
 * @brief: this enum is for returning the state of generating people process
 */
enum
{
    ERROR = -1,
    NORMAL,
    COMPLETE
};

/**
 * @brief generate random type of that person
 * @param: someone_t *someone
 * @return: int=0 -> NORMAL / int=1->COMPLETE / int = -1->ERROR
 * **/
int generate_people(someone_t *someone);
/**
 * @brief generate "antrom" type of person
 * @param: someone_t *someone
 * @return: the state of excecuting the function, ERROR= fail
 *                                                COMPLETE =success
 * **/
int generate_anxin(someone_t *someone);
/**
 * @brief generate "antrom" type of person
 * @param: someone_t *someone
 * @return: the state of excecuting the function, ERROR= fail
 *                                                COMPLETE =success
 * **/
int generate_antrom(someone_t *someone);
/**
 * @brief generate "congnhan" type of person
 * @param: someone_t *someone
 * @return: the state of excecuting the function, ERROR= fail
 *                                                COMPLETE =success
 * **/
int generate_congnhan(someone_t *someone);

/**
 * @brief: action of "anxin"
 * @param: someone_t *someone
 * @return : char *storing_string
 * @note: must check result string, if the string is NULL , that means this function has failed
 * **/
char *cadge(someone_t *person);
/**
 * @brief: action of "antrom"
 * @param: someone_t *someone
 * @return : char *storing_string
 * @note: must check result string, if the string is NULL , that means this function has failed
 * **/
char *stole(someone_t *person);
/**
 * @brief: action of "congnhan"
 * @param: someone_t *someone
 * @return : char *storing_string
 * @note: must check result string, if the string is NULL , that means this function has failed
 * **/
char *work(someone_t *person);

#endif