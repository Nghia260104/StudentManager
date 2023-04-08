#include "BackendGlobal.hpp"

using namespace Backend;

Account *Backend::activeUser = nullptr;
Semester *Backend::activeSemester = nullptr;

List<SchoolYear> Backend::g_schoolYears;
List<Semester> Backend::g_semesters;
List<Course> Backend::g_courses;
List<Class> Backend::g_classes;
List<Student> Backend::g_students;
List<StaffMember> Backend::g_staffMembers;
List<Account*> Backend::g_accounts;
