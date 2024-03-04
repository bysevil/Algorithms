#pragma once
#include"string.h"

void test1() {
	bysevil::string str0;
	std::cout << str0 << std::endl;
	std::cout << str0.size() << ' ' << str0.capacity() << std::endl;

	bysevil::string str1 = "abc";
	std::cout << str1 << std::endl;
	std::cout << str1.size() << ' ' << str1.capacity() << std::endl;

	bysevil::string str2 = str1;
	std::cout << str2 << std::endl;
	std::cout << str2.size() << ' ' << str2.capacity() << std::endl;

	bysevil::string str3 = "12345";
	std::cout << str3 << std::endl;

	str1 = str3 = str2;
	std::cout << str1 << std::endl;
	std::cout << str1.size() << ' ' << str1.capacity() << std::endl;
	std::cout << str2 << std::endl;
	std::cout << str2.size() << ' ' << str2.capacity() << std::endl;
	std::cout << str3 << std::endl;
	std::cout << str3.size() << ' ' << str3.capacity() << std::endl;
}

void test2() {
	bysevil::string str1 = "12345";

	str1.clear();
	std::cout << str1 << std::endl;
	std::cout << str1.size() << ' ' << str1.capacity() << std::endl;

	str1.push_back('c');
	std::cout << str1 << std::endl;
	std::cout << str1.size() << ' ' << str1.capacity() << std::endl;

	bysevil::string str2;
	std::cin >> str1 >> str2;
	std::cout << str1 << std::endl;
	std::cout << str1.size() << ' ' << str1.capacity() << std::endl;
	std::cout << str2 << std::endl;
	std::cout << str2.size() << ' ' << str2.capacity() << std::endl;
}

void test3() {
	bysevil::string str1 = "12345";
	str1 += '6';
	std::cout << str1 << std::endl;
	std::cout << str1.size() << ' ' << str1.capacity() << std::endl;

	std::cout << str1.empty() << std::endl;
	str1.clear();
	std::cout << str1.empty() << std::endl;
	std::cout << str1 << std::endl;
	std::cout << str1.size() << ' ' << str1.capacity() << std::endl;
	std::cout << str1[0] << std::endl;

	str1.resize(12, 'a');
	std::cout << str1 << std::endl;
	std::cout << str1.size() << ' ' << str1.capacity() << std::endl;

	str1.resize(4, 'b');
	std::cout << str1 << std::endl;
	std::cout << str1.size() << ' ' << str1.capacity() << std::endl;

	str1.resize(20, 'c');
	std::cout << str1 << std::endl;
	std::cout << str1.size() << ' ' << str1.capacity() << std::endl;
}

void test4() {
	bysevil::string str1 = "12345";
	bysevil::string str2 = "678";
	str1.swap(str2);
	std::cout << str1 << ' ' << str1.size() << ' ' << str1.capacity() << std::endl;
	std::cout << str2 << ' ' << str2.size() << ' ' << str2.capacity() << std::endl;

	str1.insert(3,"21");
	std::cout << str1 << ' ' << str1.size() << ' ' << str1.capacity() << std::endl;
	str1.insert(0, '3');
	std::cout << str1 << ' ' << str1.size() << ' ' << str1.capacity() << std::endl;
}

void test5() {
	bysevil::string str1 = "1234567890";
	str1.erase(8, 5);
	std::cout << str1 << ' ' << str1.size() << ' ' << str1.capacity() << std::endl;
	str1.erase(2, 2);
	std::cout << str1 << ' ' << str1.size() << ' ' << str1.capacity() << std::endl;
	str1.erase(0, 1);
	std::cout << str1 << ' ' << str1.size() << ' ' << str1.capacity() << std::endl;
	str1.erase(0, 0);
	std::cout << str1 << ' ' << str1.size() << ' ' << str1.capacity() << std::endl;
	str1.erase(5, 1);
	std::cout << str1 << ' ' << str1.size() << ' ' << str1.capacity() << std::endl;
}

void test6() {
	bysevil::string str1 = "12345";
	bysevil::string str2 = "12346";
	std::cout << (str1 < str2) << std::endl;
	std::cout << (str1 == str2) << std::endl;
	std::cout << (str1 <= str2) << std::endl;
	std::cout << (str1 >= str2) << std::endl;
	str2 = "12345";
	std::cout << (str1 > str2) << std::endl;
	std::cout << (str1 == str2) << std::endl;
}

void test7() {
	bysevil::string str1 = "12345";
	std::cout << str1.find("12") << std::endl;
	std::cout << str1.find("34") << std::endl;
	std::cout << str1.find("29") << std::endl;
	std::cout << str1.find("3") << std::endl;
	std::cout << str1.find("10") << std::endl;
}