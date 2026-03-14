export module domain.teacher;

import domain.user;
import std;

export class Teacher : public User
{
public:
    Teacher(std::string id, std::string name);
};

Teacher::Teacher(std::string id, std::string name)
    : User(id, name)
{
}
