#pragma once
#include<deque>
#include<iostream>

namespace bysevil
{
    template<class T, class Con = std::deque<T>>
    class stack
    {
    public:
        stack(){}
        void push(const T& x) 
        {
            _c.push_back(x);
        }
        void pop() 
        {
            _c.pop_back();
        }
        T& top() 
        {
            return _c.back();
        }
        const T& top()const 
        {
            return _c.back();
        }
        size_t size()const 
        {
            return _c.size();
        }
        bool empty()const 
        {
            return _c.empty();
        }

        void test() {
            for (int i = 0; i < 10; i++) {
                push(i);
            }
            while (!empty()) {
                std::cout << "top:" << top() << " size:" << size() << std::endl;
                pop();
            }
        }
    private:
        Con _c;
    };

    template<class T, class Con = std::deque<T>>
    class queue
    {
    public:
        void push(const T& x) {
            _c.push_back(x);
        }
        void pop() {
            _c.pop_front();
        }
        T& back() {
            return _c.back();
        }
        const T& back()const {
            return _c.back();
        }
        T& front() {
            return _c.front();
        }
        const T& front()const {
            return _c.front();
        }
        size_t size()const {
            return _c.size();
        }
        bool empty()const {
            return _c.empty();
        }
        void test() {
            for (int i = 0; i < 10; i++) {
                push(i);
            }
            while (!empty()) {
                std::cout << "front:" << front() << " back:" << back() << " size:" << size() << std::endl;
                pop();
            }
        }
    private:
        Con _c;
    };
};