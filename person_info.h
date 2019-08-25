#include<bits/stdc++.h>
using namespace std;
int count_of_user=0;                //present count of user in data
class person
{
    public:
    int getid()
    {return id;}
    string getname(){return name;}
    bool ispassword(string x)
    {return (x==password);}
    void change(string x)
    {password=x;}
    person(string x,int i,string y):name(x),password(y),id(i){}
    private:
    string name,password;
    int id;
};