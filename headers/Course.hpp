#pragma once

#include <string>

#include "List.hpp"

namespace Backend
{
	class Semester;
	class Student;
	
	class Course
	{
	public:
		Course();
		Course(const std::string &nID);

		const std::string& getID() const;
		int getMaxStudents() const;
		const List<Student*>& getStudents() const;

		void setID(const std::string &nID);
		void setMaxStudents(int nMaxStudents);
		
		bool addStudent(Student *nStudent);

	private:
		const int DEFAULT_MAX_STUDENTS = 50;
		
		std::string id_;
		int maxStudents_;
		Semester *semester_;
		List<Student*> students_;

		friend class Semester;
	};
}
