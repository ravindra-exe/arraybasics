#include "mylib.h"

int reverseNumber(int n) {
    int reversed = 0;
    while (n != 0) {
        int digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return reversed;
}

int isArmstrongNumber(int num) {
    int original = num;
    int sum = 0;
    int digits = 0;
    
    // Count digits
    int temp = num;
    while (temp > 0) {
        digits++;
        temp /= 10;
    }
    
    temp = num;
    while (temp > 0) {
        int digit = temp % 10;
        int power = 1;
        for (int i = 0; i < digits; i++) {
            power *= digit;
        }
        sum += power;
        temp /= 10;
    }
    
    return sum == original;
}

int isAdamsNumber(int num) {
    int revNum = reverseNumber(num);
    int square = num * num;
    int revSquare = reverseNumber(square);
    int squareRevNum = revNum * revNum;
    return revSquare == squareRevNum;
}

int isPrimeNumber(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i < num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int isPrimePalindrome(int num) {
    return (num == reverseNumber(num)) && isPrimeNumber(num);
}
