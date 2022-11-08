#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "menu.h"
#include "discussion.h"
#include "discussionMenu.h"
#include "unorderedArrayListType.h"

using namespace std;

DiscussionMenu::DiscussionMenu()
    : Menu("Discussions Menu") {
    addOption("1) List all discussions");
    addOption("2) View");
    addOption("3) Add");
    addOption("4) Edit");
    addOption("5) Delete");
    addOption("x) Exit");

    pDiscussion = nullptr;
    //list = new UnorderedArrayListType<Discussion*>();    
    init();
};

/*DiscussionMenu::~DiscussionMenu() {
    int i = 0;
    while (i < list->listSize()) {
        Discussion* p;
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
void DiscussionMenu::init() {    
    inFile.open(DISCUSSION_DATA, ios::in | ios::out | ios::app);

    string name;
    string availableDate;
    string dueDate;
    string possiblePoints;
    string points;
    string status;  // 1=Yes; 0=No

    string line = "";
    while (getline(inFile, line)) {
        stringstream ss(line);
        getline(ss, name, ',');
        getline(ss, availableDate, ',');
        getline(ss, dueDate, ',');
        getline(ss, possiblePoints, ',');
        getline(ss, points, ',');
        getline(ss, status, ',');

        Discussion* p = new Discussion();
        p->setName(name);
        p->setAvailableDate(availableDate);
        p->setDueDate(dueDate);
        p->setPossiblePoint(stoi(possiblePoints));
        p->setPoint(stoi(points));
        p->setStatus(stoi(status));
        list->insertEnd(p);
    }
    inFile.clear();
}

void DiscussionMenu::doList() {
    Menu c("Discussions");
    Discussion* p;
    for (int i = 1; i <= list->listSize(); i++) {
        list->retrieveAt(i - 1, p);
        c.addOption(p->getName());
    }
    int input = c.getInput();
    list->retrieveAt(input - 1, p);
    this->setDiscussion(*p);
    cout << endl;
}

void DiscussionMenu::doListPending() {
    UnorderedArrayListType<Discussion*> tmpList;
    Discussion* p;
    for (int i = 1; i <= list->listSize(); i++) {
        list->retrieveAt(i - 1, p);
        if (!p->isCompleted()) {
            tmpList.insertEnd(p);
        }
    }    

    cout << "***** View Pending Discussions *****" << endl;
    if (tmpList.listSize() != 0) {
        printHeader();
        for (int i = 1; i <= tmpList.listSize(); i++) {
            tmpList.retrieveAt(i - 1, p);
            cout << *p << endl;
        }
    } else {
        cout << "No Pending Discussions" << endl;
    }
    cout << endl;
}

void DiscussionMenu::doListCompleted() {
    UnorderedArrayListType<Discussion*> tmpList;
    Discussion* p;
    for (int i = 1; i <= list->listSize(); i++) {
        list->retrieveAt(i - 1, p);
        if (p->isCompleted()) {
            tmpList.insertEnd(p);
        }
    }
    cout << "***** View Completed Discussions *****" << endl;
    if (tmpList.listSize() != 0) {
        printHeader();
        for (int i = 1; i <= tmpList.listSize(); i++) {
            tmpList.retrieveAt(i - 1, p);
            cout << *p << endl;
        }
    }
    else {
        cout << "No Completed Discussions" << endl;
    }
    cout << endl;
}

void DiscussionMenu::doView() {
    if (pDiscussion == nullptr) {
        doList();
    }
    cout << "***** View Selected Discussion *****" << endl;
    Discussion a = getSelectedDiscussion();
    printHeader();
    cout << a << endl << endl;
}

void DiscussionMenu::doAdd() {
    cout << "***** Add New Discussion *****" << endl;
    Discussion* p = new Discussion();
    cin >> *p;
    list->insertEnd(p);
}

void DiscussionMenu::doEdit() {
    if (pDiscussion == nullptr) {
        doList();
    }
    cout << "***** Edit Selected Discussion *****" << endl;
    if (pDiscussion != nullptr) {
        cin >> *pDiscussion;
    }
    else {
        // Users need to select an Discussion to edit
        doList();
        doEdit();
    }
    cout << endl;
}

void DiscussionMenu::doDelete() {
    cout << "***** Delete Discussion *****" << endl;
    if (pDiscussion == nullptr) {
        doList();
    }
    string name = pDiscussion->getName();
    list->remove(pDiscussion);
    pDiscussion = nullptr;
    cout << name << ", deleted!" << endl << endl;
}

/**
* Save to file
*/
void DiscussionMenu::doSave() {
    cout << "Saving... " << DISCUSSION_DATA << endl;
    if (inFile.is_open()) {
        Discussion* p;
        for (int i = 1; i <= list->listSize(); i++) {
            list->retrieveAt(i - 1, p);
            inFile << p->toCSV() << endl;
        }
    }
    else {
        cerr << "Failed to open file : " << DISCUSSION_DATA
            << " (errno " << errno << ")" << endl;
    }
    cout << "Save!!!" << endl << endl;
}*/