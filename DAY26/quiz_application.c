#include <stdio.h>

int main() {
    char name[50];
    int roll;
    float marks;

    printf("===== Student Information Application =====\n");

    printf("Enter Student Name: ");
    scanf("%s", name);

    printf("Enter Roll Number: ");
    scanf("%d", &roll);

    printf("Enter Marks: ");
    scanf("%f", &marks);

    printf("\n===== Student Details =====\n");
    printf("Name : %s\n", name);
    printf("Roll No : %d\n", roll);
    printf("Marks : %.2f\n", marks);

    if(marks >= 40)
        printf("Result : Pass\n");
    else
        printf("Result : Fail\n");

    return 0;
}