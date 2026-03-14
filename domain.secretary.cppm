
// Module
// File: courseservice.cppm  Version: 1.0 License: AGPLv3
//Created: DuanEnlai    2026-03-14 13:23:21
// Description:教学秘书类
//
export module domain.secretary;


import domain.user;
import std;

export class Secretary : public User
{
public:
    Secretary(std::string id, std::string name);
};

Secretary::Secretary(std::string id, std::string name)
    : User(id, name)
{
}
