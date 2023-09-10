


// #include <iostream>
// #include <vector>
// #include <math.h>


// int recursion(std::vector<std::vector<int>>& triangle, int i, int j, int curr_val, int minimum){
//     if (i >= triangle.size()){
//         minimum = std::min(minimum, curr_val);
//         return minimum;
//     }

//     if (j < triangle[i].size()){
//         int minimum1 = recursion(triangle, i+1, j, curr_val+triangle[i][j], minimum);
//     }
//     if (j < triangle[i].size()){
//         int minimum2 = recursion(triangle, i+1, j+1, curr_val+triangle[i][j+1], minimum);
//     }
//     return std::min(minimum1, minimum2);
// }

// int minimumTotal(std::vector<std::vector<int>>& triangle) {
//     return recursion(triangle, 0, 0, 0, INT_MAX);
// }

// int main(){
//     int n;
//     std::cin>>n;
//     std::vector<std::vector <int>> triangle;

//     for (int i = 0; i < n; i++){
//         std::vector<int> temp;
//         for (int j = 0; j < i+1; j++){
//             int val;
//             std::cin>>val;
//             temp.push_back(val);
//         }
//         triangle.push_back(temp);
//     }
//     int res = minimumTotal(triangle);
//     std::cout<<"Final Answer - "<<res;
//     return 0;
// }



#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    int minimum = INT_MAX;

    void recursion(vector<vector<int>>& triangle, int i, int j, int curr_val){
        if (i >= triangle.size()){
            minimum = min(minimum , curr_val);
            return;
        }
        
        if (j < triangle[i].size()){
            recursion(triangle, i+1, j, curr_val+triangle[i][j]);
        }
        if (j+1 < triangle[i].size()){
            recursion(triangle, i+1, j+1, curr_val+triangle[i][j+1]);
        }
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        recursion(triangle, 0, 0, 0);
        return minimum;
    }
};

int main() {
    Solution solution;

    int numRows;
    cout << "Enter the number of rows in the triangle: ";
    cin >> numRows;

    vector<vector<int>> triangle;
    cout << "Enter the triangle values row by row:" << endl;
    for (int i = 0; i < numRows; i++) {
        vector<int> row(i + 1);
        for (int j = 0; j <= i; j++) {
            cin >> row[j];
        }
        triangle.push_back(row);
    }

    int result = solution.minimumTotal(triangle);

    cout << "Minimum path sum in the triangle: " << result << endl;

    return 0;
}
