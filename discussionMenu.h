#pragma once
#include <fstream>
#include "discussion.h"
//#include "unorderedLinkedList.h"
#include "menu.h"

using namespace std;

const string DISCUSSION_DATA = "discussions.dat";

enum DISCUSSION_MENU_OPTION {
	LIST_ALL = '1',	
	LIST_PENDING = '2',
	LIST_COMPLETED = '3',
	VIEW = '4',
	ADD = '5',
	EDIT = '6',
	DELETE = '7',
	Discussion_EXIT = 'x'
};

class DiscussionMenu : public Menu {
public:
	DiscussionMenu();
	~DiscussionMenu();

	void doList();
	void doListPending();
	void doListCompleted();
	void doView();
	void doAdd();
	void doEdit();
	void doDelete();
	void doSave();
	Discussion& getSelectedDiscussion() {
		return *pDiscussion;
	};

private:
	void init();
	void setDiscussion(Discussion& a) {
		pDiscussion = &a;
	};

	fstream inFile;
	Discussion* pDiscussion;
	//UnorderedLinkedListType<Discussion*>* list;
};