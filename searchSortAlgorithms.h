template <class elemType>
int seqSearch(const elemType list[], int length, const elemType& item) {
    int loc;
    bool found = false;  
    loc = 0;

    while (loc < length && !found)
        if (list[loc] == item)
            found = true;
        else
            loc++;
     
     if (found)
        return loc;
    else
        return -1;
} //end seqSearch

template <class elemType>
int binarySearch(const elemType list[], int length, const elemType& item) {
    int first = 0;
    int last = length - 1;
    int mid;

    bool found = false;

    while (first <= last && !found)
    {
        mid = (first + last) / 2;

        if (list[mid] == item)
            found = true;
        else if (list[mid] > item)
            last = mid - 1;
        else
            first = mid + 1;
    }

    if (found)
        return mid;
    else 
        return -1;
} //end binarySearch

template <class elemType>
void bubbleSort(elemType list[], int length) {
    for (int iteration = 1; iteration < length; iteration++)
    {
        for (int index = 0; index < length - iteration;
                            index++)
        {
            if (list[index] > list[index + 1])
            {
                elemType temp = list[index];
                list[index] = list[index + 1];
                list[index + 1] = temp;
            }
        }
    }
} //end bubbleSort

template <class elemType>
int minLocation(elemType list[], int first, int last) {
    int loc, minIndex;

    minIndex = first;

    for (loc = first + 1; loc <= last; loc++) {
        if (list[loc] < list[minIndex]) {
            minIndex = loc;
        }
    }

    return minIndex;
} //end minLocation

template <class elemType>
void selectionSort(elemType list[], int length) {
    int loc, minIndex;

    for (loc = 0; loc < length; loc++)
    {
        minIndex = minLocation(list, loc, length - 1);
        swap(list, loc, minIndex);
    }
} //end selectionSort

template <class elemType>
void swap(elemType list[], int first, int second) {
    elemType temp;

    temp = list[first];
    list[first] = list[second];
    list[second] = temp;
} //end swap