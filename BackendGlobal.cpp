#include "BackendGlobal.hpp"

using namespace Backend;

Account *activeUser = nullptr;
Semester *activeSemester = nullptr;

List<SchoolYear> g_schoolYears;
List<Semester> g_semesters;
List<Course> g_courses;
List<Class> g_classes;
List<Student> g_students;
List<Staff> g_staffMembers;
List<Account*> g_accounts;
