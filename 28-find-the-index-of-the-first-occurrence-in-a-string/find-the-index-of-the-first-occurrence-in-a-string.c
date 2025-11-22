int strStr(char* haystack, char* needle) {
    int hLen = strlen(haystack);
    int nLen = strlen(needle);  
    if (hLen<nLen) 
    {
        return -1;
    }  
    for (int i=0;i<=hLen;i++) 
    {
        int j;
        for (j=0;j<nLen;j++) 
        {
            if (haystack[i+j]!=needle[j]) 
            {
                break;
            }
        }
        if (j==nLen) 
        {
            return i;
        }
    }
    
    return -1;
}