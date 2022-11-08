#include "menu.h"
#include "mainMenu.h"
#include "assignmentMenu.cpp"
#include "studentMenu.cpp"

MainMenu::MainMenu()
    : Menu("My Canvas Menu") {
    addOption("1) Home");
    addOption("2) Announcements");
    addOption("3) Assignments");
    addOption("4) Discussions");
    addOption("5) Grades");
    addOption("6) Quizzes");
    addOption("7) People");
    addOption("x) Logout");
};

void MainMenu::doAssignments() {
	char option = ASSIGNMENT_MENU_OPTION::ASSIGNMENT_EXIT;
	do {
		option = assignmentMenu.getOption();

		if (option == ASSIGNMENT_MENU_OPTION::LIST_ALL) {
			assignmentMenu.doList();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::LIST_PENDING) {
			assignmentMenu.doListPending();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::LIST_COMPLETED) {
			assignmentMenu.doListCompleted();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::VIEW) {
			assignmentMenu.doView();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::ADD) {
			assignmentMenu.doAdd();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::EDIT) {
			assignmentMenu.doEdit();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::DELETE) {
			assignmentMenu.doDelete();
		}
		else if (option == ASSIGNMENT_MENU_OPTION::ASSIGNMENT_EXIT) {			
			assignmentMenu.doSave();
		}
	} while (option != ASSIGNMENT_MENU_OPTION::ASSIGNMENT_EXIT);
}

void MainMenu::doStudentMenu() {
	char option = STUDENT_MENU_OPTION::STUDENT_EXIT;
	do {
		option = studentMenu.getOption();

		if (option == STUDENT_MENU_OPTION::STUDENT_LIST) {
			studentMenu.doList();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_VIEW) {
			studentMenu.doView();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_ADD) {
			studentMenu.doAdd();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_EDIT) {
			studentMenu.doEdit();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_DELETE) {
			studentMenu.doDelete();
		}
		else if (option == STUDENT_MENU_OPTION::STUDENT_EXIT) {
			cout << "Exiting Students Menu" << endl;
		}
	} while (option != STUDENT_MENU_OPTION::STUDENT_EXIT);
}