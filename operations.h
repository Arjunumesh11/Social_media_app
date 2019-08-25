#include"person_info.h"
void dispadj(vector<int>adj[])
{
    for(int i=0;i<count_of_user;i++)
    {
        for(int j=0;j<adj[i].size();j++)
        cout<<adj[i][j]<<" ";
        cout<<endl;
    }
}
void addperson(string s,vector<person*> &data,int id,string pass="1234")
{
    person *x=new person(s,id,pass);
    data.push_back(x);
}
int findfriend(string frndname,vector<person*> &listofperson)
{
    for(int i=0;i<listofperson.size();i++)
    {
        if(listofperson[i]->getname()==frndname)
            return i;
    }
    return -1;
}
void addfrnd(int u,int v,vector<int> adj[])
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
void deletefrnd(int u,int v,vector<int> adj[])
{
    adj[u].erase(adj[u].begin()+v-1);
    for(int i=0;i<adj[v].size();i++)
        if(adj[v][i]==u)
        {
            adj[v].erase(adj[v].begin()+i);
            break;
        }
        else cout<<"Delete Unsuccessful !";    
}
bool comp(pair<int,int> t,pair<int,int> l)                            //comparing function for 
{                                                                     //sorting mutual friends    
    return t.second>l.second;
}
queue<int> mutual_dfs(vector<int> adj[],int v,int n)
{
    bool *visited = new bool[n];
    for(int i = 0; i < n; i++) 
        visited[i] = false;
    visited[v]=true; 
    queue<int> q,k,l;
    int len=0,curr;
    q.push(v); 
    while(!q.empty()) 
    {   if(len==2)
            return q;
        curr=q.front();
        q.pop(); 
        for (int i = 0; i<adj[curr].size();i++) 
        { 
            if (!visited[adj[curr][i]]) 
            { 
                if(len!=1)
                visited[adj[curr][i]] = true; 
                k.push(adj[curr][i]); 
            } 
        }
        if(q.empty())
        {
            len++;
            q=k;
            k=l;
        }
     
    } 
}
void listfrnd(int x,vector<int> adj[],vector<person*> &data)
{
    system("clear");
    cout<<data[x]->getname()<<"'s  Friends : \n\n";
    if(adj[x].empty())
        cout<<"No Friends Added !";
    for(int i=0;i<adj[x].size();i++)
        cout<<i+1<<". "<<data[adj[x][i]]->getname()<<endl;
    //dispadj(adj);
    cout<<"\n\n Press Enter to Continue !";
    cin.ignore().get();
}
