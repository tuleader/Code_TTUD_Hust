#include <bits/stdc++.h>
using namespace std;

int m, n;
int k;
const int MaxN = 31;
int x[MaxN];               // giáo viên x[i] được phân công môn học i
int load[MaxN];            // load[MaxN] số môn học mà giáo viên i đã dạy
vector<int> T[MaxN];       // T[i] là danh sách giáo viên có thể dạy được môn i
bool conflict[MaxN][MaxN]; // 2 môn không được dạy cùng nhau
int y, z;
int minMaxLoad = 1e9;
void input()
{
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        cin >> y;
        for (int j = 1; j <= y; j++)
        {
            int z;
            cin >> z;
            T[z].push_back(i);
        }
        load[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            conflict[i][j] = false;
        }
    }
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> y >> z;
        conflict[y][z] = true;
        conflict[z][y] = true;
    }
}

bool check(int t, int v) // kiểm tra xem môn v với giáo viên t có hợp lệ không
{
    for(int i=1;i<v;i++)
    {
        if(conflict[i][v] && x[i] == t)
            return false;
    }
    return true;
}

void solution(){
    int maxLoad = 0;
    for(int i=1;i<=m;i++){
        maxLoad = max(load[i],maxLoad);
    }
    if(maxLoad < minMaxLoad) 
        minMaxLoad = maxLoad;
}

void Try(int v){
    for(int i=0;i<T[v].size();i++){
        int t = T[v][i];
        if(check(t,v)){
            x[v] = t;
            load[t] +=1;
            if(v==n)
                solution();
            else if(v<n && load[t] < minMaxLoad)
                Try(v+1);
            load[t] -=1;
        }
    }
}

int main()
{
    input();
    Try(1);
    cout << minMaxLoad;
}