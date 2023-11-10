#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll mergeTwo(ll array[], ll temp_array[],
            ll firstidx_array1, ll lastidx_array1, ll firstidx_array2)
{
    ll counter = 0;
    ll p = lastidx_array1 + 1;
    ll i = firstidx_array1;

    for (ll i = firstidx_array1; i <= lastidx_array1; i++) {
        bool found = false;
        while (p <= firstidx_array2) {
            if(array[i] >= array[p]){
                p++;
                found = true;}
            else{
                break;
            }
        }
        if (found == true) {
            counter += p - (lastidx_array1 + 1);
            p--;
        }
    }
    ll k = firstidx_array1;
    p = lastidx_array1 + 1;
    i = firstidx_array1;

    while (i <= lastidx_array1 && p <= firstidx_array2) {

        if (array[i] <= array[p])
            temp_array[k++] = array[i++];
        else
            temp_array[k++] = array[p++];
    }

    while (i <= lastidx_array1)
        temp_array[k++] = array[i++];
    while (p <= firstidx_array2)
        temp_array[k++] = array[p++];

    for (ll i = firstidx_array1; i <= firstidx_array2; i++)
        array[i] = temp_array[i];
    return counter;
}

ll mergeSort(ll array[], ll temp_array[],
             ll l, ll r)
{
    ll counter = 0;
    if (l < r) {

        ll middle = (l + r) / 2;
        counter += mergeSort(array, temp_array,
                             l, middle);
        counter += mergeSort(array, temp_array,
                             middle + 1, r);
        counter += mergeTwo(array, temp_array, l,
                            middle, r);
    }

    return counter;
}

ll mergeSortPrint(ll arr[], ll N)
{
    ll temp[N];
    return mergeSort(arr, temp, 0, N - 1);
}
int main()
{
    ll n;
    cin >> n;
    ll array[n];
    for(ll i=0; i<n; i++){
        cin >> array[i];
    }
    ll size = sizeof(array);
    ll first_size = sizeof(array[0]);
    ll Num = size / first_size;
//    ll Num = sizeof(array) / sizeof(array[0]);
    ll K = 1;
    ll result = mergeSortPrint(array, Num);
    cout<<result << endl;
//    cout << "result is done";

    return 0;
}