def merge_sort(lst):
    if len(lst) <= 1:
        return lst

    # Divide the list into two halves
    mid = len(lst) // 2
    left_half = lst[:mid] # the beginning up to the element at index mid
    right_half = lst[mid:] # at index mid to the end of the list

    # Recursive calls to sort the two halves
    left_half = merge_sort(left_half)
    right_half = merge_sort(right_half)

    # Merge the sorted halves
    return merge(left_half, right_half)

def merge(left, right):
    merged = []
    i = j = 0

    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            merged.append(left[i])
            i += 1
        else:
            merged.append(right[j])
            j += 1

    # Append any remaining elements
    merged.extend(left[i:])
    merged.extend(right[j:])

    return merged


a = [38, 27, 43, 3, 9, 82, 10]
sorted_a = merge_sort(a)
print("Original list:", a)
print("Sorted list:", sorted_a)
