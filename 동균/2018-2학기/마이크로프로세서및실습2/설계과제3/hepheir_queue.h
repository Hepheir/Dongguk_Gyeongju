int push(void *arr, int typeSize, int *length, void item)
{
    *(arr + *length) = item;
    return *length++;
}

void shift(void *arr, int typeSize, int *length, void item)
{
    for (int i = 0; i < length-1; i++)
    {
        *(arr+i) = *(arr+i+1);
    }
    *(arr+length) = item;
}