#include <iostream>
#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	int b;
	int c;
	int choose;
	cout << "Vibirete punkt " << endl;
	cout << "1) Reshenie kvadratnogo yravneniya" << endl;
	cout << "2) Sravnenie algoritmov sortirovki" << endl;
	cin >> choose;
	if (choose == 1) 
	{
		cout << "Reshenie kvadratnogo yravneniya (a*x^2 + b*x + c = 0)" << endl;
		cout << "Vvedite koefficient 'a'" << endl;
		cin >> a;
		cout << "Vvedite koefficient 'b'" << endl;
		cin >> b;
		cout << "Vvedite koefficient 'c'" << endl;
		cin >> c;
		cout << "D = " << b * b - 4 * a * c << endl;
		if (rootScan(a, b, c) == 0)
		{
			cout << "Korney net";
		}
		else if (rootScan(a, b, c) == 1)
		{
			cout << "Odin koren`: " << findFirstRoot(a, b, c);
		}
		else if (rootScan(a, b, c) == 2)
		{
			cout << "Dva kornya: " << findFirstRoot(a, b, c) << ' ' << findSecondRoot(a, b, c) << endl;
		}

		return 0;
	}
	else if (choose == 2)
	{
		func2();
	}
	
}
