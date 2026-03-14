// Module
// File: courseservice.cppm  Version: 1.0 License: AGPLv3
//Created: DuanEnlai    2026-03-14 13:23:21
// Description:教师类
//
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
