
export module database;

import std;
#include "pqxx/pqxx"

namespace Database {

    constexpr const char* DB_CONN_STR = "dbname=testdb user=postgres password=your_password hostaddr=127.0.0.1 port=5432";

    export void create_teacher_table(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            txn.exec(R"(
                CREATE TABLE IF NOT EXISTS teachers (
                    id SERIAL PRIMARY KEY,
                    name VARCHAR(50) NOT NULL,
                    age INT NOT NULL,
                    subject VARCHAR(50) NOT NULL,
                    title VARCHAR(50) NOT NULL  -- 职称：教授/副教授/讲师
                )
            )");
            txn.commit();
            std::cout << "Teacher table created/verified successfully" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Create teacher table failed: " << e.what() << std::endl;
            throw;
        }
    }

    // 插入教师数据
    export void insert_teacher(pqxx::connection& conn, const std::string& name, int age, const std::string& subject, const std::string& title) {
        try {
            pqxx::work txn(conn);
            std::string query = txn.esc(R"(
                INSERT INTO teachers (name, age, subject, title) VALUES ($1, $2, $3, $4)
            )");
            txn.exec_params(query, name, age, subject, title);
            txn.commit();
            std::cout << "Inserted teacher: " << name << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Insert teacher failed: " << e.what() << std::endl;
            throw;
        }
    }

    // 查询所有教师
    export void query_all_teachers(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            pqxx::result res = txn.exec("SELECT id, name, age, subject, title FROM teachers ORDER BY id");
            txn.commit();

            std::cout << "\n=== 教师列表 ===" << std::endl;
            if (res.empty()) {
                std::cout << "暂无教师数据" << std::endl;
                return;
            }

            std::cout << std::left
                      << std::setw(6) << "ID"
                      << std::setw(15) << "姓名"
                      << std::setw(6) << "年龄"
                      << std::setw(20) << "授课科目"
                      << std::setw(15) << "职称" << std::endl;
            std::cout << "------------------------------------------------------------" << std::endl;

            for (const auto& row : res) {
                std::cout << std::left
                          << std::setw(6) << row["id"].as<int>()
                          << std::setw(15) << row["name"].as<std::string>()
                          << std::setw(6) << row["age"].as<int>()
                          << std::setw(20) << row["subject"].as<std::string>()
                          << std::setw(15) << row["title"].as<std::string>() << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Query teachers failed: " << e.what() << std::endl;
            throw;
        }
    }

    // 创建管理员表
    export void create_secretary_table(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            txn.exec(R"(
                CREATE TABLE IF NOT EXISTS secretaries (
                    id SERIAL PRIMARY KEY,
                    name VARCHAR(50) NOT NULL,
                    age INT NOT NULL,
                    department VARCHAR(50) NOT NULL,  -- 所属部门
                    username VARCHAR(50) UNIQUE NOT NULL,  -- 登录账号
                    password VARCHAR(50) NOT NULL  -- 登录密码（示例，实际需加密）
                )
            )");
            txn.commit();
            std::cout << "Secretary table created/verified successfully" << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Create secretary table failed: " << e.what() << std::endl;
            throw;
        }
    }

    // 插入管理员数据
    export void insert_secretary(pqxx::connection& conn, const std::string& name, int age, const std::string& dept, const std::string& username, const std::string& pwd) {
        try {
            pqxx::work txn(conn);
            std::string query = txn.esc(R"(
                INSERT INTO secretaries (name, age, department, username, password) VALUES ($1, $2, $3, $4, $5)
            )");
            txn.exec_params(query, name, age, dept, username, pwd);
            txn.commit();
            std::cout << "Inserted secretary: " << name << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Insert secretary failed: " << e.what() << std::endl;
            throw;
        }
    }

    // 查询所有管理员
    export void query_all_secretaries(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            pqxx::result res = txn.exec("SELECT id, name, age, department, username FROM secretaries ORDER BY id");
            txn.commit();

            std::cout << "\n=== 管理员列表 ===" << std::endl;
            if (res.empty()) {
                std::cout << "暂无管理员数据" << std::endl;
                return;
            }

            std::cout << std::left
                      << std::setw(6) << "ID"
                      << std::setw(15) << "姓名"
                      << std::setw(6) << "年龄"
                      << std::setw(20) << "所属部门"
                      << std::setw(15) << "登录账号" << std::endl;
            std::cout << "------------------------------------------------------------" << std::endl;

            for (const auto& row : res) {
                std::cout << std::left
                          << std::setw(6) << row["id"].as<int>()
                          << std::setw(15) << row["name"].as<std::string>()
                          << std::setw(6) << row["age"].as<int>()
                          << std::setw(20) << row["department"].as<std::string>()
                          << std::setw(15) << row["username"].as<std::string>() << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Query secretaries failed: " << e.what() << std::endl;
            throw;
        }
    }
}


