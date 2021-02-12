#include "root.hpp"

root::root(vector<inode*> children) : m_children(children) {}

root::root(const root& r) : m_children(r.m_children) {}

root::~root() {}

root& root::operator=(const root& r) {
	if (this != &r) {
		this->m_children = r.m_children;
	}
	return *this;
}

bool root::operator==(const inode& node) { return this == &node; }

std::vector<inode*>& root::get_children() { return this->m_children; }

void root::accept_visitor(ivisitor* visitor) { visitor->visit_root(this); }
