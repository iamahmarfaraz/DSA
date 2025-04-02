#include <iostream>
#include <vector>
using namespace std;
void printvector(vector<vector<int>> &prr)
{
    for (int i = 0; i < prr.size(); i++)
    {
        for (int j = 0; j < prr[i].size(); j++)
        {
            cout << prr[i][j] << " ";
        }
        cout << endl;
    }
}
using namespace std;
int main()
{
    // 2D VECTOR
    vector<vector<int>> arr(5, vector<int>(10, 5));

    // JAGGED ARRAY
    vector<vector<int>> brr;
    vector<int> vec1(10, 0);
    vector<int> vec2(5, 1);
    vector<int> vec3(7, 0);
    vector<int> vec4(8, 1);
    vector<int> vec5(20, 0);

    brr.push_back(vec1);
    brr.push_back(vec2);
    brr.push_back(vec3);
    brr.push_back(vec4);
    brr.push_back(vec5);

    printvector(brr);

    return 0;
}