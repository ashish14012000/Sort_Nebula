 /*  WELCOME TO THE CODE OF QUICKSORT , AS THE NAME
     SUGGESTS IT IS REALLY QUICK ENOUGH ,SO LET'S HAVE A
     LOOK TO ITS COCE . HOPE YOU WILL ENJOY IT :)  */

#include<bits/stdc++.h>

using namespace std;

int partition_ (vector< pair<int,int> > &v, int low, int high) // function to partition vector elements using pivot
{
    int pivot = v[high].first;  // creating the pivot
    int i = (low - 1);

    for (int j = low; j <= high- 1; j++)
    {
        if (v[j].first <= pivot)
        {
            i++;
            swap(v[i], v[j]);
        }
    }
    swap(v[i + 1], v[high]);
    return (i + 1);
}


void quickSort(vector< pair<int,int> > &v, int low, int high)  // function to perform quickSort
{
    if (low < high)
    {

        int pi = partition_(v, low, high);


        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}


void print(vector<pair<int,int> > &v, int n)    // function to print the list after sorting
{
    for (int i=0; i<n; ++i)
        cout << v[i].first << " "<<v[i].second<<endl;
}

int main()
{   ios_base::sync_with_stdio(false);           // for fast input and output
    cin.tie(NULL);                              // guarantees the flushing of std::cout

    vector<pair<int,int> > v;                // making a vector pair for storing key value pairs
    int n;
    cout<<" Enter the no. of key value pairs  : "<<endl;
    cin>>n;
    cout<<" Enter the key value pairs  :"<<endl;
    int i,a,b;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    quickSort(v, 0, n-1);              // calling quickSort for sorting w.r.t keys

    int j,k,t,l;                     /* here onwards I have written the code for sorting
                                      values having the same key  */
    i=0;
    while(1)
    { t=v[i].first;
      j=i;
      while(v[i].first == t)
      {
          i++;
          if(i==n)
            break;
      }
      k=i-1;

      if(j!=k)
      {
          vector< pair<int,int> > v2(v.begin()+j,v.begin()+k+1); /* making a temporary vector v2 and
                                                               and copying elements of v from j to k */

          for (l=0;l<v2.size();l++)
            swap(v2[l].first,v2[l].second);    // swapping key and values for sorting w.r.t values

          quickSort(v2,0, k-j);      // calling quickSort again for sorting values for same keys

          for (l=0;l<v2.size();l++)
            swap(v2[l].first,v2[l].second);    // again swapping key and values after sorting

          std::swap_ranges(v.begin() + j, v.begin() + k+1, v2.begin());  // merging v2 back to v after sorting
      }
      if(i==n)
        break;
    }
    cout<<" Sorted list of the key value pairs is  :  "<<endl;
    print(v, n);                    // printing the sorted key value pairs
}


/* THANKS FOR READING MY UGLY CODE :) */

