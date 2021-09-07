#include <iostream>

class C_Oper
{
public:
	C_Oper()
	{
		this->a = 0;
		this->b = 0;
	}
	C_Oper(int a, int b)
	{
		this->a = a;
		this->b = b;
	}

	inline C_Oper* operator +(C_Oper& other)
	{
		return new C_Oper
		(
			this->getA() + this->getB(),
			other.getA() + other.getB()
		);
	}
	int getA()
	{
		return this->a;
	}
	int getB()
	{
		return this->b;
	}
	void show()
	{
		std::cout << this->getA() << " : " << this->getB() << "\n";
	}
private:
	int a;
	int b;
};

int main()
{
	C_Oper oper1(9, 9); // 18
	C_Oper oper2(7, 7); // 14

	if (oper2.getA() == oper2.getB()) // Если 7 == 7, то их нужно сложить, иначе - ошибка
	{
		C_Oper* test_res = oper1 + oper2;
		test_res->show();
	}
	else
	{
		std::cout << "Error!";
	}
}