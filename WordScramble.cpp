//
//  main.cpp
//  Word Scramble
//
//  Created by lisading on 10/26/14.
//  Copyright (c) 2014 lisading. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    stack<char> s;
    string line;
    while (getline(cin, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] != ' ')
            {
                s.push(line[i]);
            }
            else
            {
                while (!s.empty())
                {
                    cout << s.top();
                    s.pop();
                }
                cout << ' ';
            }
        }
        while (!s.empty())
        {
            cout << s.top();
            s.pop();
        }
        cout << endl;
    }
}
