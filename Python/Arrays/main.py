from functions.max_value import max_value
from functions.min_value import min_value
from functions.mid_value import mid_value
from functions.bubble_sort import bubble_sort
from functions.selection_sort import selection_sort

my_arr = [10,2,23,14,67]

print(max_value(my_arr))
print(min_value(my_arr))
print(mid_value(my_arr))
print(bubble_sort(my_arr, False))
print(selection_sort(my_arr))