#include<iostream>
#include<vector>
#include<fstream>
// #include<any>
#include"Tools.h"
using namespace std;
template<typename T>
class File{
protected:
    vector<T>data;
};

class CSVFile:public File<vector<string> >{
public:
    explicit CSVFile(const string&url){
        ifstream in(url.c_str());
        if(!in){
            cerr<<"File "<<url<<" can't be found!"<<endl;
            return;
        }
        string line;
        while(getline(in,line)){
            data.push_back(Tools::split(line,','));
        }
    }
    void pop_front(){
        if(data.empty())return;
        data.erase(data.begin());
    }
    vector<vector<string> >::iterator begin(){
        return data.begin();
    }
    vector<vector<string> >::iterator end(){
        return data.end();
    }
};

