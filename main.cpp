#include <stdio.h>
#include <queue>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
	long long p[50];
	long long max = 0;
	int n, k;
	int c = 0;
	scanf("%d %d", &n, &k);
	
	priority_queue <long long> q;
	
	set <long long> chk; // 자동정렬이 되는 배열 (default 오름차순)  
	
	for (int i = 0; i < n; i++)
	{
	scanf("%lld", &p[i]);
	q.push(-p[i]); // -2 -3 -5 -7
	}
	
	sort(p, p + n);// -7 -5 -3 -2 
	

	
	while (!q.empty())
	{
		long long f = -q.top();  q.pop();//f = 루트값 top : 큰 순서대로  
		
		// printf("t %lld\n", f);
		//->ex -2 -3 -5 -7 -> 2 3 5 7 
		//2 3 4 5 6 7 8 9 10 12 14 15116 18 20 21 24 25 27
		for (int i = 0; i < n; i++) //n = 몇개 소수인지  
		{
			long long v = f * p[i]; //v = 루트 * 입력소수   
			
			if (chk.find(v) == chk.end())//v를 가리키는 반복자 반환  
			{
			
				//printf("v %lld\n", v);
				if (max < v) max = v;
				
				chk.insert(v); //자동 정렬(중복이 되도 상관x -> push는 한번만 들어가기 때문)  
				q.push(-v);
			}
		}
		
		++c;
		
		if (c == k) //k = 몇번째 숫자인지  
		{
			printf("%lld\n", f);
			break;
		}
	
	}
}

/*

#include<iostream>
#include<queue>
#include<cstdio>

using namespace std;

int main() {
	int K, N;
	int result[101]= {0,};
	int a;
	long long v=0; // 최소 비교값
	int index = 0;//최소값인 곳

	scanf("%d %d", &K, &N);
	
	queue<long long> arr[101];
	
	for (int i = 0; i < K; i++)//갯수 
	{
		scanf("%d", &a);
		arr[i].push(a);   
		result[i] = a;
	}

	for (int i = 0; i < N; i++)//자리수 
	{
		// 최소값 비교해서 먼저 보내고
		v = 9999999999999999;
		index = 0;
		 
		for (int j = 0; j < K; j++) //갯수 
		{
			
			long long temp=0;
			
			//if (!arr[j].empty())
			temp = arr[j].front();
			//else
			//	temp = 9999999999999999;
				
			printf("%lld\n", temp);
			// 나갈값 찾기 - 최소값

			if (v > temp) 
			{
				v = temp;
				index = j;
			} // k 개수 만큼 돌면서 최소값 찾기 즉, 최소값을 트리의 맨 위로 올리는 느낌
		}
		printf("\n");
		//새로운 값 추가하고
		for (int c = 0; c < K; c++) //갯수
		{
			if(c == index)//최소값이면 빼고 추가  
			{ 
				arr[c].pop();
				arr[c].push(v*result[c]);
			}
			else if (c > index)//최소값이 아니면 그냥 추가  
				arr[c].push(v*result[c]);
		
		}
	}
	printf("%lld\n", v);
	return 0;
}
*/

/*
#include <iostream>
#include <queue> 
#include <set> 
#include <vector> 
#include <algorithm> 
#include <cstdio>


using namespace std; 

long long data[101]; 
queue <long long> pq[101];

int main()
{ 
	int n, k, a;
 	long long cmp = 0; // 최소 비교값
	int index = 0;//최소값인 곳
	long long temp=0;

	scanf("%d %d", &n, &k);

	for(int i = 0; i<k;i++)
	{
		scanf("%d", &a);
		pq[i].push(a);   
		data[i] = a;
	}

	for(int i = 0; i < n; i++)//입력 4개 
	{
		// 최소값 비교해서 먼저 보내고
		cmp = 99999;
		index = 0;
		
		for (int j = 0; j < k; j++)//k번째 까지  
		{
			temp=0;
			
			if (!pq[j].empty())//비어있지 않다면  
				temp = pq[j].front();
			else//비어있다면  
				temp = 99999;
				
			printf("%lld\n", temp);
			
			// 나갈값 찾기 - 최소값
			if (cmp > temp) 
			{
				cmp = temp;
				index = j;
			}
			// k 개수 만큼 돌면서 최소값 찾기 즉, 최소값을 트리의 맨 위로 올리는 느낌
		}
		printf("\n");
	
		//새로운 값 추가
		for (int c = 0; c < k; c++)
		{
			if (c == index) 
			{
			 // 최소값이 맞다면 새로운값 추가
				pq[c].pop();
				pq[c].push(cmp*result[c]);
			}
			else if (c > index)
				pq[c].push(cmp*result[c]);
		}
	}
	    
	printf("%lld\n", cmp);
	return 0;
}
*/




/*
   	set <long long> chk;  
    
	for (int i = 0; i < n; i++)
	{ 
		scanf("%lld", &p[i]);
		q.push(-p[i]); 
	} 
	
	sort(p, p + n);
	
	ll max = 0; 
	int c = 0;
	 
	while (!q.empty())
	{
	   ll f = -q.top(); q.pop();
	   ++c;
	   if(c == k)
	   { 
		 printf("%lld\n", f);
		 break;
	   } 
		   
	   for (int i = 0; i < n; i++)
	 	{
		    ll v = f * p[i];
			if (q.size() > (k-c) && max < v)
			{
				 break;
			} 
	
			if (chk.find(v) == chk.end())
			{ 
			   if (max < v)	max = v;
			    chk.insert(v);
				q.push(-v);
			} 
		} 
	}
	
	*/

