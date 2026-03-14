export module ui;
 import std;
 import service;
 using std::print;
 using std::cin;
 using std::string;
 export class UI {
 public:
     static void run() {
         Service srv;
         while (true) {
             // 打印菜单
             print("\n==== 选课系统 ====\n");
             print("1.选课  2.查成绩  3.录分  4.课程\n");
             print("5.秘书排课  6.添加用户  7.查看用户  0.退出\n");
             print("请输入选项：");

             int op;
             cin >> op;
             // 分支处理
             if (op == 1) {
                 // 选课
                 string sid, cid;
                 print("请输入学生ID和课程ID：");
                 cin >> sid >> cid;
                 print("{}\n", srv.select(sid, cid) ? "选课成功" : "选课失败");
             } else if (op == 2) {
                 // 查成绩
                 string sid;
                 print("请输入学生ID：");
                 cin >> sid;
                 srv.show_student_score(sid);
             } else if (op == 3) {
                 // 录分
                 string tid, cid, sid;
                 int sc;
                 print("请输入教师ID、课程ID、学生ID、成绩：");
                 cin >> tid >> cid >> sid >> sc;
                 print("{}\n", srv.input_score(tid, cid, sid, sc) ? "录分成功" : "录分失败");
             } else if (op == 4) {
                 // 查看课程
                 srv.show_all_courses();
             } else if (op == 5) {
                 // 秘书排课
                 string aid;
                 print("请输入秘书ID：");
                 cin >> aid;
                 if (!srv.is_secretary(aid)) {
                     print("权限不足\n");
                     continue;
                 }
                 string cid, name, tid;
                 int cap;
                 print("请输入课程ID、课程名、教师ID、容量：");
                 cin >> cid >> name >> tid >> cap;
                 print("{}\n", srv.add_course(cid, name, tid, cap) ? "排课成功" : "排课失败");
             } else if (op == 6) {
                 // 添加用户
                 string id, name, role;
                 print("请输入ID、姓名、角色(student/teacher/secretary)：");
                 cin >> id >> name >> role;
                 if (role == "student") {
                     srv.add_student(id, name);
                     print("添加学生成功\n");
                 } else if (role == "teacher") {
                     srv.add_teacher(id, name);
                     print("添加教师成功\n");
                 } else if (role == "secretary") {
                     srv.add_secretary(id, name);
                     print("添加秘书成功\n");
                 } else {
                     print("无效角色\n");
                 }
             } else if (op == 7) {
                 // 查看用户
                 print("请选择查看类型：1.学生 2.教师 3.秘书\n");
                 int type;
                 cin >> type;
                 if (type == 1) {
                     srv.show_all_students();
                 } else if (type == 2) {
                     srv.show_all_teachers();
                 } else if (type == 3) {
                     srv.show_all_secretaries();
                 } else {
                     print("无效类型\n");
                 }
             } else if (op == 0) {
                 // 退出
                 print("退出系统\n");
                 break;
             } else {
                 print("无效选项，请重新输入\n");
             }
         }
     }
 };
