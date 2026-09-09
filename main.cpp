import std;
import polynomial_class;

int main()
{
    std::vector<int> vec = {1, 4, 2};
    Polynomial<int, int> p(vec);
    auto result = p.local_extremum();
    std::println("x = {}, y = {}", result.first, result.second);
}