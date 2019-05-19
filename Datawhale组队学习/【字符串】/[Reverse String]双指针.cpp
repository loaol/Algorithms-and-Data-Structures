void reverseString(char* s, int sSize)
{
    int from=0 ,to=sSize-1 ;
    char type;
    
    while(from<to)
    {
        type=s[from];
        s[from++]=s[to];
        s[to--]=type;
    }
    
    return s;

}
