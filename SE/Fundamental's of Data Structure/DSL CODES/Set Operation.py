
class M() :
    def __init__(self):
        
        self.Set_1=[]
        
        self.Set_2=[]
        
        self.s_0= None
        self.s1 = None
        self.s2 = None
        self.Universal_1=[]
        self.Union_1 = []
        self.uniq_1 = []
        self.Intersection_1 = []
        self.Difference_1 = []
        self.Difference_2 = []
        self.Neither_1=[]
        
    def Sets_input(self) :
        
        
        while True:
           
           
            print("Enter the name of students in Whole School (Enter Finish to Stop Entering the name) :")
        
            self.s_0 = input()
            
            if (self.s_0 == "Finish"):
                break
            
            self.Universal_1.append(self.s_0)
        
        print("==========================================xxx==================================================")
        print()
        
        while True:
            
            
            print("Enter the name of student's playing Cricket (Enter Finish to Stop Entering the name) :")
        
            self.s1 = input()
            
            if (self.s1 == "Finish"):
                break
            
            self.Set_1.append(self.s1)
        
        print("==========================================xxx==================================================")
        print()
        
        
        
        
        
        while True:
        
            print("Enter the name of student's playing Badminton (Enter Finish to Stop Entering the name) :")
            
            self.s2= input()
            
            if (self.s2 == "Finish"):
                break        
        
            self.Set_2.append(self.s2)
            

    def Union(self) :
        
        
        self.Union_1=self.Set_1 + self.Set_2
        self.uniq_1 =list(set(self.Union_1)) #It removes the repeated elements using set keyword
        print()
        print("==========================================xxx==================================================")
        print("Union Of Both cricket And Badminton player's are",self.uniq_1,end=" ")
        

    def Intersection(self) :
        
        self.Intersection_1= list(set(self.Set_1) & set(self.Set_2))
        print()
        print()
        print("==========================================xxx==================================================")
        print("Set of students who play both cricket and badminton are",self.Intersection_1,end=" ")
        
    def A_B(self) :
        self.Difference_1= list (set(self.Set_1) - set(self.Set_2))
        print()
        print()
        print("==========================================xxx==================================================")
        print("Set of students who play only cricket are",self.Difference_1,end=" ")
        
    def B_A(self) :
        self.Difference_2= list (set(self.Set_2) - set(self.Set_1))
        print()
        print()
        print("==========================================xxx==================================================")
        print("Set of students who play only badminton are",self.Difference_2,end=" ")
        
        
    def Neither(self) :
        self.Neither_1= list(set(self.Universal_1) - set(self.uniq_1))
        print()
        print()
        print("==========================================xxx==================================================")
        print("Number of students who play neither cricket nor badminton",self.Neither_1,end=" ")
        
def main():
    
    obj1= M()
    obj1.Sets_input()
    obj1.Union()
    obj1.Intersection()
    obj1.A_B()
    obj1.B_A()
    obj1.Neither()

if __name__=="__main__":
    main()



