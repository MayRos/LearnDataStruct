#include <string>
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

// KMP�㷨
static int kmp(string str1, string str2) {

}
// BM�㷨

// Sunday�㷨
