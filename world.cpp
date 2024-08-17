#include <iostream>
#include <string>

using namespace std;

class HistoricalEvent {
private:
    string name;
    string description;
    string date;

public:
    HistoricalEvent(string n = "", string d = "", string dt = "")
        : name(n), description(d), date(dt) {}

    string getName() const { return name; }
    string getDescription() const { return description; }
    string getDate() const { return date; }

    void setName(string n) { name = n; }
    void setDescription(string d) { description = d; }
    void setDate(string dt) { date = dt; }

    void input() {
        cout << "Enter historical event name: ";
        getline(cin, name);
        cout << "Enter historical event description: ";
        getline(cin, description);
        cout << "Enter historical event date: ";
        getline(cin, date);
    }
};

class Character {
private:
    string name;
    int age;
    string role;

public:
    Character(string n = "", int a = 0, string r = "")
        : name(n), age(a), role(r) {}

    string getName() const { return name; }
    int getAge() const { return age; }
    string getRole() const { return role; }

    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setRole(string r) { role = r; }

    void input() {
        cout << "Enter character name: ";
        getline(cin, name);
        cout << "Enter character age: ";
        cin >> age;
        cin.ignore();  
        cout << "Enter character role: ";
        getline(cin, role);
    }
};

class Culture {
private:
    string name;
    string traditions;
    string language;

public:
    Culture(string n = "", string t = "", string l = "")
        : name(n), traditions(t), language(l) {}

    string getName() const { return name; }
    string getTraditions() const { return traditions; }
    string getLanguage() const { return language; }

    void setName(string n) { name = n; }
    void setTraditions(string t) { traditions = t; }
    void setLanguage(string l) { language = l; }

    void input() {
        cout << "Enter culture name: ";
        getline(cin, name);
        cout << "Enter culture traditions: ";
        getline(cin, traditions);
        cout << "Enter culture language: ";
        getline(cin, language);
    }
};

class GeographicalLocation {
private:
    string name;
    string climate;
    string terrain;

public:
    GeographicalLocation(string n = "", string c = "", string t = "")
        : name(n), climate(c), terrain(t) {}

    string getName() const { return name; }
    string getClimate() const { return climate; }
    string getTerrain() const { return terrain; }

    void setName(string n) { name = n; }
    void setClimate(string c) { climate = c; }
    void setTerrain(string t) { terrain = t; }

    void input() {
        cout << "Enter geographical location name: ";
        getline(cin, name);
        cout << "Enter geographical location climate: ";
        getline(cin, climate);
        cout << "Enter geographical location terrain: ";
        getline(cin, terrain);
    }
};

class World {
private:
    static const int MAX_SIZE = 100;  // Maximum size of arrays
    HistoricalEvent events[MAX_SIZE];  // Array to store historical events
    Character characters[MAX_SIZE];    
    Culture cultures[MAX_SIZE];        
    GeographicalLocation locations[MAX_SIZE]; 

    int eventCount = 0;
    int characterCount = 0;
    int cultureCount = 0;
    int locationCount = 0;

public:
    void addEvent(const HistoricalEvent& e) { 
        if (eventCount < MAX_SIZE) {
            events[eventCount++] = e; 
        }
    }

    void addCharacter(const Character& c) { 
        if (characterCount < MAX_SIZE) {
            characters[characterCount++] = c; 
        }
    }

    void addCulture(const Culture& c) { 
        if (cultureCount < MAX_SIZE) {
            cultures[cultureCount++] = c; 
        }
    }

    void addLocation(const GeographicalLocation& l) { 
        if (locationCount < MAX_SIZE) {
            locations[locationCount++] = l; 
        }
    }

    void displayEvents() const {
        for (int i = 0; i < eventCount; ++i) {
            cout << "Event: " << events[i].getName() << " - " << events[i].getDescription() << " on " << events[i].getDate() << endl;
        }
    }

    void displayCharacters() const {
        for (int i = 0; i < characterCount; ++i) {
            cout << "Character: " << characters[i].getName() << ", Age: " << characters[i].getAge() << ", Role: " << characters[i].getRole() << endl;
        }
    }

    void displayCultures() const {
        for (int i = 0; i < cultureCount; ++i) {
            cout << "Culture: " << cultures[i].getName() << ", Traditions: " << cultures[i].getTraditions() << ", Language: " << cultures[i].getLanguage() << endl;
        }
    }

    void displayLocations() const {
        for (int i = 0; i < locationCount; ++i) {
            cout << "Location: " << locations[i].getName() << ", Climate: " << locations[i].getClimate() << ", Terrain: " << locations[i].getTerrain() << endl;
        }
    }
};

int main() {
    World middleEarth;

    int numEvents, numCharacters, numCultures, numLocations;

    cout << "Enter the number of historical events: ";
    cin >> numEvents;
    cin.ignore(); 
    for (int i = 0; i < numEvents; ++i) {
        HistoricalEvent event;
        cout << "Enter details for historical event " << (i + 1) << ":" << endl;
        event.input();
        middleEarth.addEvent(event);
    }

    cout << "Enter the number of characters: ";
    cin >> numCharacters;
    cin.ignore(); 
    for (int i = 0; i < numCharacters; ++i) {
        Character character;
        cout << "Enter details for character " << (i + 1) << ":" << endl;
        character.input();
        middleEarth.addCharacter(character);
    }

    cout << "Enter the number of cultures: ";
    cin >> numCultures;
    cin.ignore(); 
    for (int i = 0; i < numCultures; ++i) {
        Culture culture;
        cout << "Enter details for culture " << (i + 1) << ":" << endl;
        culture.input();
        middleEarth.addCulture(culture);
    }

    cout << "Enter the number of geographical locations: ";
    cin >> numLocations;
    cin.ignore();  
    for (int i = 0; i < numLocations; ++i) {
        GeographicalLocation location;
        cout << "Enter details for geographical location " << (i + 1) << ":" << endl;
        location.input();
        middleEarth.addLocation(location);
    }

    cout << "\nEvents:" << endl;
    middleEarth.displayEvents();
    cout << "\nCharacters:" << endl;
    middleEarth.displayCharacters();
    cout << "\nCultures:" << endl;
    middleEarth.displayCultures();
    cout << "\nLocations:" << endl;
    middleEarth.displayLocations();

    return 0;
}
