#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Interface for input functionality
class IInput {
public:
    virtual void input() = 0;
    virtual ~IInput() = default;
};

// Interface for display functionality
class IDisplay {
public:
    virtual void display() const = 0;
    virtual ~IDisplay() = default;
};

// Abstract class: HistoricalEntity
class HistoricalEntity : public IInput, public IDisplay {
public:
    virtual ~HistoricalEntity() = default;
};

// Derived class: HistoricalEvent
class HistoricalEvent : public HistoricalEntity {
private:
    string name;
    string description;
    string date;

public:
    HistoricalEvent(string n = "", string d = "", string dt = "")
        : name(n), description(d), date(dt) {}

    void input() override {  // Implementing the input functionality
        cout << "Enter historical event name: ";
        getline(cin, name);
        cout << "Enter historical event description: ";
        getline(cin, description);
        cout << "Enter historical event date (YYYY-MM-DD): ";
        getline(cin, date);
    }

    void display() const override {  // Implementing the display functionality
        cout << "Event: " << name << " - " << description << " on " << date << endl;
    }
};

// Base class: Person
class Person : public IInput, public IDisplay {
protected:
    string name;
    int age;

public:
    Person(string n = "", int a = 0) : name(n), age(a) {}

    void input() override {  // Implementing the input functionality
        cout << "Enter person's name: ";
        getline(cin, name);
        cout << "Enter person's age: ";
        cin >> age;
        cin.ignore();  // Clear the newline character from the input buffer
    }

    void display() const override {  // Implementing the display functionality
        cout << "Person: " << name << ", Age: " << age << endl;
    }
};

// Derived class: Character, which is both a Person and HistoricalEntity
class Character : public Person, public HistoricalEntity {
protected:
    string role;

public:
    Character(string n = "", int a = 0, string r = "")
        : Person(n, a), role(r) {}

    void input() override {  // Implementing the input functionality
        Person::input();  // Call the base class input
        cout << "Enter character role: ";
        getline(cin, role);
    }

    void display() const override {  // Implementing the display functionality
        cout << "Character: " << name << ", Age: " << age << ", Role: " << role << endl;
    }

    string getRole() const { return role; }  // Getter for role
};

// Derived class: HistoricalFigure
class HistoricalFigure : public Character {
private:
    string significance;

public:
    HistoricalFigure(string n = "", int a = 0, string r = "", string s = "")
        : Character(n, a, r), significance(s) {}

    void input() override {  // Implementing the input functionality
        Character::input();  // Call the base class input
        cout << "Enter significance of the historical figure: ";
        getline(cin, significance);
    }

    void display() const override {  // Implementing the display functionality
        cout << "Figure: " << name << ", Age: " << age 
             << ", Role: " << getRole() << ", Significance: " << significance << endl;
    }
};

// Derived class: Culture
class Culture : public HistoricalEntity {
private:
    string name;
    string traditions;
    string language;

public:
    Culture(string n = "", string t = "", string l = "")
        : name(n), traditions(t), language(l) {}

    void input() override {  // Implementing the input functionality
        cout << "Enter culture name: ";
        getline(cin, name);
        cout << "Enter culture traditions: ";
        getline(cin, traditions);
        cout << "Enter culture language: ";
        getline(cin, language);
    }

    void display() const override {  // Implementing the display functionality
        cout << "Culture: " << name << ", Traditions: " << traditions 
             << ", Language: " << language << endl;
    }
};

// Derived class: GeographicalLocation
class GeographicalLocation : public HistoricalEntity {
private:
    string name;
    string climate;
    string terrain;

public:
    GeographicalLocation(string n = "", string c = "", string t = "")
        : name(n), climate(c), terrain(t) {}

    void input() override {  // Implementing the input functionality
        cout << "Enter geographical location name: ";
        getline(cin, name);
        cout << "Enter geographical location climate: ";
        getline(cin, climate);
        cout << "Enter geographical location terrain: ";
        getline(cin, terrain);
    }

    void display() const override {  // Implementing the display functionality
        cout << "Location: " << name << ", Climate: " << climate 
             << ", Terrain: " << terrain << endl;
    }
};

