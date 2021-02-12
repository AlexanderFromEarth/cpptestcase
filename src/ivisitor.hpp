#ifndef IVISITOR_HPP
#define IVISITOR_HPP

#include <string>

using namespace std;

class file;
class dir;
class root;

class ivisitor {
	public:
	       	virtual void visit_file(file*) = 0;
		virtual void visit_dir(dir*) = 0;
		virtual void visit_root(root*) = 0;
};

#endif
