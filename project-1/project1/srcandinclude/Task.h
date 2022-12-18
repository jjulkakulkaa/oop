#pragma once
#include <string.h>
#include<iostream>

using namespace std;

class Text {
public:
	virtual Text* editedContent(string newContent) = 0;
	virtual Text* editedType(string newType) = 0;
	virtual string displayedContent() = 0;
	virtual string displayedType() = 0;

};

class Task : public Text
{
	string content;
	string type;

public:

	Task(string content);
	Task(string content, string type);

	~Task();

	Task* editedContent(string newContent);
	Task* editedType(string newType);
	string displayedContent();
	string displayedType();

};
