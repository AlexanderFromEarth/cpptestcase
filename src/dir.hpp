#ifndef DIR_HPP
#define DIR_HPP

#include "inode.hpp"
#include <vector>
#include <string>

using namespace std;

class dir : public inode {
	protected:
	       	string m_name;
	       	vector<inode*> m_children;

	public:
	       	dir(string name, vector<inode*>);
		dir(const dir&);
		~dir();
		dir& operator=(const dir&);
		bool operator==(const inode&);
		vector<inode*>& get_children();
		string get_name() const;
		void accept_visitor(ivisitor*);
};

#endif
