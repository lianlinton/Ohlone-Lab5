#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "menu.h"
#include "courseMenu.h"
#include "unorderedArrayListType.h"

using namespace std;

CourseMenu::CourseMenu()
    : Menu("Course Menu") {
    addOption("1) Select a course from the list of courses"); // Lab 5 - 1) sortBy any field in class Course; 2) use FacultyMenu to set the faculty info
    addOption("2) View course details");
    addOption("3) Add a course");   // Lab 5 - use FacultyMenu to select a faculty to add 
    addOption("4) Edit a course");  // Lab 5 - use FacultyMenu to select a faculty to edit
    addOption("5) Delete a course");
    addOption("x) Exit");

    pCourse = nullptr;
    list = new UnorderedArrayListType<Course*>();
    init();
};

CourseMenu::~CourseMenu() {
    int i = 0;
    while (i < list->listSize()) {
        Course *p;
        list->retrieveAt(i, p);
        delete p;
        i++;
    }
    delete list;
    inFile.close();
}

/**
* 
* Read/populate course_data.csv into the list
*/
void CourseMenu::init() {
    inFile.open(COURSE_DATA, ios::in | ios::out | ios::app);

    string term;
    string year;
    string startDate; // convert previous date string to class DateType
    string endDate;  // convert previous date string to class DateType
    string name;
    string section;
    string id;
    string meetDays;
    string location;
    string meetInfo;
    string instructor;
    string units;

    string line = "";
    while (getline(inFile, line)) {
        stringstream ss(line);
        getline(ss, term, ',');
        getline(ss, year, ',');
        getline(ss, startDate, ',');
        getline(ss, endDate, ',');
        getline(ss, name, ',');
        getline(ss, section, ',');
        getline(ss, id, ',');
        getline(ss, meetDays, ',');
        getline(ss, location, ',');
        getline(ss, meetInfo, ',');
        getline(ss, instructor, ',');
        getline(ss, units, ',');

        Course *p = new Course();
        p->setTerm(term);
        p->setYear(stoi(year));
        p->setStartDate(startDate);
        p->setEndDate(endDate);
        p->setName(name);
        p->setSection(section);
        p->setId(id);
        p->setMeetDays(meetDays);
        p->setLocation(location);
        p->setMeetInfo(meetInfo);
        p->setInstructor(instructor);
        p->setUnits(stoi(units));
        list->insertEnd(p);
    }
    inFile.clear();
}

void CourseMenu::doList() {
    Menu c("List of Courses");
    Course* p;
    for (int i = 1; i <= list->listSize(); i++) {
        list->retrieveAt(i - 1, p);
        c.addOption(p->getTerm() + " " + to_string(p->getYear()) + " " + p->getSection() + " " + p->getName());
    }
    int input = c.getInput();
    list->retrieveAt(input - 1, p);
    this->selectedCourse(*p);
}

void CourseMenu::doView() {
    if (pCourse == nullptr) {        
        doList();
    }
    pCourse->printCourseInfo();
}

void CourseMenu::doAdd() {
    Course* p = new Course();
    string term;
    string year;
    string startDate; // convert previous date string to class DateType
    string endDate;  // convert previous date string to class DateType
    string name;
    string section;
    string id;
    string meetDays;
    string location;
    string meetInfo;
    string instructor;
    string units;

    cout << "Enter Term: ";
    cin >> term;
    cout << "Enter Year: ";
    cin >> year;
    cout << "Enter start date (MM/DD/YYYY): ";
    cin >> startDate;
    cout << "Enter end date (MM/DD/YYYY): ";
    cin >> endDate;
    cout << "Enter course name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter section: ";
    cin >> section;
    cout << "Enter course Id: ";
    cin >> id;
    cin.ignore();
    cout << "Enter meeting days: ";
    cin >> meetDays;
    cout << "Enter meeting location: ";
    cin >> meetInfo;
    cout << "Enter instructor name: ";
    cin >> instructor;
    cout << "Enter units: ";
    cin >> units;
    p->setTerm(term);
    p->setYear(stoi(year));
    p->setStartDate(startDate);
    p->setEndDate(endDate);
    p->setName(name);
    p->setSection(section);
    p->setId(id);
    p->setMeetDays(meetDays);
    p->setLocation(location);
    p->setMeetInfo(meetInfo);
    p->setInstructor(instructor);
    p->setUnits(stoi(units));
    list->insertEnd(p);
}

void CourseMenu::doEdit() {
    if (pCourse == nullptr) {
        doList();
    }
    Course* p = pCourse;

    string temp;
    cout << "Enter new term or default  (" + p->getTerm() + "): ";
    cin.ignore();
    getline(cin, temp);

    if (!temp.empty()) {
        p->setTerm(temp);
    }
    
    p->printCourseInfo();
}

void CourseMenu::doDelete() {
    if (pCourse == nullptr) {
        doList();
    }
    list->remove(pCourse);
}

void CourseMenu::doFacultyMenu() {    
    char option = FACULTY_MENU_OPTION::FACULTY_EDIT;
    do {
        option = facultyMenu.getOption();

        if (option == FACULTY_MENU_OPTION::FACULTY_LIST) {
            facultyMenu.doList();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_VIEW) {
            facultyMenu.doView();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_ADD) {
            facultyMenu.doAdd();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_EDIT) {
            facultyMenu.doEdit();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_DELETE) {
            facultyMenu.doDelete();
        }
        else if (option == FACULTY_MENU_OPTION::FACULTY_EXIT) {
            // TODO facultyMenu.doSave();
            cout << "Exiting Faculty Menu" << endl;
        }
    } while (option != FACULTY_MENU_OPTION::FACULTY_EXIT);
}