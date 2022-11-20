#include<iostream>
using namespace std;
//using template class
template<class T>
class home_decoration
{
	public:
		T expense;
		//virtual function
		virtual void calculate();
};
template<class T> 
//inheriting a class
class painting : public home_decoration<T>{
	public:
		T l,b,area;
		// parameterised constructor
			painting(T x,T y)
			{
				l=x;
				b=y;
			}
			void calculate()
			{
				area=l*b;
				home_decoration<T>expense=area*5*5000;
				cout<<"Price of painting room:"<<expense<<endl;
			}
};

template<class T>
class furniture:public home_decoration<T>{
	public:
		T chair,table;
		public:
			furniture(T x,T y)
			{
				chair=x;
				table=y;
			}
			//overloading operator using friend function
			friend void operator++(furniture);
			void calculate()
			{
				home_decoration<T>expense;
				expense=chair*450.0+table*500.0;
				cout<<"Price of furniture:"<<expense<<endl;
			}
};
void operator++(furniture p);
			{
				++p.chair;
				++p.table;
			}
//main method			
int main()
{
	int i;
	//creating base class pointer
	home_decoration<double>*p;
	//creating objects of derived classes
	painting<double>b(24,10);
	painting<double>c(23.7f,9.5f);
	furniture<double>d(5,2);
	cout<<"Enter 1 if chair or table is broken"<<endl;
	cin>>i;
	if(i==1)
	++d;
	p=&b;
	//calling functions
	p->calculate();
	p=&c;
	p->calculate();
	p=&d;
	p->calculate();
	return 0;
}
