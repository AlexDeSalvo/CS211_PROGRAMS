#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int col)
{
	static int mp[3][3] = {{0, 2, 1},  // Man #0s Preference
						   {0, 2, 1},  // Man #1s Preference
						   {1, 2, 0}}; // Man #2s Preference

	static int wp[3][3] = {{2, 1, 0},  // Woman #0s Preference
						   {0, 1, 2},  // Woman #1s Preference
						   {2, 0, 1}}; // Woman #2s Preference

	// loop that error checks to see if this woman has been matched already
	for (int i = 0; i < col; i++)
	{
		if (q[i] == q[col])
		{
			return false;
		}
	}
	//loop to compare if any man prefers a different woman to his current pairing or
	//if any woman prefers a different man to her current pairing 
	for (int i = 0; i < col; i++)
	{		//
		if ((mp[col][q[i]] < mp[col][q[col]] && wp[q[i]][col] < wp[q[i]][i]) ||
			(mp[i][q[col]] < mp[i][q[i]] && wp[q[col]][i] < wp[q[col]][col]))
		{
			return false;
		}
	}

	return true;
}
//a print function to print our current solution
void print(int q[])
{
	static int solution = 0;
	cout << "Solution # " << ++solution << ":\nMan\tWoman\n";
	for (int i = 0; i < 3; i++)
	{
		cout << i << "\t" << q[i] << "\n";
	}
	cout << "\n";
}
//backtrack function subtracks 1 from our current column so we can find a new match
void backtrack(int &col)
{
	col--;

	if (col == -1)
	{
		exit(0);
	}
}

int main()
{
	int q[3];
	int col = 0;
	q[0] = 0;

	// new column in preference array
	while (col >= 0)
	{
		col++;
		// loop runs until col == 3 in which we print our solution
		// after we print we backtrack to find other possible solutions
		if (col == 3)
		{
			print(q);
			backtrack(col);
			// if we have not yet reached 3 then q[col] = -1
			// we use -1 so we can start our search for preference of q[col] at 0
		}
		else
		{
			q[col] = -1;
		}

		while (col >= 0)
		{
			// now q[col]is at 0
			q[col]++;
			//if the value in q[col] == 3 we need to backtrack
			//highest possible value for a choice is 2
			if (q[col] == 3)
			{
				backtrack(col);
			}
			else
			{
				//ok function checks that the current match is valid
				//if true we can break this while loop else q[col]++ 
				if (ok(q, col) == true)
				{
					break;
				}
			}
		}
	}
}
