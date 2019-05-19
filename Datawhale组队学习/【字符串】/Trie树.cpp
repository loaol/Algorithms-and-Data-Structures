#include <stdio.h>  
#include <stdlib.h>  
#include <memory.h>  
  
typedef struct Trie_node_stru  
{  
    int  count; //记录该处终结的单词个数  
    struct Trie_node_stru *next[26];//指向各个子树的指针,下标0-25代表26字符  
  
}TrieNode, *Trie;  
  
TrieNode* trie_createTrieNode()  
{  
    TrieNode* tmp = (TrieNode*)malloc(sizeof(TrieNode));  
    tmp->count = 0;  
    memset(tmp->next, 0, sizeof(tmp->next));  
    return tmp;  
}  
  
int trie_insert(Trie root, char* word)  
{  
    TrieNode* node = root;  
    char *p = word;  
    while(*p)  
    {  
        if(NULL == node->next[*p-'a'])  
        {  
            node->next[*p-'a'] = trie_createTrieNode();  
        }  
        node = node->next[*p-'a'];  
        p++;  
    }  
    node->count += 1;  
    printf("%-20s appears for %d time(s) in the Trie!\r\n",  
           word, node->count);  
    return 0;  
}  
  
int trie_search(Trie root, char* word)  
{  
    TrieNode* node = root;  
    char *p = word;  
    while(*p && NULL!=node)  
    {  
        node = node->next[*p-'a'];  
        p++;  
    }  
    return (node!=NULL && node->count>0);  
}
  
int main()  
{  
	char a[26]={};
	char p[2]="a";
	for (int i=0;i<26;i++)
		a[i]=i+97;
    Trie t = trie_createTrieNode();
    for (int i=0;i<26;i++)
    {
		p[0]=a[i];
    	trie_insert(t,p);
	}

    //test
    printf("====================\r\n");  
    if(trie_search(t,"b"))  
      printf("true\n");  
    else  
      printf("false\n");
    return 0;  
}  
