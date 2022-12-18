#pragma once
#include <wx/wx.h>
#include <wx/checklst.h>
#include <vector>
#include "Task.h"

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);

	wxButton* addTaskButton;
	wxButton* editButton;


	//place to type task we want to add

	wxTextCtrl* typingPlace;


	//place where tasks will be stored

	wxCheckListBox* todayTasksBox;
	wxCheckListBox* importantTasksBox;
	wxCheckListBox* otherTasksBox;


	//container with available task types

	wxChoice* taskTypeChoice;


	//each vector contains different types tasks 

	vector<Task> todayTasksVector;
	vector<Task> otherTasksVector;
	vector<Task> importantTasksVector;

	

private:
	void OnTypingPlaceChanged(wxCommandEvent& event);
	

	//adding task to vector and checklistbox that mathes choosen type

	void OnAddTaskButtonClicked(wxCommandEvent& event);

	//deleting task when its checkbox clicked

	void OnTCheckboxClicked(wxCommandEvent& event);
	void OnICheckboxClicked(wxCommandEvent& event);
	void OnOCheckboxClicked(wxCommandEvent& event);

	//selected task can be edited by user after editButton cliked

	void OnEditButtonClicked(wxCommandEvent& event);


};

