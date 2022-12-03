#include "header.h"
#include "math.h"
#include <stdexcept>

using namespace std;

int rootScan(int a, int b, int c)
{
	if (b * b - 4 * a * c < 0)
		return 0;
	else if (b * b - 4 * a * c == 0)
		return 1;
	else
		return 2;
}

double findFirstRoot(int a, int b, int c)
{
	if (rootScan(a,b,c) == 0)
		throw std::domain_error("no roots in that example");
	return (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

double findSecondRoot(int a, int b, int c)
{
	if (rootScan(a, b, c) == 0)
		throw std::domain_error("no roots in that example");
	return (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
}