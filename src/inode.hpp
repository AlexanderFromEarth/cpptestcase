#ifndef INODE_HPP
#define INODE_HPP

#include "ivisitor.hpp"

using namespace std;

class inode {
	public:
		virtual bool operator==(const inode&) = 0;
	       	virtual void accept_visitor(ivisitor*) = 0;
		virtual ~inode() {}
};

#endif
