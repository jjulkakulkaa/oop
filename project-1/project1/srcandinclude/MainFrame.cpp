#include "MainFrame.h"
#include <wx/wx.h>
#include <wx/checklst.h>
#include <wx/gdicmn.h>
#include <string>
#include "Task.h"
#include<iostream>
#include <vector>

using namespace std;

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	
	// creating buttons, place to user input, task containers

	wxPanel* panel = new wxPanel(this);
	panel->SetBackgroundColour(*wxWHITE);

	wxFont font(10, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL);
	
	addTaskButton = new wxButton(panel, wxID_ANY, "ADD TASK", wxPoint(620, 100), wxSize(100, 25));
	addTaskButton->SetFont(font);

	editButton = new wxButton(panel, wxID_ANY, "EDIT", wxPoint(350, 550), wxSize(100, 25));
	editButton->SetFont(font);

	wxStaticText* header = new wxStaticText(panel, wxID_ANY, "TO DO LIST", wxPoint(300, 10), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL);
	wxFont headerFont(32, wxFONTFAMILY_SWISS, wxFONTSTYLE_MAX, wxFONTWEIGHT_MAX);
	header->SetFont(headerFont);
	

	typingPlace = new wxTextCtrl(panel, wxID_ANY, "Type your task here", wxPoint(180, 100), wxSize(440, 25));
	typingPlace->SetFont(font);

	wxFont taskTypesfont(22, wxFONTFAMILY_SWISS, wxFONTSTYLE_MAX, wxFONTWEIGHT_MAX);

	todayTasksBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(80, 200), wxSize(200, 300));
	todayTasksBox->SetFont(font);

	wxStaticText* todaytext = new wxStaticText(panel, wxID_ANY, "TODAY", wxPoint(130, 160), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL);
	todaytext->SetFont(taskTypesfont);

	importantTasksBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(300, 200), wxSize(200, 300));
	importantTasksBox->SetFont(font);
	wxStaticText* importanttext = new wxStaticText(panel, wxID_ANY, "IMPORTANT", wxPoint(310, 160), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL);
	importanttext->SetFont(taskTypesfont);

	otherTasksBox = new wxCheckListBox(panel, wxID_ANY, wxPoint(520, 200), wxSize(200, 300));
	otherTasksBox->SetFont(font);
	wxStaticText* otherstext = new wxStaticText(panel, wxID_ANY, "OTHER", wxPoint(560, 160), wxSize(100, -1), wxALIGN_CENTER_HORIZONTAL);
	otherstext->SetFont(taskTypesfont);

	wxArrayString taskTypes;
	taskTypes.Add("Today");
	taskTypes.Add("Important");
	taskTypes.Add("Other");


	taskTypeChoice = new wxChoice(panel, wxID_ANY, wxPoint(80, 100), wxSize(100, -1), taskTypes);
	taskTypeChoice->SetToolTip("Choose task type");
	

	addTaskButton->Bind(wxEVT_BUTTON, &MainFrame::OnAddTaskButtonClicked, this);
	typingPlace->Bind(wxEVT_TEXT, &MainFrame::OnTypingPlaceChanged, this);

	todayTasksBox->Bind(wxEVT_CHECKLISTBOX, &MainFrame::OnTCheckboxClicked, this);
	otherTasksBox->Bind(wxEVT_CHECKLISTBOX, &MainFrame::OnOCheckboxClicked, this);
	importantTasksBox->Bind(wxEVT_CHECKLISTBOX, &MainFrame::OnICheckboxClicked, this);
	

	editButton->Bind(wxEVT_BUTTON, &MainFrame::OnEditButtonClicked, this);

	CreateStatusBar();
}

void MainFrame::OnAddTaskButtonClicked(wxCommandEvent& event) {
	
	
	if (typingPlace->GetValue().IsEmpty()) {
		wxLogMessage("Task content cannot be empty");
	}
	else {

		// creating Task with content from typingPlace 
		// and type selected from taskType choice place

		Task task(typingPlace->GetValue().ToStdString(), taskTypeChoice->GetStringSelection().ToStdString());

		if (task.displayedType() == "Today") {
			todayTasksVector.push_back(task);
			todayTasksBox->Append(task.displayedContent());

		}

		else if (task.displayedType() == "Important") {
			importantTasksVector.push_back(task);
			importantTasksBox->Append(task.displayedContent());

		}
		else {
			otherTasksVector.push_back(task);
			otherTasksBox->Append(task.displayedContent());
		}
		typingPlace->ChangeValue("Type your task here");
		wxLogStatus("Task Added ");
	}
}

