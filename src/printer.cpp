#include "printer.hpp"

printer::printer(ostream& out, int indent) : m_out(out), m_indent(indent), m_cur_indent(0) {}

void printer::visit_file(file* f) {
	auto str = string(this->m_cur_indent, ' ');
	this->m_out << str << f->get_name() << std::endl;
}

void printer::visit_dir(dir* d) {
	auto str = this->m_cur_indent ? string(this->m_cur_indent, ' ') : "";
	this->m_out << str << d->get_name() << std::endl;
	this->m_cur_indent += this->m_indent;
	for(auto node : d->get_children()) {
		node->accept_visitor(this);
	}
	this->m_cur_indent -= this->m_indent;
}

void printer::visit_root(root* r) {
	for(auto node : r->get_children()) {
		node->accept_visitor(this);
	}
}
