#include<iostream>
#include<vector>
using namespace std;
///这里的next求解实际上还是一个模式匹配问题，推荐直接背代码
void getNext(string & t,vector<int>&next){
    int j=0;next[j]=0;
    for(int i=1;i<t.size();i++){
        while(j>0&&t[i]!=t[j]){j = next[j-1];}
        if(t[i]==t[j]){j++;}
        next[i] = j;
    }
}
vector<int> KMP(string &a,string &b){
    vector<int>next(b.size(),0);
    vector<int>result;
    getNext(b,next);
    int j=0;
    for(int i=0;i<a.size();i++){
        while(j>0&&a[i]!=b[j]){j = next[j-1];}
        if(a[i]==b[j])j++;
        if(j==b.size()){
            result.push_back(i-j+1);
            j = next[j-1];
        }
    }
    return result;
}
int main(){
    string s, p;
    cout << "输入文本串: ";
    cin >> s;
    cout << "输入模式串: ";
    cin >> p;
    vector<int> positions = KMP(s, p);
    if (positions.empty()) {
        cout << "未找到匹配" << endl;
    } else {
        cout << "匹配位置: ";
        for (int pos : positions) {
            cout << pos << " ";
        }
        cout << endl;
    }
    return 0;
    return 0;
}
