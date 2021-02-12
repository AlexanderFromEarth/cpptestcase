#include "adder.hpp"
#include <typeinfo>
#include <algorithm>

adder::adder(inode* node) : m_node(node) {}

void adder::visit_root(root* r) {
	auto it = find_if(r->get_children().begin(),
		          r->get_children().end(),
			  [=](inode* el) {return *el == *(this->m_node); });
	if (it != r->get_children().end()) {
		auto srcd = dynamic_cast<dir*>(this->m_node);
		auto itd = dynamic_cast<dir*>(*it);
		if (srcd) {
			for (auto child : srcd->get_children()) {
				auto add = new adder(child);
				itd->accept_visitor(add);
				delete add;
			}
		}
	}
	else {
		r->get_children().push_back(this->m_node);
	}
}

void adder::visit_dir(dir* d) {
	auto it = find_if(d->get_children().begin(),
		          d->get_children().end(),
			  [=](inode* el) {return *el == *(this->m_node); });
	if (it != d->get_children().end()) {
		auto srcd = dynamic_cast<dir*>(this->m_node);
		auto itd = dynamic_cast<dir*>(*it);
		if (srcd) {
			for (auto child : srcd->get_children()) {
				auto add = new adder(child);
				itd->accept_visitor(add);
				delete add;
			}
		}
	}
	else {
		d->get_children().push_back(this->m_node);
	}
}

void adder::visit_file(file* f) {
	return;
}
