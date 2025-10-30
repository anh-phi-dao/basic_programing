#include "main.h"
#include "linux/net.h"

someone_t people[MAX_PEOPLE];

int main()
{
    srand(time(0));
    char *string = NULL;
    int N = rand() % MAX_PEOPLE + 1;
    for (int i = 0; i < N; i++)
    {
        generate_people(people + i);
    }
    FILE *file_ptr = fopen(FILE_NAME, "w");

    for (int i = 0; i < N; i++)
    {
        string = people[i].action(people + i);
        fputs(string, file_ptr);
        free(string); /*free memory from people[i].actions*/
    }

    string = (char *)malloc(30 * sizeof(char));
    sprintf(string, "Number of people=%d\n", N);
    fputs(string, file_ptr);
    free(string);
    fclose(file_ptr);

    return 0;
}