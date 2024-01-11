
#include <bits/stdc++.h>

using namespace std;

struct Point {
	int x, y;
};


string mapping(map<char, Point> m, string s, char a[5][5])
{
	if (m[s[0]].x == m[s[1]].x)
	{
		int x = m[s[0]].x;
		int y1 = (m[s[0]].y + 1) % 5;
		int y2 = (m[s[1]].y + 1) % 5;
		string st = "";
		st += a[x][y1];
		st += a[x][y2];
		return st; 
	}
	if (m[s[0]].y == m[s[1]].y)
	{
		int y = m[s[0]].y;
		int x1 = (m[s[0]].x + 1) % 5;
		int x2 = (m[s[1]].x + 1) % 5;
		string st = "";
		st +=  a[x1][y];
		st += a[x2][y];
		return st; 
	}
	string st = "";
	st += a[m[s[0]].x][m[s[1]].y];
	st += a[m[s[1]].x][m[s[0]].y];
	return st;
}


string mapping2(map<char, Point> m, string s, char a[5][5])
{
	if (m[s[0]].x == m[s[1]].x)
	{
		int x = m[s[0]].x;
		int y1 = (m[s[0]].y - 1 + 5) % 5;
		int y2 = (m[s[1]].y - 1 + 5) % 5;
		string st = "";
		st += a[x][y1];
		st += a[x][y2];
		return st; 
	}
	if (m[s[0]].y == m[s[1]].y)
	{
		int y = m[s[0]].y;
		int x1 = (m[s[0]].x - 1 + 5) % 5;
		int x2 = (m[s[1]].x - 1 + 5)  % 5;
		string st = "";
		st +=  a[x1][y];
		st += a[x2][y];
		return st; 
	}
	string st = "";
	st += a[m[s[0]].x][m[s[1]].y];
	st += a[m[s[1]].x][m[s[0]].y];
	return st;
}

int main()
{
	string KEY;
	cout << "Nhap KEY = ";
	cin >> KEY;

	
	// upper KEY
	for (int i = 0; i < KEY.length(); i++)
	{
		KEY[i] = toupper(KEY[i]);
		if (KEY[i] == 'J') KEY[i] = 'I';
	}
	
	cout << "KEY = " << KEY << endl;
	
	// create matrix KEY 
	
	char m[5][5];
	bool check[2000];
	for (char ch = 'A' ; ch <= 'Z'; ch++)
	{
		check[ch] = false;
	}
	
	check['J'] = true;
	
	int k = 0;
	
	cout << "MATRIX:" << endl;
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			
			while (k < KEY.length())
			{
				if (!check[KEY[k]]) {
					m[i][j] = KEY[k];
					check[KEY[k]] = true;
					//hbajdbhcout << KEY[k] << endl;
					break;
				} else {
					k++;	
				}
			}
			if (k >= KEY.length())
			{
				for (char v = 'A'; v <= 'Z'; v++)
				{
					if (!check[v])
					{
						check[v] = true;
						m[i][j] = v;
						break; 
					}
				}
			}
			 
		}
	}
	map<char, Point> MPoint;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout << m[i][j] << " ";
			Point p;
			p.x = i;
			p.y = j;
			MPoint[m[i][j]] = p;
		}
		cout << endl;
	}
	
	
	///////////////////////////
	
	cin.ignore();
	string plaintext;
	cout << "Plain Text: ";
	cin >> plaintext;
	for (int i = 0; i < plaintext.length(); i++) plaintext[i] = toupper(plaintext[i]);
	cout << plaintext << endl;
	cout <<"----------------" << endl;
	vector<string> M2Char;

	cout << "ENCRYPTION" << endl;
	for (int i = 0; i < plaintext.length(); i = i+2)
	{
		string st = "";
		if (i < plaintext.length() - 1)
		{
			if (plaintext[i] == plaintext[i+1])
			{
				st += plaintext[i];
				st += "X";
				i--;
				cout << mapping(MPoint, st, m);
				M2Char.push_back(mapping(MPoint, st, m));
				continue;
			}
			else 
			{
				st += plaintext[i];
				st += plaintext[i+ 1];				
			}	
		} 
		else
		{
			st += plaintext[i];
			st += "X";
		}	
		cout << mapping(MPoint, st, m);
		
		M2Char.push_back(mapping(MPoint, st, m));		
	}
	cout <<endl;
	cout <<endl<< "DECRYPTION" << endl;
	for (vector<string>::iterator it = M2Char.begin(); it != M2Char.end(); it++)
	{
		cout << mapping2(MPoint, *it, m);
	}
	
	return 0;
}