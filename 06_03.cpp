
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

class LogFile {
private:
    FILE* f;

public:
    LogFile(const string& name) {
        f = fopen(name.c_str(), "a");
    }

    LogFile(const LogFile& l) = delete;

    ~LogFile() {
        if (f != nullptr) {
            fclose(f);
        }
    }

    void write(const string& line) {
        if (f != nullptr) {
            string s = line + "\n";
            fputs(s.c_str(), f);
        }
    }
};

int log_songs(const vector<string>& titles) {
    LogFile log("played.log");
    int n = 0;

    for (int i = 0; i < titles.size(); i++) {
        if (titles[i] == "STOP") {
            return n;
        }

        log.write(titles[i]);
        n++;
    }

    return n;
}

int main() {
    vector<string> pjesme = {
        "Pjesma 1", "Pjesma 2", "Pjesma 3",
        "STOP", "Pjesma 4"
    };

    cout << log_songs(pjesme) << endl;

    return 0;
}
