#ifndef VIEWSCORE_H_INCLUDED
#define VIEWSCORE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

struct Score {
	float total_mark = 0;
	float final_mark = 0;
	float mid_mark = 0;
	float other_mark = 0;
};
struct Student
{
	string student_ID = "x";
	string first_name = "x";
	string last_name = "x";
	string gender = "x";
	string date_of_birth = "x";
	string social_ID = "x";

	Score score;
	Student* pNext;
};
struct Course
{
	string id = "x";
	string course_name = "x";
	string class_name = "x";
	string number_credits = "x";
	string number_students = "x";
	string teacher_name = "x";
	string day_of_week = "x";
	string sessions = "x";

	float final = 0.5;
	float midterm = 0.4;
	float other = 0.1;

	Student* student;
	Course* pNext;
};

#endif // VIEWSCORE_H_INCLUDED
