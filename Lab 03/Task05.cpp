//Name: Iqra Ashraf
//Roll number: 24K-0952

#include <iostream>
using namespace std;

const int MAX_SONGS = 100;

class MusicPlayer{
private:
    string playlist[MAX_SONGS];
    int totalSongs;
    string currentlyPlayingSong;

public:
    MusicPlayer(){
        totalSongs = 0;
        currentlyPlayingSong = "No song is playing currently.";
    }

    void addSong(string song){
        if (totalSongs < MAX_SONGS){
            playlist[totalSongs] = song;
            totalSongs++;
            cout << song << " added to the playlist." << endl;
        } else{
            cout << "Cannot add more songs." << endl;
        }
    }

    void removeSong(string song){
        for (int i = 0; i < totalSongs; i++)
        {
            if (playlist[i] == song){
                for (int j = i; j < totalSongs - 1; j++)
                {
                    playlist[j] = playlist[j + 1];
                }
                totalSongs--;
                cout << song << "  removed from the playlist.\n";
                if (currentlyPlayingSong == song){
                    currentlyPlayingSong = "No song is playing currently.";
                }
                return;
            }
        }
        cout << "Song not found in the playlist." << endl;
    }

    void playSong(string song){
        for (int i = 0; i < totalSongs; i++){
            if (playlist[i] == song){
                currentlyPlayingSong = song;
                cout << "Now playing: " << song << endl;
                return;
            }
        }
        cout << "Song not found in the playlist." << endl;
    }

    void displayPlaylist(){
        cout << "Playlist:" << endl;
        if (totalSongs == 0){
            cout << "No songs in the playlist." << endl;
            return;
        }
        for (int i = 0; i < totalSongs; i++)
        {
            cout << i + 1 << ". " << playlist[i] << endl;
        }
        cout << "Playing: " << currentlyPlayingSong << endl;
    }
};

int main() {
    MusicPlayer imranPlayer;

    imranPlayer.addSong("Song A");
    imranPlayer.addSong("Song B");
    imranPlayer.addSong("Song C");
    imranPlayer.displayPlaylist();

    imranPlayer.playSong("Song B");
    imranPlayer.removeSong("Song B");
    imranPlayer.displayPlaylist();

    return 0;
}