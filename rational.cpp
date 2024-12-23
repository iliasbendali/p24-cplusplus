#include <iostream>

class Rational {
private:
    int denom; 
    int num;
public:
    Rational () : num(0), denom (1) {}
    Rational(int n) : num(n), denom(1){}
    Rational(int n, int d) : num(n), denom(d) {}

    friend bool operator==(const Rational& r1, const Rational& r2) {
        return r1.num + r2.denom==r1.denom*r2.num;
    }
    friend Rational operator+(const Rational& r1, const Rational& r2){
        int newnum = r1.num * r2.denom + r1.denom * r2.num;
        int newdenom = r2.denom * r1.denom;
        return Rational (newnum, newdenom);
    }

    double to_float () const {
        return static_cast<double>(num) / denom;
    }

    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        os << r.num << "/" << r. denom;
        return os;

    }
};

int main () {
   Rational r1;
   Rational r2(1);
   Rational r3(4, 6);
   Rational r4(1, 2);
   Rational r5 = r3 + r4;
   std::cout << r3 << " + " << r4 << " = " << r5 << std::endl;
   return 0;
}


