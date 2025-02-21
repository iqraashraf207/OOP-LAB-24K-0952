//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

class Level {
private:
    string type;

public:
    Level() {}
    Level(string t) : type(t) {}
    void display() {
        cout << "Level: " << type << endl;
    }
};

class VideoGame {
private:
    string title;
    string genre;
    Level levels[10];
    int levelCount;

public:
    VideoGame(string t, string g) : title(t), genre(g), levelCount(0) {}
    
    void addLevel(string levelType) {
        if (levelCount < 10) {
            levels[levelCount++] = Level(levelType);
        } else {
            cout << "More levels cannot be added." << endl;
        }
    }
    
    void displayDetails() {
        cout << "Game: " << title << ", Genre: " << genre << endl;
        cout << "Levels: " << endl;
        for (int i = 0; i < levelCount; i++)
        {
            levels[i].display();
        }
    }
};

int main() {
    VideoGame game("Truck Race", "Racing Game");
    game.addLevel("High");
    game.addLevel("Medium");
    game.addLevel("Easy");
    
    game.displayDetails();
    
    return 0;
}
