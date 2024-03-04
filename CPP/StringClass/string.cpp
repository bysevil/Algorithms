#include"string.h"

bysevil::string::string(const char* str) {
	int len = strlen(str) + 1;
	reserve(len);
	memcpy(_str, str, len);
	_size = len - 1;
}

bysevil::string::string(const string& s) {
	*this = s;
}

bysevil::string& bysevil::string::operator=(const string& s) {
	if (this != &s) {
		reserve(s._capacity);
		_size = s._size;
		memcpy(_str, s._str, _size + 1);
	}
	return *this;
}
bysevil::string::~string() {
	delete[] _str;
	_str = nullptr;
	_size = _capacity = 0;
}
bysevil::string::iterator bysevil::string::begin() const
{
	return _str;
}
bysevil::string::iterator bysevil::string::end() const
{
	return _str + _size;
}
void bysevil::string::push_back(char c)
{
	insert(_size, c);
}
bysevil::string& bysevil::string::operator+=(char c)
{
	this->push_back(c);
	return *this;
}
void bysevil::string::append(const char* str)
{
	insert(_size, str);
}
bysevil::string& bysevil::string::operator+=(const char* str)
{
	this->append(str);
	return *this;
}
size_t bysevil::string::size() const {
	return _size;
}
size_t bysevil::string::capacity() const {
	return _capacity;
}
bool bysevil::string::empty() const
{
	return !_size;
}
void bysevil::string::resize(size_t n, char c)
{
	if (n < _size) {
		_size = n;
		_str[_size] = '\0';
	}
	else {
		if (n + 1 > _capacity) {
			reserve(n + 1);
		}
		for (int i = _size; i < n; i++) {
			_str[i] = c;
		}
		_size = n;
		_str[_size] = '\0';
	}
}
void bysevil::string::clear()
{
	_str[0] = '\0';
	_size = 0;
}
void bysevil::string::swap(string& s)
{
	std::swap(_capacity, s._capacity);
	std::swap(_size, s._size);
	std::swap(_str,s._str);
}

const char* bysevil::string::c_str() const {
	return _str;
}

void bysevil::string::reserve(size_t n) {
	if (n > _capacity) {
		char* tmp = new char[n];
		if (tmp == nullptr) {
			std::cout << "空间申请失败，程序结束" << std::endl;
			exit(-1);
		}
		if (_size != 0) {
			memcpy(tmp, _str, _size + 1);
			delete[] _str;
		}
		_str = tmp;
		_capacity = n;
	}	
}

char& bysevil::string::operator[](size_t index)
{
	if (index > _size || index < 0) {
		std::cout << "不正确的下标值,程序结束" << std::endl;
		exit(-1);
	}
	return _str[index];
}

const char& bysevil::string::operator[](size_t index) const
{
	if (index > _size || index < 0) {
		std::cout << "不正确的下标值,程序结束" << std::endl;
		exit(-1);
	}
	return _str[index];
}

bool bysevil::string::operator<(const string& s)
{
	if (strcmp(_str, s._str) < 0) 
		return true;
	return false;
}

bool bysevil::string::operator<=(const string& s)
{
	if (strcmp(_str, s._str) <= 0)
		return true;
	return false;
}

bool bysevil::string::operator>(const string& s)
{
	if (strcmp(_str, s._str) > 0)
		return true;
	return false;
}

bool bysevil::string::operator>=(const string& s)
{
	if (strcmp(_str, s._str) >= 0)
		return true;
	return false;
}

bool bysevil::string::operator==(const string& s)
{
	if (strcmp(_str, s._str) == 0)
		return true;
	return false;
}

bool bysevil::string::operator!=(const string& s)
{
	if (strcmp(_str, s._str) != 0)
		return true;
	return false;
}

size_t bysevil::string::find(char c, size_t pos) const
{
	char str[] = { c,'\0' };
	return find(str, pos);
	
}

size_t bysevil::string::find(const char* s, size_t pos) const
{
	int len = strlen(s);
	
	for (int i = pos; i < _size; i++) {
		if (s[0] == _str[i]) {
			bool flag = true;
			for (int j = 0; j < len; j++) {
				if (_str[i + j] != s[j]) {
					flag = false;
					break;
				}
			}
			if(flag)
				return i;
		}
	}
	return -1;
}

bysevil::string& bysevil::string::insert(size_t pos, char c)
{
	char str[2] = { c , '\0'};
	insert(pos,str);
	return *this;
}

bysevil::string& bysevil::string::insert(size_t pos, const char* str)
{
	if (pos > _size) {
		std::cout << "插入位置的下标超出索引，程序结束" << std::endl;
		exit(-1);
	}
	size_t slen = strlen(str);
	if (_size + slen + 1 > _capacity)
		reserve(_size + slen + 1);
	size_t tlen = _size - pos;
	memcpy(_str + pos + slen, _str + pos, tlen);
	memcpy(_str + pos, str, slen);
	_size += slen;
}

bysevil::string& bysevil::string::erase(size_t pos, size_t len)
{
	if (len == 0) return *this;
	if (pos >= _size) {
		std::cout << "删除位置的下标超出索引，程序结束" << std::endl;
		exit(-1);
	}
	if (pos + len < _size) {
		for (int i = pos + len; i < _size; i++,pos++) {
			_str[pos] = _str[i];
		}
	}
	_size = pos;
	_str[_size] = '\0';
}

std::ostream& bysevil::operator<<(std::ostream& _cout, const bysevil::string& s)
{
	for (auto i : s) _cout << i;
	return _cout;
}

std::istream& bysevil::operator>>(std::istream& _cin, bysevil::string& s)
{
	s.clear();
	char ch = _cin.get();
	while (ch != ' ' && ch != '\n') {
		s.push_back(ch);
		ch = _cin.get();
	}
	return _cin;
}
