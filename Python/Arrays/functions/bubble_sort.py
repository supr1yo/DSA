def bubble_sort(arr: list, ascending: bool = True) -> list:
    '''Bubble Sort is an algorithm that sorts an array from the lowest value to the highest value.'''
    
    if ascending is True:
        size = len(arr) # Length of array

        for i in range(size):
            swapped = False
            for j in range(size - i - 1):
                if arr[j] > arr[j+1]:
                    arr[j], arr[j+1] = arr[j+1], arr[j]
                    swapped = True
            if not swapped:
                break
    else:
        size = len(arr) # Length of array

        for i in range(size):
            swapped = False
            for j in range(size - i - 1):
                if arr[j] < arr[j+1]:
                    arr[j], arr[j+1] = arr[j+1], arr[j]
                    swapped = True
            if not swapped:
                break
    
    return arr
