def min_value(arr: list) -> int:
    '''
    Returns the minimum element in an array
    '''
    min_val = arr[0]

    for i in arr:
        if i < min_val:
            min_val = i
    
    return min_val