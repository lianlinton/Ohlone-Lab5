#include <iostream>
#include <string>
#include <vector>
#include "menu.h"

using namespace std;

/**
* Initial menu name
*/
Menu::Menu(string name) {
    this->name = name;
}

/**
* Add menu open name
*/
void Menu::addOption(string option) {
    options.push_back(option);
}

/**
* Dipslay option nam
*/
void Menu::display() const {
    cout << "***** " << name << " *****" << endl;
    for (int i = 0; i < (int) options.size(); i++) {
        cout << options[i] << endl;
    }
    cout << "\nEnter choice: ";
}

/**
* Display ordered index and option name
*/
void Menu::displayPrefixIndex() const {
    cout << "***** " << name << " *****" << endl;
    for (int i = 0; i < (int)options.size(); i++)
    {
        cout << i + 1 << ") " << options[i] << endl;
    }
    cout << "\nEnter choice: ";
}
/**
* Display option menu, option name; and ask users to select a choice
*/
int Menu::getInput() const {
    char ch;
    int input = 0;
    do {
        displayPrefixIndex();
        cin >> ch;
        input = static_cast<int>(ch) - 48;
    } while (input < 1 || input > (int)options.size());
    return input;
}

/**
* Display option menu, option name; and ask users to select a choice
*/
char Menu::getOption() const {
    char input;
    display();
    cin >> input;
    return input;
}