#include<vector>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<map>
#include"numcpp.h"
using namespace std;
class balltree{
private:
    struct node{
        vector<float> val;
        node*fa;
        node*left;
        node*right;
        float r;
        int tag;
        node(const vector<float>&val,int tag):val(val),tag(tag){left=right=fa=NULL;}
    };
    map<int,int>count;
    node*root;
    node* build(const vector<vector<float>>&vals,const vector<int>&tags){
        if(vals.size()==0)return NULL;
        if(vals.size()==1){
            return new node(vals[0],tags[0]);
        }
        vector<float>mx=max(vals);
        vector<float>mn=min(vals);
        int c=0;//获取最宽的维度
        for(int i=1;i<mx.size();++i){
            if(mx[i]-mn[i]>mx[c]-mn[c]){
                c=i;
            }
        }
        float midPosition=(mx[c]+mn[c])/2;
        int midPoint=0;//获取中心点
        for(int i=1;i<vals.size();++i){
            if(fabs(midPosition-vals[midPoint][c])>fabs(midPosition-vals[i][c])){
                midPoint=i;
            }
        }
        vector<vector<float> >leftvals,rightvals;//分割
        vector<int>lefttags,righttags;
        for(int i=0;i<vals.size();++i){
            if(i==midPoint)continue;
            if(vals[i][c]<=vals[midPoint][c]){
                leftvals.push_back(vals[i]);
                lefttags.push_back(tags[i]);
            }else{
                rightvals.push_back(vals[i]);
                righttags.push_back(tags[i]);
            }
        }
        node* nowPoint=new node(vals[midPoint],tags[midPoint]);
        nowPoint->left=build(leftvals,lefttags);
        nowPoint->right=build(rightvals,righttags);
        if(nowPoint->left)nowPoint->left->fa=nowPoint;
        if(nowPoint->right)nowPoint->right->fa=nowPoint;
        nowPoint->r=0;
        for(auto it:vals){
            nowPoint->r=max(nowPoint->r,len(it-vals[midPoint]));
        }
        return nowPoint;
    }
    void getkth(node*rt,const vector<float>&point,vector<vector<float> >&kthvals,vector<int>&kthtags,int k){
        if(kthvals.size()<k){
            kthvals.push_back(rt->val);
            kthtags.push_back(rt->tag);
        }else{
            vector<float> now=rt->val;
            int nowtag=rt->tag;
            for(int i=0;i<k;++i){
                if(len(now-point)<len(kthvals[i]-point)){
                    swap(now,kthvals[i]);
                    swap(nowtag,kthtags[i]);
                }
            }
        }
        float mindis=len(kthvals[0]-point);
        for(auto it:kthvals)mindis=min(mindis,len(it-point));
        if(rt->left)if(kthvals.size()!=k||len(rt->left->val-point)-rt->r<=mindis)getkth(rt->left,point,kthvals,kthtags,k);
        if(rt->right)if(kthvals.size()!=k||len(rt->right->val-point)-rt->r<=mindis)getkth(rt->right,point,kthvals,kthtags,k);
    }
    //归一化部分
    vector<float>mx,mn;
public:
    balltree(vector<vector<float>>vals,const vector<int>&tags){
        for(auto it:tags)count[it]++;
        mx=max(vals);
        mn=min(vals);
        vals=(vals-mn)/(mx-mn);
        root=build(vals,tags);
    }
    void findkth(const vector<float>&point,int k,vector<vector<float> >&kthvals,vector<int>&kthtags){
        getkth(root,point,kthvals,kthtags,k);
    }
    int predict(vector<float>point,int k){
        point=(point-mn)/(mx-mn);
        vector<vector<float> >kthvals;
        vector<int>kthtags;
        getkth(root,point,kthvals,kthtags,k);
        // cout<<point<<" begin"<<endl;
        // for(int i=0;i<k;++i)cout<<kthvals[i]<<" "<<kthtags[i]<<" "<<len(kthvals[i]-point)<<endl;
        // cout<<"end"<<endl;
        float a[2]={0,0};
        for(int i=0;i<k;++i)a[kthtags[i]]+=1.0/(count[kthtags[i]]);
        return a[1]>a[0];
    }
};