#include "Survey.h"

int Survey::getSurveyNumb()
{
	return m_surveyNumber;
}


void Survey::setSurveyNumb(int survey)
{
	m_surveyNumber = survey;
}

void Survey::setSurvey(int surveyNumb, int randNumb, string names[], int ages[], string college[], string program[])
{
	setSurveyNumb(surveyNumb);
	m_students = new Student*[m_surveyNumber];
	for(int i = 0; i < getSurveyNumb(); i++)
	{
		
		randNumb = rand() % 2 + 1;
		if (randNumb == 1)
		{
			m_students[i] = new GamingStudent(names[(rand() % 10)], ages[(rand() % 5)], college[(rand() % 5)],
			                                program[(rand() % 3)], (rand() % 4 + 1), static_cast<GamingPlatform>(rand() % 4),
			                                (rand() % 30 + 5));
		}
		if(randNumb==2)
		{
			m_students[i] = new NonGamingStudent(names[(rand() % 10)], ages[(rand() % 5)], college[(rand() % 5)],
			                                   program[(rand() % 3 + 3)], rand() % 4 + 1, static_cast<StreamingService>(rand() % 5),
			                                   (rand() % 30 + 5));
		}		
	}	
}

void Survey::Process()
{
	for (int i = 0; i < getSurveyNumb(); i++)
	{
		if(m_students[i] == nullptr)
		{
			continue;
		}
		if(m_students[i]->GetStudentType() == NONGAMINGSTUDENT)
		{
			studentAge[0] += m_students[i]->getAge();
			studentHours[0] += m_students[i]->getHoursSpent();
			studentNumb[0]++;
			switch(m_students[i]->GetStreamingService())
			{
			case NETFLIX:
				favService[0]++;
				break;
			case DISNEY:
				favService[1]++;
				break;
			case YOUTUBE:
				favService[2]++;
				break;
			case TIKTOK:
				favService[3]++;
				break;
			case HULU:
				favService[4]++;
				break;
			}
			
		}
		if (m_students[i]->GetStudentType() == GAMINGSTUDENT)
		{
			studentAge[1] += m_students[i]->getAge();
			studentHours[1] += m_students[i]->getHoursSpent();
			studentNumb[1]++;
			switch(m_students[i]->GetGamingPlatform())
			{
			case XBOX:
				favPlatform[0]++;
				break;
			case PS4:
				favPlatform[1]++;
				break;
			case SWITCH:
				favPlatform[2]++;
				break;
			case PC:
				favPlatform[3]++;
				break;
			}
		}
	}
	temp = favService[0];
	for(int i = 1; i <= 4; i++)
	{
		if(temp < favService[i])
		{
			temp = favService[i];
			tempLoc = i;
		}
		if (temp == favService[i])
		{
			temp2 = favService[i];
			tempLoc2 = i;
		}
	}
	cout << "\nNON-GAMING STUDENTS\n"
	<< "_____________________________________________________________________\n\n";
	cout << "Number of Non Gaming Students: " << studentNumb[0] << "\nAverage Age: " << studentAge[0] / studentNumb[0];
	if(tempLoc == tempLoc2)
	{
		cout << "\nFavorite Streaming Service: " << m_streaming[tempLoc] << "\nAverage Hours Spent Streaming: " << studentHours[0] / studentNumb[0] << "\n";
	}
	else if(tempLoc != tempLoc2)
	{
		cout << "\nFavorite Streaming Services: " << m_streaming[tempLoc] << " & " << m_streaming[tempLoc2] << " - It's a tie!\nAverage Hours Spent Streaming Per Week: " << studentHours[0] / studentNumb[0] << "\n";
	}


	temp = favPlatform[0];
	tempLoc = 0;
	temp2 = 0;
	tempLoc2 = 0;
	for (int i = 1; i <= 3; i++)
	{
		if (temp < favPlatform[i])
		{
			temp = favPlatform[i];
			tempLoc = i;
		}
		if (temp == favPlatform[i])
		{
			temp2 = favPlatform[i];
			tempLoc2 = i;
		}
	}
	cout << "_____________________________________________________________________\n\n"
	<< "GAMING STUDENTS\n" << "_____________________________________________________________________\n\n";
	cout << "Number of Gaming Students: " << studentNumb[1] << "\nAverage Age: " << studentAge[1] / studentNumb[1];
	if (tempLoc == tempLoc2)
	{
		cout << "\nFavorite Gaming Platform: " << m_gaming[tempLoc] << "\nAverage Hours Spent Gaming: " << studentHours[1] / studentNumb[1] << "\n";
	}
	else if (tempLoc != tempLoc2)
	{
		cout << "\nFavorite Gaming Platform: " << m_gaming[tempLoc] << " & " << m_gaming[tempLoc2] << " - It's a tie!\nAverage Hours Spent Gaming Per Week: " << studentHours[1] / studentNumb[1] << "\n";
	}
	cout << "_____________________________________________________________________\n";
}



