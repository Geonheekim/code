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
	
	set <long long> chk; // �ڵ������� �Ǵ� �迭 (default ��������)  
	
	for (int i = 0; i < n; i++)
	{
	scanf("%lld", &p[i]);
	q.push(-p[i]); // -2 -3 -5 -7
	}
	
	sort(p, p + n);// -7 -5 -3 -2 
	

	
	while (!q.empty())
	{
		long long f = -q.top();  q.pop();//f = ��Ʈ�� top : ū �������  
		
		// printf("t %lld\n", f);
		//->ex -2 -3 -5 -7 -> 2 3 5 7 
		//2 3 4 5 6 7 8 9 10 12 14 15116 18 20 21 24 25 27
		for (int i = 0; i < n; i++) //n = � �Ҽ�����  
		{
			long long v = f * p[i]; //v = ��Ʈ * �Է¼Ҽ�   
			
			if (chk.find(v) == chk.end())//v�� ����Ű�� �ݺ��� ��ȯ  
			{
			
				//printf("v %lld\n", v);
				if (max < v) max = v;
				
				chk.insert(v); //�ڵ� ����(�ߺ��� �ǵ� ���x -> push�� �ѹ��� ���� ����)  
				q.push(-v);
			}
		}
		
		++c;
		
		if (c == k) //k = ���° ��������  
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
	long long v=0; // �ּ� �񱳰�
	int index = 0;//�ּҰ��� ��

	scanf("%d %d", &K, &N);
	
	queue<long long> arr[101];
	
	for (int i = 0; i < K; i++)//���� 
	{
		scanf("%d", &a);
		arr[i].push(a);   
		result[i] = a;
	}

	for (int i = 0; i < N; i++)//�ڸ��� 
	{
		// �ּҰ� ���ؼ� ���� ������
		v = 9999999999999999;
		index = 0;
		 
		for (int j = 0; j < K; j++) //���� 
		{
			
			long long temp=0;
			
			//if (!arr[j].empty())
			temp = arr[j].front();
			//else
			//	temp = 9999999999999999;
				
			printf("%lld\n", temp);
			// ������ ã�� - �ּҰ�

			if (v > temp) 
			{
				v = temp;
				index = j;
			} // k ���� ��ŭ ���鼭 �ּҰ� ã�� ��, �ּҰ��� Ʈ���� �� ���� �ø��� ����
		}
		printf("\n");
		//���ο� �� �߰��ϰ�
		for (int c = 0; c < K; c++) //����
		{
			if(c == index)//�ּҰ��̸� ���� �߰�  
			{ 
				arr[c].pop();
				arr[c].push(v*result[c]);
			}
			else if (c > index)//�ּҰ��� �ƴϸ� �׳� �߰�  
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
 	long long cmp = 0; // �ּ� �񱳰�
	int index = 0;//�ּҰ��� ��
	long long temp=0;

	scanf("%d %d", &n, &k);

	for(int i = 0; i<k;i++)
	{
		scanf("%d", &a);
		pq[i].push(a);   
		data[i] = a;
	}

	for(int i = 0; i < n; i++)//�Է� 4�� 
	{
		// �ּҰ� ���ؼ� ���� ������
		cmp = 99999;
		index = 0;
		
		for (int j = 0; j < k; j++)//k��° ����  
		{
			temp=0;
			
			if (!pq[j].empty())//������� �ʴٸ�  
				temp = pq[j].front();
			else//����ִٸ�  
				temp = 99999;
				
			printf("%lld\n", temp);
			
			// ������ ã�� - �ּҰ�
			if (cmp > temp) 
			{
				cmp = temp;
				index = j;
			}
			// k ���� ��ŭ ���鼭 �ּҰ� ã�� ��, �ּҰ��� Ʈ���� �� ���� �ø��� ����
		}
		printf("\n");
	
		//���ο� �� �߰�
		for (int c = 0; c < k; c++)
		{
			if (c == index) 
			{
			 // �ּҰ��� �´ٸ� ���ο �߰�
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

