#include<stdio.h>
#include<stdlib.h>

#define HASHSIZE 40960
#define HASHEND (HASHSIZE - 1)

struct hashnode
{
    int index;
    int num;
    struct hashnode *next;
}hashnodes[HASHSIZE] = {[0 ... HASHEND] = {-1, 0, NULL}};
struct hashnode *pnext = NULL, *pre = NULL;

int* twoSum(int* nums, int numsSize, int target, int *returnSize)
{
    int i, h, h1, found;
    int *ret = (int *)malloc(sizeof(int) * 2);
    
    *returnSize = 0;

    for (i = 0; i < numsSize; i++)
	{
        h = nums[i] < 0 ? (0 - nums[i]) % HASHSIZE : nums[i] % HASHSIZE;
        h1 = target - nums[i] < 0 ? (nums[i] - target) % HASHSIZE : (target - nums[i]) % HASHSIZE;
        found = 0;
        if (hashnodes[h1].index > -1)
		{
            pnext = (struct hashnode *)&hashnodes[h1];
            do
			{
                pre = pnext;
                if (nums[i] == pnext->num)
				{
                    found = 1;
                    break;
                }
                pnext = pre->next;
            } while(pnext != NULL);
        }
        if (found)
		{
            ret[0] = pre->index;
            ret[1] = i;
            *returnSize = 2;
            break;
        } 
		else 
		{
            if (hashnodes[h].index == -1)
			{
                hashnodes[h].index = i;
                hashnodes[h].num = target - nums[i];
            }
			else
			{
                pnext = (struct hashnode *)&hashnodes[h];
                do
				{
                    pre = pnext;
                    pnext = pre->next;
                } while(pnext != NULL);
                pre->next = (struct hashnode *)malloc(sizeof(struct hashnode));
                pre->next->index = i;
                pre->next->num = target - nums[i];
                pre->next->next = NULL;
            }
        }    
    }
    return ret;
}
