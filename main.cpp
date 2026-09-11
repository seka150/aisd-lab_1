import std;
import polynomial_class;

int main()
{ // убрать векторы, правило трех, деления на ноль обрабатываеть, ген случ чисел, вынести все за класс, все выводить в мейн, скаляр не так работает с комплекс,
    std::vector<int> vec = {1, 4, 2};
    std::vector<int> otherVec = {3, 6, 10};
    Polynomial<int, int> p(vec);
    Polynomial<int, int> q(otherVec);
    auto result = p.local_extremum();
    std::println("x = {}, y = {}", result.first, result.second);
    std::println("p[0] = {}, p[1] = {}, p[2] = {}", p[0], p[1], p[2]);
    std::println("p[10] = {}", p[10]);
    p.set(1, 7);
    std::println("p[1] = {}", p[1]);
    p.set(5, 10);
    std::println("p[5] = {}", p[5]);
    std::println("p[3] = {}, p[4] = {}", p[3], p[4]);
    auto sum = p + q;
    std::println("sum[0] = {}, [1] = {}, [2] = {}, [3] = {}, [4] = {}, [5] = {}", sum[0], sum[1], sum[2], sum[3], sum[4], sum[5]);
    auto difference = p - q;
    std::println("difference[0] = {}, [1] = {}, [2] = {}, [3] = {}, [4] = {}, [5] = {}", difference[0], difference[1], difference[2], difference[3], difference[4], difference[5]);
    auto multiplied = p * 2;
    std::println("multiplied[0] = {}, [1] = {}, [2] = {}, [3] = {}, [4] = {}, [5] = {}", multiplied[0], multiplied[1], multiplied[2], multiplied[3], multiplied[4], multiplied[5]);
    auto multiplied2 = 2 * q;
    std::println("multiplied2[0] = {}, multiplied2[1] = {}, multiplied2[2] = {}", multiplied2[0], multiplied2[1], multiplied2[2]);
    int a = 4;
    auto result_eval = q.evaluate(a);
    std::println("result evaluate = {}", result_eval);
    p.set(5, 0);
    p.shrink_to_fit();
    std::println("p[5] = {}", p[5]);
}