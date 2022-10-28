#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct contest
{
	int tID;
	char pID;
	string tm, res;
};

bool compare(contest a, contest b)
{
	if (a.tm < b.tm)
		return true;
	else
		return false;
}

int main()
{
	int T, P, S, teamID, problemID;
	string time, result, ignore;
	while (cin >> T >> P >> S && (T && P && S))
	{
		contest submission[S];
		for (int i = 0; i < S; i++)
		{
			cin >> submission[i].tID >> submission[i].pID >> submission[i].tm >> submission[i].res;
			if (submission[i].res == "No")
				getline(cin, ignore);
		}
		sort(submission, submission + S, compare);
		int solvedProb[T + 1][P + 1], solvedTeam[P + 1][T + 1];
		memset(solvedProb, 0, sizeof(solvedProb));
		memset(solvedTeam, 0, sizeof(solvedTeam));
		string time1, time2;
		bool criteria12 = false, criteria34 = false, output1 = false, output2 = false;
		int ot1 = 0, ot2 = 0;
		for (int n = 0; n < S; n++)
		{
			teamID = submission[n].tID;
			problemID = submission[n].pID;
			time = submission[n].tm;
			result = submission[n].res;
			if (result == "Yes")
			{
				solvedProb[teamID][problemID - 64]++;
				solvedTeam[problemID - 64][teamID]++;
			}
			int solve;
			for (int i = 1; i <= T; i++)
			{
				solve = 0;
				for (int j = 1; j <= P; j++)
				{
					if (solvedProb[i][j])
						solve++;
				}
				if (solve > 0 && solve < P)
				{
					criteria12 = true;
				}
				else
				{
					criteria12 = false;
					break;
				}
			}
			for (int i = 1; i <= P; i++)
			{
				solve = 0;
				for (int j = 1; j <= T; j++)
				{
					if (solvedTeam[i][j])
						solve++;
				}
				if (solve > 0 && solve < T)
				{
					criteria34 = true;
				}
				else
				{
					criteria34 = false;
					break;
				}
			}
			if (criteria12 && criteria34)
			{
				output1 = true;
			}
			if (output1 && !ot1)
			{
				time1 = time;
				ot1 = 1;
			}
			if (ot1 && (!criteria12 || !criteria34))
			{
				output2 = true;
			}
			if (output2 && !ot2)
			{
				time2 = time;
				ot2 = 1;
			}
		}
		if (!ot1)
			cout << "--:--:-- ";
		else
			cout << time1 << ' ';
		if (!ot2)
			cout << "--:--:--" << endl;
		else
			cout << time2 << endl;
	}
}
