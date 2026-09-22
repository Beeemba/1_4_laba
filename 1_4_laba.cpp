#include <iostream>
#include <string>
#include <iomanip>

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
    std::cout << "Введите элементы матрицы (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << " [" << i << "][" << j << "] = ";
            std::cin >> matrix[i][j];
        }
    }
}

void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, std::string title = "Matrix")
{
    std::cout << "\n=== " << title << " ===\n";
    if (showBorders)
    {
        std::cout << "*";
        for (int j = 0; j < cols * 6 + 2;j++)
        {
            std::cout << "-";
        }
        std::cout << "*\n";
    }

    for (int i = 0; i < rows; i++)
    {
        if (showBorders)
        {
            std::cout << "| ";
        }
        for (int j = 0; j < cols; j++)
        {
            std::cout << std::setw(4) << matrix[i][j];
            if (j < cols - 1)
            {
                std::cout << "  ";
            }
        }
        if (showBorders)
        {
            std::cout << "   |";
        }
        std::cout << "\n";
    }

    if (showBorders)
    {
        std::cout << "*";
        for (int j = 0; j < cols * 6 + 2; j++)
        {
            std::cout << "-";
        }
        std::cout << "*\n";
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
    std::cout << "Введите количество строк (стуудентов): ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов (предметов): ";
    std::cin >> cols;
    int** grades = allocateMatrix(rows,cols);
    fillMatrix(grades, rows, cols);
    printMatrix(grades, rows, cols);
    printMatrix(grades, rows, cols, true, "Оценки студентов");
    printMatrix(grades, rows, cols, false, "Матрица оценок (без рамок)");

    freeMatrix(grades, rows);
    std::cout << "Память освобождена\n";
    return 0;
}