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
