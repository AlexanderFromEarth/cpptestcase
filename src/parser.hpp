#ifndef PARSER_HPP
#define PARSER_HPP

#include "file.hpp"
#include "dir.hpp"
#include "root.hpp"
#include <iostream>

using namespace std;

class parser {
	protected:
		istream& m_in;
	public:
		parser(istream&);
		inode* parse();
};

#endif
