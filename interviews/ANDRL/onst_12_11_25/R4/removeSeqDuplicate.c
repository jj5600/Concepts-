
// most ideal solution 
char * removeSeqDup2(char * temp )
{
    if(temp == NULL || *temp == '\0')
    {
        return NULL;
    }
    
    char * read = temp;
    char * write = temp;
    char * head = temp;
    
    write++;
    read++;
    while(*read != '\0')
    {
        if(*(write-1) != *read )
        {
            *write = *read;
            write++;
        }
        read++;
    }
    printf("we made it!");
    *write = '\0';
    return head;
}
