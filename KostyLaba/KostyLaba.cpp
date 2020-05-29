#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
	string name;
	string producer;
	int price;
	int storageLifeInDays;
	int quantity;

public:
	Product()
	{}
	Product(string name, string producer, int price, int storageLife, int quantity)
	{
		if (name.empty() || producer.empty())
		{
			cout << "Invalid name\n";
			abort();
		}
		else if (price < 0 || storageLife < 0 || quantity < 0)
		{
			cout << "price, storageLife and quantity can't be negative\n";
			abort();
		}

		this->name = name;
		this->producer = producer;
		this->price = price;
		this->storageLifeInDays = storageLife;
		this->quantity = quantity;
	}

	string GetName()
	{
		return name;
	}
	string GetProducer()
	{
		return producer;
	}
	int GetPrice()
	{
		return price;
	}
	int GetStorageLife()
	{
		return storageLifeInDays;
	}
	int Getquantity()
	{
		return quantity;
	}

	void SetName(string name)
	{
		if (name.empty())
		{
			cout << "Invalid name\n";
			abort();
		}

		this->name = name;
	}
	void SetProducer(string producer)
	{
		if (producer.empty())
		{
			cout << "Invalid producer\n";
			abort();
		}

		this->producer = producer;
	}
	void SetPrice(int price)
	{
		if (price < 0)
		{
			cout << "price can't be negative\n";
			abort();
		}

		this->price = price;
	}
	void setStorageLife(int storageLife)
	{
		if (storageLife < 0)
		{
			cout << "storageLife can't be negative\n";
			abort();
		}

		this->storageLifeInDays = storageLife;
	}
	void setQuantity(int quantity)
	{
		if (quantity < 0)
		{
			cout << "quantity can't be negative\n";
			abort();
		}

		this->quantity = quantity;
	}

	void Show()
	{
		if (name.empty() || producer.empty())
		{
			cout << "Set properties right!\n";
			abort();
		}

		cout << "Name:\t\t" << name << endl;
		cout << "Producer:\t" << producer << endl;
		cout << "Price:\t\t" << price << " hrn" << endl;
		cout << "Storage Life:\t" << storageLifeInDays << " days" << endl;
		cout << "Quantity:\t" << quantity << endl;
	}
};

enum Season 
{
	Winter,
	Spring,
	Summer,
	Autumn
};

class Vegetables : public Product
{
private:
	Season collectionSeason;
	
public:
	Vegetables(string name, string producer, int price, int storageLife, int quantity, Season season) 
		: Product(name, producer, price, storageLife, quantity)
	{
		this->collectionSeason = season;
	}

	Season GetSeason()
	{
		return this->collectionSeason;
	}

	void SetSeason(Season season) 
	{
		this->collectionSeason = season;
	}

};
int main()
{
	/*Product product1("Vegetables", "Italy", 15, 21, 300);
	Product product2("Vegetables", "Germany", 20, 21, 100);
	Product product3("Fruits", "America", 5, 14, 500);
	Product product4("Fruits", "Canada", 8, 14, 400);
	Product product5("Dairy", "Finland", 60, 60, 200);*/
	const int size = 5;
	Product products[size] =
	{
		Product("Vegetables", "Italy", 15, 21, 300),
		Product("Vegetables", "Germany", 20, 21, 100),
		Product("Fruits", "America", 5, 14, 500),
		Product("Fruits", "Canada", 8, 14, 400),
		Product("Dairy", "Finland", 60, 60, 200)
	};

	cout << "Lets show our products, choose the category: Vegetables/Fruits/Dairy\n";
	string str;
	cin >> str;
	while (str != "Vegetables" && str != "Fruits" && str != "Dairy")
	{
		cout << "Wrong category! Try again\n";
		cin >> str;
	}

	if (str == "Vegetables")
	{
		int count = 1;
		for (int i = 0; i < size; i++)
		{
			if (products[i].GetName() == str)
			{
				cout << "\nProduct " << count++ << endl;
				products[i].Show();
			}
		}

		cout << "\nSelect the highest price\n";
		count = 1;
		int price;
		cin >> price;
		for (int i = 0; i < size; i++)
		{
			if (products[i].GetPrice() < price && products[i].GetName() == str)
			{
				cout << "\nProduct " << count++ << endl;
				products[i].Show();
			}
		}
	}
	else if (str == "Fruits")
	{
		int count = 1;
		for (int i = 0; i < size; i++)
		{
			if (products[i].GetName() == str)
			{
				cout << "\nProduct " << count++ << endl;
				products[i].Show();
			}
		}
		cout << "\nSelect the highest price\n";
		count = 1;
		int price;
		cin >> price;
		for (int i = 0; i < size; i++)
		{
			if (products[i].GetPrice() < price && products[i].GetName() == str)
			{
				cout << "\nProduct " << count++ << endl;
				products[i].Show();
			}
		}
	}
	else if (str == "Dairy")
	{
		int count = 1;
		for (int i = 0; i < size; i++)
		{
			if (products[i].GetName() == str)
			{
				cout << "\nProduct " << count++ << endl;
				products[i].Show();
			}
		}
		cout << "\nSelect the highest price\n";
		count = 1;
		int price;
		cin >> price;
		for (int i = 0; i < size; i++)
		{
			if (products[i].GetPrice() < price && products[i].GetName() == str)
			{
				cout << "\nProduct " << count++ << endl;
				products[i].Show();
			}
		}
	}

	cout << "\nSelect the lowest storage term\n";
	int num;
	cin >> num;
	if (num < 0)
	{
		cout << "Storage term can't be below 0\n";
		abort();
	}

	int count = 1;
	for (int i = 0; i < size; i++)
	{
		if (products[i].GetStorageLife() > num)
		{
			cout << "\nProduct " << count++ << endl;
			products[i].Show();
		}
	}
	return 0;
}
