char* reverseWords(char* s) {
    // 先删除多余空格
    int count = 0;
    int i = 0;
    while(s[count] == ' ' && ++count); // 计数开头的空格
    while(s[count])
        if(s[count] != ' ' || s[count+1] != ' ')
            s[i++] = s[count++];
        else
            s[i] = s[++count];
    s[i] = 0;
    if(s[0] && s[i-1] == ' ') // 末尾可能剩一个空格
        s[i-1] = 0;
    // 单独翻转每个单词
    int l, r;
    i = 0;
    while(s[i]) {
        l = i;
        r = i;
        while(s[r] != ' ' && s[r] != 0 && ++r)
            i = s[r] == ' '? r+1: r;
        while(l < r-1)
        {
            int temp = s[l];
            s[l++] = s[--r];
            s[r] = temp;
        }
    }
    
    // 翻转整个字符串
    l = 0;
    r = strlen(s) - 1;
    while(l < r)
    {
        int temp = s[l];
        s[l++] = s[r];
        s[r--] = temp;
    }
    
    return s; 
}
