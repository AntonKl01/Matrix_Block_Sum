#include"solution.h"
#include"solution2.h"

int main() {
    std::vector<std::vector<int>> a = {{76,4,73},{21,8,56},{4,56,61},{70,32,38}, {31,94,67}};
    //std::vector<std::vector<int>> a = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //std::vector<std::vector<int>> a = {{1, 2, 3, 4, 5}, {6, 7, 8, 9 ,10}, {11, 12, 13, 14, 15}};
    
    std::vector<std::vector<int>> answer1(a.size(), (std::vector<int>(a[0].size(), 0)));
    std::vector<std::vector<int>> answer2(a.size(), (std::vector<int>(a[0].size(), 0)));



    // for (int i = 0; i < 3; ++i) {
    //     for (int j = 0; j < 3; ++j) {
    //         std::cout << a[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }

    Solution solution;
    answer1 = solution.matrixBlockSum(a, 1);
    for (int i = 0; i < answer1.size(); ++i) {
        for (int j = 0; j < answer1[0].size(); ++j) {
            std::cout << answer1[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\n";

    Solution2 solution2;
    answer2 = solution2.matrixBlockSum(a, 1);
    for (int i = 0; i < answer2.size(); ++i) {
        for (int j = 0; j < answer2[0].size(); ++j) {
            std::cout << answer2[i][j] << " ";
        }
        std::cout << "\n";
    }



    return 0;
}