import std;
import polynomial_class;

int main()
{
    // Constructor from coefficient array
    double coefficients[] = {3.0, 4.0, 2.0};
    Polynomial<double, double> p(coefficients, 3);

    std::cout << "Polynomial p: " << p << '\n';

    // operator[]
    std::cout << "p[0] = " << p[0] << '\n';
    std::cout << "p[1] = " << p[1] << '\n';
    std::cout << "p[2] = " << p[2] << '\n';
    std::cout << "p[5] = " << p[5] << '\n';

    // set
    p.set(3, 5.0);
    std::cout << "\nAfter set(3, 5.0): " << p << '\n';

    // expand
    p.expand(5);
    std::cout << "After expand(5): " << p << '\n';

    // Second polynomial
    double coefficients2[] = {1.0, 2.0, 3.0};
    Polynomial<double, double> q(coefficients2, 3);

    std::cout << "\nPolynomial q: " << q << '\n';

    // Addition
    Polynomial<double, double> sum = p + q;
    std::cout << "p + q = " << sum << '\n';

    // Subtraction
    Polynomial<double, double> difference = p - q;
    std::cout << "p - q = " << difference << '\n';

    // Scalar multiplication
    Polynomial<double, double> multiplied1 = p * 2.0;
    Polynomial<double, double> multiplied2 = 2.0 * p;

    std::cout << "p * 2 = " << multiplied1 << '\n';
    std::cout << "2 * p = " << multiplied2 << '\n';

    // Evaluation
    double x = 2.0;
    std::cout << "p(" << x << ") = " << p.evaluate(x) << '\n';

    // Copy constructor
    Polynomial<double, double> copy = p;
    std::cout << "\nCopy of p: " << copy << '\n';

    // Assignment operator
    Polynomial<double, double> assigned(0);
    assigned = p;
    std::cout << "Assigned polynomial: " << assigned << '\n';

    // Comparison
    std::cout << "p == copy: " << (p == copy) << '\n';
    std::cout << "p != q: " << (p != q) << '\n';

    // Shrink
    p.shrink_to_fit();
    std::cout << "After shrink_to_fit: " << p << '\n';
    std::cout << "Size: " << p.getSize() << '\n';

    // Local extremum
    double quadratic_coefficients[] = {3.0, 4.0, 2.0};
    Polynomial<double, double> quadratic(quadratic_coefficients, 3);

    auto extremum = local_extremum(quadratic);

    std::cout << "\nQuadratic polynomial: " << quadratic << '\n';
    std::cout << "Local extremum: ("
              << extremum.first << ", "
              << extremum.second << ")\n";

    // int
    int int_coefficients[] = {1, 2, 3};
    Polynomial<int, int> int_polynomial(int_coefficients, 3);

    std::cout << "\nint polynomial: " << int_polynomial << '\n';
    std::cout << "int polynomial at 2: "
              << int_polynomial.evaluate(2) << '\n';

    // float
    float float_coefficients[] = {1.0f, 2.0f, 3.0f};
    Polynomial<float, float> float_polynomial(float_coefficients, 3);

    std::cout << "\nfloat polynomial: " << float_polynomial << '\n';
    std::cout << "float polynomial at 2.0: "
              << float_polynomial.evaluate(2.0f) << '\n';

    // double
    double double_coefficients[] = {1.0, 2.0, 3.0};
    Polynomial<double, double> double_polynomial(double_coefficients, 3);

    std::cout << "\ndouble polynomial: " << double_polynomial << '\n';
    std::cout << "double polynomial at 2.0: "
              << double_polynomial.evaluate(2.0) << '\n';

    // complex<float>
    std::complex<float> complex_float_coefficients[] = {
        {1.0f, 2.0f},
        {3.0f, 4.0f},
        {5.0f, 6.0f}};

    Polynomial<std::complex<float>, std::complex<float>>
        complex_float_polynomial(complex_float_coefficients, 3);

    std::cout << "\ncomplex<float> polynomial: "
              << complex_float_polynomial << '\n';

    // complex<double>
    std::complex<double> complex_double_coefficients[] = {
        {1.0, 2.0},
        {3.0, 4.0},
        {5.0, 6.0}};

    Polynomial<std::complex<double>, std::complex<double>>
        complex_double_polynomial(complex_double_coefficients, 3);

    std::cout << "\ncomplex<double> polynomial: "
              << complex_double_polynomial << '\n';

    return 0;
}