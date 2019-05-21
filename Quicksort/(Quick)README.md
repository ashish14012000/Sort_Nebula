PSEUDOCODE  :  QUICK SORT

Main function:

       declare vector pair v containing 
       vector of pairs of keys and values.
      
       input size or n and values of pairs.

       call quickSort() for sorting w.r.t keys.
      
	   after this again sorting 
	   by values for same keys  : 
	    
	     int i=0
             while(1)
              {    int t=v[i].first
                  int j=i
			   
                  while(v[i].first == t)
                    i++;if(i==n) break
          
                  int k=i-1

                  if(j!=k)
                  making a vector v2(v.begin()+j,v.begin()+k+1).
                  swap the keys and values of v2.
                  sort v2  quickSort(v2, k-j+1).
                  again swap the keys and values of v2.

                 if(i==n) break
              }
		 
         call print function to print the 
	     final sorted list.
		   
Functions :
		
quickSort(v as vector pair ,int low ,int high)

      sorting elements before and after the pivot.
	  
     if (low < high) 
        int pivot = partition(arr, low, high) 
        quickSort(v, low, pivot - 1) 
        quickSort(v, pivot + 1, high) 
    

partition(v as vector pair, n as int, i as int)
      
	  Placing the pivot at its correct position
	  in the sorted list .
	  
	   int pivot = v[high].first
           int i = (low - 1)

          for j=low to high-1
             if (v[j].first <= pivot)
               i++,swap(v[i], v[j])
    
          swap(v[i + 1], v[high])
         return (i + 1)
		
		
print(v as vector,n as size)

         for i=0 to n-1
          print v[i]	

