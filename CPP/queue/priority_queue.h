#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include<assert.h>
namespace bysevil
{
    template <class T, class Container = std::vector<T>, class Compare = std::less<T> >
    class priority_queue
    {
    public:
        priority_queue() {

        }

        template <class InputIterator>
        priority_queue(InputIterator first, InputIterator last) {
            while (first != last) {
                push(*first);
                ++first;
            }
        }

        bool empty() const {
            return c.empty();
        }

        size_t size() const {
            return c.size();
        }

        T top() const {
            assert(!c.empty());
            return c.front();
        }

        void push(const T& x) {
            c.push_back(x);
            std::push_heap(c.begin(), c.end(), comp);
        }

        void pop() {
            assert(!c.empty());
            std::pop_heap(c.begin(), c.end(), comp);
            c.pop_back();
        }

        int test() {
            std::vector<int> vt;
            priority_queue<int> obj1;
            std::cout << "rand value push 10 " << std::endl;
            std::srand(std::time(0));
            for (int i = 0; i < 10; i++) {
                obj1.push(std::rand());
                vt.push_back(std::rand());

            }
            priority_queue<int> obj2(vt.begin(),vt.end());
            while (!obj1.empty()) {
                std::cout << "top: " << obj1.top() << std::endl;
                std::cout << "pop" << std::endl;
                obj1.pop();
            }
            while (!obj2.empty()) {
                std::cout << "top: " << obj2.top() << std::endl;
                std::cout << "pop" << std::endl;
                obj2.pop();
            }
            obj2.pop();
            return 0;
        }
    private:
        Container c;
        Compare comp;
    };
};
