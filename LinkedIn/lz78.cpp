#include <iostream>
#include <unordered_map>
#include <vector>
#include <assert.h>

using namespace std;

using pic = pair<int, char>;

string decompress(vector<pic> &compressed) {
    vector<string> v = {""};
    string ans = "";
    for(auto &[id, c]: compressed) {
        string temp = v[id];
        if(c!='#') {
            temp+=c;
            v.push_back(temp);
        }
        ans+=temp;
    }
    return ans;
}

vector<pic> compress(const string& s) {
    int n = s.size();
    if (n == 0) {
        return {};
    }
    vector<pic> ans;
    vector<string> v = {""};
    unordered_map<string, int> mp;  // string -> id
    mp[""] = 0;

    int i = 0;
    while (i < n) {
        // find the longest matching prefix
        int j = i;
        string pref = "";
        pic temp;
        bool foundNew = false;
        while (j < n) {
            temp = {mp[pref], s[j]};
            pref += s[j++];
            if (!mp.count(pref)) {
                foundNew = true;
                break;
            }
        }
        if (foundNew) {
            ans.push_back(temp);
            v.push_back(pref);
            mp[pref] = v.size() - 1;
        } else {
            ans.push_back({mp.at(pref), '#'});
        }

        i = j;
    }
    return ans;
}

int main() {
    string s = "AABBA";
    vector<pic> compressed = compress(s);
    for (auto it : compressed) {
        printf("(%d, %c)\n", it.first, it.second);
    }
    string t = decompress(compressed);
    cout<<"decompressed string = "<<t<<"\n";
    if(s==t) {
        cout<<"matches!";
    }else{
        cout<<"Fail!\n";
    }
}
