#pragma once

#include<vector>
#include<string>
#include<iostream>
#include<chrono>
#include<ctime>
#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <bits/stdc++.h>

#include"history.hpp"
#include"dirs.hpp"

using namespace std;

class Handler{
	public:
		Handler();
		int handle(vector<string>);
	private:
		History history;
		Dirs dirs;
		double ptime;

		string vstos(vector<string>);
		string cwd();
};
