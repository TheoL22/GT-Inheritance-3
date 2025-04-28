#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Beverage {
protected:
    string name;
    int volume;
    bool isChilled;

public:
    Beverage(string name, int volume, bool isChilled)
        : name(name), volume(volume), isChilled(isChilled) {}

    string toString() {
        return name + " (" + to_string(volume) + "mL) is " + (isChilled ? "still chilled" : "not chilled anymore");
    }
};

class Water : public Beverage {
private:
    string type;

public:
    Water(int volume, bool isChilled, string type = "Regular")
        : Beverage("Water", volume, isChilled), type(type) {}

    string toString() {
        return "Water (" + to_string(volume) + "mL) is " + (isChilled ? "still chilled" : "not chilled anymore") + " (" + type + ")";
    }
};

class Beer : public Beverage {
private:
    double alcoholicContent;

public:
    Beer(int volume, bool isChilled, double alcoholicContent)
        : Beverage("Beer", volume, isChilled), alcoholicContent(alcoholicContent) {}

    string toString() {
        string chilledStatus = isChilled ? "still chilled" : "not chilled anymore";
        string type = (alcoholicContent < 0.03) ? "Flavored" :
                      (alcoholicContent < 0.06) ? "Regular" : "Strong";

        return "Beer (" + to_string(volume) + "mL) is " + chilledStatus +
               " (" + to_string(alcoholicContent * 100) + "% alcoholic content) | " + type;
    }
};

int main() {
    int volume;
    bool isChilled;
    string isChilledInput, type;

    cout << "Enter water volume (mL): ";
    cin >> volume;
    cout << "Is the water chilled? (yes/no): ";
    cin >> isChilledInput;
    isChilled = (isChilledInput == "yes");

    cout << "Do you want to specify water type? (yes/no): ";
    cin >> isChilledInput;

    if (isChilledInput == "yes") {
        cout << "Enter water type (Purified, Regular, Distilled): ";
        cin >> type;
    } else {
        type = "Regular";
    }

    Water water(volume, isChilled, type);
    cout << "\nWater Details:\n" << water.toString() << endl;

    cout << "\nEnter beer volume (mL): ";
    cin >> volume;
    cout << "Is the beer chilled? (yes/no): ";
    cin >> isChilledInput;
    isChilled = (isChilledInput == "yes");

    double alcoholicContent;
    cout << "Enter alcohol content (e.g., 0.045 for 4.5%): ";
    cin >> alcoholicContent;

    Beer beer(volume, isChilled, alcoholicContent);
    cout << "\nBeer Details:\n" << beer.toString() << endl;

    return 0;
}