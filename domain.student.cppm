
// Module
// File: courseservice.cppm  Version: 1.0 License: AGPLv3
//Created: DuanEnlai    2026-03-14 13:23:21
// Description:学生类
//
export module domain.student;

import domain.user;
import std;

export class Student : public User
{
public:
    Student(std::string id, std::string name);
};

Student::Student(std::string id, std::string name)
    : User(id, name)
{
}
