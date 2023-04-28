#include <iostream>
#include <fstream>
#include <iomanip>
#include <string.h>
using namespace std;
struct Student {
	string No;
	string student_ID;
	string first_name;
	string last_name;
	string gender;
	string date_of_birth;
	string social_ID;
	double fMark;
	double midMark;
	double oMark;
	double toMark;
	Student* pNext;
};
struct Course
{
	string id;
	string course_name;
	string class_name;
	int number_credits;
	int number_students;
	string teacher_name;
	string day_of_week;
	string sessions;
	Student* student;
	Course* pNext;
};
struct Semester
{
	string semester_name;
	Course* course;
	Semester* pNext;
};
struct Class
{
	string class_name;
	Student* student;
	Class* pNext;
};
struct SchoolYear
{
	string year_name;
	Semester* semester;
	SchoolYear* pNext;
};
void load_student_InClass(Student*& pHead, string class_name);
void load_class(Class*& pHead);
void load_student_InCourse(Student*& pHead, string schoolYear_name, string semester_name, string course_name);
void load_course(Course*& pHead, string schoolYear_name, string semester_name);
void load_semester(Semester*& pHead, string schoolYear_name);
void load_schoolYear(SchoolYear*& pHead);
void load_input(SchoolYear*& pHead_schoolYear);
void import_score_of_course (Course *&z);
void import_scoreboard_toCourse(SchoolYear*& list_year, string year);
void view_scoreboard_toCourse(SchoolYear* &list_year,string year);
