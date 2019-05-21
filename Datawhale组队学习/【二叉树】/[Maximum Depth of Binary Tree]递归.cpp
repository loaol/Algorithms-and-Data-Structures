int maxDepth(struct TreeNode* root)
{
    int result=0;
    return getdeep(result,root);
}

int getdeep(int depth,struct TreeNode *tree)
{
    if(tree!=NULL)
        depth+=1;
    else 
        return depth;    
    return max(getdeep(depth,tree->right),getdeep(depth,tree->left));
}

int max(int a,int b)
{
	return a>b?a:b;
}
