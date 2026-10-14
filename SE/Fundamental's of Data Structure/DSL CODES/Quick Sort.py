"""Write a Python program to store first year percentage of students in array. 
Write function for sorting array of floating point numbers in ascending order using quick sort 
and display top five scores."""

def Quick_sort(arr,left,right):
    if left<right:
        partition_pos=partition(arr,left,right)
        Quick_sort(arr,left,partition_pos-1)
        Quick_sort(arr,partition_pos+1,right)
def partition(arr,left,right):
    i=left
    j=right-1
    pivot=arr[right]
    while i<j:
        while(i<right) and arr[i]<pivot:
            i+=1
        while(j>left) and arr[j]>=pivot:
            j-=1 
        if i<j:
            arr[i],arr[j]=arr[j],arr[i]
    if arr[i]>pivot:
        arr[i],arr[right]=arr[right],arr[i]
    return i
def reverse_sort(Score_list):
    for i in range(len(Score_list)):
        min_score=i 
        for j in range(i+1,len(Score_list)):
            Score_list[j]>min_score
            min_score=j
            Score_list[i],Score_list[min_score]=Score_list[min_score],Score_list[i]
    
def top_five(Score_list):
    Quick_sort(Score_list,0,len(Score_list)-1)
    reverse_sort(Score_list)

    temp=[]
    for i in range(5):
        temp=Score_list[i]
        print(temp)
    


n=int(input("Enter the no. of students present in the class:"))
print("Enter the scores:(in float point)")
Score_list=[]
for i in range(n):
    data=float(input())
    Score_list.append(data)
print("Unsorted Score:",Score_list)

Quick_sort(Score_list,0,len(Score_list)-1)
print("Sorted Scores:",Score_list)
print("Top Five scores:")
top_five(Score_list)


