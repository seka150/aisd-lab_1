import std;
import polynomial_class;

int main()
{
    Polynomial<double, double> polynomial(2);

    polynomial.set(0, 3);
    polynomial.set(1, 4);
    polynomial.set(2, 2);

    std::println("Polynomial:");
    for (int i = 0; i <= 2; i++)
    {
        std::println("p[{}] = {}", i, polynomial[i]);
    }

    std::println("\nAccess outside the polynomial:");
    std::println("p[10] = {}", polynomial[10]);
    std::println("p[-1] = {}", polynomial[-1]);

    auto [x, y] = polynomial.local_extremum();

    std::println("\nLocal extremum: x = {}, y = {}", x, y);

    Polynomial<double, double> copy = polynomial;
    copy.set(0, 100);

    std::println("\nCopy constructor:");

    std::println("polynomial[0] = {}", polynomial[0]);
    std::println("copy[0] = {}", copy[0]);

    std::println("\nCopy assignment:");

    Polynomial<double, double> assigned(2);
    assigned = polynomial;
    assigned.set(0, 200);

    std::println("polynomial[0] = {}", polynomial[0]);
    std::println("assigned[0] = {}", assigned[0]);

    Polynomial<std::complex<double>, double> complexPolynomial(3);

    complexPolynomial.set(0, {4, 3});
    complexPolynomial.set(1, {5, 3});
    complexPolynomial.set(2, {7, 3});
    complexPolynomial.set(3, {8, 3});

    std::println("\nComplex polynomial:");

    for (int i = 0; i < 4; i++)
    {
        std::println(
            "p[{}] = {} + {}i",
            i,
            complexPolynomial[i].real(),
            complexPolynomial[i].imag());
    }

    auto multipliedComplex = complexPolynomial * 2.0;

    std::println("\nComplex polynomial multiplied by 2:");

    for (int i = 0; i < 4; i++)
    {
        std::println(
            "p[{}] = {} + {}i",
            i,
            multipliedComplex[i].real(),
            multipliedComplex[i].imag());
    }

    polynomial.set(5, 10);
    polynomial.set(5, 0);
    polynomial.shrink_to_fit();

    std::println("\nAfter shrink_to_fit:");

    std::println("p[3] = {}", polynomial[3]);
    std::println("p[4] = {}", polynomial[4]);
    std::println("p[5] = {}", polynomial[5]);

    polynomial.expand(5);

    std::println("\nAfter expand: ");

    for (int i = 0; i <= 5; i++)
    {
        std::println("p[{}] = {}", i, polynomial[i]);
    }

    polynomial.set(5, 10);
    std::println("p[5] = {}", polynomial[5]);

    Polynomial<double, double> other(2);
    other.set(0, 1);
    other.set(1, 2);
    other.set(2, 3);

    auto sum = polynomial + other;
    auto difference = polynomial - other;

    std::println("\nAddition: ");

    for (int i = 0; i <= 5; i++)
    {
        std::println("sum[{}] = {}", i, sum[i]);
    }

    std::println("\nSubtraction:");

    for (int i = 0; i <= 5; i++)
    {
        std::println("difference[{}] = {}", i, difference[i]);
    }

    double xValue = 2.0;
    double result = polynomial.evaluate(xValue);

    std::println("\nPolynomial evaluation: ");
    std::println("p({}) = {}", xValue, result);

    auto right = polynomial * 2.0;
    auto left = 2.0 * polynomial;

    std::println("\nScalar multiplication: ");

    std::println("p * 2: ");
    for (int i = 0; i <= 5; i++)
    {
        std::println("p[{}] = {}", i, right[i]);
    }
    std::println();
    std::println("2 * p: ");
    for (int i = 0; i <= 5; i++)
    {
        std::println("p[{}] = {}", i, left[i]);
    }

    return 0;
}
