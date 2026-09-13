import std;
import polynomial_class;

int main()
{ // убрать векторы, правило трех, деления на ноль обрабатываеть, ген случ чисел, вынести все за класс, все выводить в мейн, скаляр не так работает с комплекс, добавлыяем рандом и ручками забиваем тоже)
    Polynomial<double, double> p(2);
    p.set(0, 3);
    p.set(1, 4);
    p.set(2, 2);
    auto [x, y] = p.local_extremum();
    std::println("{}, {}", x, y);
    std::println("p[0] = {}", p[0]);
    std::println("p[1] = {}", p[1]);
    std::println("p[2] = {}", p[2]);
    std::println("p[10] = {}", p[10]);
    std::println("p[-1] = {}", p[-1]);
    p.set(1, 7);
    std::println("p[1] = {}", p[1]);
    p.set(5, 10);
}