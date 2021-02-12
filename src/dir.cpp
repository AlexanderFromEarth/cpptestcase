#include "dir.hpp"

dir::dir(string name, vector<inode*> children) : m_name(name), m_children(children) {}

dir::dir(const dir& d) : m_name(d.m_name), m_children(d.m_children) {}

dir::~dir() {}

dir& dir::operator=(const dir& d) {
	if (this != &d) {
		this->m_name = d.m_name;
		this->m_children = d.m_children;
	}
	return *this;
}

bool dir::operator==(const inode& node) {
	auto fd = dynamic_cast<const dir*>(&node);
	if (fd) {
		return fd->m_name == this->m_name;
	}
	else {
		return false;
	}
}

std::string dir::get_name() const { return this->m_name; }

std::vector<inode*>& dir::get_children() { return this->m_children; }

void dir::accept_visitor(ivisitor* visitor) { visitor->visit_dir(this); }
