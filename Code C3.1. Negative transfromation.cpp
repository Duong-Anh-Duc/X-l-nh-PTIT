#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
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

    // Biến đổi âm bản
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            image[i][j] = 255 - image[i][j]; // Âm bản = 255 - giá trị pixel
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
