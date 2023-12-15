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

int32_t main()
{
    try
    {
        std::vector<std::vector<int32_t>> board = {};
        
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