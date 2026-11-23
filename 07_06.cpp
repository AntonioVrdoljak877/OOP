#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <cctype>

struct WordCount {
    std::string word;
    int count;
};

std::string clean(const std::string& word) {
    std::string rezultat;
    for (char c : word) {
        if (std::isalpha(static_cast<unsigned char>(c))) {
            rezultat += std::tolower(static_cast<unsigned char>(c));
        }
    }
    return rezultat;
}

int main() {
    std::ifstream ulaz("tekst.txt");
    if (!ulaz) {
        std::cerr << "Ne mogu otvoriti tekst.txt" << std::endl;
        return 1;
    }

    std::map<std::string, int> freq;
    std::string rijec;

    while (ulaz >> rijec) {
        std::string cista = clean(rijec);
        if (!cista.empty()) {
            ++freq[cista];
        }
    }

    std::cout << freq.size() << std::endl;
    std::cout << freq["alice"] << std::endl;

    std::vector<WordCount> lista;
    for (const auto& p : freq) {
        lista.push_back({p.first, p.second});
    }

    std::sort(lista.begin(), lista.end(),
              [](const WordCount& a, const WordCount& b) {
                  if (a.count != b.count) {
                      return a.count > b.count;
                  }
                  return a.word < b.word;
              });

    int n = std::min(5, (int)lista.size());
    for (int i = 0; i < n; i++) {
        std::cout << lista[i].word << " " << lista[i].count << std::endl;
    }

    return 0;
}