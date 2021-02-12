#ifndef PRINTER_HPP
#define PRINTER_HPP

#include "file.hpp"
#include "dir.hpp"
#include "root.hpp"
#include <iostream>

using namespace std;

class printer : public ivisitor {
	protected:
	       	int m_indent;
		int m_cur_indent;
		ostream& m_out;

	public:
		printer(ostream&, int);
	       	void visit_file(file*);
		void visit_dir(dir*);
		void visit_root(root*);
};

#endif
