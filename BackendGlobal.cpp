#include <codecvt>

#include "BackendGlobal.hpp"

using namespace Backend;

const std::string Backend::DATA_PATH = "../Data";
const std::string Backend::SCHOOL_YEARS_PATH = Backend::DATA_PATH + "/School Years";
const std::string Backend::CLASSES_PATH = Backend::DATA_PATH + "/Classes";
const std::string Backend::ACCOUNTS_PATH = Backend::DATA_PATH + "/accounts.csv";

Account *Backend::activeUser = nullptr;
SchoolYear *Backend::activeSchoolYear = nullptr;
Semester *Backend::activeSemester = nullptr;
Course *Backend::activeCourse = nullptr;
Class *Backend::activeClass = nullptr;

List<SchoolYear> Backend::g_schoolYears;
List<Semester> Backend::g_semesters;
List<Course> Backend::g_courses;
List<Class> Backend::g_classes;
List<Student> Backend::g_students;
List<StaffMember> Backend::g_staffMembers;
Admin Backend::g_admin;
List<Account*> Backend::g_accounts;

bool Backend::loadData()
{
    bool isLoadable = 
		Account::loadAccounts() &&
		Class::loadClasses() &&
		SchoolYear::loadSchoolYears();

	g_schoolYears.sort(
		[](const SchoolYear &s1, const SchoolYear &s2) -> bool
		{
			return s1.getStartYear() < s2.getStartYear();
		});
	if (!g_schoolYears.empty())
		setActiveSchoolYear(&g_schoolYears.back());
	
	g_semesters.sort(
		[](const Semester &s1, const Semester &s2) -> bool
		{
			int startYear1 = s1.schoolYear()->getStartYear(),
				startYear2 = s2.schoolYear()->getStartYear(),
				id1 = s1.getID(), id2 = s2.getID();
			return startYear1 < startYear2 || (startYear1 == startYear2 && id1 < id2);
		});
	if (!g_semesters.empty())
		setActiveSemester(&g_semesters.back());
	
	g_classes.sort(
		[](const Class &c1, const Class &c2) -> bool
		{
			return c1.getID() < c2.getID();
		});
	for (Class &currClass: g_classes)
	{
		currClass.students().sort(
			[](const Student *s1, const Student *s2) -> bool
			{
				return std::stoi(s1->getID()) < std::stoi(s2->getID());
			});
	}

	return isLoadable;
}

void Backend::saveData()
{
	Account::saveAccounts();
	Class::saveClasses();
	SchoolYear::saveSchoolYears();
}

void Backend::setActiveUser(Account *account)
{
	activeUser = account;
}

void Backend::setActiveSchoolYear(SchoolYear *schoolYear)
{
	activeSchoolYear = schoolYear;
}

void Backend::setActiveSemester(Semester *semester)
{
	activeSemester = semester;
	setActiveSchoolYear(semester->schoolYear());
}

void Backend::setActiveCourse(Course *course)
{
	activeCourse = course;
	setActiveSemester(course->semester());
}

void Backend::setActiveClass(Class *currClass)
{
	activeClass = currClass;
}
