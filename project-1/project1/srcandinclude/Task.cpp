#pragma once
#include "Task.h"


Task::Task(string content) {
	this->content = content;
	this->type = "Other";
}

Task::Task(string content, string type) {
	try {
		if (content == "")
			throw invalid_argument("error: content cannot be empty");
		else {
			this->content = content;
		}
	}
	catch (invalid_argument& error) {
		cout << error.what();

	}
	this->type = type;
}

Task::~Task() {

}

Task* Task::editedContent(string newContent) {
	try {
		if (newContent == "")
			throw invalid_argument("error: content cannot be empty");

		Task* task = new Task(newContent, type);
		return task;
	}
	catch (invalid_argument& error) {
		cout << error.what();
		exit(0);
	}
}
Task* Task::editedType(string newType) {
	Task* task = new Task(content, newType);
	return task;
}
string Task::displayedContent() {
	return content;
}
string Task:: displayedType() {
	return type;
}