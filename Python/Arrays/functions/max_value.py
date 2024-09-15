def max_value(arr: list) -> int:
    '''
    Returns the maximum element in an array
    '''
    max_val = arr[0]

    for i in arr:
        if i > max_val:
            max_val = i
    
    return max_val