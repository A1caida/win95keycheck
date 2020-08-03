constexpr auto TRUE = 0;
constexpr auto FALSE = 1;
//todo: сделай графический интерфейс
#include <iostream>
#include <string>

using namespace std;

int wrong()
{
	cout << "The key is wrong." << endl;
	exit(FALSE);
}

int main()
{
	string key, temp;

	cout << "Write your code here:"; cin >> key; cout << endl;
   
	for (size_t i = 0; i < key.find('-'); i++)
	{
		temp = temp + key[i];
	}
	if (key.find('-') != 5)
		wrong();
	key.erase(0, 6);
	
	int num = stoi(temp);

	if (num > 365)
		wrong();

	temp = key[0]; temp = temp + key[1]; temp = temp + key[2];

	if (temp != "OEM")
		wrong();
	
	key.erase(0, 4);

	if (key.find('-') != 7)
		wrong();

	temp.replace(0, 3, key, 0, 7);
	num = stoi(temp);
	
	if (num % 7 == 0)
	{
		key.erase(0, 8);
		if (key.length() !=5)
		{
			wrong();
		}
		else 
		{
			cout << "The key is right." << endl;
			return TRUE;
		}
	}
	wrong();
}

