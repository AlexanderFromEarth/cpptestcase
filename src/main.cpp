#include "parser.hpp"
#include "printer.hpp"
#include "sorter.hpp"
#include <iostream>
#include <fstream>
#include <typeinfo>

bool cmp(const inode* f, const inode* s) {
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

int main(int argc, char* argv[]) {
	if (argc == 1) {
		cout << "No input file" << endl;
		return 0;
	}
	ifstream in (argv[1]);
	auto prs = new parser(in);
	auto srt = new sorter(cmp);
	auto tree = prs->parse();
	tree->accept_visitor(srt);
	if (argc == 2) {
		auto prnt = new printer(cout, 1);
		tree->accept_visitor(prnt);
	}
	else if (argc == 3) {
		ofstream out(argv[2]);
		auto prnt = new printer(out, 1);
		tree->accept_visitor(prnt);
	}
	else {
		return 0;
	}
}
