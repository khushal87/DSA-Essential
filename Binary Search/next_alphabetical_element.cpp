#include <bits/stdc++.h>
using namespace std;

char nextAlphabeticalElement(char arr[], int n, char el)
{
    int start = 0;
    int end = n - 1;
    char res = '#';
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        //Continue search
        if (arr[mid] == el)
        {
            start = mid + 1;
        }
        else if (arr[mid] < el)
        {
            start = mid + 1;
        }
        else if (arr[mid] > el)
        {
            res = arr[mid];
            end = mid - 1;
        }
    }
    return res;
}