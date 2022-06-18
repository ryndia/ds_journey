#include <iostream>

using namespace std;

class rectangle
{
private:
	int width;
	int height;


public:
	rectangle()
	{
		width = 0;
		height = 0;
	}
	rectangle(int x,int y)
	{
		width = x;
		height = y;
	}

	void setheight(int h)
	{
		height = h;
	}
	void setwidth(int w)
	{
		width = w;
	}

	int getheight()
	{
		return height;
	}

	int getwidth()
	{
		return width;
	}

	int getarea()
	{
		return width*height;
	}

	int  getperimeter()
	{
		return (2);
	}

	void tostring()
	{
		cout<<"width ="<<width<<endl;
		cout<<"height="<<height<<endl;
	}

	~rectangle()
	{


	}
};






int main()
{
	rectangle r(2,3);

	cout<<"width ="<<r.getwidth()<<endl;
	cout<<"height="<<r.getheight()<<endl;

	r.setwidth(4);
	r.setheight(5);

	cout<<"width ="<<r.getwidth()<<endl;
	cout<<"height="<<r.getheight()<<endl;

	cout<<"area ="<<r.getarea()<<endl;

	int w,h;
	cin>>w>>h;
	rectangle s(w,h);

	r.~rectangle();
	cout<<r.getheight()<<endl;
	return 0;
}

