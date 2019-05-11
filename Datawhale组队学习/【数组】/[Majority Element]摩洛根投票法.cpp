//摩尔投票法
int majorityElement(int* nums, int numsSize)
{
    int count=0;//记录次数 
    int number=nums[0];//记录初值 
    for(int i=0; i<numsSize; i++)
    {
        if(count==0) //抵消完了改则变数进行投票 
        {
            number=nums[i];
            count=1;
        }
        else if(number!=nums[i]) //相同则加一，否则抵消 
            count--;
        else
            count++;
    }
    return number;
}
