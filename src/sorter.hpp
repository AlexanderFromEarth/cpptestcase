#ifndef SORTER_HPP
#define SORTER_HPP

#include "file.hpp"
#include "dir.hpp"
#include "root.hpp"

class sorter : public ivisitor {
	protected:
		bool (*m_comparator)(const inode*, const inode*);
	public:
		sorter(bool (*comparator)(const inode*, const inode*));
		void visit_dir(dir*);
		void visit_file(file*);
		void visit_root(root*);
};

#endif
