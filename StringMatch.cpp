#include <string>
#include <vector>
using namespace std;
//�ַ���ƥ���㷨

// ���ص��ַ���ƥ���㷨
static int NaiveMartch(string str1, string str2) {
    int len1 = str1.length();
    int len2 = str2.length();
    if (len1 < len2) {
        return -1;
    }
    for (int i = 0; i < len1; i++)
    {
        int j = 0;
        for (j = 0; j < len2; j++) {
            if (str1.at(i+j) != str2.at(j))
            {
                break;
            }
        }
        if (j == len2)
        {
            return i;
        }
    }
    return -1;
}

static void getNext(vector<int>& next, string str2);
// KMP�㷨
static int kmp(string str1, string str2) {
    vector<int> next(str2.size(), -1);
    getNext(next, str2);
    int i = 0, j = 0;
    for ( ;i < str1.size()&&j<str2.size(); )
    {
        if (str1[i] == str2[j]) {
            i++;
            j++;
        }
        else if (next[j] == -1) {
            i++;
            j = 0;
        }
        else {
            j = next[j];
        }
    }
    if (j >= str2.size()) {
        return i - str2.size();
    }
    return -1;
}
void getNext(vector<int>& next, string str2)
{
    int j = -1;
    next[0] = j;
    for (int i = 0; i < str2.size()-1;)
    {
        while (j >= 0 && str2[i] != str2[j])
        {
            j = next[j];
        }
        j++;
        i++;
        if (str2[i]==str2[j])
        {
            next[i] = next[j];
        }
        else {
            next[i] = j;
        }
    }
}
// BM�㷨

// Sunday�㷨
