
#include<iostream>
using namespace std;

int main(){
    int n = 10;
    cout<<"Pre-decrement - ";
    for (int i = n-1; i >= 0; --i){
        cout<<i<<"\t";
    }
    cout<<"\nPost-decrement - ";
    for (int i = n-1; i >= 0; i--){
        cout<<i<<"\t";
    }
    return 0;
}


// Output - Pre-decrement - 9       8       7       6       5       4       3       2       1       0
//          Post-decrement - 9      8       7       6       5       4       3       2       1       0

// Note - Both pre-increment/ decrement gives the same result in loop condition because the flow of control works roughly like this :
//  1. test the condition
//  2. if it is false, terminate
//  3. if it is true, execute the body
//  4. execute the incrementation step
//  Because (1) and (4) are decoupled, either pre- or post-increment can be used.

//  * After evaluating i-- or --i, the new value of i will be the same in both cases. The difference between pre- and post-increment/decrement 
//    is in the result of evaluating the expression itself.

// ++i increments i and evaluates to the new value of i.

// i++ evaluates to the old value of i, and increments i.