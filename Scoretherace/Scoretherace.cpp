#include <iostream>
#include <vector>

using namespace std;

const int MAXTEAM = 26;

// RULES//:
//  each team has name A-Z : 26 teams Non repeating
//  same number of members
//  No ties

// data struct for teams//
struct team
{
    int runners = 0;
    int points = 0;
    char name;
    bool active = false;
    float totalscore = points / runners;
};

int activeTeamCount(string &input, team allteams[])
{
    int activeTeamTotal = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == allteams[i].name)
        {
            allteams[i].active = true;
            activeTeamTotal++;
        }
    }
    return activeTeamTotal;
}

int teamFind(char &ref, team allteams[], int low, int high)
{

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (allteams[mid].name == ref)
        {
            return mid;
        }

        if (allteams[mid].name < ref)
        {
            low = mid + 1;
        }
        if (allteams[mid].name > ref)
        {
            high = mid - 1;
        }
    }
    return -1;
}

int findWinner(team allteams[])
{
    int maxscore = 0;
    int winnerindex;
    for (int i = 0; i < MAXTEAM; i++)
    {
        if (maxscore < allteams[i].totalscore)
        {
            maxscore = allteams[i].totalscore;
            winnerindex = i;
        }
    }
    return winnerindex;
}

void teamScores(string &input, team allteams[])
{
    // iterate through input
    for (int i = 0; i < input.size(); i++)
    {
        // increment runners field
        allteams[teamFind(input[i], allteams, 0, MAXTEAM - 1)].runners++;
        // increment points field
        allteams[teamFind(input[i], allteams, 0, MAXTEAM - 1)].points += i + 1;
    }
}

int runnerCountCheck(team allteams[])
{
    int runnerCount = 0;
    for (int i = 0; i < MAXTEAM; i++)
    {

        for (int j = i + 1; j < MAXTEAM; j++)
        {

            if (allteams[i].active && allteams[j].active == true)
            {

                if (allteams[i].runners != allteams[j].runners)
                {
                    return -1;
                }
                else
                    (runnerCount = allteams[i].runners);
            }
        }
    }
    return runnerCount;
}

void teamStatsOutput(int activeTeamTotal, int runnerCount, team allteams[])
{
    cout << "There are " << activeTeamTotal << " teams." << endl;
    cout << "There are " << runnerCount << " runners on a team" << endl;

    cout << "The names of the teams and their scores are: " << endl;

    for (int i = 0; i < MAXTEAM; i++)
    {
        if (allteams[i].active == true)
        {
            cout << allteams[i].name << " : " << allteams[i].totalscore << endl;
        }
    }

    cout << "The winning team is " << allteams[findWinner(allteams)].name << "With a score of " << allteams[findWinner(allteams)].totalscore;
}

int main()
{

    // reference values
    string input = "";
    int activeTeamTotal = 0;
    int runnerCount = 0;

    cout<<"hello";

    // initialize 26 structs for all letters of possible teams
    team allteams[MAXTEAM];
    
    cout<<"hello";
 


#ifdef TEST 
    // intialize the name field of all teams
    char tempchar = 'A';
    for (int i = 0; i < MAXTEAM; i++)
    {
        allteams[i].name = tempchar;
        tempchar++;
    }

    // loop and prompt for input until user enters done

    // count active teams
    activeTeamTotal = activeTeamCount(input, allteams);

    // tally scores
    teamScores(input, allteams);

    // check runner count is valid//
    if (runnerCountCheck(allteams) == -1)
    {
        cout << "Error unequal amount of runners on each team.";
        return 0;
    }
    else
        (runnerCount = runnerCountCheck(allteams));

    // Output stats and winner
    teamStatsOutput(activeTeamTotal, runnerCount, allteams);
#endif
    return 0;
}