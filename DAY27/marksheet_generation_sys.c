#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float m1, m2, m3, m4, m5;
    float total, percentage;
    char grade;
    char result[10];
};

int main()
{
    struct Student s[100];
    int n, i;

    printf("Enter Number of Students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {

        printf("\nEnter Details of Student %d\n", i + 1);

        printf("Roll Number: ");
        scanf("%d", &s[i].roll);

        printf("Name: ");
        scanf("%s", s[i].name);

        do
        {
            printf("Marks in Subject 1 (0-100): ");
            scanf("%f", &s[i].m1);
            if (s[i].m1 < 0 || s[i].m1 > 100)
                printf("Invalid Marks! Enter again.\n");
        } while (s[i].m1 < 0 || s[i].m1 > 100);

        do
        {
            printf("Marks in Subject 2 (0-100): ");
            scanf("%f", &s[i].m2);
            if (s[i].m2 < 0 || s[i].m2 > 100)
                printf("Invalid Marks! Enter again.\n");
        } while (s[i].m2 < 0 || s[i].m2 > 100);

        do
        {
            printf("Marks in Subject 3 (0-100): ");
            scanf("%f", &s[i].m3);
            if (s[i].m3 < 0 || s[i].m3 > 100)
                printf("Invalid Marks! Enter again.\n");
        } while (s[i].m3 < 0 || s[i].m3 > 100);

        do
        {
            printf("Marks in Subject 4 (0-100): ");
            scanf("%f", &s[i].m4);
            if (s[i].m4 < 0 || s[i].m4 > 100)
                printf("Invalid Marks! Enter again.\n");
        } while (s[i].m4 < 0 || s[i].m4 > 100);

        do
        {
            printf("Marks in Subject 5 (0-100): ");
            scanf("%f", &s[i].m5);
            if (s[i].m5 < 0 || s[i].m5 > 100)
                printf("Invalid Marks! Enter again.\n");
        } while (s[i].m5 < 0 || s[i].m5 > 100);

        s[i].total = s[i].m1 + s[i].m2 + s[i].m3 + s[i].m4 + s[i].m5;
        s[i].percentage = s[i].total / 5;

        if (s[i].m1 < 40 || s[i].m2 < 40 || s[i].m3 < 40 ||
            s[i].m4 < 40 || s[i].m5 < 40)
        {

            sprintf(s[i].result, "FAIL");
            s[i].grade = 'F';
        }
        else
        {

            sprintf(s[i].result, "PASS");

            if (s[i].percentage >= 90)
                s[i].grade = 'A';
            else if (s[i].percentage >= 75)
                s[i].grade = 'B';
            else if (s[i].percentage >= 60)
                s[i].grade = 'C';
            else
                s[i].grade = 'D';
        }
    }

    printf("\n================== MARKSHEET ==================\n");

    for (i = 0; i < n; i++)
    {

        printf("\nStudent %d\n", i + 1);
        printf("Roll Number : %d\n", s[i].roll);
        printf("Name        : %s\n", s[i].name);
        printf("Total Marks : %.2f / 500\n", s[i].total);
        printf("Percentage  : %.2f%%\n", s[i].percentage);
        printf("Grade       : %c\n", s[i].grade);
        printf("Result      : %s\n", s[i].result);
    }

    return 0;
}