# The list/stack of plates.
plates = []

def home_screen():
    """This function is where the user can select other functions from
     to modify the stack of plates or exit the program entirely."""

    #Creates the variable which manages the while loop and user input.
    home_screen_choice = ""
    
    #While loop that runs while the user is using the program.
    while (home_screen_choice != 'exit') and (home_screen_choice != 'Exit'):
        print("\n")
        print("                 |Home Screen|")
        print("Hello welcome to plate stacker this program allows the user ")
        print("to stack nonzero positive whole numbers in a pyramid pattern.")    
        print("To begin please select an option and start stacking!")
        print("To add plates type add.")
        print("To remove plates type remove.")
        print("To display your current stack type display.")
        print("To exit this program type exit.")
        #Grabs user input to select which option to nagivate to.
        home_screen_choice = input("Type your choice here: ")

        #If option activate depending on what the user enters such as "add" for the Add screen. 
        #Allows the user to type the lower or upper case version of their input.
        if (home_screen_choice == 'add') or (home_screen_choice == 'Add'):
           add_plates_to_stack()

        elif (home_screen_choice == 'remove') or (home_screen_choice == 'Remove'):
            remove_plates_from_stack()

        elif (home_screen_choice == 'display') or (home_screen_choice == 'Display'):
            display_plates_from_stack()

        elif (home_screen_choice == 'exit') or (home_screen_choice == 'Exit'):
             print("Thank you for using my program have a nice day!")

        else:
            print("That is not an option please try again.")


def add_plates_to_stack():
    """This function uses the what_to_add_to_plates variable and .append to add 
     values to the plates list."""

    #Variable that monitors the while loop only set to false once the user successfully inputs a number.
    add_loop_check = ""
    while not add_loop_check:
        
        print("\n")
        print("                 |Add Screen|")
        print("To add a plate size to the stack type a nonzero positive whole number that is smaller")
        print("or equal to the previous number, unless its your first number,")
        print("in which case go crazy!")
        print("If you wish to exit the add screen type exit.")
        #Grabs user input to add to the stack.
        what_to_add_to_plates = input("Please type a number to add to the stack: ")
        #Grabs the current stack size for comparison to what_to_add_to_plates.
        current_stack_size = len(plates)

        #Lets the user exit the Add Screen if they need to.
        if (what_to_add_to_plates == 'exit') or (what_to_add_to_plates == 'Exit'):
            add_loop_check = " "

        #Checks if the user inputs is a number by using the .isnumeric() function.    
        elif (what_to_add_to_plates <= '0') or (not what_to_add_to_plates.isnumeric()):
            print("The value you entered is invalid please try again.")
        
        #Checks if the stack is empty.
        elif current_stack_size == 0:
            print("Plate added!")
            add_loop_check = " "
            #Converts the user input to an int to add to the plates list/stack
            plates.append(int(what_to_add_to_plates))

        #Adds a plate to the stack if the requirments are met.
        elif int(what_to_add_to_plates) <= int(plates[current_stack_size-1]): 
            print("Plate added!")
            add_loop_check = " "
            #Converts the user input to an int to add to the plates list/stack
            plates.append(int(what_to_add_to_plates))

        #Checks if the plate they added is too large for the stack.
        elif int(what_to_add_to_plates) > int(plates[current_stack_size-1]):
            print("That value is to large to add to the stack.")  

        #Catches invalid inputs.
        else:
            print("The value you entered is invalid please try again.")


def remove_plates_from_stack(): 
    """ This function uses the amount_to_remove_from_plates variable and .pop to
    remove an amount of numbers from the plates list/stack."""

    #Variable that monitors the while loop only set to false once the user successfully inputs a number.
    remove_loop_check = ""
    while not remove_loop_check:

        print("\n")
        print("                 |Remove Screen|")

        #Grabs the current stack size for comparison to amount_to_remove_from_plates and to check if the stack is empty.
        current_stack_size = len(plates)
        if (current_stack_size == 0):
            print("The stack is empty you cant remove any plates.")
            home_screen()
        
        print("Type how many plates you want removed from the stack as a nonzero positive whole number")
        print("but make sure you dont remove more values then there are in the stack.")
        print("If you wish to exit the remove screen type exit.")
        print(f"The current height of the stack is {current_stack_size}")
        amount_to_remove_from_plates = input("Please type how many plates to remove from the stack. ")

        #Lets the user exit the Remove Screen if they need to
        if (amount_to_remove_from_plates == 'exit') or (amount_to_remove_from_plates == 'Exit'):
            remove_loop_check = " "

        #Checks if the user inputs is a number by using the .isnumeric() function.      
        elif (amount_to_remove_from_plates <= '0') or (not amount_to_remove_from_plates.isnumeric()):
            print("The value you entered is invalid please try again.")

        #Uses .pop to remove as many numbers from the stack as the user requested.
        elif int(amount_to_remove_from_plates) <= int(current_stack_size): 
            
            #Converts amount_to_remove_from_plates to an int to
            #loop through the stack 'iteration' times using .pop to remove values from the stack.
            #Iteration is a variable that slowly increases to iterate through the list.
            for iteration in range(int(amount_to_remove_from_plates)):
                plates.pop()
            print(f"{amount_to_remove_from_plates} Plate(s) removed!")
            remove_loop_check = " "
            

        #Checks if the user tries to remove too many plates from the plates list/stack.
        elif int(amount_to_remove_from_plates) > int(plates[current_stack_size-1]):
            print("The stack isnt that large please select a smaller value to remove.")

         #Catches invalid inputs.
        else:
            print("The value you entered is invalid please try again.")


def display_plates_from_stack(): 
    """This function uses a for loop with range to print the stack of plates."""

    print("\n")
    print("                 |Display Screen|")
    print("Here is your current stack.")

    #Grabs the current stack size to check if the stack is empty.
    current_stack_size = len(plates)
    if (current_stack_size == 0):
            print("The stack is empty you cant display any plates.")
            home_screen()

    #For loop goes through the stack and print all numbers in the stack in order of first to last.
    #Iteration is a variable that slowly increases to iterate through the list.
    for iteration in range(current_stack_size):
        #Scroll value is the value by which plates uses to iterate through itself.
        scroll_value = current_stack_size-iteration
        print(plates[scroll_value-1])


#This calls my home_screen or 'main' function to begin the program.
home_screen()