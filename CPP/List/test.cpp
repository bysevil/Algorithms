#include"list.h"

int main() {
	std::cout << bysevil::ListNode<int>(1)._val << std::endl;
	
	bysevil::list<int> ls1(7,7);
	for (auto& e : ls1) {
		std::cout << e << std::endl;
	}
	bysevil::list<int> ls2 = ls1;
	for (auto& e : ls2) {
		std::cout << e << std::endl;
	}
	//bysevil::ListIterator<int, int&, int*> li = ls1.cbegin();
	bysevil::list<int> ls3(ls1.begin(), ls1.end());
	for (auto& e : ls3) {
		std::cout << e << std::endl;
	}
	ls3 = ls2;
	for (auto& e : ls3) {
		std::cout << e << std::endl;
	}
	
	return 0;
}