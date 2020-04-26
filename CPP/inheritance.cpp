#include<iostream>
class polygon
{
	protected :
		int width,height;
	public:
	void setvalues(int a,int b)
		{
			width=a;
			height=b;
		}
};
class rect : public polygon
{
	public:
	int area(void)
	{
		return(width*height);
	}
};
class tri : public polygon
{
	public:
	int area(void)
	{
		return height*width/2;
	}
};
int main (void)
{
	rect R;
	tri T;
	R.setvalues(2,6);
	T.setvalues(2,6);
	std::cout<<R.area()<<std::endl;
	std::cout<<T.area()<<std::endl;
	return 0;
}
