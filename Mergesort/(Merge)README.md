PSEUDOCODE  :  MERGE SORT

Main function:

       declare vector pair v containing 
	   vector of pairs of keys and values.
      
       input size or n and values of pairs.

       call mergeSort() for sorting w.r.t keys.
      
	   after this again sorting 
	   by values for same keys  : 
	    
	   int i=0
           while(1)
            { int t=v[i].first
              int j=i
			   
               while(v[i].first == t)
                i++;if(i==n) break
          
             int k=i-1

            if(j!=k)
             making a vector v2(v.begin()+j,v.begin()+k+1).
             swap the keys and values of v2.
             sort v2  mergeSort(v2, k-j+1).
             again swap the keys and values of v2.

            if(i==n) break
          }
		 
         call print function to print the 
         final sorted list.
		   
Functions :
		
mergeSort(v as vector pair ,int left,int right)

      if(left<right)
	     int m=left+(right-left)/2
             mergeSort(v,left,m)		 
             mergeSort(v,m+1,right)
		 merge(v,left,m,right)
		 

merge(v as vector pair, left,m,right)
     
	  int i,j,k,n1=m-left+1,n2=right-1
	 
	  declare 2 temporary vector pair L ,R.
	  
	  for i=0 to n1-1
	  copy from vector v as L[i] <-- v[left+i]
	  
	  for j=0 to n2-1
	  copy from vector v as R[j] <-- v[m+1+j]
		
	  Merge the temporary vectors back into v.
		 
         initialise i = 0,j = 0,k = left 
		 while (i < n1 and j < n2) 
            {    
              if (L[i].first <= R[j].first)  
              copying v[k] <-- L[i],i++
        
              else
              copying v[k] <-- R[j],j++ 
            
              k++
	     }
			
	      Copy the remaining elements of L, if there 
          are any .
             while (i < n1)
             copying v[k] <-- L[i],i++,k++ 
    
  
          Copy the remaining elements of R, if there 
          are any .
             while (j < n2) 
             copying v[k] <-- R[j],j++,k++ 
    
	   
print(v as vector,n as size)

          for i=0 to n-1
            print v[i]	
