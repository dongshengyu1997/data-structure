#include <iostream>
#include<algorithm>
#include <set>
#include <vector>
using namespace std;
#define vexcount 9
struct edge
{
    int a1;
    int a2;
    int w;
};
int graph[vexcount][vexcount];
void krusakl(vector<edge>);
bool daxiao(edge&,edge&);
int main() {

    return 0;
}
bool daxiao(edge&a,edge&b)
{
    return a.w < b.w;
}
void kruskal(vector<edge>bian)
{
    sort(bian.begin(),bian.end(),daxiao);
    vector<set<int>>a(vexcount);
    for(int i=0;i<vexcount;i++)
    {
        a[i] = {i};
    }
    for(auto a:bian)
    {

    }
}