#include<iostream>
#include<vector>

class Solution2 {
    public:
        std::vector<std::vector<int>> matrixBlockSum(std::vector<std::vector<int>>& mat, int k) {
            if(mat.empty()) {
                std::cout << "You have the empty matrix" << std::endl;
                return std::vector<std::vector<int>>();
            }
            int n = mat.size(); // number of rows
            int m = mat[0].size(); // number of columns

            std::vector<std::vector<int>> answer(n, (std::vector<int>(m, 0)));
            int max_dim = std::max(n, m);
            int min_dim = std::min(n, m);

            // left_r <= r <= right_r
            int left_r = 0;
            int right_r = 0;
            // left_c <= c <= right_c
            int left_c = 0;
            int right_c = 0;

            int col_add_ptr = 0;
            int col_sub_ptr = 0;
            int row_add_ptr = 0;
            int row_sub_ptr = 0;

            //Вычисление answer[0][0]
            right_r = std::min(n - 1, k);
            right_c = std::min(m - 1, k);
            for (int r = left_r; r <= right_r; ++r) {
                for (int c = left_c; c <= right_c; ++c) {
                    answer[0][0] += mat[r][c];
                }
            }
            row_add_ptr = right_r + 1;
            col_add_ptr = right_c + 1;

            for (int i = 0; i <= n - 1; ++i) {
                for (int j = i; j <= max_dim - 1; ++j) {
                    if (j == 0 && i == 0) {
                        continue;
                    }

                    if (i == j) {
                        left_r = std::max(0, i - k);
                        right_r = std::min(n - 1, i + k); // min_dim
                        left_c = std::max(0, j - k);
                        right_c = std::min(m  - 1, j + k);

                        row_add_ptr = i + k + 1;
                        col_add_ptr = j + k;
                        row_sub_ptr = std::max(0, i - k);
                        col_sub_ptr = std::max(0, j - k - 1);

                        answer[i][j] = answer[i][j-1];
                        if (j <= k) {
                            if (col_add_ptr < m) {
                                for (int r = left_r; r <= right_r; ++r) {
                                    answer[i][j] += mat[r][col_add_ptr];
                                }
                                col_add_ptr += 1;
                            }
                        } else {
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

                    } else {
                        if (j < m) {
                            answer[i][j] = answer[i][j-1];
                            left_r = std::max(0, i - k);
                            right_r = std::min(n - 1, i + k);
                            if (j <= k) {
                                if (col_add_ptr < m) {
                                    for (int r = left_r; r <= right_r; ++r) {
                                        answer[i][j] += mat[r][col_add_ptr];
                                    }
                                    col_add_ptr += 1;
                                }
                            } else {
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
                        if (j < n) {
                            answer[j][i] = answer[j-1][i];
                            left_c = std::max(0, i - k);
                            right_c = std::min(m - 1, i + k);
                            if (j <= k) {
                                if (row_add_ptr < n) {
                                    for (int c = left_c; c <= right_c; ++c) {
                                        answer[j][i] += mat[row_add_ptr][c];
                                    }
                                    row_add_ptr += 1;
                                }
                            } else {
                                if (row_add_ptr < n) {
                                    for (int c = left_c; c <= right_c; ++c) {
                                        answer[j][i] += mat[row_add_ptr][c];
                                    }
                                    row_add_ptr += 1;
                                    for (int c = left_c; c <= right_c; ++c) {
                                        answer[j][i] -= mat[row_sub_ptr][c];
                                    }
                                    row_sub_ptr += 1;
                                } else {
                                    for (int c = left_c; c <= right_c; ++c) {
                                        answer[j][i] -= mat[row_sub_ptr][c];
                                    }
                                    row_sub_ptr += 1;
                                }
                            }
                        }
                    }    
                }
                if (i == min_dim - 1) {
                    break;
                }
            }
            return answer;
        }
};