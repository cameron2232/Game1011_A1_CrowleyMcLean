#include "Survey.h"
#include <iostream>
int temp;
char choice;
using namespace std;
int main()
{
	cout << "Welcome to the College Student Survey Processor!\n\nThe purpose of this application is to process a survey of students"
	<< "\nand present to you some neat Statistics."
	<< "\n\nThese Statistics include:"
	<< "\n_______________________________________________________________________________"
	<< "\n|1.) The Number of Students in Gaming / Non Gaming Programs.                  |"
	<< "\n|2.) The average Age of all Students in said these two catagories.            |"
	<< "\n|3.) The most preffered streaming service of Non Gaming Students.             |"
	<< "\n|4.) The most preffered gaming platform of Gaming Students.                   |"
	<< "\n|5.) The average amount of hours Students spend in their entertainment outlet.|"
	<< "\n|_____________________________________________________________________________|"
		<<"\n\nReady to begin?\n\nPlease enter the amount of students you would like to be processed: ";
	cin >> temp;
	
	while(temp > 500)
	{
		system("cls");
		cout << "That number is too big!\n\n" << "Please enter a different amount of students to create (Max 500!) ";
		cin >> temp;
	}
	system("cls");
	Survey StudentSurvey(temp);
	cout << "Survey Created. Are you ready to process the survey?\n\nY: Process Survey\nN: Exit program\n\nSelection: ";
	cin >> choice;
	if(choice=='Y')
	{
		system("cls");
		StudentSurvey.Process();
	}
	else if(choice == 'N')
	{
		cout << "\n\nGoodbye!";
	}	
}