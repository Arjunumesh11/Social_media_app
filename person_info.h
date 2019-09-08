#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
#include<queue>
using namespace std;
int count_of_user = 0;                //present count of user in data
class person
{
public:
	int getid()
	{
		return id;
	}
	string getname() { return name; }
	bool ispassword(string x)
	{
		return (x == password);
	}
	void change(string x)
	{
		password = x;
	}
	person(string x, int i, string y) :name(x), password(y), id(i) {}
	void edit_profile()
	{
		//fill in
	}
	void get_profile()
	{
		//fill in
	}
private:
	string name, password,mail_id,phone_no;
	int id;
}; 
