#include <iostream>
using namespace std;

bool ok(int pro[], int col) {
    // mp means Men’s Preference
    int mp[3][3] = {{0, 2, 1},// mp[0][0] most, mp[0][2] mid, mp[0][1] least

                    {0, 2, 1},// mp[1][0] most, mp[1][2] mid, mp[1][1] least

                    {1, 2, 0} };//mp[2][2] most, mp[2][0] mid, mp[2][1] least

    // wp means Woman’s Preferences
    int wp[3][3] = {{2, 1, 0},//wp[0][2] most, wp[0][1] mid, wp[0][0] least

                    {0, 1, 2},//wp[1][0] most, wp[1][1] mid, wp[1][2] least

                    {2, 0,  1} };//wp[2][1] most, wp[2][2] mid, wp[2][0] least

    for(int i = 0; i < col; i++) {
        // Condition 1
        // If the woman is pared to two different men, return false;
        if(pro[col] == pro[i]) {
            return false;
        }
        // Condition 2
        // If man_i and man_c's wife like each other more than their own spouses, return false
        if((mp[i][pro[col]] < mp[i][pro[i]]) && (wp[pro[col]][i] < wp[pro[i]][i])) {
            return false;
        }
        // Condition 3
        // If man_c and man_i's wife like each other more than their own spouses, return false
        if((mp[col][pro[i]] < mp[col][pro[col]]) && (wp[pro[i]][col] < wp[pro[i]][i])) {
            return false;
        }
    }
    return true;
}

void print(int q[]) {
    static int solution = 0;
    cout << "Solution # " << ++solution << ":\nMan \tWoman\n";
    for(int i =0; i < 3; i++) {
        cout << i << "       " << q[i] << endl;
    }
}

int main() {
    int pairs[3], c = 0; // Initialization
    pairs[c] = 0; //Initialization

    while(c >= 0) {
        c++; // Moves to next index
        if (c > 2) {
            print(pairs); // If it goes over the index, print
            c--; // and backtrack
        }
        else {
            pairs[c] = -1; //start over
        }
        while(c >= 0) {
            pairs[c]++; // Move to next value
            if(pairs[c] > 2) { // If it goes over the value
                c--; // backtrack
            }
            else {
                if(ok(pairs, c)) {
                    break;
                }
            }
        }
    }
    return 0;
}