#include <iostream>
#include <vector>
#include <algorithm> // For std::min and std::max

using namespace std;

int main()
{
    double a, b;
    int n;

    // Nhập a và b
    cin >> a >> b;

    // Nhập kích thước ma trận
    cin >> n;

    vector<vector<int>> image(n, vector<int>(n));

    // Nhập ma trận ảnh
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> image[i][j];
        }
    }

    // Biến đổi ảnh theo hệ số a và b
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            // Thực hiện phép biến đổi tuyến tính
            int newValue = static_cast<int>(a * image[i][j] + b);
            // Đảm bảo giá trị pixel nằm trong khoảng [0, 255]
            newValue = min(max(newValue, 0), 255);
            image[i][j] = newValue;
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
