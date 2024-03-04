#include<iostream>
#include<mysql/mysql.h>

int main(){
    //显示mysql版本号
	std::cout << mysql_get_client_info() << std::endl;
	return 0;
}
