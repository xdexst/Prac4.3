#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class TPen {
private:
	string FColor;
public:
	TPen() {}
	string GetColor() {
		return FColor;
	}
	void SetColor(string color) {
		FColor = color;
	}
};

int main()
{
	setlocale(LC_ALL, "ru");
	const int SIZE = 5;
	TPen pens[SIZE];
	ifstream fin("color.txt");
	if (!fin) {
		cout << "File not found!" << endl;
		return 1;
	}

	int i = 0;
	while (!fin.eof() && i < SIZE) {
		string temp;
		getline(fin, temp);
		pens[i].SetColor(temp);
		i++;
	}
	fin.close();

	for (int j = 0; j < SIZE; j++) {
		cout << "Color: " << pens[j].GetColor() << endl;
	}

	return 0;
}
