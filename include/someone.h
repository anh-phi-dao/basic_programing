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

struct people
{
    income_t income;
    char *type;
    char *(*action)(someone_t *person);
};

enum
{
    AN_XIN,
    AN_TROM,
    CONG_NHAN,
};

enum
{
    ERROR,
    NORMAL,
    COMPLETE
};

int generate_people(someone_t *someone);
void generate_anxin(someone_t *someone);
void generate_antrom(someone_t *someone);
void generate_congnhan(someone_t *someone);

char *cadge(someone_t *person);
char *stole(someone_t *person);
char *work(someone_t *person);

#endif