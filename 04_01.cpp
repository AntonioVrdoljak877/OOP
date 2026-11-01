#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void input_vector(std::vector<int>& v) {
    int n;
    while (std::cin >> n && n != 0) {
        v.push_back(n);
    }
}

int main() {
    std::vector<int> v;
    std::cout << "Unesite brojeve (0 za kraj): ";
    input_vector(v);

    int k;
    std::cout << "k: ";
    std::cin >> k;

    int negativnih = std::count_if(v.begin(), v.end(),
                                   [](int x) { return x < 0; });
    std::cout << "negativnih: " << negativnih << std::endl;

    auto it = std::find_if(v.begin(), v.end(),
                           [k](int x) { return x % k == 0; });
    if (it != v.end()) {
        std::cout << "prvi visekratnik od " << k << ": " << *it
                  << " (pozicija " << std::distance(v.begin(), it) << ")\n";
    } else {
        std::cout << "nema visekratnika od " << k << std::endl;
    }

    if (!v.empty()) {
        auto min_it = std::min_element(v.begin(), v.end());
        auto max_it = std::max_element(v.begin(), v.end());
        std::cout << "min " << *min_it
                  << " (pozicija " << std::distance(v.begin(), min_it) << "), "
                  << "max " << *max_it
                  << " (pozicija " << std::distance(v.begin(), max_it) << ")\n";
    }

    v.erase(std::remove_if(v.begin(), v.end(),
                           [k](int x) { return x % k == 0; }),
            v.end());

    std::cout << "bez visekratnika: ";
    for (int x : v) std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
