#ifndef FILE_HPP
#define FILE_HPP

#include "inode.hpp"
#include <string>

using namespace std;

class file : public inode {
	protected:
	       	string m_name;
	       	int m_size;

	public:
	       	file(string, int);
		file(const file&);
		~file();
		file& operator=(const file&);
		bool operator==(const inode&);
		int get_size() const;
		string get_name() const;
		void accept_visitor(ivisitor*);
};

#endif
