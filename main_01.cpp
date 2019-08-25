#include"operations.h"
void Addfrndscreen(vector<int> adj[],int id_user,int n,vector<person*> &data)
{
    int no_sorted;                              //integer for getting the input position of suggestions
    vector<pair<int,int>> mutualfrnds;          //list contains the id and count
    unordered_map<int,int> m;                   //map for finding frequency of mutual friends
    unordered_map<int,int>::iterator t;         //iterator for m
    queue<int> frnd;                            //id of mutual friends
    string name_find_frnd;                      //input for the add friend menu
    int choice,find_frnd_status;                
    frnd=mutual_dfs(adj,id_user,n);
    while(!frnd.empty())
    {
       m[frnd.front()]++;
       frnd.pop();
    }
    for(t=m.begin();t!=m.end();++t)
        mutualfrnds.push_back(pair<int,int>(t->first,t->second));
    sort(mutualfrnds.begin(),mutualfrnds.end(),comp);
    system("clear");
    cout<<"\n\n     1. Suggestion : ";
    if(mutualfrnds.empty())
    cout<<"\n\n        No Suggestions ";
    for(int i=0;i<mutualfrnds.size();i++)
       { cout<<"\n"<<i+1<<". "<<data[mutualfrnds[i].first]->getname()<<" ("<<mutualfrnds[i].second<<")"<<endl;}
    cout<<"\n\n     2. Find User :  \n\n";
    cin>>choice;
    system("clear");
    switch (choice)
    {
    case 1:
            if(mutualfrnds.empty())
                break;
            for(int i=0;(i<mutualfrnds.size())&&(i<5);i++)
            {
               cout<<data[mutualfrnds[i].first]->getname()<<" "<<mutualfrnds[i].second<<endl;
            }
            cout<<"\n Enter No : ";cin>>no_sorted;
            addfrnd(id_user,mutualfrnds[no_sorted-1].first,adj);
        break;
    case 2:
            cout<<"Enter Name of User :";cin>>name_find_frnd;
            find_frnd_status=findfriend(name_find_frnd,data);
            if(find_frnd_status!=-1)
                addfrnd(id_user,find_frnd_status,adj);
            else cout<<"\n Does not exist";
            break;
    default:
        break;
    }
}
int Login(unordered_map<string,pair<string,int>> &user)
{
    string username,password;
    system("clear");
    cout<<"\n\n";
    cout<<"Enter username : ";cin>>username;
    cout<<"Enter password : ";cin>>password;
    if(user[username].first==password)
        {
            cout<<"\n login Sussessfull ! \n";
            return user[username].second;
        }
    cout<<"\n Login failed ! \n";
    cout<<"\n\n Press Enter to Continue !";
    cin.ignore().get();
    return -1;
}
int Signup(unordered_map<string,pair<string,int>> &user,vector<person*> &data)
{
    string username,password;
    system("clear");
    cout<<"\n\n";
    cout<<"Enter username : ";cin>>username;
    cout<<"Enter password : ";cin>>password;
    if(user.count(username)>0)
        {
            cout<<"\n signup failed !";
            cout<<"\n\n User Already exist !";
            return -1;
        }
    user[username].first=password;
    user[username].second=count_of_user;
    addperson(username,data,count_of_user,password);
    count_of_user++;
    return user[username].second;
}
void loginscreen(int id_user,vector<int> adj[],int no_user,vector<person*> &data)
{
    string choice;
    int pos_delete;
    while(1)
    {
    system("clear");
    cout<<"   User name : "<<data[id_user]->getname()<<"\n";
    cout<<"   User ID   : "<<id_user<<"\n\n\n";
    cout<<"   1.View    Friends  :\n";
    cout<<"   2.Add     Friends  :\n";
    cout<<"   3.Delete  Friends  :\n";
    cout<<"   4.Logout           :\n";
    cin>>choice;
    switch(stoi(choice))
    {
        case 1:listfrnd(id_user,adj,data);break;
        case 2:Addfrndscreen(adj,id_user,no_user,data);break;
        case 3:listfrnd(id_user,adj,data);
        cout<<"Enter the number to be deleted : ";cin>>pos_delete;
        deletefrnd(id_user,pos_delete,adj);break;
        case 4:return;
    }
    }
}
string menu()
{
    string choice;
    system("clear");
    cout<<"            Welcome \n\n\n";
    cout<<"     1.Login  : \n";
    cout<<"     2.Signup : \n";
    cout<<"     3.Exit   : \n";
    cin>>choice;
    return choice;
}
int main()
{
    int n=100,id_user;                               //max n = no of users
    int choice;                                     //choice in menu
    vector<person*> data;                           //queue for classes
    vector<int> adj[n];                             //adjacency matrix showing connections
    unordered_map<string,pair<string,int>> user;    //user info password and id
    while(1)
    {
        choice=stoi(menu());
        switch(choice)
        {
            case 1:id_user=Login(user);if(id_user!=-1){loginscreen(id_user,adj,n,data);}break;
            case 2:id_user=Signup(user,data);if(id_user!=-1){loginscreen(id_user,adj,n,data);}break;
            case 3:exit(0);
        }
    }

}
