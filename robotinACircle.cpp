// https://leetcode.com/problems/robot-bounded-in-circle/

#include <bits/stdc++.h>
using namespace std;

// Observations:
// 1. try simulating the testcases in all possible directions. i.e. NSEW.
// 2. it will be found that if dir == North after performing all moves then the ans will be false since the robot is never going to come back.
// 3. else if dir != North then the ans will always be true. try simulating once again to confirm.

bool isRobotBounded(string inss) {
        
    int x = 0, y = 0;
    char dir = 'N';
    for(auto ins: inss){
        if(ins == 'G'){
            if(dir == 'N') y++;
            else if(dir == 'S') y--;
            else if(dir == 'E') x++;
            else if(dir == 'W') x--;
        }
        
        else if(ins == 'L'){
            if(dir == 'N') dir = 'W';
            else if(dir == 'S') dir = 'E';
            else if(dir == 'E') dir = 'N';
            else if(dir == 'W') dir = 'S';
        }
        else if(ins == 'R'){
            if(dir == 'N') dir = 'E';
            else if(dir == 'S') dir = 'W';
            else if(dir == 'E') dir = 'S';
            else if(dir == 'W') dir = 'N';
        }
        
    }
    
    // checks:
    if(x == 0 and y == 0) return true;
    else if(dir == 'N') return false;
    
    return true;
    
}

int main(){
    
    return 0;
}