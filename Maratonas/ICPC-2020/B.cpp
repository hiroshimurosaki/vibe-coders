#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n;
    cin >> n;
    set<pair<int, int>> barcos;

    while (n--)
    {

        int d, l, r, c;
        cin >> d >> l >> r >> c;

        if (d)
        {   
            if (r + l - 1 > 10)
            {
                cout << "N" << endl;
                return 0;
            }
            else
            {
                for (int i = r; i <= r + l - 1; i++)
                {
                    if (!barcos.count({i, c}))
                    {

                        barcos.insert({i, c});
                    }
                    else
                    {
                        cout << "N" << endl;
                        return 0;
                    }
                }
            }
        }
        else
        {
            if (c + l - 1 > 10)
            {
                cout << "N" << endl;
                return 0;
            }
            else
            {
                for (int i = c; i <= c + l - 1; i++)
                {
                    if (!barcos.count({r, i}))
                    {   
                        barcos.insert({r, i});
                    }
                    else
                    {
                        cout << "N" << endl;
                        return 0;
                    }
                }
            }
        }

    }
    cout << "Y" << endl;
    return 0;
}