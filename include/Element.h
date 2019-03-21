#include "vector"

#ifndef Element_h
#define Element_h

class element
{
private:
	int ID;
	int out_line_num = 0;
	double PR = 0;
	double tem_PR = 0;
	std::vector<int>out_ID;

public:
	element();

	void set_ID(int set);
	void set_PR(double set_PR);
	void set_tem_PR(double set_PR);

	void replace();
	void add_out_line_num();
	void add_out_ID(int set);

	int get_ID();
	int get_out_line_num();
	double get_PR();
	double get_tem_PR();
	int get_out_ID(int set);

	~element();
};

#endif