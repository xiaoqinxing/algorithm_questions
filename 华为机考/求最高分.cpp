#include <iostream>
#include <map>
using namespace std;
int main()
{
    int N, M;
    char proc;
    int A, B, max_score, tmp;
    map<int, int> students;
    while (cin >> N >> M)
    {
        for (int i = 1; i <= N; i++)
        {
            cin >> students[i];
        }
        for (int i = 0; i < M; i++)
        {
            max_score = 0;
            cin >> proc >> A >> B;
            if (proc == 'Q')
            {
                if (A > B)
                {
                    tmp = A;
                    A = B;
                    B = tmp;
                }
                for (int n = A; n <= B; n++)
                {
                    if (max_score < students[n])
                        max_score = students[n];
                }
                cout << max_score << endl;
            }
            else if (proc == 'U')
            {
                students[A] = B;
            }
        }
    }
    return 0;
}