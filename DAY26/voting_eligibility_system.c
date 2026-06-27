#include <stdio.h>

int main() {
    char name[50];
    int age;

    printf("=== Voting Eligibility System ===\n");

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter your age: ");
    scanf("%d", &age);

    if (age >= 18) {
        printf("\n%s is eligible to vote.\n", name);
    } else {
        printf("\n%s is not eligible to vote.\n", name);
        printf("You can vote after %d year(s).\n", 18 - age);
    }

    return 0;
}