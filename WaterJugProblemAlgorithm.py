p = int(input("Enter the Capacity of Jug 1 : ")) #Capacity of Jug 1                         #----Chandresh Maniya----
q = int(input("Enter the Capacity of Jug 2 : ")) #Capacity of Jug 2                         
goalP = int(input("Enter the goal for Jug 1 : ")) #Final goal for Jug 1                     
goalQ = int(input("Enter the goal for Jug 2 : ")) #Final goal for Jug 2                     
print("\n")
x = 0 #Current Water in Jug 1
y = 0 #Current Water in Jug 2

#Main Process...
def mainProcess():
    global p, q, x, y, goalP, goalQ
    
    print("Press 1: Fill Jug 1")
    print("Press 2: Fill Jug 2")
    print("Press 3: Empty Jug 1")
    print("Press 4: Empty Jug 2")
    print("Press 5: Transfer from Jug 1 to Jug 2")
    print("Press 6: Transfer from Jug 2 to Jug 1")

    #For continue the process until goal chieved...
    choice = int(input("Enter the Choice : "))

    if choice == 1:
        fill1()
    elif choice == 2:
        fill2()
    elif choice == 3:
        empty1()
    elif choice == 4:
        empty2()
    elif choice == 5:
        Jug1_to_Jug2()
    elif choice == 6:
        Jug2_to_Jug1()
    
    if x != goalP or y != goalQ:
        mainProcess()
    else:
        print("Goal Achieved !!!")


#Fill the Jug 1...
def fill1():
    global p, q, x, y, goalP, goalQ

    if x < p:
        x = p
        print("Jug 1 is Filld")
        print("(",x,",",y,")")
    else:
        print("Jug 1 is Already Full")
        print("(",x,",",y,")")


#Fill the Jug 2...
def fill2():
    global p, q, x, y, goalP, goalQ

    if y < q:
        y = q
        print("Jug 2 is Filled")
        print("(",x,",",y,")")
    else:
        print("Jug 2 is Already Full")
        print("(",x,",",y,")")


#Empty the Jug 1...
def empty1():
    global p, q, x, y, goalP, goalQ

    if x > 0:
        x = 0
        print("Jug 1 Emptied Successfully")
        print("(",x,",",y,")")
    else:
        print("Jug 1 is Already Empty")
        print("(",x,",",y,")")


#Empty the Jug 2...
def empty2():
    global p, q, x, y, goalP, goalQ

    if y > 0:
        y = 0
        print("Jug 2 Emptied Successfully")
        print("(",x,",",y,")")
    else:
        print("Jug 2 is Already Empty")
        print("(",x,",",y,")")


#Transfering from the Jug 1 to the Jug 2...
def Jug1_to_Jug2():
    global p, q, x, y, goalP, goalQ

    if x + y > q:
        x = (x + y) - q
        y = q
    elif x + y <= q:
        y = x + y
        x = 0
    
    print("(",x,",",y,")")


#Transfering the Jug 2 to the Jug 1...
def Jug2_to_Jug1():
    global p, q, x, y, goalP, goalQ

    if x + y > p:
        x = p
        y = (x + y) - p
    elif x + y <= q:
        x = x + y
        y = 0
    
    print("(",x,",",y,")")


mainProcess()