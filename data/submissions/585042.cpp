#include <iostream>
#include <string>
using namespace std;
class Med
{
public:
	virtual void print() =0;
	virtual string id() =0;
protected:
	string title;
};
class Book : Med
{
public:
	Book(string a="", string t="", string p="", string i="") : author(a), pub(p), isbn(i)
	{ title = t; }
	void print()
	{
		cout << title << " , Author: " << author << ", Publisher: " << pub << ".\n";
	}
	string id()
	{
		return isbn;
	}
private:
	string author, pub, isbn;
};
class CD : Med
{
	string composer, make, number;
public:
	CD(string a, string b, string c, string d):composer(b),make(c),number(d){title=a;}
	void print()
	{
		cout << title << ", CD composer:" << composer << endl;
	}
	string id()
	{
		return make+number;
	}
};
class Mag : Med
{
	string issn, pub;
	int volume, number;
public:
	Mag(string a, string b, int c, int d):issn(b),volume(c),number(d){title=a;}
	void print()
	{
		cout << title << " , Magzine: Vol. " << volume << ", No. " << number << "\n";
	}
	string id()
	{
		return issn;
	}
};
int main()
{
	Book book("张三", "C++ 语言程序设计", "清华大学出版社", "0-000-00000-1");
	Mag mag("辨析C/C++编程模式", "0000-000X", 020, 01);
	CD cd("C++源代码", "清华大学计算中心", "ARCHIV", "000001");
	book.print();
	cout << "\tid: " << book.id() << endl;
	mag.print();
	cout << "\tid: " << mag.id() << endl;
	cd.print();
	cout << "\tid: " << cd.id() << endl;
	return 0;
}
