"""

Write a Python program to store marks scored in subject “Fundamental of Data
Structure” by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Display the list of students who were absent for the test
d) Display mark with highest frequency

"""

Total_student=int(input("How many students are in Class?-->"))
S=[]
for i in range(Total_student):
    data=input("Name of the student "+str(i+1)+" is:")
    S.append(data)
print("Students in class:",S)
marks_scored=[]
absent_student=[]
total=0
for i in S:
    marks=eval(input("Marks scored by student  "+ i +  " in FDS test is:(put marks -1 for Absent students):"))
    if marks==-1:
        absent_student.append(i)
    else:
        marks_scored.append(marks)
        total+=marks
def avg():
    Average=total/(len(marks_scored))
    print("Average of Score of the class :",Average)
#2..To print higesht and lowest Score
def maxi():
    max_score=marks_scored[0]
    for mark in marks_scored:
        if max_score<mark:
            max_score=mark;
    print("Highest score of class is:",max_score)
def mini():
    min_score=marks_scored[0]
    for mark in marks_scored:
        if mark<min_score:
            min_score=mark;
    print("Lowest score of class is:",min_score)

#mark with highest frequency
def freq():
    
    max = j = 0
    print("\nMarks\t|\tFrequency")
    for i in marks_scored:
        if(marks_scored.index(i)==j):
            print(i,"\t|\t",marks_scored.count(i))
            if(max<marks_scored.count(i)):
                max = marks_scored.count(i)
                mark = i
        j += 1
    print("\nScore",mark,"is with highest frequency",max)

while(1):
    print("\nEnter\n1.Average\n2.High score\n3.Lowest Score\n4.Higest Frequency\n5.No. of Absent Students\n6Name of the Absent students")
    o=input()
    if o=='1':
        avg()
    elif o=='2':
        maxi()
    elif o=='3':
        mini()
    elif o=='4':
        freq()
    elif o=='5':
        print("No. of students absent for FDS test:",len(absent_student))
    elif o=='6':
        print("Name of students who were absent for the test are: ",absent_student)








