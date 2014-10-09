//
//  main.cpp
//  Magic Square
//
//  Created by lisading on 10/9/14.
//  Copyright (c) 2014 lisading. All rights reserved.
//




#include <iostream>

using namespace std;

// To create a magic square of size n; n is odd.
void Magic(const int n);
int main()
{
    int n;
    cout << "Please enter an odd integer: ";
    cin >> n;
    Magic (n);
    return 0;
}

void Magic (const int n)
{
    const int Maxsize = 100; //maximum square size
    int square[Maxsize][Maxsize];
    
    //check the correctness of n
    if ((n > Maxsize)||(n < 1))
        throw "Error! n out of range";
    else if (!(n % 2))
        throw "Error! n is even";
    
    //initialize square to 0
    int i, j;
    for (i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            square[i][j] = 0;
    
    int key = 2; //key is the number in the square
    i = 0; j = (n-1)/2; //i and j are current position
    square[i][j] = 1; //number in middle of first row is 1
    
    int k, l;
    while (key <= n*n)
    {//using Coxeter's rule: move up and left
        
        if (i-1 < 0) k = n-1; else k = i-1;
        if (j-1 < 0) l = n-1; else l = j-1;
        
        if (!square[k][l])
        {i = k; j = l;} //square is unoccupied
        else i = (i+1) % n; //square is occupied, move down
        
        square[i][j] = key;
        key++;
    }
    
    //output the magic square
    for(i = 0; i < n; i++)
    {
        for(j = 0;j < n; j++)
            cout << square[i][j] << ' ';
        cout<<endl;
    }
}

