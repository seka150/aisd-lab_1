module;
export module polynomial_class;
import std;

export template <typename T, typename U>
class Polynomial
{
private:
    T *_data;
    int _size;

public:
    Polynomial(int degree)
    {
        if (degree < 0)
        {
            throw std::invalid_argument("Degree cannot be negative");
        }
        _size = degree + 1;
        _data = new T[_size]{};
    }

    Polynomial(const T *coeff, int size)
    {
        if (size <= 0)
        {
            throw std::out_of_range("size <= 0");
        }
        _size = size;
        _data = new T[size];
        for (int i = 0; i < size; i++)
        {
            _data[i] = coeff[i];
        }
    }

    ~Polynomial()
    {
        delete[] _data;
    }

    Polynomial(const Polynomial &other) : _data(new T[other._size]), _size(other._size)
    {
        for (int i = 0; i < _size; i++)
        {
            _data[i] = other._data[i];
        }
    }

    int getSize() const
    {
        return _size;
    }

    T getData(int degree) const
    {
        return (*this)[degree];
    }

    Polynomial &operator=(const Polynomial &other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] _data;
        _size = other._size;
        _data = new T[other._size];
        for (int i = 0; i < _size; i++)
        {
            _data[i] = other._data[i];
        }
        return *this;
    }

    T operator[](int degree) const
    {
        if (degree < 0)
        {
            throw std::out_of_range("Degree cannot be negative");
        }
        if (degree >= _size)
        {
            return 0;
        }

        return _data[degree];
    }

    bool operator==(const Polynomial &other) const
    {
        if (_size != other._size)
        {
            return false;
        }
        for (int i = 0; i < _size; i++)
        {
            if ((*this)[i] != other[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Polynomial &other) const
    {
        return !(*this == other);
    }

    void set(int degree, T value)
    {
        if (degree < 0)
        {
            throw std::out_of_range("Degree cannot be negative");
        }

        expand(degree);
        _data[degree] = value;
    }

    Polynomial operator+(const Polynomial &other) const
    {
        int new_size;
        if (_size > other._size)
        {
            new_size = _size;
        }
        else
        {
            new_size = other._size;
        }

        Polynomial result(new_size - 1);

        for (int i = 0; i < new_size; i++)
        {
            result.set(i, (*this)[i] + other[i]);
        }
        return result;
    }

    Polynomial operator-(const Polynomial &other) const
    {
        int new_size;
        if (_size > other._size)
        {
            new_size = _size;
        }
        else
        {
            new_size = other._size;
        }

        Polynomial result(new_size - 1);

        for (int i = 0; i < new_size; i++)
        {
            result.set(i, (*this)[i] - other[i]);
        }
        return result;
    }

    Polynomial operator*(U scalar) const
    {
        Polynomial result(_size - 1);
        for (int i = 0; i < _size; i++)
        {
            result.set(i, (*this)[i] * scalar);
        }
        return result;
    }

    T evaluate(U x) const // вычисление значения многочлена при указанном значении х
    {
        T result = 0;
        for (int i = 0; i < _size; i++)
        {
            result += (*this)[i] * std::pow(x, i);
        }
        return result;
    }

    void shrink_to_fit() // удаление нулей в конце
    {
        while (_size > 1 && _data[_size - 1] == 0)
        {
            _size--;
        }
        T *new_data = new T[_size];
        for (int i = 0; i < _size; i++)
        {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
    }

    void expand(int degree)
    {
        if (degree < 0)
        {
            throw std::out_of_range("Degree cannot be negative");
        }
        int old_size = _size;
        if (degree + 1 <= old_size)
        {
            return;
        }

        _size = degree + 1;
        T *new_data = new T[_size]{};
        for (int i = 0; i < old_size; i++)
        {
            new_data[i] = _data[i];
        }
        delete[] _data;
        _data = new_data;
    }
};

export template <typename T, typename U>
std::ostream &operator<<(std::ostream &out, const Polynomial<T, U> &polynomial)
{
    for (int i = 0; i < polynomial.getSize(); i++)
    {
        out << polynomial[i];
        if (i < polynomial.getSize() - 1)
        {
            out << " ";
        }
    }
    return out;
}

export template <typename T, typename U>
std::pair<U, U> local_extremum(const Polynomial<T, U> &polynomial)
{
    if (polynomial.getSize() < 3)
    {
        throw std::out_of_range("Polynomial must have at least 3 coefficients");
    }
    if (polynomial.getData(2) == 0)
    {
        throw std::invalid_argument("Polynomial must be quadratic");
    }

    U x = -static_cast<U>(polynomial.getData(1)) / (2 * static_cast<U>(polynomial.getData(2)));
    U y = static_cast<U>(polynomial.getData(2)) * x * x + static_cast<U>(polynomial.getData(1)) * x + static_cast<U>(polynomial.getData(0));
    return std::make_pair(x, y);
}

export template <typename T, typename U>
Polynomial<T, U> operator*(U scalar, const Polynomial<T, U> &polynomial)
{
    return polynomial * scalar;
}