#include <string>
#include <vector>
#include <iostream>

class Song {
public:
    std::string title;
    std::string artist;
    int seconds;

    Song(const std::string& t, const std::string& a, int s)
        : title(t), artist(a), seconds(s) {}
};

class Album {
    std::string title;
    int year;
    std::vector<Song> songs;

public:
    Album(const std::string& t, int y, Song first)
        : title(t), year(y)
    {
        songs.push_back(first);
    }

    bool add(Song s) {
        for (const auto& existing : songs) {
            if (existing.title == s.title)
                return false;
        }
        songs.push_back(s);
        return true;
    }

    int duration() const {
        int total = 0;
        for (const auto& s : songs)
            total += s.seconds;
        return total;
    }

    void print() const {
        std::cout << title << " (" << year << ")\n";
        for (const auto& s : songs) {
            std::cout << "  " << s.artist << " - " << s.title
                      << " (" << s.seconds << " s)\n";
        }
        std::cout << "Ukupno: " << duration() << " s\n";
    }
};