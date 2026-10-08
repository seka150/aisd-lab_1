import std;
import polynomial_class;

int main()
{
    // Create a polynomial from an array of coefficients
    double coefficients[] = {3.0, 4.0, 2.0};
    Polynomial<double, double> p(coefficients, 3);

    std::cout << "Polynomial p: " << p << '\n';

    // operator[]
    std::cout << "p[0] = " << p[0] << '\n';
    std::cout << "p[1] = " << p[1] << '\n';
    std::cout << "p[5] = " << p[5] << '\n';

    // set and expand
    p.set(3, 5.0);
    std::cout << "After set(3, 5.0): " << p << '\n';

    p.expand(5);
    std::cout << "After expand(5): " << p << '\n';

    // Create a second polynomial
    double coefficients2[] = {1.0, 2.0, 3.0};
    Polynomial<double, double> q(coefficients2, 3);

    std::cout << "\nPolynomial q: " << q << '\n';

    // Addition and subtraction
    std::cout << "p + q = " << p + q << '\n';
    std::cout << "p - q = " << p - q << '\n';

    // Scalar multiplication
    std::cout << "p * 2 = " << p * 2.0 << '\n';
    std::cout << "2 * p = " << 2.0 * p << '\n';

    // Evaluation
    std::cout << "p(2) = " << p.evaluate(2.0) << '\n';

    // Copy constructor
    Polynomial<double, double> copy(p);
    std::cout << "Copy of p: " << copy << '\n';

    // Assignment operator
    Polynomial<double, double> assigned(0);
    assigned = p;
    std::cout << "Assigned polynomial: " << assigned << '\n';

    // Comparison
    std::cout << "p == copy: " << (p == copy) << '\n';
    std::cout << "p != q: " << (p != q) << '\n';

    // shrink_to_fit
    p.shrink_to_fit();
    std::cout << "After shrink_to_fit: " << p << '\n';

    // Local extremum
    double quadratic_coefficients[] = {3.0, 4.0, 2.0};
    Polynomial<double, double> quadratic(quadratic_coefficients, 3);

    auto extremum = local_extremum(quadratic);

    std::cout << "\nQuadratic polynomial: " << quadratic << '\n';
    std::cout << "Local extremum: ("
              << extremum.first << ", "
              << extremum.second << ")\n";

    // Template type checks
    int int_coefficients[] = {1, 2, 3};
    Polynomial<int, int> int_polynomial(int_coefficients, 3);

    float float_coefficients[] = {1.0f, 2.0f, 3.0f};
    Polynomial<float, float> float_polynomial(float_coefficients, 3);

    std::complex<float> complex_float_coefficients[] = {
        {1.0f, 2.0f},
        {3.0f, 4.0f},
        {5.0f, 6.0f}};

    Polynomial<std::complex<float>, std::complex<float>>
        complex_float_polynomial(complex_float_coefficients, 3);

    std::complex<double> complex_double_coefficients[] = {
        {1.0, 2.0},
        {3.0, 4.0},
        {5.0, 6.0}};

    Polynomial<std::complex<double>, std::complex<double>>
        complex_double_polynomial(complex_double_coefficients, 3);

    std::cout << "\nint polynomial: " << int_polynomial << '\n';
    std::cout << "int polynomial at 2: "
              << int_polynomial.evaluate(2) << '\n';

    std::cout << "float polynomial: " << float_polynomial << '\n';
    std::cout << "float polynomial at 2: "
              << float_polynomial.evaluate(2.0f) << '\n';

    std::cout << "complex<float> polynomial: "
              << complex_float_polynomial << '\n';

    std::cout << "complex<double> polynomial: "
              << complex_double_polynomial << '\n';

    // Random polynomial
    auto random_p = random_polynomial<double, double>(5);

    std::cout << "\nRandom polynomial: " << random_p << '\n';

    std::cout << "random_p[0] = " << random_p[0] << '\n';
    std::cout << "random_p[10] = " << random_p[10] << '\n';

    random_p.set(6, 5.0);
    std::cout << "After set(6, 5.0): " << random_p << '\n';

    random_p.expand(8);
    std::cout << "After expand(8): " << random_p << '\n';

    std::cout << "random_p + q = " << random_p + q << '\n';
    std::cout << "random_p - q = " << random_p - q << '\n';
    std::cout << "random_p * 2 = " << random_p * 2.0 << '\n';
    std::cout << "2 * random_p = " << 2.0 * random_p << '\n';

    std::cout << "random_p(2) = "
              << random_p.evaluate(2.0) << '\n';

    Polynomial<double, double> random_copy(random_p);
    std::cout << "Copy of random_p: "
              << random_copy << '\n';

    Polynomial<double, double> random_assigned(0);
    random_assigned = random_p;

    std::cout << "Assigned random_p: "
              << random_assigned << '\n';

    std::cout << "random_p == random_copy: "
              << (random_p == random_copy) << '\n';

    std::cout << "random_p != q: "
              << (random_p != q) << '\n';

    random_p.shrink_to_fit();
    std::cout << "After shrink_to_fit: "
              << random_p << '\n';

    return 0;
}