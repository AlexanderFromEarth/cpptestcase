#ifndef ROOT_HPP
#define ROOT_HPP

#include "inode.hpp"
#include <vector>

using namespace std;

class root : public inode {
	protected:
		vector<inode*> m_children;
	public:
		root(vector<inode*>);
		root(const root&);
		~root();
		root& operator=(const root&);
		bool operator==(const inode&);
		void accept_visitor(ivisitor*);
		vector<inode*>& get_children();
};

#endif
