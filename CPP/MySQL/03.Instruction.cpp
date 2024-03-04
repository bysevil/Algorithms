#include<iostream>
#include<mysql/mysql.h>

// 服务所在IP地址
const std::string host = "127.0.0.1";
// 服务所在端口
const unsigned int port = 3306;
// 登录用户名
const std::string user = "user";
// 用户密码
const std::string passwd = "password";
// 用户访问的数据库
const std::string db = "database";


int main(){
     //初始化Mysql对象
    MYSQL* mysql_obj = mysql_init(nullptr);
    //验证初始化是否成功
    if(nullptr == mysql_obj){
        std::cout << "初始化失败" << std::endl;
        return 1;
    }
    std::cout << "初始化对象成功" << std::endl;

    // 连接到数据库
    if(mysql_real_connect(mysql_obj, host.c_str(), user.c_str(), passwd.c_str(), db.c_str(), port, nullptr, 0) == nullptr){
        std::cout << "连接数据库失败" << std::endl;
        return 2;
    }
    std::cout << "连接数据库成功" << std::endl;

    // 要执行的指令
    std::string ins = "";
    //执行指令
    int ret =  mysql_query(mysql_obj, ins.c_str());
    if(ret == 0) std::cout << "执行成功" << std::endl;
    else std::cout << "执行失败" << std::endl;

    //销毁mysql对象
    mysql_close(mysql_obj);

    return 0;
}