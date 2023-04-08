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

		const std::string& getID() const;
		const Class* getClass() const;
		const List<Course*>& getCourses() const;
		
		void setID(const std::string &nID);
		void setClass(Class *nClass);

	private:
		std::string id_;
		Class *class_;
		List<Course*> courses_;
		
		friend class Class;
		friend class Course;
	};
}
