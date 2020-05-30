#include <iostream>
#include <string>

using namespace std;

enum Season
{
	Winter,
	Spring,
	Summer,
	Autumn
};

class Product
{
protected:
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

	virtual void Show() 
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

class FruitOrVegetable : public Product
{
private:
	Season collectionSeason;
	
public:
	FruitOrVegetable(string name, string producer, int price, int storageLife, int quantity, Season season)
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

	void Show() override
	{
		if (name.empty() || producer.empty())
		{
			cout << "Set properties right!\n";
			abort();
		}

		cout << "Name:\t\t" << name << endl;
		cout << "Producer:\t" << producer << endl;
		cout << "Season:\t" << collectionSeason << endl;
		cout << "Price:\t\t" << price << " hrn" << endl;
		cout << "Storage Life:\t" << storageLifeInDays << " days" << endl;
		cout << "Quantity:\t" << quantity << endl;
	}
};

class Dairy : public Product
{
private:
	double fatPercentage;
	
public:
	Dairy(string name, string producer, int price, int storageLife, int quantity, double fat)
		: Product(name, producer, price, storageLife, quantity)
	{
		if (fat > 100 || fat < 0)
			abort();

		this->fatPercentage = fat;
	}

	double GetFat()
	{
		return fatPercentage;
	}
	void SetFatPercentage(double fat)
	{
		this->fatPercentage = fat;
	}

	void Show() override
	{
		if (name.empty() || producer.empty())
		{
			cout << "Set properties right!\n";
			abort();
		}

		cout << "Name:\t\t" << name << endl;
		cout << "Producer:\t" << producer << endl;
		cout << "FatPercentage:\t" << fatPercentage<< endl;
		cout << "Price:\t\t" << price << " hrn" << endl;
		cout << "Storage Life:\t" << storageLifeInDays << " days" << endl;
		cout << "Quantity:\t" << quantity << endl;
	}
};

int main()
{	
	const int size = 5;
	Product products[size] =
	{
		FruitOrVegetable("apples", "Italy", 15, 21, 300, Season::Winter),
		FruitOrVegetable("carrots", "Germany", 20, 21, 100, Season::Autumn),
		FruitOrVegetable("onions", "America", 5, 14, 500, Season::Winter),
		Dairy("milk", "Canada", 8, 14, 400, 2.5),
		Dairy("butter", "Finland", 60, 60, 200, 82)
	};

	cout << "Lets show our products\n";
	
	for (int i = 0; i < size; i++)
	{
		products[i].Show();
	}
	cout << "\nLet's sort them!";

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
