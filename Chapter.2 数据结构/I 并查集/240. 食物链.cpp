// #include<iostream>
// #include<utility>
// using namespace std;
// #define MAX_N 50010

// int father[MAX_N];
// //distance为当前点距离父节点的距离
// //%3=0,1,2三类分别对应三种动物
// int distanceToFather[MAX_N];

// //first:id,second:distance
// pair<int,int> QueryAncestor(int id){
//     if(father[id]==id) return {0,id};
//     int fatherId = QueryAncestor(father[id]).first;
//     distanceToFather[id] += distanceToFather[father[id]];
//     return {distanceToFather[id],fatherId};
// }


// void Insert(int childId,int fatherId,int distance){
//     int childAncestorId = QueryAncestor(childId).first;
//     auto queryFather = QueryAncestor(fatherId);
//     if(childAncestorId==queryFather.first) return;
//     int fatherAncestorId = queryFather.first;
//     int fatherToAncestorDistance=queryFather.second;
//     father[childAncestorId] = fatherAncestorId;
//     distanceToFather[childAncestorId] = distance+fatherToAncestorDistance;
// }

// int main(){
//     int n,m;
//     cin>>n>>m;
//     for(int i=1;i<=n;i++){
//         father[i]=i;
//         distanceToFather[i]=0;
//     }
//     int answer=0;
//     while(m--){
//         int d,a,b;
//         cin>>d>>a>>b;
//         if(a>n||b>n){
//             answer++;
//             // cout<<"Fake!"<<endl;
//             continue;
//         }
//         auto queryA=QueryAncestor(a);
//         auto queryB=QueryAncestor(b);
//         int aAncestorId = queryA.first;
//         int bAncestorId = queryB.first;
//         int aToAncestorDistance = queryA.second;
//         int bToAncestorDistance = queryB.second;
//         switch(d){
//             case 1:{
//                 if(aAncestorId!=bAncestorId){
//                     Insert(a,b,3);
//                 }else{
//                     if(aToAncestorDistance%3!=bToAncestorDistance%3){
//                         answer++;
//                         // cout<<"Fake!"<<endl;
//                     }
//                 }
//                 break;
//             }
//             case 2:{
//                 if(a==b){
//                     answer++;
//                     // cout<<"Fake!"<<endl;
//                     break;
//                 }
//                 if(aAncestorId!=bAncestorId){
//                     Insert(b,a,1);
//                 }else{
//                     if(bToAncestorDistance-aToAncestorDistance==2){
//                         answer++;
//                         // cout<<"Fake!"<<endl;
//                     }
//                 }
//                 break;
//             }
//         }
//     }
//     cout<<answer<<endl;
//     return 0;
// }
#pragma once
/*
* https://www.acwing.com/problem/content/242/
*/
#include<iostream>
#include<algorithm>
#include <unordered_map>
using namespace std;

int f[50010];
int m_distance[50010];
int n, k;
int find(int x)
{
	if (f[x] == x)return x;
	int x_root = find(f[x]);
	m_distance[x] += m_distance[f[x]];
	f[x] = x_root;
	return f[x];
}
void Solution()
{
	int fake = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		f[i] = i;
	while (k)
	{
		k--;
		int d, x, y;
		cin >> d >> x >> y;

		if (x > n || y > n)
		{
			fake++;
			continue;
		}

		int x_root = find(x), y_root = find(y);
		if (d == 1)
		{
			if (x_root == y_root && (m_distance[x] - m_distance[y]) % 3 != 0)
				fake++;
			else if (x_root != y_root)
			{
				f[x_root] = y_root;
				m_distance[x_root] = m_distance[y] - m_distance[x];
			}
			
		}
		else
		{
			if (x_root == y_root && (m_distance[x] - m_distance[y] - 1) % 3)
				fake++;
			else if (x_root != y_root)
			{
				f[x_root] = y_root;
				m_distance[x_root] = m_distance[y] + 1 - m_distance[x];
			}
		}
	}
	cout << fake;
}
int main()
{
	Solution();
	return 0;
}