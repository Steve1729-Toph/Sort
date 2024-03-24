/*#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class H_Index{
private:
    int Count = 0, n, m;
    vector<int> a;
public:
    H_Index(){}
    ~H_Index(){}
    void Input(){
        int x;
        //cout<<"nhap vao so luong bai bao: ";
        cin>>m;
        for(int i = 0; i < m; ++i){
            cin>>x;
            a.push_back(x);
        }
    }
    void Output()const{
        for(int i = 0; i < m; ++i){
            cout<<"\nphan tu thu "<<i<<": "<<a[i];
        }
    }
    void Sort(){
        sort(a.begin(),a.end());
    }
    void HIndex_TL(){
        int i = m - 1;
        while(m <= a[i] && i != -1){
            Count++;
            i--;
        }
        Count++;
        while(Count < a[i] && i != -1){
            Count++;
            --i;
        }
        cout<<a[i];
    }
};

int main(){
    H_Index a;
    a.Input();
    a.Sort();
    //a.Output();
    a.HIndex_TL();
    return 0;
}*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> citations(n);
    for (int i = 0; i < n; i++) {
        cin >> citations[i];
    }

    sort(citations.begin(), citations.end()); // Sắp xếp tăng dần

    int left = 0, right = n - 1;
    int hIndex = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (citations[mid] >= n - mid) {
            hIndex = n - mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << hIndex << endl;

    return 0;
}
