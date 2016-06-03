#include<iostream>
#include<cstring>
using namespace std;
class Pizza {
public:

	int price;
	char NamePizza[30];
	Pizza(int _price = 10, char * _NamePizza = "Pizza") : price(_price)
	{
		strcpy_s(NamePizza, _NamePizza);
	}
	int getPrice() const
	{
		return price;
	}

};
class Order {
public:

	int NumberOrder;
	Pizza pizza;
	Order(int _NumberOrder = 1, Pizza _pizza = Pizza()) :NumberOrder(_NumberOrder), pizza(_pizza) {}
	int getNumberOrder() const
	{
		return NumberOrder;
	}
	void sumOrder() {
		double sum = 0;
	}

};
class Client {
public:

	int NumberOrders;
	Order orders;
	char PersonName[50];
	Client(Order _orders = Order(), char * _PersonName = "") : orders(_orders)
	{
		strcpy_s(PersonName, _PersonName);
	}
	void Bill(Order &order) {
		orders[NumberOrders] = order;
		NumberOrders++;
	}
};

int main()
{
	Pizza Margarita(10, "Margarita");
	Order order1(1, Margarita);
	Client client1(order1, "Zdravko Chiflishki");
	system("pause");
	return 0;
}