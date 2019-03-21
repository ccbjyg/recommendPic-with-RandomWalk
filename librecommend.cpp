#include "fstream"
#include "librecommend.h"
#include "Map.h"

using namespace std;

int __stdcall count(char *fl)
{
	fstream cfl;
	int temp;
	int number = 0;
	cfl.open(fl, ios::in);
	while(!cfl.eof())
	{
		cfl >> temp;
		number++;
	}
	cfl.close();
	return number;
}

extern "C" int __stdcall queryId(int id, char* tfl, char* pfl, char* lines)
{
	fstream fl;
	int picID;

	int termsNumber = count(tfl);
	int picsNumber = count(pfl);
	int *terms = new int(termsNumber);
	int *pics = new int(picsNumber);

	//sipport
	int p;
	int a, b;

	Map map;

	//loading
	p = 0;
	fl.open(tfl, ios::in);
	while(!fl.eof())
	{
		fl >> terms[p];
		p++;
	}
	fl.close();
	p = 0;

	fl.open(pfl, ios::in);
	while (!fl.eof())
	{
		fl >> pics[p];
		p++;
	}
	fl.close();

	map.set_term_ID(terms, termsNumber);
	map.set_pic_ID(pics, picsNumber);

	fl.open(lines, ios::in);
	while (!fl.eof())
	{
		fl >> a >> b;
		map.set_line(a, b);
	}
	fl.close();

	map.run(id, 10, 0.8, false);
	picID = map.query();
	
	return picID;
}