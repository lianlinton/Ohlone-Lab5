#include "menu.h"
#include "studentMenu.h"

StudentMenu::StudentMenu()
    : Menu("Course Menu") {
    addOption("1) Student list");   // Lab 5 - sortBy any field in class Student and Person
    addOption("2) View student details");
    addOption("3) Add a student");
    addOption("4) Edit a student");
    addOption("5) Delete a student");
    addOption("x) Exit");
    
    list = new vector<Student*>();
    init();
};

StudentMenu::~StudentMenu() {
    for (int i = 0; i < (int) list->size(); i++) {
        delete list->at(i);
    }
    delete list;
    inFile.close();
}

void StudentMenu::init() {    
    inFile.open(STUDENT_DATA, ios::in | ios::out | ios::app);
    // TODO - load STUDENT_DATA
    inFile.clear();
}

void StudentMenu::doList() {
    // TODO
}

void StudentMenu::doView() {
    // TODO
}

void StudentMenu::doAdd() {
    // TODO
}

void StudentMenu::doEdit() {
    // TODO
}

void StudentMenu::doDelete() {
    // TODO
}