#include "someone.h"

/**
 * Purpose: generate random type of that person
 * @param: someone_t *someone
 * @return: int=0 -> NORMAL / int=1->COMPLETE / int = -1->ERROR
 * **/
int generate_people(someone_t *someone)
{
    int type_in_number = rand() % 3;
    switch (type_in_number)
    {
    case AN_XIN:
        generate_anxin(someone);
        break;

    case AN_TROM:
        generate_antrom(someone);
        break;

    case CONG_NHAN:
        generate_congnhan(someone);
        break;
    default:
        printf("Error during generation process\n");
        return ERROR;
    }
    return COMPLETE;
}

/**
 * Purpose: generate "anxin" type of person
 * @param: someone_t *someone
 * **/
int generate_anxin(someone_t *someone)
{
    someone->type = malloc(sizeof(char) * 5);
    if (someone->type == NULL)
    {
        return ERROR;
    }
    sprintf(someone->type, "anxin");
    someone->income.informal_income = malloc(sizeof(char) * 5);
    if (someone->income.informal_income == NULL)
    {
        if (someone->type != NULL)
        {
            free(someone->type);
        }
        return ERROR;
    }
    sprintf(someone->income.informal_income, "tuytam");
    someone->income.formal_income_vnd = INFORMAL;
    someone->action = cadge;
    return COMPLETE;
}

/**
 * Purpose: generate "antrom" type of person
 * @param: someone_t *someone
 * **/
int generate_antrom(someone_t *someone)
{
    someone->type = malloc(sizeof(char) * 6);
    if (someone->type == NULL)
    {
        return ERROR;
    }
    sprintf(someone->type, "antrom");
    someone->income.informal_income = malloc(sizeof(char) * 5);
    if (someone->income.informal_income == NULL)
    {
        if (someone->type != NULL)
        {
            free(someone->type);
        }
        return ERROR;
    }
    sprintf(someone->income.informal_income, "henxui");
    someone->income.formal_income_vnd = INFORMAL;
    someone->action = stole;
    return COMPLETE;
}

/**
 * Purpose: generate "congnhan" type of person
 * @param: someone_t *someone
 * **/
int generate_congnhan(someone_t *someone)
{
    someone->type = malloc(sizeof(char) * 8);
    if (someone->type == NULL)
    {
        return ERROR;
    }
    sprintf(someone->type, "congnhan");
    someone->income.informal_income = NULL;
    if (someone->income.informal_income == NULL)
    {
        if (someone->type != NULL)
        {
            free(someone->type);
        }
        return ERROR;
    }
    someone->income.formal_income_vnd = 500000;
    someone->action = work;
    return COMPLETE;
}

/**
 * @brief: action of "anxin"
 * @param: someone_t *someone
 * @return : char *storing_string
 * **/
char *cadge(someone_t *person)
{
    char *storing_string = (char *)malloc(50 * sizeof(char));
    sprintf(storing_string, "Lam on binh phuoc\n");
    printf("%s", storing_string);
    return storing_string;
}

/**
 * @brief: action of "antrom"
 * @param: someone_t *someone
 * @return : char *storing_string
 * **/
char *stole(someone_t *person)
{
    char *storing_string = (char *)malloc(10 * sizeof(char));
    sprintf(storing_string, "!!!\n");
    printf("%s", storing_string);
    return storing_string;
}

/**
 * @brief: action of "congnhan"
 * @param: someone_t *someone
 * @return : char *storing_string
 * **/
char *work(someone_t *person)
{
    char *storing_string = (char *)malloc(50 * sizeof(char));
    sprintf(storing_string, "income=%d\n", person->income.formal_income_vnd);
    printf("%s", storing_string);
    return storing_string;
}