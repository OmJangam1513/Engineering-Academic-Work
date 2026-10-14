
def RBchatbot():

    while(True):
        user = input("You: ").lower()

        if user == 'hello':
            print("Bot: Hi, how may i help You")
            print("1.Book Ticket")
            print("2.Cancel Ticket")
            print("3.Price Details")
            print("4.Bye")

        elif user == "book ticket":

            print("Bot: Successfully booked the bus ticket.")
    
        elif user == "cancel ticket":

            print("Bot: Cancelling Your Ticket")
    
        elif user == "price details":

            print("Bot: The fair cost 500 rs.")

        elif user == "bye":

            print("Bot: Hope you like the experience")
            break
        
        else:
            print("Bot: I didn't understand...")

RBchatbot()