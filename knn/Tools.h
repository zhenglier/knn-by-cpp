#ifndef TOOLS
#define TOOLS

#include<cstring>
#include<vector>
#include<iostream>
#include<sstream>
#include<random>
using namespace std;
namespace Tools {
    vector<string> split(const string &s, char c) {//将字符串s以c为分隔符分割为字符串向量
        vector<string> tokens;
        string token;
        istringstream in(s);
        while (getline(in, token, c))tokens.push_back(token);
        return tokens;
    }
    template<typename T>
    void train_test_split(const vector<T>&data,vector<T>&train,vector<T>&test,float test_percent){
        vector<T>ls(data);
        int all_size=data.size();
        int train_size=all_size*test_percent;
        int test_size=all_size-train_size;
        shuffle(ls.begin(),ls.end(),default_random_engine(time(0)));
        train=vector<T>(ls.begin(),ls.begin()+train_size);
        test=vector<T>(ls.begin()+train_size,ls.end());
    }
}

#endif
