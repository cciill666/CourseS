
// Module
// File: courseservice.cppm  Version: 1.0 License: AGPLv3
//Created: DuanEnlai    2026-03-14 13:23:21
// Description:业务逻辑，

export module service;

import std;
import repo;
import domain.user;
import domain.student;
import domain.teacher;
import domain.secretary;
import domain.course;
import domain.enrollment;

using std::print;
using std::string;
using std::vector;

export class Service
{
private:
     Repository m_repo;
public:
    // === 新增：用户管理 ===
     void add_student(string id, string name);
     void add_teacher(string id, string name);
     void add_secretary(string id, string name);
     void show_all_students();
     void show_all_teachers();
     void show_all_secretaries();
     // 原有
     bool select(const string& sid, const string& cid);
     bool input_score(const string& tid, const string& cid, const string& sid, int score);
     void show_all_courses();
     void show_student_score(const string& sid);
     bool add_course(const string& cid, const string& name, const string& tid, int cap);
     bool del_course(const string& cid);
     bool is_teacher(const string& id);
     bool is_secretary(const string& id);
};



void Service::add_student(string id, string name)
{
     m_repo.add_student(Student(id, name));
}
void Service::add_teacher(string id, string name)
{
     m_repo.add_teacher(Teacher(id, name));
}
void Service::add_secretary(string id, string name)
{
     m_repo.add_secretary(Secretary(id, name));
}
void Service::show_all_students()
{
     m_repo.show_all_students();
}
void Service::show_all_teachers()
{
     m_repo.show_all_teachers();
}
void Service::show_all_secretaries()
{
     m_repo.show_all_secretaries();
}

bool Service::select(const string& sid, const string& cid)
{
     auto s = m_repo.find_student(sid);
     auto c = m_repo.find_course(cid);
     if (!s || !c) return false;
     for (auto& e : m_repo.all_enrolls())
         if (e.match(sid, cid)) return false;
     if (!c->try_select()) return false;
     m_repo.add_enroll(Enrollment(sid, cid));
     return true;
}
bool Service::input_score(const string& tid, const string& cid, const string& sid, int score)
{
     auto c = m_repo.find_course(cid);
     if (!c || !c->taught_by(tid)) return false;
     for (auto& e : m_repo.all_enrolls())
     {
         if (e.match(sid, cid))
         {
             e.set_score(score);
             return true;
         }
     }
     return false;
}
void Service::show_all_courses()
{
     for (auto& c : m_repo.all_courses())
         c.show();
}
void Service::show_student_score(const string& sid)
{
     for (auto& e : m_repo.all_enrolls())
     {
         if (e.match(sid, ""))
         {
             e.show();
         }
     }
}
bool Service::add_course(const string& cid, const string& name, const string& tid, int cap)
{
     m_repo.add_course(Course(cid, name, tid, cap));
     return true;
}
bool Service::del_course(const string& cid)
{
     return m_repo.remove_course(cid);
}
bool Service::is_teacher(const string& id)
{
     return m_repo.find_teacher(id) != nullptr;
}
bool Service::is_secretary(const string& id)
{
     return m_repo.find_secretary(id) != nullptr;
}
