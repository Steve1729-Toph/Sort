#include <iostream>
#include <time.h>
#include <vector>

using namespace std;

int n, x, l, r;
vector<int> a;

void SelectionSort();//O(n^2)

void InterchangeSort();//O(n^2)

void InsertionSort();//O(n^2)

void BubbleSort();//O(n^2)

int PartitionL(vector<int>&, int , int );//LOMUTO cham hon ti
void QuickSortL(vector<int>&, int , int );
int PartitionH(vector<int>&, int , int );//HOARE ban goc nen nhanh hon
void QuickSortH(vector<int>&, int , int );
 //O(nlogn) and worst O(n^2)

void Heapify(vector<int>&, int, int);
void HeapSort();//O(nlogn)

int GetMax(vector<int>&);
void CountSort(vector<int>& , int);
void RadixSort(vector<int>&);//O(n) hoac O(d*(n+k)) = O((n+k)log(max))


void Merge( int, int , int , int );
void MergeSort( int, int , int );//O(nlogn)

//========================================================================
int main()
{
    cin>>n;
    int b[n];
    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        x = rand()%1000;
        a.push_back(x);
        b[i] = x;
    }
    cout<<"truoc khi sap xep: \n";
    for(int x:a) cout<<x<<' ';
    cout<<"\nSau khi sap xep: \n";

    //SelectionSort();
    //InsertionSort();
    //InterchangeSort();
    //BubbleSort();
    //QuickSort(a, 0, n-1);
    //MergeSort(b,0,n-1);
    //HeapSort();
    //RadixSort(a);
    
    for(int x:a) cout<<x<<' ';
    return 0;
}
//========================================================================
void SelectionSort()
{
    int i=0, Min, j;
    while(i < n-1)
    {
        Min=i;
        j=i+1;
        while(j < n)
        {
            if(a[j] < a[Min]) Min = j;
            ++j;
        }
        swap(a[i], a[Min]);
        ++i;
    }
}
//========================================================================
void InsertionSort()
{
    int i=1, k, e;
    while(i < n)
    {
        e = a[i];
        k = i-1;
        while(k >= 0 && a[k] > e)
        {
            a[k+1] = a[k];
            k--;
        }
        a[k+1] = e;
        i++;
    }
}
//========================================================================
void InterchangeSort()
{
    int i = 0, j;
    while (i < n-1)
    {
        j = i + 1;
        while (j < n)
        {
            if (a[i] > a[j]) swap(a[i], a[j]);
            ++j;
        }
        ++i;
    }
}
//========================================================================
void BubbleSort()
{
    bool flag = false;
    while (!flag)
    {
        int i = 0;
        flag = true;
        while (i < n-1)
        {
            if (a[i] > a[i+1]) 
            {
                swap(a[i], a[i+1]);
                flag = false;
            }
            i++;
        }
    }
}
//========================================================================
int PartitionL (vector<int>& a, int l, int r){
    int pivot = a[r];
    int i = l - 1;
    for (int j = l; j < r; ++j){// 2 5 3 1 9 7 4
        if(a[j] <= pivot) {
            ++i;
            swap(a[i], a[j]);
        }
    }
    ++i;
    swap(a[i],a[r]);
    return i;
} 
int PartitionH(vector<int>& a, int l, int r){
    int pivot = a[l];
    int i = l-1, j = r+1;
    while(1){
        do{
            i++;
        }while(a[i] < pivot);
        do{
            j--;
        }while(a[j] > pivot);
        if(i > j) return j;
        else swap(a[i], a[j]);
    }

}
void QuickSortL(vector<int>& a, int l, int r){
    if (l >= r) return ;
    int p = PartitionL(a, l, r);
    QuickSortL(a, l, p-1);
    QuickSortL(a, p+1, r);
    
}
void QuickSortH(vector<int>& a, int l, int r){
    if (l >= r) return ;
    int p = PartitionH(a, l, r);
    QuickSortH(a, l, p);
    QuickSortH(a, p+1, r);
    
}
//========================================================================
void Merge(int b[], int l, int m, int r)
{
    vector<int> x(b+l, b+m+1);
    vector<int> y(b+m+1, b+r+1);
    int i=0, j=0;
    //cout<<"ne "<<a+l;
    while (i < x.size() && j < y.size())
    {
        if(x[i]<= y[j])
        {
            b[l] = x[i];
            ++l;
            ++i;
        }
        else
        {
            b[l] = y[j];
            ++l;
            ++j;
        }
    }
    while(i<x.size())
    {
        b[l] = x[i];
        ++l;
        ++i;
    }
    while(j<y.size())
    {
        b[l] = y[j];
        ++l;
        ++j;
    }
}
void MergeSort(int b[], int l, int r)
{
    if(l>=r) return;
    int m=(l+r)/2;
    MergeSort(b,l,m);
    MergeSort(b,m+1,r);
    Merge(b,l,m,r);
}
//========================================================================
void Heapify(vector<int>& a, int n, int i){
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && a[l] > a[largest]) largest = l;
    if (r < n && a[r] > a[largest]) largest = r;
    if (largest != i){
        swap(a[i], a[largest]);
        Heapify(a, n, largest);
    } 
}
void HeapSort(){
    for(int i = n/2 +1; i >= 0; --i){
            Heapify(a,n,i);
    }
    for(int i = n-1; i >=0; --i){
        swap(a[i], a[0]);
        Heapify(a,i,0);
    }
}
//========================================================================
int GetMax(vector<int>& a) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}
void CountSort(vector<int>& a,int exp) {
    int output[n]; // Mảng output chứa kết quả sắp xếp
    int count[10] = {0}; // Mảng count để lưu số lượng phần tử

    // Đếm số lượng phần tử
    for (int i = 0; i < n; i++) {
        count[(a[i] / exp) % 10]++;
    }

    // Cộng dồn để xác định vị trí thực sự của phần tử trong mảng output
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Xếp các phần tử vào mảng output
    for (int i = n - 1; i >= 0; i--) {
        output[count[(a[i] / exp) % 10] - 1] = a[i];
        count[(a[i] / exp) % 10]--;
    }

    // Copy mảng output vào mảng arr
    for (int i = 0; i < n; i++) {
        a[i] = output[i];
    }
}

void RadixSort(vector<int>& a) {
    int max = GetMax(a);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        CountSort(a, exp);
    }
}
//========================================================================