#include <iostream>

using namespace std;

string str;
int zindex[1000001];
int maxx=0;
int pos=0;
int ans[1000001];
int ans2[1000001];

int mins(int a, int b)
{
    if(a<b)
        return a;
    return b;
}

//For problem "password" codeforces, zindex box method to calculate length of prefix that a substring is.

int main()
{
    cin >> str;
    int starts=0;
    int ends=0,i;
    zindex[0]=str.length();
    for(i=1;i<str.length();i++)
    {
        if(i<=ends)
        {
            int val=i-starts;
            if(zindex[val]<=ends-i-1) //Its within the box, so the prefix of str is starts to ends, and i is in this range, and the zindex of the value calculated at the position i-starts is the value of this one as well, since the substring here is just a copy of the prefix of str.
                zindex[i]=zindex[val];
            else //If the zindex[val]>ends-i-1 then we cant say if the value of this zindex is that or not, as the string here is a copy of only till ends-i-1, of the prefix of str, so now we move ends forward. Since zindex[val]>ends-i-1, that means from i till ends is a prefix of str, so we can put starts at i and then move ends until we get the complete possible prefix and update zindex[i].
            {
                starts=i;
                while(str[ends-starts]==str[ends])
                    ends++;
                ends--;
                zindex[i]=ends-starts+1;
            }
        }
        else //Our index is out of range, so we calculate the zindex again starting from this index.
        {
            starts=i;
            ends=i;
            while(str[ends-starts]==str[ends])
                ends++;
            ends--;
            zindex[i]=ends-starts+1;
        }
    }
    for(i=0;i<str.length();i++)
	cout << zindex[i] << " ";
    cout << endl;
    return 0;
}
