#include <iostream>

#include "GameBoard.hpp"

void print_board(const GameBoard& board)
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

size_t count_live_neighbors(int32_t i, int32_t j, const GameBoard& board)
{
    // In this function we counts the number of live neighbors for each cell.
    // It loops for each cell's neighbors, incrementing the count if a neighbor is alive.

    size_t count = 0;
    
    // we define a vector of pair neighbors, which represents the relative coordinates of neighboring cells.
    // Each pair in the vector represents the offset in row and column values from the current cell.

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

void update_board(GameBoard& board)
{
    if (board.empty())
    {
        return;
    }

    const uint32_t m = board.size();
    const uint32_t n = board[0].size();

    for (int32_t i = 0; i < m; i++)
    {
        for (int32_t j = 0; j < n; j++)
        {
            size_t liveNeighbors = count_live_neighbors(i, j, board);

            // "Any live cell with two or three live neighbors remains alive."
            if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3))
            {
                board[i][j] = -1; // Kill
            }
            // "Moreover, any dead cell with exactly three live neighbors becomes alive."
            if (board[i][j] == 0 && liveNeighbors == 3)
            {
                board[i][j] = 2; // Revive
            }
        }
    }

    // A loop that converts the values (-1 and 2) to 0 and 1, respectively.
    for (int32_t i = 0; i < m; i++)
    {
        for (int32_t j = 0; j < n; j++)
        {
            if (board[i][j] == 2) 
            {
                board[i][j] = 1; // Alive
            }
            else if (board[i][j] == -1)
            {
                board[i][j] = 0; // Dead
            }
        }
    }
}

int32_t main()
{
    try
    {
        static constexpr size_t CYCLES = 3;

        GameBoard board = 
        {
            {1, 1, 1, 1, 0, 1, 1},
            {1, 0, 1, 0, 1, 1, 0},
            {1, 0, 0, 0, 0, 1, 0},
            {0, 0, 1, 0, 0, 1, 0}
        };

        for (size_t cycle = 0; cycle < CYCLES; cycle++)
        {
            print_board(board);
            update_board(board);
        }

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