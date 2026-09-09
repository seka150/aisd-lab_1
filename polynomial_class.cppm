module;
export module polynomial_class;
import std;

template <typename T, typename U>
class Polynomial
{
private:
    std::vector<T> _vec;

public:
    Polynomial(std::vector<T> vec) : _vec(vec) {}

    Polynomial(int degree) : _vec(degree + 1, 0) {}

    std::pair<U, U> local_extremum() const
    {
        if (_vec.size() < 3)
        {
            throw std::out_of_range("Polynomial must have at least 3 coefficients");
        }
        if (_vec[2] == 0)
        {
            throw std::invalid_argument("Polynomial must be quadratic");
        }

        U x = -_vec[1] / (2 * _vec[2]);
        U y = _vec[2] * x * x + _vec[1] * x + _vec[0];
        return std::make_pair(x, y);
    }

    T operator[](int degree) const
    {
        if (degree < 0)
        {
            return 0;
        }
        if (static_cast<std::size_t>(degree) >= _vec.size())
        {
            return 0;
        }

        return _vec[degree];
    }

    void set(int degree, T value)
    {
        if (degree >= _vec.size())
        {
            _vec.resize(degree + 1);
        }
        _vec[degree] = value;
    }

    Polynomial operator+(const Polynomial &other) const
    {
        std::size_t size;
        if (_vec.size() > other._vec.size())
        {
            size = _vec.size();
        }
        else
        {
            size = other._vec.size();
        }
        Polynomial result(size - 1);

        for (std::size_t i = 0; i < size; i++)
        {
            result.set(i, (*this)[i] + other[i]);
        }
        return result;
    }

    Polynomial operator-(const Polynomial &other) const
    {
        std::size_t size;
        if (_vec.size() > other._vec.size())
        {
            size = _vec.size();
        }
        else
        {
            size = other._vec.size();
        }
        Polynomial result(size - 1);

        for (std::size_t i = 0; i < size; i++)
        {
            result.set(i, (*this)[i] - other[i]);
        }
        return result;
    }

    Polynomial operator*(T scalar) const
    {
        Polynomial result(_vec.size() - 1);
        for (std::size_t i = 0; i < _vec.size(); i++)
        {
            result.set(i, (*this)[i] * scalar);
        }
        return result;
    }

    T evaluate(U x) const
    {
        T result = 0;
        for (std::size_t i = 0; i < _vec.size(); i++)
        {
            result += _vec[i] * std::pow(x, i);
        }
        return result;
    }

    void shrink_to_fit()
    {
        while (_vec.size() > 1 && _vec.back() == 0)
        {
            _vec.pop_back();
        }
        _vec.shrink_to_fit();
    }

    void expand(int degree)
    {
        if (_vec.size() < degree + 1)
        {
            _vec.resize(degree + 1);
        }
    }
};

template <typename T, typename U>
Polynomial<T, U> operator*(T scalar, const Polynomial<T, U> &polynomial)
{
    return polynomial * scalar;
}