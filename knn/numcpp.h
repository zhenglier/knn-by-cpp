#ifndef NUMCPP
#define NUMCPP

#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
//vector之间的运算
template<typename T>
vector<T> operator +(const vector<T>&a,const vector<T>&b){
    vector<T>ret;
    if(a.size()!=b.size()){
        cerr<<"Out of range!"<<endl;
        return ret;
    }
    for(int i=0;i<a.size();++i){
        ret.push_back(a[i]+b[i]);
    }
    return ret;
}
template<typename T>
vector<T> operator -(const vector<T>&a,const vector<T>&b){
    vector<T>ret;
    if(a.size()!=b.size()){
        cerr<<"Out of range!"<<endl;
        return ret;
    }
    for(int i=0;i<a.size();++i){
        ret.push_back(a[i]-b[i]);
    }
    return ret;
}
template<typename T>
vector<T> operator *(const vector<T>&a,const vector<T>&b){
    vector<T>ret;
    if(a.size()!=b.size()){
        cerr<<"Out of range!"<<endl;
        return ret;
    }
    for(int i=0;i<a.size();++i){
        ret.push_back(a[i]*b[i]);
    }
    return ret;
}
template<typename T>
vector<T> operator /(const vector<T>&a,const vector<T>&b){
    vector<T>ret;
    if(a.size()!=b.size()){
        cerr<<"Out of range!"<<endl;
        return ret;
    }
    for(int i=0;i<a.size();++i){
        ret.push_back(a[i]/b[i]);
    }
    return ret;
}
template<typename T>
vector<T> max(const vector<T>&a,const vector<T>&b){
    vector<T>ret;
    if(a.size()!=b.size()){
        cerr<<"Out of range!"<<endl;
        return ret;
    }
    for(int i=0;i<a.size();++i){
        ret.push_back(max(a[i],b[i]));
    }
    return ret;
}
template<typename T>
vector<T> min(const vector<T>&a,const vector<T>&b){
    vector<T>ret;
    if(a.size()!=b.size()){
        cerr<<"Out of range!"<<endl;
        return ret;
    }
    for(int i=0;i<a.size();++i){
        ret.push_back(min(a[i],b[i]));
    }
    return ret;
}
//vector内获取最大/最小/和
template<typename T>
T max(const vector<T>&a){
    if(a.size()==0)return T();
    T ret=a[0];
    for(auto it:a){
        ret=max(ret,it);
    }
    return ret;
}
template<typename T>
T min(const vector<T>&a){
    if(a.size()==0)return T();
    T ret=a[0];
    for(auto it:a){
        ret=min(ret,it);
    }
    return ret;
}
template<typename T>
T sum(const vector<T>&a){
    T sum=T();
    for(auto i:a)sum=sum+i;
    return sum;
}
//vector内元素批量运算
template<typename T>
vector<T> operator +(const vector<T>&a,const T&val){
    vector<T>ret;
    for(auto it:a)ret.push_back(it+val);
    return ret;
}
template<typename T>
vector<T> operator -(const vector<T>&a,const T&val){
    vector<T>ret;
    for(auto it:a)ret.push_back(it-val);
    return ret;
}
template<typename T>
vector<T> operator *(const vector<T>&a,const T&val){
    vector<T>ret;
    for(auto it:a)ret.push_back(it*val);
    return ret;
}
template<typename T>
vector<T> operator /(const vector<T>&a,const T&val){
    vector<T>ret;
    for(auto it:a)ret.push_back(it/val);
    return ret;
}

//特殊运算
//归一化
template<typename T>
vector<T>normalize(const vector<T>&a){
    return (a-min(a))/(max(a)-min(a));
}
//取模长
float len(const vector<float>&a){
    return sqrt(sum(a*a));
}
//获取vector的一部分
template<typename T>
vector<T> range(vector<T>v,int l=0,int r=2147483647){
    if(l<0)l=v.size()+l;
    if(r<0)r=v.size()+r;
    r=min(r,int(v.size()));
    if(l>=r)return vector<T>();
    return vector<T>(v.begin()+l,v.begin()+r);
}

#endif