#pragma once

#include <string>

#include "Account.hpp"
#include "Course.hpp"
#include "Class.hpp"

namespace Backend
{
	class Student : public Account
	{
	public:
		Student();

		const std::string& getID() const;
		const Class* getClass() const;
		const List<Course*>* getCourses() const;
		
		void setID(const std::string &nID);
		void setClass(Class *nClass);
		void addCourse(Course *nCourse);

	private:
		std::string id_;
		Class *class_;
		List<Course*> courses_;
		
		friend class Class;
		friend class Course;
	};
}
