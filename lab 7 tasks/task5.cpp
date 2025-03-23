#include <iostream>
using namespace std;

class Media {
protected:
    string title, date, id, publisher;
public:
    Media(string t, string d, string i, string p) : title(t), date(d), id(i), publisher(p) {}

    virtual void show() {
        cout << "Title: " << title << " | Date: " << date << " | ID: " << id << " | Publisher: " << publisher << endl;
    }
};

class Book : public Media {
    string author, isbn;
    int pages;
public:
    Book(string t, string d, string i, string p, string a, string isb, int pg)
        : Media(t, d, i, p), author(a), isbn(isb), pages(pg) {}

    void show() override {
        Media::show();
        cout << "Author: " << author << " | ISBN: " << isbn << " | Pages: " << pages << endl;
    }
};

class DVD : public Media {
    string director;
    float time;
    int rate;
public:
    DVD(string t, string d, string i, string p, string dir, float tm, int r)
        : Media(t, d, i, p), director(dir), time(tm), rate(r) {}

    void show() override {
        Media::show();
        cout << "Director: " << director << " | Time: " << time << " hrs | Rating: " << rate << "/10" << endl;
    }
};

class CD : public Media {
    string artist, type;
    int tracks;
public:
    CD(string t, string d, string i, string p, string art, string ty, int tr)
        : Media(t, d, i, p), artist(art), type(ty), tracks(tr) {}

    void show() override {
        Media::show();
        cout << "Artist: " << artist << " | Type: " << type << " | Tracks: " << tracks << endl;
    }
};

// Function Overloading for Searching
void find(string title) {
    cout << "Finding: " << title << endl;
}

void find(string title, string author) {
    cout << "Finding book: " << title << " by " << author << endl;
}

void find(int year) {
    cout << "Finding media from year: " << year << endl;
}

int main() {
    Book b("C++ Basics", "2022", "B101", "TechPub", "Ali", "123-456", 200);
    DVD d("Avengers", "2018", "D202", "Marvel", "Russo", 2.5, 9);
    CD c("Best Songs", "2020", "C303", "MusicInc", "Atif", "Pop", 10);

    cout << "\n Library \n";
    b.show();
    d.show();
    c.show();

    cout << "\n Search\n";
    find("C++ Basics");
    find("C++ Basics", "Ali");
    find(2018);

    return 0;
}
