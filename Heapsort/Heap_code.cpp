/*    WELCOME TO THE CODE OF HEAPSORT , SO LET US 
      SEE HOW THIS BEUTIFUL CODE LOOKS LIKE .HOPE
      YOU WILL ENJOY IT :)  */

#include <bits/stdc++.h>

using namespace std;

void heapify(vector<pair<int,int> > &v, int n, int i) // function to make a tree and heapify it
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && v[l].first > v[largest].first)
        largest = l;

    if (r < n && v[r].first > v[largest].first)
        largest = r;


    if (largest != i)
    {
        swap(v[i], v[largest]);

        heapify(v, n, largest);
    }
}

void heapSort(vector<pair<int,int> > &v, int n) //function to implement the heapSort algorithm
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(v, n, i);

    for (int i=n-1; i>=0; i--)
    {
        swap(v[0], v[i]);

        heapify(v, i, 0);
    }
}

void print(vector<pair<int,int> > &v, int n) // function to print the list after sorting
{
    for (int i=0; i<n; ++i)
        cout << v[i].first << " "<<v[i].second<<endl;
}

int main()
{   ios_base::sync_with_stdio(false);      // for fast input and output
    cin.tie(NULL);                         // guarantees the flushing of std::cout

    vector<pair<int,int> > v;            // making a vector pair for storing key value pairs
    int n;
    cout<<" Enter the no. of key value pairs :  "<<endl;
    cin>>n;
    cout<<" Enter the key value pairs  :"<<endl;
    int i,a,b;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }

    heapSort(v, n);             // calling heapSort for sorting w.r.t keys

    int j,k,t,l;                /* here onwards I have written the code for sorting 
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
          vector< pair<int,int> > v2(v.begin()+j,v.begin()+k+1);  /* making a temporary vector v2 and
                                                               and copying elements of v from j to k */

          for (l=0;l<v2.size();l++)
            swap(v2[l].first,v2[l].second); // swapping key and values for sorting w.r.t values

          heapSort(v2, k-j+1);   // calling heapSort again for sorting values for same keys

          for (l=0;l<v2.size();l++)
            swap(v2[l].first,v2[l].second); // again swapping key and values after sorting 

          std::swap_ranges(v.begin() + j, v.begin() + k+1, v2.begin()); // merging v2 back to v after sorting
      }
      if(i==n)
        break;
    }
    cout << " Sorted list of key value pairs is : "<<endl;
    print(v, n);                     // printing the sorted key value pairs
}


/* THANKS FOR READING MY UGLY CODE :) */ 

