#include<iostream>

class base
{
	protected:
		int width;
	public :
		void setwidth(void)
		{width=10;}
};

class der : public base
{
	private:
		int height;
	public :
		void showarea(void);
};

void der :: showarea(void)
{
	height=19;
	std::cout<<"Area ="<<height*width<<std::endl;
}
int main(void)
{
	der D;
	D.setwidth();
	D.showarea();
	return 0;
}
