#include <stdio.h>

int main()
{
    int students, subjects;

    printf("Enter the number of students to be recorded\n");
    scanf("%d", &students);
    printf("Enter the number of subjects to be recorded\n");
    scanf("%d", &subjects);

    int student[students][subjects];

    for (int i = 0; i < students; i++)
    {
        for (int j = 0; j < subjects; j++)
        {
            printf("Enter the marks of student %d in subject %d\n", i + 1, j + 1);
            scanf("%d", &student[i][j]);
        }
    }
    for (int i = 0; i < students; i++)
    {
        for (int j = 0; j < subjects; j++)
        {
            printf("The marks of student %d in subject %d is %d\n", i + 1, j + 1, student[i][j]);
        }
    }

    return 0;
}
