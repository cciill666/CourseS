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
