export module repo;
 import std;
 import domain.user;
 import domain.student;
 import domain.teacher;
 import domain.secretary;
 import domain.course;
 import domain.enrollment;
 using std::print;
 using std::string;
 using std::vector;
 export class Repository
 {
 private:
     vector<Student>   m_students;
     vector<Teacher>   m_teachers;
     vector<Secretary> m_secretaries;
     vector<Course>    m_courses;
     vector<Enrollment> m_enrolls;
 public:
     Repository();
     // 学生
     void add_student(Student s);
     void show_all_students() const;
     // 教师
     void add_teacher(Teacher t);
     void show_all_teachers() const;
     // 秘书
     void add_secretary(Secretary a);
     void show_all_secretaries() const;
     // 原有
     Student*   find_student(const string& id);
     Teacher*   find_teacher(const string& id);
     Secretary* find_secretary(const string& id);
     Course*    find_course(const string& id);
     void add_course(Course c);
     void add_enroll(Enrollment e);
     bool remove_course(const string& cid);
     vector<Course>&    all_courses();
     vector<Enrollment>& all_enrolls();
 };
 Repository::Repository()
 {
     // 初始数据不变
     m_students.emplace_back("S001", "Zhang");
     m_teachers.emplace_back("T001", "Wang");
     m_secretaries.emplace_back("A001", "Li");
     m_courses.emplace_back("C001", "C++", "T001", 50);
 }
 // === 新增：添加用户 ===
 void Repository::add_student(Student s)
 {
     m_students.push_back(std::move(s));
 }
 void Repository::add_teacher(Teacher t)
 {
     m_teachers.push_back(std::move(t));
 }
 void Repository::add_secretary(Secretary a)
 {
     m_secretaries.push_back(std::move(a));
 }
 // === 新增：查看所有用户 ===
 void Repository::show_all_students() const
 {
     print("--- all students ---\n");
     for (auto& s : m_students)
         s.show();
 }
 void Repository::show_all_teachers() const
 {
     print("--- all teachers ---\n");
     for (auto& t : m_teachers)
         t.show();
 }
 void Repository::show_all_secretaries() const
 {
     print("--- all secretaries ---\n");
     for (auto& a : m_secretaries)
         a.show();
 }
 // 以下原有函数不变
 Student* Repository::find_student(const string& id)
 {
     for (auto& s : m_students)
         if (s.is_same_id(id)) return &s;
     return nullptr;
 }
 Teacher* Repository::find_teacher(const string& id)
 {
     for (auto& t : m_teachers)
         if (t.is_same_id(id)) return &t;
     return nullptr;
 }
 Secretary* Repository::find_secretary(const string& id)
 {
     for (auto& a : m_secretaries)
         if (a.is_same_id(id)) return &a;
     return nullptr;
 }
 Course* Repository::find_course(const string& id)
 {
     for (auto& c : m_courses)
         if (c.is_same_id(id)) return &c;
     return nullptr;
 }
 void Repository::add_course(Course c)
 {
     m_courses.push_back(std::move(c));
 }
 void Repository::add_enroll(Enrollment e)
 {
     m_enrolls.push_back(std::move(e));
 }
 bool Repository::remove_course(const string& cid)
 {
     for (auto it = m_courses.begin(); it != m_courses.end(); ++it)
     {
         if (it->is_same_id(cid))
         {
             m_courses.erase(it);
             return true;
         }
     }
     return false;
 }
 vector<Course>& Repository::all_courses()
 {
     return m_courses;
 }
 vector<Enrollment>& Repository::all_enrolls()
 {
     return m_enrolls;
 }
