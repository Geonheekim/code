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

