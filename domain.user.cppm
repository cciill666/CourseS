export module domain.user;

import std;

using std::print;
using std::string;
using std::vector;
export class User
{
protected:
     string m_id;
     string m_name;
public:
     User(string id, string name);
     bool is_same_id(const string& uid) const;
     void show() const;
};
User::User(string id, string name)
     : m_id(id), m_name(name)
{}
bool User::is_same_id(const string& uid) const
{
     return m_id == uid;
}
void User::show() const
{
     print("{} {}\n", m_id, m_name);
}
