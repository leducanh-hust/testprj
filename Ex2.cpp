#include <iostream>

using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    // Constructor with default values
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom)
    {
        simplify(); // Simplify the fraction when initialized
    }

    // Function to calculate the greatest common divisor (GCD)
    int gcd(int a, int b)
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to simplify the fraction
    void simplify()
    {
        int gcdNum = gcd(numerator, denominator);
        numerator /= gcdNum;
        denominator /= gcdNum;
    }

    // Overloaded division operator (/)
    Fraction operator/(const Fraction &other) const
    {
        Fraction result(numerator * other.denominator, denominator * other.numerator);
        result.simplify();
        return result;
    }

    // Overloaded unary operator (!) to reverse the fraction
    Fraction operator!() const
    {
        return Fraction(denominator, numerator);
    }

    // Friend function to overload the insertion operator (<<) for output
    friend ostream &operator<<(ostream &os, const Fraction &fraction)
    {
        os << fraction.numerator << "/" << fraction.denominator;
        return os;
    }
};

int main()
{
    // Test cases
    Fraction frac1(3, 4);
    Fraction frac2(2, 5);

    // Display the original fractions
    cout << "Fraction 1: " << frac1 << endl;
    cout << "Fraction 2: " << frac2 << endl;

    // Perform division and display the result
    Fraction resultDivide = frac1 / frac2;
    cout << "Result of Division: " << resultDivide << endl;

    // Perform inversion and display the result
    Fraction resultInverse = !frac1;
    cout << "Result of Inversion: " << resultInverse << endl;

    return 0;
}
