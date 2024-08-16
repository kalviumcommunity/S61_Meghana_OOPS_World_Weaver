#include <iostream>
#include <string>
#include <vector>

using namespace std;

// HistoricalEvent Class
class HistoricalEvent {
private:
    string name;
    string description;
    string date;

public:
    // Constructor
    HistoricalEvent(string n = "", string d = "", string dt = "")
        : name(n), description(d), date(dt) {}

    // Getter Methods
    string getName() const { return name; }
    string getDescription() const { return description; }
    string getDate() const { return date; }

    // Setter Methods
    void setName(string n) { name = n; }
    void setDescription(string d) { description = d; }
    void setDate(string dt) { date = dt; }

    // Input Method
    void input() {
        cout << "Enter historical event name: ";
        getline(cin, name);
        cout << "Enter historical event description: ";
        getline(cin, description);
        cout << "Enter historical event date: ";
        getline(cin, date);
    }
};

// Character Class
class Character {
private:
    string name;
    int age;
    string role;

public:
    // Constructor
    Character(string n = "", int a = 0, string r = "")
        : name(n), age(a), role(r) {}

    // Getter Methods
    string getName() const { return name; }
    int getAge() const { return age; }
    string getRole() const { return role; }

    // Setter Methods
    void setName(string n) { name = n; }
    void setAge(int a) { age = a; }
    void setRole(string r) { role = r; }

    // Input Method
    void input() {
        cout << "Enter character name: ";
        getline(cin, name);
        cout << "Enter character age: ";
        cin >> age;
        cin.ignore();  // To ignore the newline character left in the buffer
        cout << "Enter character role: ";
        getline(cin, role);
    }
};

// Culture Class
class Culture {
private:
    string name;
    string traditions;
    string language;

public:
    // Constructor
    Culture(string n = "", string t = "", string l = "")
        : name(n), traditions(t), language(l) {}

    // Getter Methods
    string getName() const { return name; }
    string getTraditions() const { return traditions; }
    string getLanguage() const { return language; }

    // Setter Methods
    void setName(string n) { name = n; }
    void setTraditions(string t) { traditions = t; }
    void setLanguage(string l) { language = l; }

    // Input Method
    void input() {
        cout << "Enter culture name: ";
        getline(cin, name);
        cout << "Enter culture traditions: ";
        getline(cin, traditions);
        cout << "Enter culture language: ";
        getline(cin, language);
    }
};

// GeographicalLocation Class
class GeographicalLocation {
private:
    string name;
    string climate;
    string terrain;

public:
    // Constructor
    GeographicalLocation(string n = "", string c = "", string t = "")
        : name(n), climate(c), terrain(t) {}

    // Getter Methods
    string getName() const { return name; }
    string getClimate() const { return climate; }
    string getTerrain() const { return terrain; }

    // Setter Methods
    void setName(string n) { name = n; }
    void setClimate(string c) { climate = c; }
    void setTerrain(string t) { terrain = t; }

    // Input Method
    void input() {
        cout << "Enter geographical location name: ";
        getline(cin, name);
        cout << "Enter geographical location climate: ";
        getline(cin, climate);
        cout << "Enter geographical location terrain: ";
        getline(cin, terrain);
    }
};

// World Class
class World {
private:
    vector<HistoricalEvent> events;
    vector<Character> characters;
    vector<Culture> cultures;
    vector<GeographicalLocation> locations;

public:
    // Add Event
    void addEvent(const HistoricalEvent& e) { events.push_back(e); }

    // Add Character
    void addCharacter(const Character& c) { characters.push_back(c); }

    // Add Culture
    void addCulture(const Culture& c) { cultures.push_back(c); }

    // Add Location
    void addLocation(const GeographicalLocation& l) { locations.push_back(l); }

    // Display Events
    void displayEvents() const {
        for (const auto& e : events) {
            cout << "Event: " << e.getName() << " - " << e.getDescription() << " on " << e.getDate() << endl;
        }
    }

    // Display Characters
    void displayCharacters() const {
        for (const auto& c : characters) {
            cout << "Character: " << c.getName() << ", Age: " << c.getAge() << ", Role: " << c.getRole() << endl;
        }
    }

    // Display Cultures
    void displayCultures() const {
        for (const auto& c : cultures) {
            cout << "Culture: " << c.getName() << ", Traditions: " << c.getTraditions() << ", Language: " << c.getLanguage() << endl;
        }
    }

    // Display Locations
    void displayLocations() const {
        for (const auto& l : locations) {
            cout << "Location: " << l.getName() << ", Climate: " << l.getClimate() << ", Terrain: " << l.getTerrain() << endl;
        }
    }
};

int main() {
    World middleEarth;

    int numEvents, numCharacters, numCultures, numLocations;

    // Input number of historical events
    cout << "Enter the number of historical events: ";
    cin >> numEvents;
    cin.ignore();  // To ignore the newline character left in the buffer
    for (int i = 0; i < numEvents; ++i) {
        HistoricalEvent event;
        cout << "Enter details for historical event " << (i + 1) << ":" << endl;
        event.input();
        middleEarth.addEvent(event);
    }

    // Input number of characters
    cout << "Enter the number of characters: ";
    cin >> numCharacters;
    cin.ignore();  // To ignore the newline character left in the buffer
    for (int i = 0; i < numCharacters; ++i) {
        Character character;
        cout << "Enter details for character " << (i + 1) << ":" << endl;
        character.input();
        middleEarth.addCharacter(character);
    }

    // Input number of cultures
    cout << "Enter the number of cultures: ";
    cin >> numCultures;
    cin.ignore();  // To ignore the newline character left in the buffer
    for (int i = 0; i < numCultures; ++i) {
        Culture culture;
        cout << "Enter details for culture " << (i + 1) << ":" << endl;
        culture.input();
        middleEarth.addCulture(culture);
    }

    // Input number of geographical locations
    cout << "Enter the number of geographical locations: ";
    cin >> numLocations;
    cin.ignore();  // To ignore the newline character left in the buffer
    for (int i = 0; i < numLocations; ++i) {
        GeographicalLocation location;
        cout << "Enter details for geographical location " << (i + 1) << ":" << endl;
        location.input();
        middleEarth.addLocation(location);
    }

    // Display all information
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
