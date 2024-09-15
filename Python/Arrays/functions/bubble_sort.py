
def bubble_sort(arr: list) -> list:
    size = len(arr) # Length of array


    for i in range(size):
        swapped = False
        for j in range(size - i - 1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        if not swapped:
            break
    
    return arr
