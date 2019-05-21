/*   WELCOME TO THE CODE OF MERGESORT , SO LET US
      EXPLORE HOW THIS VERY EFFICIENT CODE LOOKS LIKE .
      HOPE YOU WILL ENJOY IT :)  */

#include<bits/stdc++.h>

using namespace std;

void merge1(vector<pair<int,int> > &v, int l, int m, int r) // function to merge two sub vector pairs
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    vector< pair<int,int> > L, R;       // creating two temporary sub vector pairs L,R


    for (i = 0; i < n1; i++)            // copying data in L and R from vector v
        L.push_back(v[l + i]);
    for (j = 0; j < n2; j++)
        R.push_back(v[m + 1+ j]);


    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)            // merging L and R back into the vector v
    {
        if (L[i].first <= R[j].first)
        {  vector< pair<int,int> > p(L.begin()+i,L.begin()+i+1);
            std::swap_ranges(v.begin() + k, v.begin() + k+1, p.begin());

            i++;
        }
        else
        {  vector< pair<int,int> > q(R.begin()+j,R.begin()+j+1);
            std::swap_ranges(v.begin() + k, v.begin() + k+1, q.begin());

            j++;
        }
        k++;
    }


    while (i < n1)                        // copying the remaining elements of L if any remains
    {   vector< pair<int,int> > p1(L.begin()+i,L.begin()+i+1);
        std::swap_ranges(v.begin() + k, v.begin() + k+1, p1.begin());

        i++;
        k++;
    }


    while (j < n2)                        // copying the remaining elements of R if any remains
    {    vector< pair<int,int> > q1(R.begin()+j,R.begin()+j+1);
         std::swap_ranges(v.begin() + k, v.begin() + k+1, q1.begin());

        j++;
        k++;
    }
}


void mergeSort(vector< pair<int,int> > &v, int l, int r) // function to perform the mergeSort
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(v, l, m);
        mergeSort(v, m+1, r);

        merge1(v, l, m, r);
    }
}

void print(vector<pair<int,int> > &v, int n)     // function to print the list after sorting
{
    for (int i=0; i<n; ++i)
        cout << v[i].first << " "<<v[i].second<<endl;
}

int main()
{   ios_base::sync_with_stdio(false);           // for fast input and output
    cin.tie(NULL);                              // guarantees the flushing of std::cout

    vector<pair<int,int> > v;                // making a vector pair for storing key value pairs
    int n;
    cout<<" Enter the no. of key value pairs  :  "<<endl;
    cin>>n;
    cout<<" Enter the key value pairs  :"<<endl;
    int i,a,b;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    mergeSort(v, 0, n- 1);           // calling mergeSort for sorting w.r.t keys

    int j,k,t,l;                    /* here onwards I have written the code for sorting
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
            swap(v2[l].first,v2[l].second);  // swapping key and values for sorting w.r.t values

          mergeSort(v2,0, k-j);   // calling heapSort again for sorting values for same keys

          for (l=0;l<v2.size();l++)
            swap(v2[l].first,v2[l].second);  // again swapping key and values after sorting

          std::swap_ranges(v.begin() + j, v.begin() + k+1, v2.begin()); // merging v2 back to v after sorting
      }
      if(i==n)
        break;
    }

    cout<<" Sorted list of key value pairs is  :  "<<endl;
    print(v, n);                   // printing the sorted key value pairs
}


/* THANKS FOR READING MY UGLY CODE :) */

