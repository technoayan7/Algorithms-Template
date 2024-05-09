#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> zfunc(string str)
{
    int n = str.size();
    int l = 0, r = 0;
    vector<int> z(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (i > r)
        {
            l = r = i;
            while (r < n && str[r] == str[r - l])
            {
                r++;
            }
            z[i] = r - l;
            r--;
        }
        else
        {
            int idx = i - l;
            if (i + z[idx] <= r)
            {
                z[i] = z[idx];
            }
            else
            {
                l = i;
                while (r < n && str[r] == str[r - l])
                {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
        }
    }
    return z;
}

vector<int> search(string pat, string txt)
{
    vector<int> ans;
    string str = pat + "#" + txt;
    vector<int> z = zfunc(str);
    for (int i = 0; i < z.size(); i++)
    {
        if (z[i] == pat.size())
        {
            ans.push_back(i - pat.size());
        }
    }
    return ans;
}

int main()
{
    string txt = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    vector<int> result = search(pat, txt);
    if (result.empty())
    {
        cout << "Pattern not found in text." << endl;
    }
    else
    {
        cout << "Pattern found at positions: ";
        for (int i = 0; i < result.size(); i++)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
