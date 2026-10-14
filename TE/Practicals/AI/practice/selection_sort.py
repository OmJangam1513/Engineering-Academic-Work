def Selection_Sort(arr):

    n =  len(arr)

    for i in range(n):

        min_index = i

        for j in range(i+1,n):
            if (arr[j] < arr[min_index]):
                min_index = j

        arr[i], arr[min_index] = arr[min_index], arr[i]
    
    return arr

arr = [23,45,73,21,63,22,1,4,43,83]

Sorted_arr = Selection_Sort(arr)

print("Sorted Array:", Sorted_arr)