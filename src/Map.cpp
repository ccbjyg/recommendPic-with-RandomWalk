#include "iostream"

#include "Element.h"
#include "Map.h"

#include "QSort.h"

using namespace std;

Map::Map() {}

void Map::set_term_ID(int terms[], int set)
{
	own_terms = new element[set];
	terms_num = set;

	for (int cont = 0; cont < set; cont++)
	{
		own_terms[cont].set_ID(terms[cont]);
	}
}

void Map::set_pic_ID(int pics[], int set)
{
	own_pics = new element[set];
	pics_num = set;

	for (int cont = 0; cont < set; cont++)
	{
		own_pics[cont].set_ID(pics[cont]);
	}
}

void Map::set_line(int term_ID, int pic_ID)
{
	int cont_t = this->finder(term_ID, true);
	int cont_p = this->finder(pic_ID, false);

	if (cont_t&&cont_p)
	{
		cont_t -= 1;
		cont_p -= 1;

		//cout << "find!!term_ID:" << own_terms[cont_t].get_ID()<<"\n";
		//cout << "find!!pic_ID:" << own_pics[cont_p].get_ID() << "\n";

		own_terms[cont_t].add_out_line_num();
		own_terms[cont_t].add_out_ID(own_pics[cont_p].get_ID());

		own_pics[cont_p].add_out_line_num();
		own_pics[cont_p].add_out_ID(own_terms[cont_t].get_ID());
	}
}

//目前是依据随机游走进行计算、单线程，根据算法来说，理论上还有一个参数项----已游走的图。
void Map::run(int set, int N = 10, double alpha = 0.8, bool p = false)
{
	int time = 0;
	int cont_p, cont_t;
	int cID;
	double tem_PR = 0;

	if (p) { own_pics[this->finder(set, false) - 1].set_PR(1.0); }
	else { own_terms[this->finder(set, true) - 1].set_PR(1.0); }

	cout << "-------------" << time << "----------------\n";

	do
	{
		for (cont_p = 0; cont_p < pics_num; cont_p++)
		{
			for (cID = 0; cID < own_pics[cont_p].get_out_line_num(); cID++)
			{
				cont_t = this->finder(own_pics[cont_p].get_out_ID(cID), true) - 1;
				tem_PR += own_terms[cont_t].get_PR() / own_terms[cont_t].get_out_line_num();
			}
			tem_PR *= alpha;
			own_pics[cont_p].set_tem_PR(tem_PR);
			tem_PR = 0;
		}

		for (cont_t = 0; cont_t < terms_num; cont_t++)
		{
			for (cID = 0; cID < own_terms[cont_t].get_out_line_num(); cID++)
			{
				cont_p = this->finder(own_terms[cont_t].get_out_ID(cID), false) - 1;
				tem_PR += own_pics[cont_p].get_PR() / own_pics[cont_p].get_out_line_num();
			}
			tem_PR *= alpha;
			own_terms[cont_t].set_tem_PR(tem_PR);
			tem_PR = 0;
		}

		if (p) 
		{
			cont_p = this->finder(set, false) - 1;
			tem_PR = own_pics[cont_p].get_tem_PR() + (1 - alpha);
			own_pics[cont_p].set_tem_PR(tem_PR);
		}
		else
		{
			cont_t = this->finder(set, true) - 1;
			tem_PR = own_terms[cont_t].get_tem_PR() + (1 - alpha);
			own_terms[cont_t].set_tem_PR(tem_PR);
		}

		this->replace();

		tem_PR = 0;
		time++;
		this->print(false);
		cout <<"-------------"<< time << "------------\n";
	} while (time < N);
}

int Map::query()
{
	int picid;
	double picPR = 0;
	for (int c = 0; c < pics_num;c++)
	{
		if (own_pics[c].get_PR() >= picPR)
		{
			picPR = own_pics[c].get_PR();
			picid = own_pics[c].get_ID();
		}
	}
	return picid;
}

void Map::print(bool p = false)
{
	int cont;
	//double total = 0;

	for (cont = 0; cont < terms_num; cont++) { cout << "ID: " << own_terms[cont].get_ID() << " PR: " << own_terms[cont].get_PR() << "\n"; }
	for (cont = 0; cont < pics_num; cont++) { cout << "ID: " << own_pics[cont].get_ID() << " PR: " << own_pics[cont].get_PR() << "\n"; }

	/*
	if (p)
	{
		for (cont = 0; cont < terms_num; cont++) { cout << "ID: " << own_terms[cont].get_ID() << " PR: " << own_terms[cont].get_PR() << "\n"; }
	}
	else
	{
		for (cont = 0; cont < pics_num; cont++) { cout << "ID: " << own_pics[cont].get_ID() << " PR: " << own_pics[cont].get_PR() << "\n"; }
	}
	*/
}

void Map::reset()
{
	int cont;
	for (cont = 0; cont < terms_num; cont++) { own_terms[cont].set_PR(0); }
	for (cont = 0; cont < pics_num; cont++) { own_pics[cont].set_PR(0); }
}

void Map::replace()
{
	int cont;
	for (cont = 0; cont < terms_num; cont++) { own_terms[cont].replace(); }
	for (cont = 0; cont < pics_num; cont++) { own_pics[cont].replace(); }

}

int Map::finder(int set, bool p = false)
{
	int cont;
	if (p)
	{
		for (cont = 0; cont < terms_num; cont++)
		{
			if (own_terms[cont].get_ID() == set) { return cont + 1; }
		}
		return 0;
	}
	else
	{
		for (cont = 0; cont < pics_num; cont++)
		{
			if (own_pics[cont].get_ID() == set) { return cont + 1; }
		}
		return 0;
	}
}

Map::~Map() {}