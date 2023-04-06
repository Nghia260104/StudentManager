#pragma once

#include <string>

#include "Student.hpp"

namespace Backend
{
	class Class
	{
	public:
		Class();

		const std::string& getID() const;
		const List<Student*>* getStudents() const;

		void setID(const std::string &nID);
		void addStudent(Student *nStudent);

	private:
		std::string id_;
		List<Student*> students_;
	};
}
