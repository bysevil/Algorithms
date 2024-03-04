#include<iostream>
#include<mysql/mysql.h>

int main(){
    //初始化Mysql对象
    MYSQL* mysql_obj = mysql_init(nullptr);
    if(nullptr == mysql_obj){
        std::cout << "初始化失败" << std::endl;
        return 1; 
    }

    std::cout << "初始化对象成功" << std::endl;
    //销毁mysql对象
    mysql_close(mysql_obj);

    return 0;
}