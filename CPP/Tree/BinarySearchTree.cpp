#pragma once
#include<iostream>
#include<string>
#include<cassert>

template<class K,class V>
struct BSTNode {
	BSTNode* _left;
	BSTNode* _right;
	std::pair<K, V> _data;

	BSTNode(const std::pair<K, V>& data)
		:_left(nullptr)
		, _right(nullptr)
		, _data(data)
	{}

	V& value() {
		return _data.second;
	}

	K& key() {
		return _data.first;
	}
};


template<class K, class V>
class BSTree
{
	typedef BSTNode<K, V> Node;
public:
	bool Insert(const K& key, const V& value) {
		Node* NewNode = new Node(std::pair<K, V>(key, value));
		assert(NewNode);

		if(!_root){
			_root = NewNode;
			return true;
		}

		Node* cur = _root;
		while (cur) {
			if (key > cur->key()) {
				if (!cur->_right) {
					cur->_right = NewNode;
					return true;
				}
				cur = cur->_right;
			}
			else if (key < cur->key()) {
				if (!cur->_left) {
					cur->_left = NewNode;
					return true;
				}
				cur = cur->_left;
			}
			else {
				delete NewNode;
				return false;
			}
		}
	}
	
	Node* Find(const K& key) {
		Node* cur = _root;
		while (cur) {
			if (key < cur->key()) {
				cur = cur->_left;
			}
			else if (key > cur->key()) {
				cur = cur->_right;
			}
			else {
				return cur;
			}
		}
		return nullptr;
	}

	bool Erase(const K& key) {
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur) {
			if (key < cur->key()) {
				parent = cur;
				cur = cur->_left;
			}
			if (key > cur->key()) {
				parent = cur;
				cur = cur->_right;
			}
			else {
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}

					delete cur;

				} 
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}

					delete cur;
				}
				else
				{
					Node* pminRight = cur;
					Node* minRight = cur->_right;
					while (minRight->_left)
					{
						pminRight = minRight;
						minRight = minRight->_left;
					}

					cur->key() = minRight->key();

					if (pminRight->_left == minRight)
					{
						pminRight->_left = minRight->_right;
					}
					else
					{
						pminRight->_right = minRight->_right;
					}

					delete minRight;
				}
				return true;
			}
		}
		return false;
	}
	void InOrder() {
		_InOrder(_root);
		std::cout << std::endl;
	}
private:
	void _InOrder(Node* root) {
		if (!root)
			return;
		
		_InOrder(root->_left);
		std::cout << root->key() << ':' << root->value() << ' ';
		_InOrder(root->_right);
	}

	Node* _root = nullptr;
};

void test1()
{
	BSTree<std::string, std::string> dict;
	dict.Insert("insert", "插入");
	dict.Insert("erase", "删除");
	dict.Insert("left", "左边");
	dict.Insert("string", "字符串");

	std::string str;
	while (std::cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			std::cout << str << ":" << ret->value() << std::endl;
		}
		else
		{
			std::cout << "单词拼写错误" << std::endl;
		}
	}

}

void test2(){
	std::string strs[] = { "苹果", "西瓜", "苹果", "樱桃", "苹果", "樱桃", "苹果", "樱桃", "苹果" };
	// 统计水果出现的次
	BSTree<std::string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.Find(str);
		if (ret)
			(ret->value())++;
		else
			countTree.Insert(str, 1);
	}
	countTree.InOrder();

	countTree.Erase("苹果");
	countTree.InOrder();
}