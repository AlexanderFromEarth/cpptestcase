#include "parser.hpp"
#include "adder.hpp"
#include <sstream>
#include <exception>

parser::parser(istream& in) : m_in(in) {}

vector<string> split(const string& str, char d=' ') {
	string tmp;
	vector<string> result;
	stringstream ss(str);
	while(getline(ss, tmp, d)) {
		result.push_back(tmp);
	}
	return result;
}

inode* parse_elem(string s) {
	auto fnd = s.find("\\");
	if (fnd != string::npos) {
		return new dir(
			s.substr(0, fnd),
			vector<inode*>({parse_elem(s.substr(fnd + 1))})
			);
	}
	try {
		auto spl = split(s);
		auto size = stoi(spl.back());
		spl.pop_back();
		stringstream ss;
		for (auto str : spl) {
			ss << str << " ";
		}
		auto name = ss.str();
		name.erase(name.length() - 1);
		return new file(name, size);
	}
	catch (...) {
		return new dir(
			s,
			vector<inode*>()
			);
	}
}

inode* parser::parse() {
	auto r = new root(vector<inode*>());
	while(this->m_in) {
		string s;
		getline(this->m_in, s);
		if (s != "") {
			auto add = new adder(parse_elem(s));
			r->accept_visitor(add);
			delete add;
		}
	}
	return r;
}


