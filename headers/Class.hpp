#pragma once

#include <string>

namespace Backend
{
	class Student;
	
	class Class
	{
	public:
		Class();
		Class(const std::string &nID);

		const std::string& getID() const;
		const List<Student*>& getStudents() const;

		void setID(const std::string &nID);
		void addStudent(Student *nStudent);

	private:
		std::string id_;
		List<Student*> students_;
	};
}
