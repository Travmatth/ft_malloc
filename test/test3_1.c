int main ()
{
    char * addr1;
    char * addr2;
    char * addr3;

    addr1 = (char *) malloc (16 * M);
    strcpy (addr1, "hello \ n");
    print (addr1);
    addr2 = (char *) malloc (16 * M);
    addr3 = (char *) realloc (addr1, 128 * M);
    addr3 [127 * M] = 42;
    print (ADDR3);
    return (0);
}

