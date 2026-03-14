
// Module
// File: courseservice.cppm  Version: 1.0 License: AGPLv3
//Created: DuanEnlai    2026-03-14 13:23:21
// Description:课程类

export module domain.course;

import std;

using std::print;
using std::string;
using std::vector;

export class Course
{
private:
     string m_id;
     string m_name;
     string m_tid;
     int m_cap;
     int m_selected = 0;
public:
     Course(string id, string name, string tid, int cap);
     bool try_select();
     bool is_same_id(const string& cid) const;
     bool taught_by(const string& tid) const;
     void show() const;
};
Course::Course(string id, string name, string tid, int cap)
     : m_id(std::move(id)), m_name(std::move(name)),
       m_tid(std::move(tid)), m_cap(cap)
{
}
bool Course::try_select()
{
     if (m_selected < m_cap)
     {
         m_selected++;
         return true;
     }
     return false;
}
bool Course::is_same_id(const string& cid) const
{
     return m_id == cid;
}
bool Course::taught_by(const string& tid) const
{
     return m_tid == tid;
}
void Course::show() const
{
     print("{} {}\n", m_id, m_name);
}
