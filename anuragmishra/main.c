#include <stdio.h>
#include "mylib.h"
#include "arraylib.h"

int main() {
    int choice, num;
    int numbers[] = {12, 70, 153, 13, 23};
    int size = 5;
    int backup[size];
    copyArray(numbers, backup, size);

    do {
        printf("\nChoose Your Operation:\n");
        printf("1. Check Armstrong Number\n");
        printf("2. Check Adams Number\n");
        printf("3. Check Prime Palindrome Number\n");
        printf("4. Array Operations\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Exiting program. Goodbye!\n");
            break;
        }

        if (choice >= 1 && choice <= 3) {
            printf("Enter a number: ");
            scanf("%d", &num);
        }

        switch (choice) {
            case 1:
                printf("%d is %san Armstrong number.\n", num,
                       isArmstrongNumber(num) ? "" : "NOT ");
                break;
            case 2:
                printf("%d is %san Adams number.\n", num,
                       isAdamsNumber(num) ? "" : "NOT ");
                break;
            case 3:
                printf("%d is %sa Prime Palindrome number.\n", num,
                       isPrimePalindrome(num) ? "" : "NOT ");
                break;
            case 4:
                displayArray(numbers, size);
                printf("Max Index: %d\n", findMaxIndex(numbers, size));
                printf("Min Index: %d\n", findMinIndex(numbers, size));
                printf("Average: %.2f\n", calculateAverage(numbers, size));
                
                reverseArray(numbers, size);
                printf("Reversed array: "); displayArray(numbers, size);
                copyArray(backup, numbers, size);

                sortArray(numbers, size);
                printf("Sorted array: "); displayArray(numbers, size);
                copyArray(backup, numbers, size);

                printf("Enter value to search: ");
                scanf("%d", &num);
                int index = linearSearch(numbers, size, num);
                if (index == -1) printf("Value not found.\n");
                else printf("Value found at index %d.\n", index);
                break;
            default:
                printf("Invalid choice! Select between 1-5 only.\n");
        }
        printf("----------------------------------\n");
    } while (choice != 5);

    return 0;
}
