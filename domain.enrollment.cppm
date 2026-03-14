export module domain.enrollment;

import std;

using std::print;
using std::string;
using std::vector;

export class Enrollment
{
private:
     string m_sid;
     string m_cid;
     int m_score = -1;
public:
     Enrollment(string sid, string cid);
     void set_score(int s);
     bool match(const string& sid, const string& cid) const;
     void show() const;
};
Enrollment::Enrollment(string sid, string cid)
     : m_sid(std::move(sid)), m_cid(std::move(cid))
{
}
void Enrollment::set_score(int s)
{
     if (s >= 0 && s <= 100)
         m_score = s;
}
bool Enrollment::match(const string& sid, const string& cid) const
{
     return m_sid == sid && m_cid == cid;
}
void Enrollment::show() const
{
     if (m_score == -1)
         print("score: unmarked\n");
     else
         print("score: {}\n", m_score);
}
