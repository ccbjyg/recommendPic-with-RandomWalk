#include "Element.h"

using namespace std;

element::element() { out_line_num = 0; }

void element::set_ID(int set) { ID = set; }

void element::set_PR(double set_PR) { PR = set_PR; }

void element::set_tem_PR(double set_PR) { tem_PR = set_PR; }

void element::replace() { PR = tem_PR; tem_PR = 0; }

void element::add_out_line_num() { out_line_num++; }

void element::add_out_ID(int set) { out_ID.push_back(set); }

int element::get_ID() { return ID; }

int element::get_out_line_num() { return out_line_num; }

double element::get_PR() { return PR; }

double element::get_tem_PR() { return tem_PR; }

int element::get_out_ID(int set) { return out_ID[set]; }

element::~element() {}
