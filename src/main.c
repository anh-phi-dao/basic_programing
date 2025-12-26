#include "main.h"
#include "someone.h"

someone_t people[MAX_PEOPLE];

int main()
{
    srand(time(0));
    char *string = NULL;
    int N = rand() % MAX_PEOPLE + 1;
    int actual_people = 0;
    for (int i = 0; i < N; i++)
    {
        generate_people(people + i);
    }
    FILE *file_ptr = fopen(FILE_NAME, "w");

    for (int i = 0; i < N; i++)
    {
        if (people[i].state == ERROR)
        {
            continue;
        }
        string = people[i].action(people + i);
        if (string == NULL)
        {
            continue;
        }
        fputs(string, file_ptr);
        free(string); /*free memory from people[i].actions*/
        actual_people++;
    }

    string = (char *)malloc(30 * sizeof(char));
    sprintf(string, "Number of people=%d\n", N);
    fputs(string, file_ptr);
    sprintf(string, "Number of actual people=%d\n", actual_people);
    fputs(string, file_ptr);
    free(string);
    fclose(file_ptr);

    return 0;
}