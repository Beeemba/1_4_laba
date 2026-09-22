#include <iostream>

int** allocateMatrix(int rows, int cols)
{
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new int[cols]{};
    }
    return matrix;
}

void fillMatrix(int** matrix, int rows, int cols)
{
    std::cout << "Введите элементы матрицы (" << rows << "x" << cols "):\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << " [" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }
}

void freeMatrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main()
{
    int rows, cols;
    std::cout << "Создание матрицы " << rows << "x" << cols << "\n";
    int** grades = allocateMatrix(rows,cols);
    fillMatrix(grades, rows, cols);
    std::cout << "Матрица создана успешно!\n";
    
    freeMatrix(grades, rows);
    std::cout << "Память освобождена\n";
    return 0;
}