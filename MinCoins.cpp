#include <bits/stdc++.h> 
int findMinimumCoins(int amount) 
{
    // Write your code here
    int coins[9];
    coins[0] = 1;
    coins[1] = 2;
    coins[2] = 5;
    coins[3] = 10;
    coins[4] = 20;
    coins[5] = 50;
    coins[6] = 100;
    coins[7] = 500;
    coins[8] = 1000;
    // coins = {1, 2, 5, 10, 20, 50, 100, 500, 1000};
    int req=0;
    int j=8;
    while(amount!=0 && j>=0)
    {
        if(amount>=coins[j])
        {
            int temp=amount/coins[j];
            req+=temp;
            amount-=temp*coins[j];
            if(amount==0)
            break;
        }
        j--;
    }
    return req;
}
