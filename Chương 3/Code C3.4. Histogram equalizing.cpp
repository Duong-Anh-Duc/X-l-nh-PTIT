#include <iostream>
#include <vector>
#include <algorithm> // For std::min and std::max
#include <cmath>
using namespace std;

int main()
{
    int rows, cols, num_levels;

    // Nhập số hàng và số cột
    cin >> rows >> cols;

    // Nhập số mức xám
    cin >> num_levels;

    vector<vector<int>> image(rows, vector<int>(cols));

    // Nhập ma trận ảnh
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> image[i][j];
        }
    }

    // Bước 1: Tính toán histogram
    vector<int> histogram(num_levels, 0);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            histogram[image[i][j]]++;
        }
    }

    // Bước 2: Tính toán hàm phân phối tích lũy (CDF)
    vector<double> cdf(num_levels, 0.0);
    cdf[0] = histogram[0] / double(rows * cols);
    for (int i = 1; i < num_levels; i++)
    {
        cdf[i] = cdf[i - 1] + histogram[i] / double(rows * cols);
    }

    // Bước 3: Chuyển đổi ảnh dựa trên CDF
    vector<vector<int>> equalized_image(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            int new_value = round(cdf[image[i][j]] * (num_levels - 1));
            equalized_image[i][j] = new_value;
        }
    }

    // Xuất ma trận đã cân bằng histogram
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << equalized_image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
