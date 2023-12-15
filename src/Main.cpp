#include <iostream>
#include <vector>

void print_board(const std::vector<std::vector<int32_t>>& board)
{
    for (size_t i = 0; i < board.size(); ++i)
    {
        const std::vector<int32_t>& row = board[i];

        for (size_t j = 0; j < row.size(); ++j)
        {
            int32_t cell = row[j];
            std::cout << cell << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int32_t count_live_neighbors(int32_t i, int32_t j, const std::vector<std::vector<int32_t>>& board)
{
    size_t count = 0;
    
    std::vector<std::pair<int32_t, int32_t>> neighbors = 
    {
        {-1, -1}, {-1, 0}, {-1, 1},
        {0, -1},           {0, 1},
        {1, -1},  {1, 0},  {1, 1}
    };

    const uint32_t m = board.size();
    const uint32_t n = board[0].size();
    
    for (size_t k = 0; k < neighbors.size(); ++k)
    {
        int x = i + neighbors[k].first;
        int y = j + neighbors[k].second;
        if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == -1))
        {
            count++;
        }
    }
    return count;
}

int32_t main()
{
    try
    {
        std::vector<std::vector<int32_t>> board = 
        {
            {1, 1, 0},
            {1, 0, 1},
            {1, 0, 1},
            {0, 0, 1}
        };

        print_board(board);

        return EXIT_SUCCESS;
    }
    catch (const std::exception& exception)
    {
        std::cerr << exception.what() << std::endl;
    }
    catch (...)
    {
        std::cout << "Unknown exception caught!" << std::endl;
    }
    return EXIT_FAILURE;
}