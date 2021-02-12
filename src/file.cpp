#include "file.hpp"

file::file(string name, int size) : m_name(name), m_size(size) {}

file::file(const file& f) : m_name(f.m_name), m_size(f.m_size) {}

file::~file() {}

file& file::operator=(const file& f) {
	if (this != &f) {
		this->m_name = f.m_name;
		this->m_size = f.m_size;
	}
	return *this;
}

bool file::operator==(const inode& node) {
	auto fd = dynamic_cast<const file*>(&node);
	if (fd) {
		return fd->m_name == this->m_name;
	}
	else {
		return false;
	}
}

std::string file::get_name() const { return this->m_name; }

int file::get_size() const { return this->m_size; }

void file::accept_visitor(ivisitor* visitor) { visitor->visit_file(this); }
