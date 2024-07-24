#include "palindrome.h"

int is_palindrome(unsigned long n) {
    unsigned long original = n;
    unsigned long reversed = 0;
    
    while (n != 0) {
        unsigned long digit = n % 10;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    
    return original == reversed;
}
