#include<iostream>
#include<string>
#include"File.h"
#include"iostreampp.h"
#include"numcpp.h"
#include"balltree.h"
// #include"train_test_split.h"
using namespace std;
int main(){
    vector<vector<float> >data,train_vals,test_vals,train,test;
    vector<int>train_tags,test_tags;
    CSVFile file=CSVFile("heart.csv");
    file.pop_front();
    for(auto line:file){
        vector<float>l;
        for(auto it:line){
            l.push_back(atof(it.c_str()));
        }
        data.push_back(l);
    }
    Tools::train_test_split(data,train,test,0.2);
    for(auto it:train){
        train_vals.push_back(range(it,0,-1));
        train_tags.push_back(*(--it.end()));
    }
    for(auto it:test){
        test_vals.push_back(range(it,0,-1));
        test_tags.push_back(*(--it.end()));
    }
    balltree bt(train_vals,train_tags);
    int ac=0,k=4;
    for(int i=0;i<test_vals.size();++i){
        int predicttag=bt.predict(test_vals[i],k);
        if(predicttag==test_tags[i])ac++;
    }
    cout<<k<<"nn算法的准确率："<<1.0*ac/test_vals.size()<<endl;
    return 0;
}