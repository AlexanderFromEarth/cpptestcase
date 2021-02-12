#include "sorter.hpp"
#include <algorithm>

sorter::sorter(bool (*comparator)(const inode*, const inode*)) : m_comparator(comparator) {}

void sorter::visit_file(file* f) {
	return;
}

void sorter::visit_dir(dir* d) {
	for(auto node : d->get_children()) {
		node->accept_visitor(this);
	}
	sort(d->get_children().begin(), d->get_children().end(), this->m_comparator);
}

void sorter::visit_root(root* r) {
	for(auto node : r->get_children()) {
		node->accept_visitor(this);
	}
	sort(r->get_children().begin(), r->get_children().end(), this->m_comparator);
}
