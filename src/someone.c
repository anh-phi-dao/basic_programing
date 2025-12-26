#include "someone.h"

int generate_people(someone_t *someone)
{
    int type_in_number = rand() % 3;
    int state = 0;
    switch (type_in_number)
    {
    case AN_XIN:
        state = generate_anxin(someone);
        break;

    case AN_TROM:
        state = generate_antrom(someone);
        break;

    case CONG_NHAN:
        state = generate_congnhan(someone);
        break;
    default:
        printf("Error during generation process\n");
        return ERROR;
    }
    return state;
}

int generate_anxin(someone_t *someone)
{
    someone->type = (char *)malloc(sizeof(char) * 10);
    if (someone->type == NULL)
    {
        someone->state = ERROR;
        return ERROR;
    }
    sprintf(someone->type, "anxin");
    someone->income.informal_income = (char *)malloc(sizeof(char) * 10);
    if (someone->income.informal_income == NULL)
    {
        free(someone->type);
        someone->type = NULL;
        someone->state = ERROR;
        return ERROR;
    }
    sprintf(someone->income.informal_income, "tuytam");
    someone->income.formal_income_vnd = INFORMAL;
    someone->action = cadge;
    someone->state = NORMAL;
    return COMPLETE;
}

int generate_antrom(someone_t *someone)
{
    someone->type = (char *)malloc(sizeof(char) * 10);
    if (someone->type == NULL)
    {
        someone->state = ERROR;
        return ERROR;
    }
    sprintf(someone->type, "antrom");
    someone->income.informal_income = (char *)malloc(sizeof(char) * 10);
    if (someone->income.informal_income == NULL)
    {
        free(someone->type);
        someone->type = NULL;
        someone->state = ERROR;
        return ERROR;
    }
    sprintf(someone->income.informal_income, "henxui");
    someone->income.formal_income_vnd = INFORMAL;
    someone->action = stole;
    someone->state = NORMAL;
    return COMPLETE;
}

int generate_congnhan(someone_t *someone)
{
    someone->type = (char *)malloc(sizeof(char) * 10);
    if (someone->type == NULL)
    {
        someone->state = ERROR;
        return ERROR;
    }
    sprintf(someone->type, "congnhan");
    someone->income.informal_income = NULL;
    someone->income.formal_income_vnd = 500000;
    someone->action = work;
    someone->state = NORMAL;
    return COMPLETE;
}

char *cadge(someone_t *person)
{
    char *storing_string = (char *)malloc(50 * sizeof(char));
    if (storing_string == NULL)
    {
        return storing_string;
    }
    sprintf(storing_string, "Lam on binh phuoc\n");
    printf("%s", storing_string);
    return storing_string;
}

char *stole(someone_t *person)
{
    char *storing_string = (char *)malloc(10 * sizeof(char));
    if (storing_string == NULL)
    {
        return storing_string;
    }
    sprintf(storing_string, "!!!\n");
    printf("%s", storing_string);
    return storing_string;
}

char *work(someone_t *person)
{
    char *storing_string = (char *)malloc(50 * sizeof(char));
    if (storing_string == NULL)
    {
        return storing_string;
    }
    sprintf(storing_string, "income=%d\n", person->income.formal_income_vnd);
    printf("%s", storing_string);
    return storing_string;
}