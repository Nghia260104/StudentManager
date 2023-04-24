#pragma once

#include <string>

#include "Account.hpp"
#include "List.hpp"

namespace Backend
{
	class Class;
	class Course;
	
	class Student : public Account
	{
	public:
		Student();
		Student(const std::string &nID);
		
		static bool loadStudents();
		
		const std::string& getID() const;
		const Class* getClass() const;
		const List<Course*>& getCourses() const;
		
		void setID(const std::string &nID);

	private:
		static void readCSV(std::stringstream &streamLine, std::string &word);
		
		std::string id_;
		Class *class_;
		List<Course*> courses_;

		friend class Class;
		friend class Course;
	};
}
