#include "StaffMember.hpp"
#include "Student.hpp"
#include "BackendGlobal.hpp"

using namespace Backend;

StaffMember::StaffMember()
{}

StaffMember::StaffMember(const std::string &nID)
	: id_(nID)
{}

bool StaffMember::addStudent(const std::string &studentID) const
{
	if (g_students.find_if(
			[](const Student &student) -> bool
			{
				return student.getID() == studentID;
			}))
	{
		return 0;
	}
	
	g_students.push_back(Student(studentID));
	return 1;
}
