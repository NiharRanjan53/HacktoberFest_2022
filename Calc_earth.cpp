#include<bits/stdc++.h>
using namespace std;
int calculate_earth_minutes(int minutes, int second){
    int earthTime = 0;
    
    int totalSec = minutes * second;

    return ceil((float)totalSec/60);

    //return earthTime;  

}
int main(){

    cout << calculate_earth_minutes(1000, 20);

    return 0;
}