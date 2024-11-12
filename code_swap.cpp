

#include <iostream>

#include <limits>

void
swap(int* a, int* b) {
    int t {*a};
    *a = *b;
    *b = t;
}

int main() {
    int x {18};
    int y {99};
    swap(&x,&y);
    return 0;
}