#pragma once

#include "List.hpp"
#include "SchoolYear.hpp"
#include "Semester.hpp"
#include "Course.hpp"
#include "Class.hpp"
#include "Student.hpp"
#include "Staff.hpp"

namespace Backend
{
	extern Account *activeUser;
	extern Semester *activeSemester;
	
	extern List<SchoolYear> g_schoolYears;
	extern List<Semester> g_semesters;
	extern List<Course> g_courses;
	extern List<Class> g_classes;
	extern List<Student> g_students;
	extern List<Staff> g_staffMembers;
	extern List<Account*> g_accounts;
}
