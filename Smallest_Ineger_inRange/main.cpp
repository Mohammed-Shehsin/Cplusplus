/*
 *
 *
 *
 * Write a function:
 "int solution(vector<int> &A);"

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
For example,
"given A = [1, 3, 6, 4, 1, 2], the function should return 5."
"Given A = [1, 2, 3], the function should return 4."
"Given A = [−1, −3], the function should return 1."

Write an efficient algorithm for the following assumptions:
1.N is an integer within the range [1..100,000];
2.each element of array A is an integer within the range [−1,000,000..1,000,000].


*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solution(std::vector<int> &A) {
    sort(A.begin(), A.end());
    int smallest = 1;
    for (auto x : A) {
        if (x > 0 && x == smallest) {
            smallest++;
        } else if (x > 0 && x > smallest) {
            break;
        }
    }
    return smallest;
}
int main() {
    vector<int> A = {1, 3, 6, 4, 1, 2};
    int result = solution(A);
    cout << "Result: " << result << std::endl; //  output: 5

    A = {1, 2, 3};
    result = solution(A);
    cout << "Result: " << result << std::endl; //  output: 4

    A = {-1, -3};
    result = solution(A);
    cout << "Result: " << result << std::endl; //  output: 1

    return 0;
}
