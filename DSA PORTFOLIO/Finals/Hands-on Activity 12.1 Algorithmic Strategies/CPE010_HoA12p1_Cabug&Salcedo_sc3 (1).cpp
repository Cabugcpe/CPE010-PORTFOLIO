#include <iostream>
#include <vector>

int M, N, target;
    std::vector<std::vector<int>> mat;
    std::vector<std::vector<std::vector<int>>> memo;

int dp(int i, int j, int cost){
    if (cost < 0) return 0;
    if (i == 0 && j == 0)
        return (cost == mat[0][0]) ? 1 : 0;

    if (memo[i][j][cost] != -1)
        return memo[i][j][cost];
    
    int res = 0;
    if (i > 0) res += dp(i-1, j, cost - mat[i][j]);
    if (j > 0) res += dp(i, j-1, cost - mat[i][j]);

    return memo[i][j][cost] = res;
}

int main(){
    mat = {
        {4,7,1,6},
        {5,7,3,9},
        {3,2,1,2},
        {7,1,6,3}
    };
    target = 25;
    M = mat.size();
    N = mat[0].size();

    memo.assign(M, std::vector<std::vector<int>>(N, std::vector<int>(target+1, -1)));
    
    std::cout << "Result: " <<dp(M-1, N-1, target) << std::endl;
    return 0;
}
