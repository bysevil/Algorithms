#include<iostream>

namespace bysevil
{
    template<class T>
    class vector
    {
    public:
        // Vector的迭代器是一个原生指针
        typedef T* iterator;

        typedef const T* const_iterator;

        iterator begin(){
            return _start;
        }

        iterator end(){
            return _finish;
        }

        const_iterator cbegin() {
            return _start;
        }

        const_iterator cend() const {
            return _finish;
        }

        // construct and destroy

        vector() {
            reserve(2);
        }

        vector(int n, const T& value = T()) {
            resize(n, value);
        }

        template<class InputIterator>
        vector(InputIterator first, InputIterator last) {
            size_t len = last - first;
            reserve(len);
            _finish = _start + len;
            while (len --> 0)
                *(_start + len) = *(first + len);
        }

        vector(const vector<T>& v) {
            *this = v;
        }

        vector<T>& operator = (const vector<T>& v) {
            reserve(v.capacity());
            size_t len = v.size();
            _finish = _start + len;
            while(len --> 0){
                *(_start + len) = v[len];
            }
            return *this;
        }

        ~vector() {
            delete[] _start;
            _start = _finish = _endOfStorage = nullptr;
        }

        // capacity

        size_t size() const {
            return _finish - _start;
        }

        size_t capacity() const {
            return _endOfStorage - _start;
        }

        void reserve(size_t n) {
            iterator tmp = new T[n];
            if (tmp == nullptr) {
                std::cout << "空间开辟失败，程序退出" << std::endl;
                exit(-1);
            }
            size_t len = size();
            _finish = tmp + len;
            while (len-- > 0)
                *(tmp + len) = *(_start + len);
            delete[] _start;
            _start = tmp;
            _endOfStorage = tmp + n;
        }

        void resize(size_t n, const T& value = T()) {
            size_t len = size();
            if (n < len) {
                _finish = _start + n;
                return;
            }
            if (n > capacity())
                reserve(n);
            while (n-- > len)
                *_finish++ = value;
        }



        ///////////////access///////////////////////////////

        T& operator[](size_t pos) {
            if (pos > size() || pos < 0) {
                std::cout << "访问索引超出界限，程序退出" << std::endl;
                exit(-1);
            }
            return *(_start + pos);
        }

        const T& operator[](size_t pos)const {
            if (pos > size() || pos < 0) {
                std::cout << "访问索引超出界限，程序退出" << std::endl;
                exit(-1);
            }
            return *(_start + pos);
        }



        ///////////////modify/////////////////////////////

        void push_back(const T& x) {
            insert(_finish, x);
        }

        void pop_back() {
            erase(_finish - 1);
        }

        //void swap(vector<T>& v);

        iterator insert(iterator pos, const T& x) {
            if (pos > _finish || pos < _start) {
                std::cout << "插入索引超限，程序退出" << std::endl;
                exit(-1);
            }
            if (_finish >= _endOfStorage) {
                size_t tmp = pos - _start;
                reserve(2 * capacity());
                pos = _start + tmp;
            }
            for (auto i = _finish; i > pos; i--)
                *(i + 1) = *i;
            *pos = x;
            _finish++;
            return pos+1;
        }

        iterator erase(iterator pos) {
            if (pos < _start || pos >= _finish) {
                std::cout << "删除索引超限，程序退出" << std::endl;
                exit(-1);
            }
            while (pos < _finish - 1) {
                *pos++ = *(pos + 1);
            }
            _finish--;
            return pos;
        }

    private:

        iterator _start = nullptr; // 指向数据块的开始

        iterator _finish = nullptr; // 指向有效数据的尾

        iterator _endOfStorage = nullptr; // 指向存储容量的尾

    };

    void test1() {
        //无参构造测试
        vector<int> vtr1;
        std::cout << vtr1[0] << "  "; //[]重载测试
        std::cout << vtr1.size() << ' ' << vtr1.capacity() << std::endl;//size()和capacity()测试
        //双参构造测试
        vector<int> vtr2(10, 6);
        for (auto e : vtr2) {//迭代器测试
            std::cout << e << "  ";
        }
        std::cout << vtr2.size() << ' ' << vtr2.capacity() << std::endl;
        //单参构造测试
        vector<int> vtr3(10);
        for (auto e : vtr3) {//迭代器测试
            std::cout << e << "  ";
        }
        std::cout << vtr3.size() << ' ' << vtr3.capacity() << std::endl;

        vtr1[-1];//超限测试
        vtr1[1];
    }

    void test2() {
        //string成员构造测试
        vector<std::string> vtr1(10,"abc");
        for (auto e : vtr1) {
            std::cout << e << "  ";
        }
        std::cout << vtr1.size() << ' ' << vtr1.capacity() << std::endl;

        //拷贝构造测试
        vector<std::string> vtr2 = vtr1;
        for (auto e : vtr2) {
            std::cout << e << "  ";
        }
        std::cout << vtr2.size() << ' ' << vtr2.capacity() << std::endl;
        //迭代器范围构造测试
        vector<std::string> vtr3(vtr2.begin(), vtr2.end());
        for (auto e : vtr3) {
            std::cout << e << "  ";
        }
        std::cout << vtr3.size() << ' ' << vtr3.capacity() << std::endl;

    }

    void test3() {
        vector<std::string> vtr1(1, "abc");
        //push_back测试
        vtr1.push_back("bcd");
        vtr1.push_back("cde");
        for (auto e : vtr1) {
            std::cout << e << "  ";
        }
        std::cout << vtr1.size() << ' ' << vtr1.capacity() << std::endl;
        //insert测试
        vtr1.insert(vtr1.begin() + 3, "sf");
        for (auto e : vtr1) {
            std::cout << e << "  ";
        }
        std::cout << vtr1.size() << ' ' << vtr1.capacity() << std::endl;
        vtr1.insert(vtr1.begin() + 5, "sf");//超限测试
        vtr1.insert(vtr1.begin() - 1, "sf");//超限测试
    }

    void test4() {
        vector<std::string> vtr1(1, "abc");
        vtr1.push_back("bcd");
        vtr1.pop_back();//pop_back测试
        for (auto e : vtr1) {
            std::cout << e << "  ";
        }
        std::cout << vtr1.size() << ' ' << vtr1.capacity() << std::endl;

        vtr1.erase(vtr1.begin());//erase测试
        for (auto e : vtr1) {
            std::cout << e << "  ";
        }
        std::cout << vtr1.size() << ' ' << vtr1.capacity() << std::endl;

        //vtr1.erase(vtr1.begin());//删除空vector测试

        vtr1.push_back("bcd");
        //vtr1.erase(vtr1.end());//超限测试
        vtr1.erase(vtr1.begin() - 1);
    }
}