# Ricardo Calvo
# A01028889

def quickSort(Arr, left, right):
    if left < right:  # si esto es verdad significa que el arreglo contiene al menos dos elementos
        position = partition(Arr, left, right)
        quickSort(Arr, left, position - 1)
        quickSort(Arr, position + 1, right)


def partition(Arr, left, right):
    i = left
    j = right - 1
    pivot = Arr[right]
    print(f"pivot: {pivot}")

    while i < j:
        while i < right and Arr[i] < pivot:
            i += 1
        while j > left and Arr[j] >= pivot:
            j -= 1
        if i < j:
            Arr[i], Arr[j] = Arr[j], Arr[i]
            print(Arr)

    if Arr[i] > pivot:
        Arr[i], Arr[right] = Arr[right], Arr[i]
        print(Arr)

    return i


Arr = [523, 108, 999, 754, 0, 632, 45, 2500, 876, 125,
       1800, 394, 272, 15, 1000, -12, -32, -500, -789, -100]
quickSort(Arr, 0, len(Arr)-1)
