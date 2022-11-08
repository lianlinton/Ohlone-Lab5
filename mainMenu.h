#pragma once
#include "menu.h"
#include "studentMenu.h"
#include "assignmentMenu.h"

using namespace std;

enum MAIN_MENU_OPTION {
	MAIN_MENU_HOME='1', 
	MAIN_MENU_ANNOUNCEMENT='2',
	MAIN_MENU_ASSIGNMENT = '3',
	MAIN_MENU_DISCUSSION='4',
	MAIN_MENU_GRADE = '5',
	MAIN_MENU_QUIZ = '6',
	MAIN_MENU_STUDENT = '7',
	MAIN_MENU_SYLLABUS = '8',	
	MAIN_MENU_EXIT='x'
};

class MainMenu : public Menu {
public:
	MainMenu();

	void doAssignments();
	void doStudentMenu();
private:
	StudentMenu studentMenu;				// TODO: Lab 5 - Use LinkedQueue<Student*>
	AssignmentMenu assignmentMenu;
	// TODO:
	// HomeMenu homeMenu;
	// AnnouncementMenu announcementMenu;	// TODO: Lab 5 - Use LinkedStack<Announcement*>
	// DiscussionMenu discussionMenu;		// TODO: Lab 5 - Use LinkedList<Discussion*>
	// GradeMenu gradeMenu;
	// SyllabusMenu syllabus;
};

