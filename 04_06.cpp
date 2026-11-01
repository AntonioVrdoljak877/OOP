#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

std::vector<std::string> split_words(const std::string& text) {
    std::vector<std::string> words;
    size_t start = 0;
    size_t pos = text.find(' ');
    while (pos != std::string::npos) {
        if (pos > start)
            words.push_back(text.substr(start, pos - start));
        start = pos + 1;
        pos = text.find(' ', start);
    }
    if (start < text.size())
        words.push_back(text.substr(start));
    return words;
}

int main() {
    std::vector<std::string> dictionary = {
        "programski", "jezik", "c++", "je", "brz", "i", "mocan",
        "ali", "nije", "jednostavan", "za", "pocetnike"
    };

    std::sort(dictionary.begin(), dictionary.end());

    std::string sentence;
    std::cout << "Recenica: ";
    std::getline(std::cin, sentence);

    auto words = split_words(sentence);
    std::vector<std::string> unknown;

    for (auto& w : words) {
        w.erase(std::remove_if(w.begin(), w.end(),
                               [](char c) { return c == ',' || c == '.'; }),
                w.end());

        std::transform(w.begin(), w.end(), w.begin(),
                       [](unsigned char c) { return std::tolower(c); });

        if (!std::binary_search(dictionary.begin(), dictionary.end(), w)) {
            unknown.push_back(w);
        }
    }

    std::cout << "nepoznatih rijeci: " << unknown.size();
    for (const auto& u : unknown) std::cout << " " << u;
    std::cout << std::endl;

    return 0;
}
