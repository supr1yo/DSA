def selection_sort(arr: list)-> list:
    '''The Selection Sort algorithm finds the lowest value in an array and moves it to the front of the array'''
    size = len(arr) # Length of the array

    for i in range(size):
        min_index = i # Index of the lowest value element
        for j in range(i+1, size):
            if arr[j] < arr[min_index]:
                min_index = j 
        min_value = arr.pop(min_index) # Remove the element
        arr.insert(i, min_value) # Insert element to the front
    
    return arr


