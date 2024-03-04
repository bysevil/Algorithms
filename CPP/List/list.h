#pragma once

#include<iostream>
using namespace std;

namespace bysevil
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T(), ListNode<T>* pPrev = nullptr, ListNode<T>* pNext = nullptr)
            :_val(val)
            , _pPrev(pPrev)
            , _pNext(pNext)
        {}
        ListNode<T>* _pPrev;
        ListNode<T>* _pNext;
        T _val;
    };


    //List的迭代器类
    template<class T, class Ref, class Ptr>
    struct ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;

        ListIterator(PNode pNode = nullptr)
            :_pNode(pNode)
        {}
        ListIterator(const Self& l) {
            _pNode = l._pNode;
        }
        T& operator*() {
            return _pNode->_val;
        }
        T* operator->() {
            return &(_pNode->_val);
        }
        Self& operator++() {
            _pNode = _pNode->_pNext;
            return *this;
        }
        Self operator++(int) {
            Self tmp(*this);
            _pNode = _pNode->_pNext;
            return tmp;
        }
        Self& operator--() {
            _pNode = _pNode->_pPrev;
            return *this;
        }
        Self& operator--(int) {
            Self tmp(*this);
            _pNode = _pNode->_pPrev;
            return tmp;
        }
        bool operator!=(const Self& l) {
            return this->_pNode != l._pNode;
        }
        bool operator==(const Self& l) {
            return this->_pNode == l._pNode;
        }
        PNode _pNode;
    };


    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T*> const_iterator;
    public:
        ///////////////////////////////////////////////////////////////
        // List的构造
        list() {
            CreateHead();
        }
        list(int n, const T& value = T()) {
            CreateHead();
            if (n > 0) {
                while (n--) {
                    push_back(value);
                }
            }
        }
        template <class Iterator>
        list(Iterator first, Iterator last) {
            CreateHead();
            while (first != last) {
                push_back(*first);
                first++;
            }
        }

        list(const list<T>& l) {
            CreateHead();
            list<T> tmp(l.begin(), l.end());
            swap(tmp);
        }
        list<T>& operator=(list<T>& l) {
            swap(l);
            return *this;
        }
        ~list() {
            clear();
        };


        ///////////////////////////////////////////////////////////////
        // List Iterator
        iterator begin() {
            return iterator(_pHead->_pNext);
        }
        iterator end() {
            return iterator(_pHead);
        }
        const_iterator begin() const{
            return const_iterator(_pHead->_pNext);
        }
        const_iterator end() const{
            return const_iterator(_pHead);
        }


        ///////////////////////////////////////////////////////////////
        // List Capacity
        size_t size()const {
            return _size;
        };
        bool empty()const {
            return size();
        };


        ////////////////////////////////////////////////////////////
        // List Access
        T& front() {
            return _pHead->_pNext->_val;
        }
        const T& front()const {
            return _pHead->_pNext->_val;
        }
        T& back() {
            return _pHead->_pPrev->_val;
        }
        const T& back()const {
            return _pHead->_pPrev->_val;
        }


        ////////////////////////////////////////////////////////////
        // List Modify
        void push_back(const T& val) { 
            insert(end(), val); 
        }
        void pop_back() { 
            erase(--end()); 
        }
        void push_front(const T& val) { 
            insert(begin(), val); 
        }
        void pop_front() { 
            erase(begin()); 
        }
        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val) {
            _size++;
            PNode newNode = new Node(val);
            newNode->_pPrev = pos._pNode->_pPrev;
            newNode->_pNext = pos._pNode;
            pos._pNode->_pPrev->_pNext = newNode;
            pos._pNode->_pPrev = newNode;
            return newNode;
        }
        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos) {
            _size--;
            pos._pNode->_pPrev->_pNext = pos._pNode->_pNext;
            pos._pNode->_pNext->_pPrev = pos._pNode->_pPrev;
            iterator del = pos;
            pos++;
            free(pos._pNode);
            return pos;
        }
        void clear() {
            while (!empty()) {
                pop_back();
            }
            _pHead = nullptr;
        }
        void swap(list<T>& l) {
            PNode tmp = this->_pHead;
            this->_pHead = l._pHead;
            l._pHead = tmp;
        }
    private:
        void CreateHead() {
            _size = 0;
            _pHead = new Node();
            _pHead->_pNext = _pHead;
            _pHead->_pPrev = _pHead;
        };
        PNode _pHead;
        size_t _size;
    };
};
