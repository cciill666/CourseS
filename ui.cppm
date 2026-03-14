// ui.cppm（完整修改版）
export module ui;

import std;
import database;

namespace UI {
    // 辅助函数：清空输入缓冲区
    void clear_input_buffer() {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // ========== 学生相关交互（原有，保持不变） ==========
    void input_new_student(pqxx::connection& conn) { /* 原有逻辑 */ }
    void query_all_students(pqxx::connection& conn) { /* 原有逻辑 */ }

    // ========== 新增：教师录入交互 ==========
    void input_new_teacher(pqxx::connection& conn) {
        std::string name, subject, title;
        int age = 0;

        std::cout << "\n=== 录入新教师 ===" << std::endl;

        std::cout << "请输入姓名: ";
        std::cin >> name;
        clear_input_buffer();

        while (true) {
            std::cout << "请输入年龄: ";
            if (std::cin >> age && age > 0) {
                clear_input_buffer();
                break;
            }
            std::cerr << "年龄输入无效，请输入正整数！" << std::endl;
            clear_input_buffer();
        }

        std::cout << "请输入授课科目: ";
        std::cin >> subject;
        clear_input_buffer();

        std::cout << "请输入职称(教授/副教授/讲师): ";
        std::cin >> title;
        clear_input_buffer();

        Database::insert_teacher(conn, name, age, subject, title);
    }

    // ========== 新增：管理员录入交互 ==========
    void input_new_secretary(pqxx::connection& conn) {
        std::string name, dept, username, pwd;
        int age = 0;

        std::cout << "\n=== 录入新管理员 ===" << std::endl;

        std::cout << "请输入姓名: ";
        std::cin >> name;
        clear_input_buffer();

        while (true) {
            std::cout << "请输入年龄: ";
            if (std::cin >> age && age > 0) {
                clear_input_buffer();
                break;
            }
            std::cerr << "年龄输入无效，请输入正整数！" << std::endl;
            clear_input_buffer();
        }

        std::cout << "请输入所属部门: ";
        std::cin >> dept;
        clear_input_buffer();

        std::cout << "请输入登录账号: ";
        std::cin >> username;
        clear_input_buffer();

        std::cout << "请输入登录密码: ";
        std::cin >> pwd;
        clear_input_buffer();

        Database::insert_secretary(conn, name, age, dept, username, pwd);
    }

    // ========== 主交互逻辑（扩展菜单） ==========
    export void run() {
        std::cout << "=== 学生-教师-管理员管理系统 ===" << std::endl;

        try {
            // 1. 连接数据库
            auto db_conn = Database::connect();

            // 2. 创建所有表（学生+教师+管理员）
            Database::create_student_table(*db_conn);
            Database::create_teacher_table(*db_conn);
            Database::create_secretary_table(*db_conn);

            // 3. 主交互循环
            int choice = 0;
            while (true) {
                std::cout << "\n========================" << std::endl;
                std::cout << "请选择操作：" << std::endl;
                std::cout << "【学生管理】" << std::endl;
                std::cout << "1. 录入新学生" << std::endl;
                std::cout << "2. 查看所有学生" << std::endl;
                std::cout << "【教师管理】" << std::endl;
                std::cout << "3. 录入新教师" << std::endl;
                std::cout << "4. 查看所有教师" << std::endl;
                std::cout << "【管理员管理】" << std::endl;
                std::cout << "5. 录入新管理员" << std::endl;
                std::cout << "6. 查看所有管理员" << std::endl;
                std::cout << "【其他】" << std::endl;
                std::cout << "7. 查看PostgreSQL版本" << std::endl;
                std::cout << "0. 退出系统" << std::endl;
                std::cout << "请输入选项(0-7): ";

                // 处理输入
                if (!(std::cin >> choice)) {
                    clear_input_buffer();
                    std::cerr << "输入无效，请输入数字！" << std::endl;
                    continue;
                }

                // 分支逻辑
                switch (choice) {
                // 学生
                case 1: input_new_student(*db_conn); break;
                case 2: Database::query_all_students(*db_conn); break;
                // 教师
                case 3: input_new_teacher(*db_conn); break;
                case 4: Database::query_all_teachers(*db_conn); break;
                // 管理员
                case 5: input_new_secretary(*db_conn); break;
                case 6: Database::query_all_secretaries(*db_conn); break;
                // 其他
                case 7: Database::query_example(*db_conn); break;
                case 0:
                    std::cout << "感谢使用，再见！" << std::endl;
                    return;
                default:
                    std::cerr << "选项无效，请输入0-7之间的数字！" << std::endl;
                    break;
                }
            }

        } catch (const std::exception& e) {
            std::cerr << "\n系统运行错误: " << e.what() << std::endl;
            std::cerr << "系统退出..." << std::endl;
        }
    }
}

