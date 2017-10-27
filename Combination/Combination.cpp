// AllSubSets.cpp : Defines the entry point for the console application.
/*
Given two integers n and k, return all possible combinations of k numbers out of 1 2 3 ... n.

Make sure the combinations are sorted.

To elaborate,

Within every entry, elements should be sorted. [1, 4] is a valid entry while [4, 1] is not.
Entries should be sorted within themselves.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

bool compare(int a, int b) { return a > b; }

void subset_util(vector<int> &curr_sol, int i, int N, int K, vector<vector<int> > &sol_set)
{
	if (curr_sol.size() == K) //We have considered K numbers
	{
		sol_set.push_back(curr_sol);
		return;
	}

	if (i > N) return;

	//take ith num
	curr_sol.push_back(i);
	subset_util(curr_sol, i+1, N, K, sol_set);

	//or Dont take (n)th item
	curr_sol.pop_back();
	subset_util(curr_sol, i+1, N, K, sol_set);


}

void print_All_SubSets(int N, int K, vector<vector<int> > &sol_set)
{
	vector<int> currSol;
	subset_util(currSol, 1, N, K, sol_set);
}

void print_solution(vector<vector<int> > &sol_set)
{
	for (int i = 0; i < sol_set.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < sol_set[i].size(); j++)
		{
			cout << sol_set[i][j] << ",";
		}
		cout << "]" << endl;
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	
	vector<vector<int> > sol_set;

	print_All_SubSets(n, k,  sol_set);

	sort(sol_set.begin(), sol_set.end());

	print_solution(sol_set);
	return 0;
}

