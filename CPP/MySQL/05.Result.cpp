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

    //设置编码
    mysql_set_character_set(mysql_obj,"utf8");

    //进行查询操作
    std::string ins = "select * from test";
    //执行指令
    int ret =  mysql_query(mysql_obj, ins.c_str());
    if(ret == 0) std::cout << "执行成功" << std::endl;
    else std::cout << "执行失败" << std::endl;

    //获取查询结果
    MYSQL_RES* res = mysql_store_result(mysql_obj);
    if(res == nullptr){
        std::cout << "获取查询结果失败" << std::endl;
        return 3;
    }
    //查看查询结果的行列数
    my_ulonglong rows = mysql_num_rows(res);
    my_ulonglong fields =  mysql_num_fields(res);
    std::cout << "查询结果有" << rows << "行" << fields << "列" << std::endl;

    //获取查询结果的列属性
    MYSQL_FIELD* field = mysql_fetch_field(res);

    //输出列属性
    for(int i = 0; i < fields; i++){
        //输出列名
        std::cout << field[j].name << ' ';
    }
    std::cout << std::endl;

    //遍历查询结果
    for(int i = 0; i < rows; i++){
        MYSQL_ROW row = mysql_fetch_row(res);
        for(int j = 0; j < fields; j++){
            std::cout << row[j] << ' ';
        }
        std::cout << std::endl;
    }
    //释放查询结果
    mysql_free_result(res);

    //销毁mysql对象
    mysql_close(mysql_obj);

    return 0;
}
