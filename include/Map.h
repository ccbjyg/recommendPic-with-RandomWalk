#ifndef Map_h
#define Map_h

class element;

class Map
{
private:
	element *own_pics;
	int pics_num;

	element *own_terms;
	int terms_num;

public:
	Map();

	void set_term_ID(int terms[], int set);
	void set_pic_ID(int pics[], int set);
	void set_line(int term_ID, int pic_ID);

	void run(int set, int N, double alpha, bool p);
	int query();

	void print(bool p);
	void reset();
	void replace();
	int finder(int set, bool p);

	~Map();
};

#endif