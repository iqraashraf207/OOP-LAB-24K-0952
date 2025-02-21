//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
#include <string>
using namespace std;

class Level {
public:
    string levelType;

    Level(string type) : levelType(type) {}

    void display() {
        cout << "Level Type: " << levelType << endl;
    }
};

class VideoGame {
public:
    string title;
    string genre;
    Level levels[5];
    int levelCount;

    VideoGame(string t, string g, Level l[], int count) : title(t), genre(g), levelCount(count) {
        for (int i = 0; i < count; i++)
        {
            levels[i] = l[i];
        }
    }

    void display() {
        cout << "Game Title: " << title << endl << "Genre: " << genre << endl << "Levels:" << endl;
        for (int i = 0; i < levelCount; i++)
        {
            levels[i].display();
        }
        cout << endl;
    }
};

int main() {
    Level levelArray[] = {Level("High"), Level("Medium"), Level("Easy")};

    VideoGame game("Truck Race", "Racing Game", levelArray, 3);

    game.display();

    return 0;
}