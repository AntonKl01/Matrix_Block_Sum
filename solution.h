#include<iostream>
#include<vector>

class Solution {
    public:
        std::vector<std::vector<int>> matrixBlockSum(std::vector<std::vector<int>>& mat, int k) {
            if(mat.empty()) {
                std::cout << "You have the empty matrix" << std::endl;
                return std::vector<std::vector<int>>();
            }
            int n = mat.size(); // number of rows
            int m = mat[0].size(); // number of columns

            std::vector<std::vector<int>> answer(n, (std::vector<int>(m, 0)));
            // col_add_ptr points to the index of a column, needing to add to the previous value of the answer matrix in column
            // to recieve new value in the current column
            // for j = 0 col_add_ptr = k + 1 
            int col_add_ptr = k + 1;
            // col_sub_ptr points to the index of a column, needing to subtraction to the previous value of the answer matrix
            // in column to recieve new value in current column
            int col_sub_ptr = 0; 
            int row_add_ptr = k + 1; 
            int row_sub_ptr = 0;

            // left_r, right_r are left and right parts of the inequality from description: left_r <= r <= right_r
            int left_r = 0; // max(0, i - k)
            int right_r = 0; // min(n - 1, i + k)
            // left_c, right_c are left and right parts of the inequality form description: left_c <= c <= right_c
            int left_c = 0; // max(0, j - k) 
            int right_c = std::min(m - 1, k); // min(m - 1, j + k)

            for (int i = 0; i <= n - 1; ++i) {
                left_r = std::max(0, i - k);
                right_r = std::min(n - 1, i + k);

                for (int j = 0; j <= m - 1; ++j) {
                    if (i == 0 && j == 0) {
                        for (int  r = left_r; r <= right_r; ++r) {
                            for (int c = left_c; c <= right_c; ++c) {
                                answer[i][j] += mat[r][c]; 
                            }
                        }
                    } else if (j == 0) {
                        col_sub_ptr = 0;
                        col_add_ptr = k + 1;
                        if (i <= k) {
                            answer[i][j] = answer[i-1][j];
                            if (row_add_ptr < n) {
                                for (int c = left_c; c <= right_c; ++c) {
                                    answer[i][j] += mat[row_add_ptr][c];
                                }
                                row_add_ptr += 1;
                            }
                        } else {
                            answer[i][j] = answer[i-1][j];
                            if (row_add_ptr < n) {
                                for (int c = left_c; c <= right_c; c++) {
                                    answer[i][j] += mat[row_add_ptr][c];
                                }
                                row_add_ptr += 1;
                                for (int c = left_c; c <= right_c; ++c) {
                                    answer[i][j] -=  mat[row_sub_ptr][c];
                                }
                                row_sub_ptr += 1;
                            } else {
                                for (int c = left_c; c <= right_c; ++c) {
                                    answer[i][j] -=  mat[row_sub_ptr][c];
                                }
                                row_sub_ptr += 1;
                            }
                        }
                    } else if (j <= k) {
                        answer[i][j] = answer[i][j-1];
                        if (col_add_ptr < m) {
                            for (int r = left_r; r <= right_r; ++r) {
                                answer[i][j] += mat[r][col_add_ptr];
                            }
                            col_add_ptr += 1;
                        }
                    } else {
                        answer[i][j] = answer[i][j-1];
                        if (col_add_ptr < m) {
                            for (int r = left_r; r <= right_r; ++r) {
                                answer[i][j] += mat[r][col_add_ptr];
                            }
                            col_add_ptr += 1;
                            for (int r = left_r; r <= right_r; ++r) {
                                answer[i][j] -= mat[r][col_sub_ptr];
                            }
                            col_sub_ptr += 1;

                        } else {
                            for (int r = left_r; r <= right_r; ++r) {
                                answer[i][j] -= mat[r][col_sub_ptr];
                            }
                            col_sub_ptr += 1;
                        }
                    }

                }

            }
            return answer;
        }
};