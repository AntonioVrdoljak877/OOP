#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

struct PasswordInfo {
    int length;
    int digits;
    int uppercase;
    int special;
};

PasswordInfo analyze(const std::string& password) {
    PasswordInfo info{};
    info.length = password.size();
    info.digits = std::count_if(password.begin(), password.end(),
                                [](unsigned char c) { return std::isdigit(c); });
    info.uppercase = std::count_if(password.begin(), password.end(),
                                   [](unsigned char c) { return std::isupper(c); });
    info.special = std::count_if(password.begin(), password.end(),
                                 [](unsigned char c) { return std::ispunct(c); });
    return info;
}

bool is_strong(const PasswordInfo& info) {
    return info.length >= 10 &&
           info.digits >= 1 &&
           info.uppercase >= 1 &&
           info.special >= 1;
}

int main() {
    std::string pass1 = "lozinka123";
    std::string pass2 = "Lozinka123!";

    auto a1 = analyze(pass1);
    auto a2 = analyze(pass2);

    std::cout << pass1 << ": duljina " << a1.length
              << ", znamenke " << a1.digits
              << ", velika " << a1.uppercase
              << ", posebni " << a1.special
              << " -> " << (is_strong(a1) ? "jaka" : "slaba") << std::endl;

    std::cout << pass2 << ": duljina " << a2.length
              << ", znamenke " << a2.digits
              << ", velika " << a2.uppercase
              << ", posebni " << a2.special
              << " -> " << (is_strong(a2) ? "jaka" : "slaba") << std::endl;

    return 0;
}