// New Derived Class: HistoricalPlace (Extending the system without modifying existing code)
class HistoricalPlace : public HistoricalEntity {
private:
    string name;
    string historicalSignificance;
    string geographicalLocation;

public:
    HistoricalPlace(string n = "", string hs = "", string gl = "")
        : name(n), historicalSignificance(hs), geographicalLocation(gl) {}

    void input() override {  // Implementing the input functionality
        cout << "Enter historical place name: ";
        getline(cin, name);
        cout << "Enter historical place significance: ";
        getline(cin, historicalSignificance);
        cout << "Enter geographical location of the place: ";
        getline(cin, geographicalLocation);
    }

    void display() const override {  // Implementing the display functionality
        cout << "Place: " << name << ", Historical Significance: " << historicalSignificance 
             << ", Location: " << geographicalLocation << endl;
    }
};

// Class to manage the world and its historical entities
class World {
private:
    vector<HistoricalEntity*> entities;  // Collection of historical entities

public:
    ~World() {
        for (auto entity : entities) {
            delete entity;  // Clean up
        }
    }

    void addEntity(HistoricalEntity* entity) {  // Accepts any HistoricalEntity
        entities.push_back(entity);
    }

    void displayEntities() const {  // Displays all entities
        for (const auto& entity : entities) {
            entity->display();  // Calls the overridden display function
        }
    }
};

int main() {
    World middleEarth;

    int numEvents, numCharacters, numFigures, numCultures, numLocations, numPlaces;

    // Input for Historical Events
    cout << "Enter the number of historical events: ";
    cin >> numEvents;
    cin.ignore(); 
    for (int i = 0; i < numEvents; ++i) {
        HistoricalEvent* event = new HistoricalEvent();
        cout << "Enter details for historical event " << (i + 1) << ":" << endl;
        event->input(); // Call to the overridden input function
        middleEarth.addEntity(event);
    }

    // Input for Characters
    cout << "Enter the number of characters: ";
    cin >> numCharacters;
    cin.ignore(); 
    for (int i = 0; i < numCharacters; ++i) {
        Character* character = new Character();
        cout << "Enter details for character " << (i + 1) << ":" << endl;
        character->input(); // Call to the overridden input function
        middleEarth.addEntity(character);
    }

    // Input for Historical Figures
    cout << "Enter the number of historical figures: ";
    cin >> numFigures;
    cin.ignore(); 
    for (int i = 0; i < numFigures; ++i) {
        HistoricalFigure* figure = new HistoricalFigure();
        cout << "Enter details for historical figure " << (i + 1) << ":" << endl;
        figure->input(); // Call to the overridden input function
        middleEarth.addEntity(figure); 
    }

    // Input for Cultures
    cout << "Enter the number of cultures: ";
    cin >> numCultures;
    cin.ignore(); 
    for (int i = 0; i < numCultures; ++i) {
        Culture* culture = new Culture();
        cout << "Enter details for culture " << (i + 1) << ":" << endl;
        culture->input(); // Call to the overridden input function
        middleEarth.addEntity(culture);
    }

    // Input for Geographical Locations
    cout << "Enter the number of geographical locations: ";
    cin >> numLocations;
    cin.ignore();  
    for (int i = 0; i < numLocations; ++i) {
        GeographicalLocation* location = new GeographicalLocation();
        cout << "Enter details for geographical location " << (i + 1) << ":" << endl;
        location->input(); // Call to the overridden input function
        middleEarth.addEntity(location);
    }

    // Input for Historical Places
    cout << "Enter the number of historical places: ";
    cin >> numPlaces;
    cin.ignore();  // To clear the input buffer after the integer input
    for (int i = 0; i < numPlaces; ++i) {
        HistoricalPlace* place = new HistoricalPlace();
        cout << "Enter details for historical place " << (i + 1) << ":" << endl;
        place->input(); // Call to the overridden input function for HistoricalPlace
        middleEarth.addEntity(place);
    }

    // Display all information
    cout << "\nEntities in the World:" << endl;
    middleEarth.displayEntities(); // Calls the display method for each entity
    
    return 0;
}
