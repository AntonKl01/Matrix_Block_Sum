# Matrix_Block_Sum
Description of the task could be found on [leetcode](https://leetcode.com/problems/matrix-block-sum/description/). Briefly we have a $n\times m$ matrix *mat* and an integer *k* and we want to construct a matrix *answer* such that $$answer[i][j] = \sum_{k=1}^n\sum_{r = i - k}^{i + k} mat[r][c]$$.

The solutions based on the following observation: if we alredy have $answer[0][0]$, we could recive $answer[0][1]$ like $answer[0][0] + \sum_{r = i-k}^{i + k}mat[r][col_add_ptr]$, where *col_add_ptr* indicates on column of *mat* matrix needing to add. In more general sense we apply this procedure, when $j\leqslant k$. If $j > k$, we need to performe subtraction rather than addition.
## The first solution
In the first solution(solution.h) we run through all rows and performe procedure described above.
## The second solution
In the second solution(solution2.h) we run through diagonal elements only and for each elements performe the procedure described above to the right on columns and down to the rows.  
