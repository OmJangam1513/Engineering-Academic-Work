r1=int(input("Enter Number of Rows in matrix_1 : "))
c1=int(input("Enter Number of Columns in matrix_1 : "))

 

print("==================================xxx==================================")    

print("Enter Elements for matrix_1:")
    
matrix_1=[[int(input()) for i in range (r1)]for j in range (c1)]

print("Matrix_1 :")

for i in range (r1) :
    
    for j in range (c1) :
        print(format(matrix_1[i][j]),end=" ")
    print()    

print()
print("==================================xxx==================================")    
print()

r2=int(input("Enter Number of Rows in matrix_2 : "))
c2=int(input("Enter Number of Columns in matrix_2 : "))

 

print("==================================xxx==================================")    

print("Enter Elements for matrix_2:")
    
matrix_2=[[int(input()) for i in range (r2)]for j in range (c2)]

print("Matrix_2 :")

for i in range (r2) :
    
    for j in range (c2) :
        print(format(matrix_2[i][j]),end=" ")
    print()

print("==================================xxx==================================")    


if (r1!=r2 or c1!=c2):
    print("The Matrix Are Not Having Same No. Of Rows And Columns")
else :
    
    print("Addition of the two Matrices :")
    
    add=[[(0) for i in range (r1)]for j in range (c1)]    
    for i in range (r1):
        for j in range (c1):
            add[i][j]=matrix_1[i][j]+matrix_2[i][j]

    
    for i in range (r1):
        for j in range (c1):
            print(format(add[i][j]),end=" ")
        print()       

print("==================================xxx==================================")    

 
if (r1!=r2 or c1!=c2):
    
    print("The Matrix Are Not Having Same No. Of Rows And Columns")

else :
    
    print("Substraction of the two Matrices :")
    
    sub=[[(0) for i in range (r1)]for j in range (c1)]    
    for i in range (r1):
        for j in range (c1):
            sub[i][j]=matrix_1[i][j]-matrix_2[i][j]
    
    for i in range (r1):
        for j in range (c1):
            print(format(sub[i][j]),end=" ")
        print()   
    
print("==================================xxx==================================")    


if (r1!=r2 or c1!=c2):
    
    print("The Matrix Are Not Having Same No. Of Rows And Columns")

else :
    
    print("Multiplication of the two Matrices :")
    
    mul=[[(0) for i in range (r1)]for j in range (c1)]    
    for i in range (len(matrix_1)):
        for j in range (len(matrix_2 [i])):
            for k in range (len(matrix_2)):
                    
                mul[i][j] += matrix_1[i][k] * matrix_2[k][j]
    
    for i in range (r1):
        for j in range (c1):
            print(format(mul[i][j]),end=" ")
        print()       

print("==================================xxx==================================")    

print("Transpose of the two Matrices are :")
print()

print("==================================xxx==================================")    
    
Trans1=[[(0) for i in range (r1)]for j in range (c1)]    
for i in range (r1):
    for j in range (c1):
            
        Trans1[i][j] = matrix_1[j][i]

print("Transpose of Matrix_1")
 
for i in range (r1):
    for j in range (c1):
        print(format(Trans1[i][j]),end=" ")
    print()       

print("==================================xxx==================================")    

        
Trans2=[[(0) for i in range (r1)]for j in range (c1)]    
for i in range (r1):
    for j in range (c2):
            
        Trans2[i][j] = matrix_2[j][i]

print("Transpose of Matrix_2")

for i in range (r1):
    for j in range (c1):
        print(format(Trans2[i][j]),end=" ")
    print()       
        