#include <iostream>
#include <vector>
#include <cmath> // Để sử dụng hàm round

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> image(n, vector<int>(n));
    vector<vector<int>> result(n - 2, vector<int>(n - 2));

    // Nhập ma trận ảnh
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> image[i][j];
        }
    }

    // Thực hiện lọc trung bình 3x3
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            int sum = 0;
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    sum += image[i + x][j + y];
                }
            }
            // Làm tròn giá trị trung bình của phần tử 3x3
            result[i - 1][j - 1] = round(sum / 9.0); // Làm tròn với round
        }
    }

    // Xuất ma trận kết quả
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < n - 2; j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
