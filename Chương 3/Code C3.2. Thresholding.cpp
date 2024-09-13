#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int threshold, n;

    // Nhập ngưỡng và kích thước ma trận
    cin >> threshold >> n;

    vector<vector<int>> image(n, vector<int>(n));

    // Nhập ma trận ảnh
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> image[i][j];
        }
    }

    // Biến đổi phân ngưỡng
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (image[i][j] > threshold)
            {
                image[i][j] = 255; // Nếu giá trị >= ngưỡng, đặt thành 255
            }
            else
            {
                image[i][j] = 0; // Nếu giá trị < ngưỡng, đặt thành 0
            }
        }
    }

    // Xuất ma trận đã biến đổi
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
