#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
int n,m,y;
vector<int> a;
vector<int> b;
void Input();
void Mix();

int main()
{
    cin>>y;
    cin>>n>>m;
    for(int i=0; i < y; i++)
    {
        Input();
        Mix();

    }
    return 0;
}
void Input()
{
    int x;
    for(int i=0; i < n; i++) 
    {
        cin>>x;
        a.push_back(x);
    }

    for(int i=0; i < m; i++) 
    {
        cin>>x;
        b.push_back(x);
    }

}

 void Mix()
 {
    int i=0, j=0;
    while((i < n) && (j < m))
    {
        if(a[i] < b[j]) 
        {
            cout<<a[i]<<' ';
            i++;
        }
        else 
        {
            cout<<b[j]<<' ';
            j++;
        }
    }
    while(i < n)
    {
        cout<<a[i]<<' ';
        i++;
    }
    while(j < m)
    {
        cout<<b[j]<<' ';
        j++;
    }
    a.clear();
    b.clear();
    
 }