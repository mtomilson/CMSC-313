#include <stdio.h>

int largestNumber(int a, int b, int c);
int smallestNumber(int a, int b, int c);

int main(void) {
    
    int a, b, c;
    printf("Enter 3 Integers\n");
    scanf("%d %d %d", &a, &b ,&c);

    int largest = largestNumber(a, b, c);
    int smallest = smallestNumber(a, b, c);

    printf("Largest Number: %d", largest);
    printf("\nSmallest Number: %d", smallest);


}

int largestNumber(int a, int b, int c) {
    int largest = a;

    if(b >= a && b >= c) {
        largest = b;
    }

    if(c >= a && c >= b) {
        largest = c;
    }

    return largest;
}

int smallestNumber(int a, int b, int c) {
    int smallest = a;

    if(b <= a && b <= c) {
        smallest = b;
    }

    if(c <= a && c <= b) {
        smallest = c;
    }

    return smallest;
}
