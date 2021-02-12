#include "test.hpp"

void test_parse() {
	stringstream ss1;
	stringstream ss2;
	stringstream ss3;
	ss1 << "TEST1\\TEST\\b 77" << endl;
	ss1 << "TEST1\\TEST\\C" << endl;
	auto f1 = new file("b", 77);
	auto d1 = new dir("C", vector<inode*>());
	auto d2 = new dir("TEST", vector<inode*>({f1, d1}));
	auto d3 = new dir("TEST1", vector<inode*>({d2}));
	auto r1 = new root(vector<inode*>({d3}));
	auto print1 = new printer(ss2, 2);
	auto print2 = new printer(ss3, 2);
	auto pars = new parser(ss1);
	r1->accept_visitor(print1);
	pars->parse()->accept_visitor(print2);
	assert(ss2.str() == ss3.str());
}

