#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

string findOs(void);
void clear(void);

int main()
{
	bool registred = false;
	string username,password,which;
	bool loginpage = true;
	bool inputtingscreen = false;
	while (loginpage)
	{
		cout << "-------------Choose an option------------- \n";
		cout << "                                         |\n";
		cout << "1.Login                                  |\n";
		cout << "2.register                               |\n";
		cout << "                                         |\n";
		cout << "------------------------------------------\n";
		cin >> which;

		if (which == "1")
		{
			which = "Login";
			loginpage = false;
			inputtingscreen = true;
		}
		else if (which == "2")
		{
			which = "Register";
			loginpage = false;
			inputtingscreen = true;
		}
		else
		{
			cout << "invalid input";
			clear();
		}
	}
	clear();

	while (inputtingscreen)
	{
		cout << "-------------" << which << "------------- \n";
		cout << "Type your Username: \n";
		cin >> username;
		cout << "Type your Password:  \n";
		cin >> password;
		clear();

		ifstream file(username + ".txt");
		if (file.fail())
		{
			registred = false;
		}
		else
		{
			registred = true;
		}

		fstream File;
		File.open(username + ".txt", ios::in);
		if (registred)
		{
			string pass;
			getline(File, pass);
			if (pass == password)
			{
				inputtingscreen = false;
				cout << "LOGGED IN";
				cout << "Yeeee i did my first cpp project without google or chatgpttttt";
			    
			}
			else
			{
				clear();
				which = "Wrong password";
			}
		}
		else
		{
			clear();
			cout << "Successfully Registered";
			File.open(username + ".txt", ios::out);
			File << password;
			inputtingscreen = false;
		}
	}
	return 0;
}

string findOs(void)
{
#ifdef _WIN32
	return "windows";
#else
	return "linux";
#endif
}

void clear(void)
{
	if (findOs() == "linux")
	{
		system("clear");
	}
	else
	{
		system("CLS");
	}
}
