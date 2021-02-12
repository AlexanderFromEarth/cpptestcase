#include "test.hpp"

bool comp(const inode* f, const inode* s) {
	auto fd = dynamic_cast<const dir*>(f);
	auto sd = dynamic_cast<const dir*>(s);

	if (fd && sd) {
		return fd->get_name() < sd->get_name();
	}
	else if (fd) {
		return true;
	}
	else if (sd) {
		return false;
	}
	else {
		auto ff = dynamic_cast<const file*>(f);
		auto sf = dynamic_cast<const file*>(s);

		if (ff->get_size() == sf->get_size()) {
			return ff->get_name() < sf->get_name();
		}
		else {
			return ff->get_size() > sf->get_size();
		}
	}
}

void test_sort() {
	auto f1 = new file("a", 10);
	auto f2 = new file("c", 11);
	auto f3 = new file("b", 11);
	auto f4 = new file("d", 10);
	auto d1 = new dir("C", vector<inode*>({f1, f2, f3}));
	auto d2 = new dir("B", vector<inode*>());
	auto r1 = new root(vector<inode*>({f4, d1, d2 }));
	auto d3 = new dir("B", vector<inode*>());
	auto d4 = new dir("C", vector<inode*>({f3, f2, f1}));
	auto r2 = new root(vector<inode*>({d3, d4, f4}));
	auto s = new sorter(comp);
	stringstream ss1;
	stringstream ss2;
	auto p1 = new printer(ss1, 2);
	auto p2 = new printer(ss2, 2);
	r1->accept_visitor(s);
	r1->accept_visitor(p1);
	r2->accept_visitor(p2);
	assert(ss1.str() == ss2.str());
}
