#include <vector>
#include "myCanvas.h"
#include "loginMenu.cpp"
#include "courseMenu.cpp"
#include "studentMenu.cpp"
#include "mainMenu.cpp"


using namespace std;

MyCanvas::MyCanvas() {
}

MyCanvas::~MyCanvas() {

}

bool MyCanvas::doLogin() {	
	char option = loginMenu.getOption();
	switch (option) {
		case LOGIN_MENU_OPTION::LOGIN:
			return loginMenu.doLogin();
		case LOGIN_MENU_OPTION::CREATE:
			// TODO
			loginMenu.doCreate();
			break;
		case LOGIN_MENU_OPTION::RESET:
			// TODO
			loginMenu.doReset();
			break;
		case LOGIN_MENU_OPTION::EXIT:
			cout << "Exiting Login Menu" << endl;
			return false;
		default: {}
	}

	return false;
}

void MyCanvas::doLogout() {
	// TODO: Lab 5 
}

bool MyCanvas::doCourseMenu() {
	char option = COURSE_MENU_OPTION::COURSE_EXIT;
	do {
		option = courseMenu.getOption();

		if (option == COURSE_MENU_OPTION::COURSE_LIST) {
			courseMenu.doList();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_VIEW) {
			courseMenu.doView();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_ADD) {
			courseMenu.doAdd();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_EDIT) {
			courseMenu.doEdit();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_DELETE) {
			courseMenu.doDelete();
		}
		else if (option == COURSE_MENU_OPTION::COURSE_EXIT) {
			// TODO courseMenu.doSave();
			cout << "Exiting Course Menu" << endl;
		}
	} while (option != EXIT);

	return courseMenu.isSelectedCourse();
}

void MyCanvas::doMainMenu() {	
	char option = MAIN_MENU_OPTION::MAIN_MENU_EXIT;
	do {
		option = mainMenu.getOption();

		if (option == MAIN_MENU_OPTION::MAIN_MENU_HOME){
			//TODO mainMenu.doHome();
		}
		else if (option == MAIN_MENU_OPTION::MAIN_MENU_ANNOUNCEMENT) {
			//TODO mainMenu.doAnnouncement();
		}
		else if (option == MAIN_MENU_OPTION::MAIN_MENU_DISCUSSION) {
			//TODO mainMenu.doDiscussion();
		}
		else if (option == MAIN_MENU_OPTION::MAIN_MENU_ASSIGNMENT) {
			mainMenu.doAssignments();
		}
		else if (option == MAIN_MENU_OPTION::MAIN_MENU_QUIZ) {
			//TODO mainMenu.doQuiz();
		}
		else if (option == MAIN_MENU_OPTION::MAIN_MENU_STUDENT) {				
			mainMenu.doStudentMenu();
		}
		else if (option == MAIN_MENU_OPTION::MAIN_MENU_SYLLABUS) {
			// TODO mainMenu.doSyllabus();
		} // else EXIT
	} while (option != MAIN_MENU_OPTION::MAIN_MENU_EXIT);
}