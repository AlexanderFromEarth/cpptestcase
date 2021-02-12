#include "test.hpp"

void test_print() {
	auto f1 = new file("a", 12);
	auto f2 = new file("b", 10);
	vector<inode*> v;
	v.push_back(f1);
	v.push_back(f2);
	auto d1 = new dir("A", v);
	stringstream ss;
	stringstream test;
	test << "A" << endl << string(2, ' ') << "a" << endl << string(2, ' ') << "b" << endl;
	auto p = new printer(ss, 2);
	d1->accept_visitor(p);
	assert(ss.str() == test.str());
	assert(ss.str().length() == test.str().length());
}
