import random
import re

responses = {
    'greeting' : [
                    'Hello, Welcome to our Restaurant. How can I assist you today?', 
                    'Hi there! How many I help you?', 
                    'Welcome! Do you have a reservation?'
                  
                  ],
    
    'farewell' : [
                    'Thank you for dining at our restaurant! Do visit again!',
                    'I am glad you enjoyed our food and service. Do visit again!',
                    'Your satisfaction is our top pirority. I am glad you liked our service. Do visit again!'
                  
                  ],

    'about_menu' : [
                    'Have you dined with us before?',
                    "Are you interested in today's specials?",
                    "These are our signature dishes."

                    ],
    
    'ordering' : [
                    'These are our appetizers and soups to start the dinner',
                    'These are our main course dishes.',
                    'Would you like any sided with it?'

                ],
    
    'after_meal' : [
                    'Would you like any desserts?',
                    'Would you like anything to drink?',
                    'Can I get you the check?',
                    'Did you like our food and service?'

                    ],

    'default' : [
                    "I'm sorry but I didn't understand your request.",
                    "Apologies, I didn't quite get that. Could you please repeat?",
                    "Pardon me. I was unable to understand your question."
  
                ],
    
        

}

def respond(inquiry):
    inquiry = inquiry.lower()

    if re.search(r"\b(?:hello|hi)\b", inquiry):
        return random.choice(responses['greeting'])
    
    elif re.search(r"\b(?:goodbye|bye)\b", inquiry):
        return random.choice(responses['farewell'])
    
    elif re.search(r"\b(?:about|menu)\b", inquiry):
        return random.choice(responses['about_menu'])
    
    elif re.search(r"\b(?:place|order)\b", inquiry):
        return random.choice(responses['ordering'])
    
    elif re.search(r"\b(?:after|meal|over|done|finish)\b", inquiry):
        return random.choice(responses['after_meal'])
    
    elif inquiry == 'yes' or inquiry == 'Yes':
        return 'Great!'
    
    else:
        return random.choice(responses['default'])
        

print("Welcome to the Customer Interaction Chatbot for Restaruants!")
print("Type 'exit' to end the conversation.\n")

while True:
    user_input = input("Customer: ")

    if(user_input.lower() == 'exit'):
        break
    
    if(user_input.lower() == 'bye' or user_input.lower() == 'goodbye'):
        break
    
    
    bot_response = respond(user_input)
    print("Chatbot: ",bot_response)

print('\nThank you for interacting with the Chatbot. Goodbye!')