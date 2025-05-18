#include <iostream>
#include <math.h>

using namespace std;

const int mp[3][3] = {{0, 2, 1}, {0, 2, 1}, {1, 2, 0}};
const int wp[3][3] = {{2, 1, 0}, {0, 1, 2}, {2, 0, 1}};

void print(int q[])
{
	static int solution_num = 0;
	cout << "Solution #: " << ++solution_num << "\n";

	for (int i = 0; i < 3; i++)
	{
		cout << "Man " << i + 1 << "paired with women " << q[i] + 1 << "\n";
	}
}

void backtrack(int &c)
{
	c--;
	if (c <= 0)
	{
		exit(0);
	}
}
// work on this function
bool ok(int q[], int &c)
{

	for (int i = 0; i < c; i++)
	{
		if (q[i] == q[c])
		{
			return false;
		}
	}

	for (int i = 0; i < c; i++)
	{
		if
	}
}

int main()
{
	int q[3];
	int c = 0;
	q[c] = 0;
	while (c >= 0)
	{
		c++;
		if (c >= 3)
		{
			print(q);
			backtrack(c);
		}
		else
			q[c] = 0;

		while (q[c] >= 0)
		{
			if (q[c] >= 3)
			{
				backtrack(c);
			}
			else if (ok(q, c))
			{
				break;
			}
		}
	}

	return 0;
}