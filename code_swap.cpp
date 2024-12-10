

#include <iostream>

#include <limits>

void swap(int* pa, int* pb) {
    int t = (*pa);
    *pa = *pb;
    *pb = t;
}

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

int main() {
    int a = 82;
    int b = -72;
    int* pa = &a;
    int* pb = &b; 
}