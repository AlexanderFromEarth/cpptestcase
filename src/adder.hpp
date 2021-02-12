#ifndef ADDER_HPP
#define ADDER_HPP

#include "file.hpp"
#include "dir.hpp"
#include "root.hpp"

class adder : public ivisitor {
	protected:
		inode* m_node;

	public:
		adder(inode*);
		void visit_file(file*);
		void visit_dir(dir*);
		void visit_root(root*);
};

#endif
