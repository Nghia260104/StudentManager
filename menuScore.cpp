#include "menuScore.h"
void load_student_InCourse(Student*& pHead, string schoolYear_name, string semester_name, string course_name)
{
	ifstream file;
	file.open(schoolYear_name + "\\" + semester_name + "\\" + course_name + ".txt");
	if (!file.is_open())
	{
		ifstream file;
		file.open(schoolYear_name + "\\" + semester_name + "\\" + course_name + ".txt",ios::app);
	}
	Student* pCur = nullptr;
	pHead = new Student();
	pCur = pHead;
	while (!file.eof())
	{
		string tmp;
		getline(file, pCur->student_ID , ',');
		getline(file, pCur->first_name, ',');
		getline(file, pCur->last_name,',');
		getline(file,tmp);
		if(!file.eof()){
		pCur->pNext = new Student();
		pCur = pCur->pNext;
		}
		else{
		pCur->pNext =nullptr;
		}
	}
	file.close();
}
void load_course(Course*& pHead, string schoolYear_name, string semester_name)
{
	ifstream file;
	file.open(schoolYear_name +"\\"+semester_name+"\\courseList.txt");
	pHead=new Course();
	Course* pCur = nullptr;
	pCur=pHead;
	while (!file.eof())
	{
		getline(file,pCur->id, ',');
		getline(file, pCur->course_name, ',');
		getline(file, pCur->class_name, ',');
		getline(file, pCur->teacher_name, ',');
		string get_numberCredit;
		getline(file, get_numberCredit, ',');
		pCur->number_credits = std::stoi(get_numberCredit);
		string get_numberStudent;
		getline(file, get_numberStudent, ',');
		pCur->number_students = std::stoi(get_numberStudent);
		getline(file, pCur->day_of_week, ',');
		getline(file, pCur->sessions, ',');
		getline(file, get_numberCredit);
		if(!file.eof()){
		pCur->pNext = new Course();
		pCur = pCur->pNext;
		}
		else{
		pCur->pNext =nullptr;
		}
	}
	file.close();
}
void load_semester(Semester*& pHead, string schoolYear_name){
	ifstream file;
	file.open(schoolYear_name + "\\semesterList.txt");
	if (!file.is_open())
	{
		cout << "Khong mo duoc file semesterList.txt";
		return;
	}
	Semester* pCur = nullptr;
	pHead=new Semester();
	pCur=pHead;
	string tmp;
	getline(file,pCur->semester_name,',');
	getline(file,tmp);
	if (!file.eof())
		{
		pCur->pNext = new Semester();
		pCur=pCur->pNext;
		}
		else
		{
		pCur->pNext=nullptr;
		}
	while (!file.eof())
	{
		getline(file,pCur->semester_name,',');
		getline(file,tmp);
		if (!file.eof())
		{
		pCur->pNext = new Semester();
		pCur=pCur->pNext;
		}
		else
		{
		pCur->pNext=nullptr;
		}
	}
	file.close();
}
void load_schoolYear(SchoolYear*& pHead)
{
	ifstream file;
	file.open("schoolYearList.txt");
	if (!file.is_open())
	{
		cout << "Khong mo duoc file schoolYearList.txt";
		return;
	};
	SchoolYear* pCur = nullptr;
	while (!file.eof())
	{
		if (pHead == nullptr)
		{
			pHead = new SchoolYear();
			pCur=pHead;
		}
		else
		{
			pCur = new SchoolYear();
		}
		file >> pCur->year_name;
		pCur->pNext =nullptr;
		pCur = pCur->pNext;
	}
	file.close();
}
void load_input(SchoolYear*& pHead_schoolYear){
	pHead_schoolYear = nullptr;
	load_schoolYear(pHead_schoolYear);
	SchoolYear* pCur = nullptr;
	pCur=pHead_schoolYear;
	while (pCur != nullptr)
	{
		Semester* pHead_Semester=nullptr;
		load_semester(pHead_Semester, pCur->year_name);
		pCur->semester=pHead_Semester;
		Semester* currSemester=pCur->semester;
		while(currSemester!=nullptr){
		Course* pHead_Course=nullptr;
		load_course(pHead_Course, pCur->year_name, currSemester->semester_name);
		currSemester->course=pHead_Course;
		Course* currCourse=currSemester->course;
		while(currCourse!=nullptr){
		Student* pHead_Student = nullptr;
		load_student_InCourse(pHead_Student, pCur->year_name, currSemester->semester_name, currCourse->id);
		currCourse->student=pHead_Student;
		currCourse=currCourse->pNext;
		}
		currSemester=currSemester->pNext;
		}
		pCur = pCur->pNext;
	}
}

int main(){
	SchoolYear * head;
	Class* clas;
	load_input(head);

	cout<<head->year_name;
	cout<<head->semester->semester_name;
	return 0;
}


