int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    
    int target = 0, newTarget;
    int i, j, k;
    int ptr_ra = -1;
    void quickSort(int* nums,int first,int end);
	quickSort(nums,0,numsSize-1); //ÅÅÐò

    int **returnArray = (int **)malloc(sizeof(int *) * 17000);
    *returnColumnSizes = (int *)malloc(sizeof(int) * 17000);
    
    for (i = 0; i < numsSize-2; i++)
    {
        if (i == 0 || (i > 0) && (nums[i] != nums[i-1]))
        {        
            //Ë«Ö¸Õë
            j = i + 1;
            k = numsSize - 1;
            newTarget = target - nums[i];
            while (j < k)
            {
                if (nums[j] + nums[k] == newTarget)
                {
                    returnArray[++ptr_ra] = (int *)malloc(sizeof(int) * 3);
                    returnArray[ptr_ra][0] = nums[i];
                    returnArray[ptr_ra][1] = nums[j];
                    returnArray[ptr_ra][2] = nums[k];
                    (*returnColumnSizes)[ptr_ra] = 3;
                    while (j < k && nums[j] == nums[j+1]) 
						j++;
                    j++;
                    while (j < k && nums[k] == nums[k-1])
						k--; 
                    k--;
                }
                else if (nums[j] + nums[k] < newTarget)
                {
                    while (j < k && nums[j] == nums[j+1])
						j++;
                    j++;
                }
                else if (nums[j] + nums[k] > newTarget)
                {
                    while (j < k &&  nums[k] == nums[k-1])
						k--;
                    k--;
                }
            }
        }
    }
    *returnSize = ptr_ra+1;
    return returnArray;
}

void quickSort(int* nums,int first,int end)
{  
    int temp,l,r;  
    if(first>=end)
		return;  
    temp=nums[first];  
    l=first;r=end;  
    while(l<r)
	{  
        while(l<r && nums[r]>=temp)
			r--;  
        if(l<r)
			nums[l]=nums[r];  
        while(l<r && nums[l]<=temp)
			l++;  
        if(l<r)
			nums[r]=nums[l];  
    }  
    nums[l]=temp;  
    quickSort(nums,first,l-1);  
    quickSort(nums,l+1,end);  
}
