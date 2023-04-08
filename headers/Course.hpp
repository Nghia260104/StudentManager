#pragma once

#include <string>

#include "Semester.hpp"
#include "List.hpp"

namespace Backend
{
	class Student;
	
	class Course
	{
	public:
		Course();
		Course(const std::string &nID);

		const std::string& getID() const;
		const List<Student*>& getStudents() const;

		void setID(const std::string &nID);
		bool addStudent(Student *nStudent);

	private:
		std::string id_;
		Semester *semester_;
		List<Student*> students_;

		friend class Semester;
	};
}
