#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;
 
int main()
{
	int n, cs = 1;
	cin >> n;
	string pass1, pass2;
	while (n--)
	{
		cin >> pass1 >> pass2;
		bool caps = false, num = false, wrong = false;
		if (pass1 == pass2)
			cout << "Case " << cs++ << ": Login successful." << endl;
		else
		{
			if (pass1.size() > pass2.size())
			{
				bool digit = false;
				for (int i = 0; i < pass1.size(); i++)
				{
					if (isdigit(pass1[i]))
					{
						digit = true;
						break;
					}
				}
				if (digit)
				{
					pass1.erase(remove(pass1.begin(), pass1.end(), '1'), pass1.end());
					pass1.erase(remove(pass1.begin(), pass1.end(), '2'), pass1.end());
					pass1.erase(remove(pass1.begin(), pass1.end(), '3'), pass1.end());
					pass1.erase(remove(pass1.begin(), pass1.end(), '4'), pass1.end());
					pass1.erase(remove(pass1.begin(), pass1.end(), '5'), pass1.end());
					pass1.erase(remove(pass1.begin(), pass1.end(), '6'), pass1.end());
					pass1.erase(remove(pass1.begin(), pass1.end(), '7'), pass1.end());
					pass1.erase(remove(pass1.begin(), pass1.end(), '8'), pass1.end());
					pass1.erase(remove(pass1.begin(), pass1.end(), '9'), pass1.end());
					pass1.erase(remove(pass1.begin(), pass1.end(), '0'), pass1.end());
				}
				else
				{
					wrong = true;
					goto last;
				}
				if (pass1.size() == pass2.size())
				{
					if (pass1 == pass2)
						num = true;
					else
					{
						for (int i = 0; i < pass1.size(); i++)
						{
							if ((pass1[i] >= 'A' && pass1[i] <= 'Z')
								&& (pass2[i] >= 'a' && pass2[i] <= 'z'))
							{
								if ((char)(pass1[i] + 32) == pass2[i])
								{
									caps = true;
								}
								else
								{
									wrong = true;
									break;
								}
							}
							else if ((pass1[i] >= 'a' && pass1[i] <= 'z')
									 && (pass2[i] >= 'A' && pass2[i] <= 'Z'))
							{
								if ((char)(pass1[i] - 32) == pass2[i])
								{
									caps = true;
								}
								else
								{
									wrong = true;
									break;
								}
							}
							else
							{
								wrong = true;
								break;
							}
						}
					}
					if (caps && !wrong)
						num = true;
				}
				else
					wrong = true;
			}
			else if (pass1.size() < pass2.size())
				wrong = true;
			else
			{
				for (int i = 0; i < pass1.size(); i++)
				{
					if ((pass1[i] >= 'A' && pass1[i] <= 'Z')
						&& (pass2[i] >= 'a' && pass2[i] <= 'z'))
					{
						if ((char)(pass1[i] + 32) == pass2[i])
						{
							caps = true;
						}
						else
						{
							wrong = true;
							break;
						}
					}
					else if ((pass1[i] >= 'a' && pass1[i] <= 'z')
							 && (pass2[i] >= 'A' && pass2[i] <= 'Z'))
					{
						if ((char)(pass1[i] - 32) == pass2[i])
						{
							caps = true;
						}
						else
						{
							wrong = true;
							break;
						}
					}
					else if (isdigit(pass1[i]) && isdigit(pass2[i]))
					{
						if (pass1[i] != pass2[i])
						{
							wrong = true;
							break;
						}
					}
					else
					{
						wrong = true;
						break;
					}
				}
			}
		  last:
			if (wrong)
				cout << "Case " << cs++ << ": Wrong password." << endl;
			else if (num && caps)
				cout << "Case " << cs++ <<
					": Wrong password. Please, check your caps lock and num lock keys." << endl;
			else if (num)
				cout << "Case " << cs++ << ": Wrong password. Please, check your num lock key." <<
					endl;
			else if (caps)
				cout << "Case " << cs++ << ": Wrong password. Please, check your caps lock key." <<
					endl;
		}
	}
}