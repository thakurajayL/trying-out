#include<iostream>

class Base {
	virtual void print() {
		std::cout<<" Base "<<std::endl;
	}
};

class Derived1 : public Base {
	virtual void print() {
		std::cout<<" Derived1 "<<std::endl;
	}
};

class Derived2 : public Base {
	virtual void print() {
		std::cout<<" Derived2 "<<std::endl;
	}
};

int main()
{
	Derived1 d1;
	Base *bp = dynamic_cast<Base*>(&d1);
	if(bp == nullptr) {
		std::cout<<"dynamic cast failed Derived*->Base"<<std::endl;
	} else {
		std::cout<<"dynamic cast success Derived*->Base*"<<std::endl;
	}

	Derived2 *d2 = dynamic_cast<Derived2 *>(bp);
	if(d2 == nullptr) {
		std::cout<<"dynamic cast failed Base*->Derived2* "<<std::endl;
	} else {
		std::cout<<"dynamic cast success Base*->Derived2*"<<std::endl;
	}
}

