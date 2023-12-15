#include <iostream>

int32_t main()
{
    try
    {
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