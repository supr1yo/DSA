def mid_value(arr: list) -> list:
    '''
    Returns middle value of an array
    '''
    size = len(arr)
    mid = []

    if size % 2 == 0:
        mid.append(arr[size//2-1])
        mid.append(arr[size//2])
    else:
        mid.append(arr[size//2])

    return mid
