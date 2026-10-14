def Linear_Probing():
    
    Telephone=int(input("Enter the Telephone Number to Stored :"))
    
    index=Telephone%size
    
    flag=False
    
    if(Hash[index]==-1):
        
        Hash[index]=Telephone
        
        flag=True
    
    else:
        
        for j in range (size):
            
            P = (index+j)%size
            
            if(Hash[P]==-1):
                
                Hash[P]=Telephone
                
                flag=True
    
    if(flag):
        print("---------------------------------------")
        print("Succesfully Entered in the Data Base")
        print("---------------------------------------")
    else:
        print("Error: The Data Base is full ")
    
def Quadratic_Probing():
    
    Telephone=int(input("Enter the Telephone Number to Stored :"))
    
    index=Telephone%size
    
    flag=False
    
    if(Hash[index]==-1):
        
        Hash[index]=Telephone
        
        flag=True
    
    else:
        
        for j in range (size):
            
            P = (index+(j*j))%size
            
            if(Hash[P]==-1):
                
                Hash[P]=Telephone
                
                flag=True
    
    if(flag):
        print("---------------------------------------")
        print("Succesfully Entered in the Data Base")
        print("---------------------------------------")
    else:
        print("Error: The Data Base is full ")
        
def Searching():
    
    Target=int(input("Enter The Element to be Searched :"))
    
    count = 0
    
    flag= False
    
    for i in range (size):
    
        count=count+1
            
        if(Hash[i]==Target):
            
            print("Telephone Number Found")
            
            print(f"With {count} Comparison.")
            
            flag = True
    
    if(flag):
        return 0
    else:
        print("Telephone Number Not Found")
        
Hash=[]

size=int(input("Enter the size of the hasing table :"))

for i in range (size):
    
    Hash.append(-1)


print("==============MENU================")
print("1.Linear Probing")
print("2.Quadratic Probing")
print("3.Searching")
print("4.Exit")
print("-------------------------------")

print("Enter the choice :")
choice=int(input())

while(True):
    
    if(choice==1):
        Linear_Probing()
    elif(choice==2):
        Quadratic_Probing()
    elif(choice==3):
        Searching()
    elif(choice==4):
        break
    else:
        print()
        print("=========================================")
        print("Error :Invalid Choice Entered.")
        print("Please try Again.......")
        print("=========================================")
        print()