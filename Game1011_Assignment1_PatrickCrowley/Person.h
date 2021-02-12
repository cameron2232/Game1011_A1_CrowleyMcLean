#pragma once
#include <iostream>
#include <stdlib.h>
using namespace std;
enum StudentType{NONGAMINGSTUDENT, GAMINGSTUDENT};
enum StreamingService{NETFLIX, DISNEY, YOUTUBE, TIKTOK, HULU};
enum GamingPlatform{XBOX, PS4, SWITCH, PC};
//Abstract base class
class Person
{
public:
	Person(){}
	Person(string a_name, int a_age);

	virtual ~Person() = default;
	//Getters
	string getName();
	int getAge();
	//Setters
	void setName(string name);
	void setAge(int age);
	//Pure Virtuals
	virtual void DisplayInfo() = 0;
	virtual float getHoursSpent() = 0;
	virtual StudentType GetStudentType() = 0;
	virtual StreamingService GetStreamingService() = 0;
	virtual GamingPlatform GetGamingPlatform() = 0;
protected:
	string m_name;
	int m_age;
	StudentType m_studenttype;
	StreamingService m_stream;
	GamingPlatform m_gamingplatform;
};

//Student class
class Student : public Person
{
public:
	Student(){}
	Student(string a_name, int a_age, string a_collegeName, string a_programName, int a_currentSemester) : Person(a_name, a_age)
	{
		setName(a_name);
		setAge(a_age);
		setCollegeName(a_collegeName);
		setProgramName(a_programName);
		setCurrentSemster(a_currentSemester);
	}

	~Student() = default;
	//Getters
	string getCollegeName() const;
	string getProgramName() const;
	int getCurrentSemster() const;
	//Setters
	void setCollegeName(string name);
	void setProgramName(string name);
	void setCurrentSemster(int semester);
	void setHoursSpent(float hours);
	void setStudentType(StudentType type);
	//Overrides
	void DisplayInfo() override
	{
		cout << "Name: " << getName() << " | Age: " << getAge() << " | College & Program: " << getCollegeName() << " | "
			<< getProgramName();
	}
	float getHoursSpent() override
	{
		return m_hoursSpent;
	}
	StudentType GetStudentType() override
	{
		return m_studenttype;
	}
	StreamingService GetStreamingService() override
	{
		return m_stream;
	}
	GamingPlatform GetGamingPlatform() override
	{
		return m_gamingplatform;
	}
protected:
	string m_collegeName;
	string m_programName;
	int m_currentSemester;
	float m_hoursSpent;
};

//NonGamingStudent class
class NonGamingStudent : public Student
{
public:
	NonGamingStudent(){}
	NonGamingStudent(string a_name, int a_age, string a_collegeName, string a_programName, int a_currentSemester, StreamingService a_streamingService, float a_hoursSpent)
	: Student(a_name, a_age, a_collegeName, a_programName, a_currentSemester)
	{
		setName(a_name);
		setAge(a_age);
		setCollegeName(a_collegeName);
		setProgramName(a_programName);
		setCurrentSemster(a_currentSemester);
		setStreamingService(a_streamingService);
		setHoursSpent(a_hoursSpent);
		setStudentType(NONGAMINGSTUDENT);
	}

	~NonGamingStudent() = default;

	void setStreamingService(StreamingService name);

	void DisplayInfo() override
	{
		cout << "Name: " << getName() << " | Age: " << getAge() << " | College & Program: " << getCollegeName() << " | "
			<< getProgramName() << "\nStreaming Platform: " << m_streaming[GetStreamingService()] << " | Time spent Streaming: " << getHoursSpent() << " hours\n\n";
	}

private:
	string m_streaming[5] = { "Netflix", "Disney+", "YouTube", "TikTok", "Hulu" };
};

//GamingStudent class
class GamingStudent : public Student
{
public:
	GamingStudent(){}
	GamingStudent(string a_name, int a_age, string a_collegeName, string a_programName, int a_currentSemester, GamingPlatform a_gamingPlatform, float a_hoursSpent)
		: Student(a_name, a_age, a_collegeName, a_programName, a_currentSemester)
	{
		setName(a_name);
		setAge(a_age);
		setCollegeName(a_collegeName);
		setProgramName(a_programName);
		setCurrentSemster(a_currentSemester);
		setGamingPlatform(a_gamingPlatform);
		setHoursSpent(a_hoursSpent);
		setStudentType(GAMINGSTUDENT);
	}

	~GamingStudent() = default;

	void setGamingPlatform(GamingPlatform name);

	void DisplayInfo() override
	{
		cout << "Name: " << getName() << " | Age: " << getAge() << " | College & Program: " << getCollegeName() << " | "
			<< getProgramName() << "\nGaming Platform: " << m_gaming[GetGamingPlatform()] << " | Time spent Gaming: " << getHoursSpent() << " hours\n\n";
	}

private:
	string m_gaming[4] = { "Xbox One X", "Playstation 4", "Nintendo Switch", "PC" };
};