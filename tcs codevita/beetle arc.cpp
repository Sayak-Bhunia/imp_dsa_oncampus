#include <bits/stdc++.h>
using namespace std;
#define PIE 3.14
int sx,sy,sz;
float shortDist(int x,int y,int z)
{
    float dist;
    // checking if the Z-axis and any other one axis are the same.
    if(z == sz && ( y == sy || x == sx) && sz != 0) {
    //checking if the x axis of next co-ordinate is same
        if(x != sx){  
        dist = (2 * PIE * (abs(x-sx)))/6.0;
        }
        //checking if the y axis of next co-ordinate is same 
        else
        dist = (2 * PIE * (abs(y-sy)))/6.0;
    }
    //else meaning bee is moving to another face
    else{ 
    // finding eculidean distance between x and y and the abs distance of Z axis
    dist = (int)(sqrt(pow(x-sx,2) + pow(y-sy,2)) + abs(z-sz)); 
    }
    sx = x;sy = y;sz = z;
    return dist;
}
int main()
{
    int n,arr[50],x,y,z;
    float sum = 0.0;
    cin>>n;
    n = 3 * n;
    for(int i = 0;i < n;i++)
    {
        cin>>arr[i];
    }
    sx = arr[0];
    sy = arr[1];
    sz = arr[2];
    for(int i=3;i<n;i+=3)
    {
        sum += shortDist(arr[i],arr[i+1],arr[i+2]);
    }
    printf("%.2f",sum);
} 
