PSEUDOCODE  :  HEAP SORT

Main function:
     
       declare vector pair v containing 
       vector of pairs of keys and values.
       
       input size or n and values of pairs.

       call heapSort() for sorting w.r.t keys.
      
	   after this again sorting 
	   by values for same keys  : 
	    
	     int i=0
         while(1)
           {  int t=v[i].first
              int j=i
			   
               while(v[i].first == t)
                i++;if(i==n) break
          
             int k=i-1

            if(j!=k)
             making a vector v2(v.begin()+j,v.begin()+k+1).
             swap the keys and values of v2.
             sort v2  heapSort(v2, k-j+1).
             again swap the keys and values of v2.

            if(i==n) break
          }
		 
         call print function to print the 
		 final sorted list.
		   
Functions :
		
heapSort(v as vector pair ,n (sizeof vector))

     n = no. of elements_in v
    for i = floor(n/2)-1 to 0
        Heapify(v,n,i)
		
    for i = n-1 to 0
        swap(v[0].first, v[i].first)
        Heapify(v,i,0)


Heapify(v as vector pair, n as int, i as int)
    
     max =i
    left = 2i+1
    right = 2i+2
    
    if (left < n) and (v[left].first > v[max].first)
        max = left

    if (right< n) and (v[right].first > v[max].first)
        max = right

    if (max != i)
        swap(v[i], v[max])
        Heapify(v,n, max)
		
		
print(v as vector,n as size)

      for i=0 to n-1
       print v[i]
