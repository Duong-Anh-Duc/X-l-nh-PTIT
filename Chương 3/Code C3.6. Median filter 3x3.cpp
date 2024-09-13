#include <iostream>
#include <vector>
#include <algorithm> // Để sử dụng hàm sort

using namespace std;

// Hàm tìm giá trị median của một mảng
int median(vector<int> &values)
{
    sort(values.begin(), values.end()); // Sắp xếp mảng
    return values[values.size() / 2];   // Trả về giá trị median
}

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

    // Thực hiện lọc median 3x3
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            vector<int> values;
            for (int x = -1; x <= 1; x++)
            {
                for (int y = -1; y <= 1; y++)
                {
                    values.push_back(image[i + x][j + y]);
                }
            }
            result[i - 1][j - 1] = median(values); // Lấy giá trị median
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