void MainFrame::OnTypingPlaceChanged(wxCommandEvent& event) {
	wxString str = wxString::Format("Typing: %s", event.GetString());
	wxLogStatus(str);
}


//deleting tasks

void MainFrame::OnTCheckboxClicked(wxCommandEvent& event) {
	int taskIndex = event.GetInt();
	todayTasksVector.erase(todayTasksVector.begin() + taskIndex);
	todayTasksBox->Delete(taskIndex);
	
}

void MainFrame::OnICheckboxClicked(wxCommandEvent& event) {
	int taskIndex = event.GetInt();
	importantTasksVector.erase(importantTasksVector.begin() + taskIndex);
	importantTasksBox->Delete(taskIndex);
}

void MainFrame::OnOCheckboxClicked(wxCommandEvent& event) {
	int taskIndex = event.GetInt();
	otherTasksVector.erase(otherTasksVector.begin() + taskIndex);
	otherTasksBox->Delete(taskIndex);
}


// editing tasks
// to edit task user have to click on task and click EDIT button 
// then editing task window will display

void MainFrame::OnEditButtonClicked(wxCommandEvent& event) {

	// checking which task was selected by user
	// by checking every checkListBox with tasks

	int selectedTaskId = todayTasksBox->GetSelection();
	if (selectedTaskId == wxNOT_FOUND) {

		selectedTaskId = importantTasksBox->GetSelection();
		if (selectedTaskId == wxNOT_FOUND) {

			selectedTaskId = otherTasksBox->GetSelection();
			if (selectedTaskId != wxNOT_FOUND) {

				// editing for other tasks
				// works the same as code for today tasks below 

				string tmp_content = otherTasksVector[selectedTaskId].displayedContent();
				wxTextEntryDialog editPlace(this, "Edit your task:", "Task editing", tmp_content);
				if (editPlace.ShowModal() == wxID_OK)
				{
					wxString userInput = editPlace.GetValue();
					Task* editedTaskTmp = otherTasksVector[selectedTaskId].editedContent(userInput.ToStdString());
					Task editedTask = *editedTaskTmp;
					otherTasksVector.push_back(editedTask);
					otherTasksBox->Append(editedTask.displayedContent());
					otherTasksVector.erase(otherTasksVector.begin() + selectedTaskId);
					otherTasksBox->Delete(selectedTaskId);
				}
			
			}
		}
		else {

			// editing for important task
			// works the same as code for today tasks below

			string tmp_content = importantTasksVector[selectedTaskId].displayedContent();
			wxTextEntryDialog editPlace(this, "Edit your task:", "Task editing", tmp_content);
			if (editPlace.ShowModal() == wxID_OK)
			{
				wxString userInput = editPlace.GetValue();
				Task* editedTaskTmp = importantTasksVector[selectedTaskId].editedContent(userInput.ToStdString());
				Task editedTask = *editedTaskTmp;
				importantTasksVector.push_back(editedTask);
				importantTasksBox->Append(editedTask.displayedContent());
				importantTasksVector.erase(importantTasksVector.begin() + selectedTaskId);
				importantTasksBox->Delete(selectedTaskId);

			}
			
		}
	}
	else {

		// editing tasks for today
		// getting content of task that will be edited

		string tmp_content = todayTasksVector[selectedTaskId].displayedContent();

		// window that enables task edit displays

		wxTextEntryDialog editPlace(this, "Edit your task:", "Task editing", tmp_content);
		if (editPlace.ShowModal() == wxID_OK)
		{
			// getting user input and putting it into Task method which returns pointer to new task object
			// this new object contains old type and new content
			// then task after editing goes to vector and checklistbox

			wxString userInput = editPlace.GetValue();
			Task* editedTaskTmp = todayTasksVector[selectedTaskId].editedContent(userInput.ToStdString());
			Task editedTask = *editedTaskTmp;
			todayTasksVector.push_back(editedTask);
			todayTasksBox->Append(editedTask.displayedContent());
			todayTasksVector.erase(todayTasksVector.begin() + selectedTaskId);
			todayTasksBox->Delete(selectedTaskId);
		}

	}
}

