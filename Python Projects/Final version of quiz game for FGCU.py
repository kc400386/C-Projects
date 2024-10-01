"""The Quizening"""
__author__ = "Caleb Blackburn"

# This program will be a quiz game
# works cited
# https://stackoverflow.com/questions/37826322/get-a-specific-input-in-python
# History.com for the history and general facts
import time


def main():
    """This function starts my quiz and houses the score function"""
    # this sets score to zero when the user starts and creates score
    score = 0
    quiz_categories(score)


# the def functions lets me create and assign my own functions.
# Adding the variables to the definition call allows me to carry them over to
# the next definition
def quiz_categories(score):
    """this function introduces the user to the game asks for their category"""
    print("Hello and welcome to Caleb Blackburn's Quiz game extraordinaire!")
    print("If you want to quit enter bye")
    print("Follow all instructions as given for your answers to count!")
    print("Type answers as written for multiple choice questions.")
    print("Some questions have corresponding letters in front of ", end=" ")
    print("them, type the letters for your answers to count.")
    print("Do not use capital letters.")
    print("Type return at any time in the quiz to return to", end=" ")
    print("category selection.")
    # this creates a loop for the user to input their category
    program_continue = True
    while program_continue:
        print("Choose your category! math, history, games, sciences")
        # this assigns the user's input to category
        category = input("Type your category here as written above: ")
        print("lets get quizening!")
        # The "if" allows me to specify a certain result to occur for a
        # specific input
        if category == "history":
            # this piece of code lets me call out this function
            countdown_loop()
            history_questions(score)
        elif category == "math":
            countdown_loop()
            math_questions(score)
        elif category == "games":
            countdown_loop()
            games_questions(score)
        elif category == "sciences":
            countdown_loop()
            sciences_questions(score)
        # this allows the user to exit the code by entering bye
        elif category == "bye":
            program_continue = False
            print("Alright well see ya!")
        # this lets the code loop if an invalid input is entered
        else:
            print("You seem to have misspelled a category please try again.")


# Each of the question definitions contains a question for the user to answer
def history_questions(score):
    """This function starts the history category and asks the user a question
    until its correct"""
    print("Welcome to the history category!")
    # this  forces the question to loop until the correct answer is given
    program_continue = True
    while program_continue:
        # hq stands for history question
        user_answer_hq1 = input("Where is Rome located? ")
        correct_answer_hq1 = "italy"
        if user_answer_hq1 == "return":
            quiz_categories(score)
        if not (user_answer_hq1 == correct_answer_hq1):
            incorrect_quiz_answer()
        if user_answer_hq1 == correct_answer_hq1:
            # this keeps score of how many questions the user got right
            score += 1
            print("Your score is now", score)
            history_question_1(score)


def history_question_1(score):
    """This function asks the user the second history question until its
    correct"""
    # sep inserts the smiley face in between good and job
    print("Good", "job.", sep=' :) ')
    print("Now when did the American civil war end?", end=' ')
    program_continue = True
    while program_continue:
        user_answer_hq2 = input("1859, 1778, 1868, 1871 ")
        correct_answer_hq2 = "1868"
        # this returns the user to the quiz categories function
        if user_answer_hq2 == "return":
            quiz_categories(score)
        if user_answer_hq2 != correct_answer_hq2:
            incorrect_quiz_answer()
        if user_answer_hq2 == correct_answer_hq2:
            score += 1
            print("Your score is now", score)
            history_question_2(score)


def history_question_2(score):
    """This function ask the user the third history question until its
    correct"""
    # the end= ' ' links my two print statements to the same line
    print("Alright you know your stuff,", end=' ')
    print("now who crossed the Alps? ")
    program_continue = True
    while program_continue:
        print("This question has 2 answers, add a space between them.")
        print("a.hannibal, b.the huns, c.napoleon,", end=" ")
        user_answer_hq3 = input("or d.jeff ")
        correct_answer_hq3 = "a c"
        if user_answer_hq3 == "return":
            quiz_categories(score)
        if user_answer_hq3 != correct_answer_hq3:
            incorrect_quiz_answer()
        if user_answer_hq3 == "d a" or "d b" or "d c":
            print("Well I mean someone named jeff might have done it but... ")
        if (user_answer_hq3 == correct_answer_hq3) and (not 0):
            score += 1
            print("Your score is now", score)
            history_question_3(score)


def history_question_3(score):
    """This function asks the user the fourth history question until its
    correct"""
    print("You know your history huh? Well last question then!")
    print("How did America acquire the Statue of Liberty?")
    program_continue = True
    while program_continue:
        print("a.MERICA!, b.it was a gift from france", end=' ')
        print("c.they made it, or d.it was a gift from england", end=" ")
        user_answer_hq4 = input("")
        correct_answer_hq4 = "b"
        if user_answer_hq4 == "return":
            quiz_categories(score)
        if user_answer_hq4 != correct_answer_hq4:
            incorrect_quiz_answer()
        if user_answer_hq4 == "a":
            print("MERICA!.........now please try again.")
        if (user_answer_hq4 == correct_answer_hq4) and (not 0):
            score += 1
            print("Your score is now", score)
            history_quiz_end_point(score)


def history_quiz_end_point(score):
    """This function ends the history category and lets the user return to
    the beginning to increase their score"""
    print("Wow good job you finished the history category!")
    print("You even got a score of", score)
    program_continue = True
    while program_continue:
        # hep stands for history end point
        print("Now if you want to go back and try the other", end=" ")
        user_answer_hep = input("categories type return.")
        if user_answer_hep == "return":
            quiz_categories(score)
        else:
            print("You seemed to have mistyped something please try again.")


# I use the majority of the numerical operators in the math section of my quiz
def math_questions(score):
    """This function starts the math category and asks the user a question
    until its correct"""
    program_continue = True
    print("Welcome to everyone's favorite category math!", end=" ")
    print("and yes you can use a calculator.")
    while program_continue:
        # mq stands for math question
        user_answer_mq1 = input("What is 99/55? ")
        correct_answer_mq1 = "1.8"
        if user_answer_mq1 == "return":
            quiz_categories(score)
        if user_answer_mq1 != correct_answer_mq1:
            incorrect_quiz_answer()
        if user_answer_mq1 == correct_answer_mq1:
            score += 1
            print("Your score is now.", score)
            math_question_1(score)


def math_question_1(score):
    """This function asks the user the second math question until its
    correct"""
    print("Nice job with that calculator!")
    print("** means exponent.")
    program_continue = True
    while program_continue:
        user_answer_mq2 = input("Now what is 5**3 - 40 ")
        correct_answer_mq2 = "85"
        if user_answer_mq2 == "return":
            quiz_categories(score)
        if user_answer_mq2 != correct_answer_mq2:
            incorrect_quiz_answer()
        if user_answer_mq2 == correct_answer_mq2:
            score += 1
            print("Your score is now", score)
            math_question_2(score)


def math_question_2(score):
    """This function asks the user the third math  question until its
    correct"""
    print("You really know how to use that calculator now do.")
    program_continue = True
    while program_continue:
        # the end function lets me print the next statement on the same line.
        user_answer_mq3 = input(" 1**2/2 + 55 - 80 * ln(1) ")
        correct_answer_mq3 = "0"
        if user_answer_mq3 == "return":
            quiz_categories(score)
        if user_answer_mq3 != correct_answer_mq3:
            incorrect_quiz_answer()
        if user_answer_mq3 == correct_answer_mq3:
            score += 1
            print("Your score is now", score)
            math_question_3(score)


def math_question_3(score):
    """This function asks the user the fourth math question until its
    correct"""
    print("% means to find the remainder", end=' ')
    print(" // means to divide and only use the remainder.")
    program_continue = True
    while program_continue:
        user_answer_mq4 = input("whats 5%8-20//9 ")
        correct_answer_mq4 = "3"
        if user_answer_mq4 == "return":
            quiz_categories(score)
        if user_answer_mq4 != correct_answer_mq4:
            incorrect_quiz_answer()
        if user_answer_mq4 == correct_answer_mq4:
            score += 1
            print("Your score is now", score)
            math_question_4(score)


def math_question_4(score):
    """This function asks the user the fifth math question until its
    correct"""
    print("Nice job this is the last question of the math section!")
    print("Answer should be one of the following: true, false")
    print("Find if the equation is true for both x=-2 and x=4")
    program_continue = True
    while program_continue:
        user_answer_mq5 = input("18-30x+1/2(90)-x>=(20+30)/(1.95(20.6))+10x ")
        correct_answer_mq5 = "false"
        if user_answer_mq5 == "return":
            quiz_categories(score)
        if (user_answer_mq5 != correct_answer_mq5) or (
                not (user_answer_mq5 == correct_answer_mq5)):
            incorrect_quiz_answer()
        if user_answer_mq5 == correct_answer_mq5:
            score += 1
            print("Your score is now", score)
            math_quiz_end_point(score)


def math_quiz_end_point(score):
    """This function ends the math category and lets the user return to
    the beginning to increase their score"""
    print("Wow good job you finished the math category!")
    print("You even got a score of", score)
    program_continue = True
    while program_continue:
        print("Now if you want to go back and try the other", end=" ")
        # mep stands for math end point
        user_answer_mep = input("categories type return.")
        if user_answer_mep == "return":
            quiz_categories(score)
        else:
            print("You seemed to have mistyped something please try again")


def games_questions(score):
    """This function starts the games category and asks the user a question
    until its correct"""
    program_continue = True
    print("Welcome to the games category!")
    print("When was the first video game made?")
    while program_continue:
        # gq means game question
        user_answer_gq1 = input("1900, 1958, 1990, 2000: ")
        correct_answer_gq1 = "1958"
        if user_answer_gq1 == "return":
            quiz_categories(score)
        if user_answer_gq1 != correct_answer_gq1:
            incorrect_quiz_answer()
        if user_answer_gq1 == correct_answer_gq1:
            score += 1
            print("Your score is now", score)
            games_question_1(score)


def games_question_1(score):
    """This function asks the user the second games question until its
    correct"""
    print("Great job!")
    program_continue = True
    while program_continue:
        print("Now who held the first olympics and where: ")
        print("a.greece athens, b.england london, c.greece sparta,", end=" ")
        user_answer_gq2 = input("d.Babylonia Babylon ")
        correct_answer_gq2 = "a"
        if user_answer_gq2 == "return":
            quiz_categories(score)
        if user_answer_gq2 != correct_answer_gq2:
            incorrect_quiz_answer()
        if user_answer_gq2 == correct_answer_gq2:
            score += 1
            print("Your score is now", score)
            games_question_2(score)


def games_question_2(score):
    """This function asks the user the third games question until its
    correct"""
    # The * allows clap to be printed 5 times
    print("Clap " * 5, "well done.")
    program_continue = True
    while program_continue:
        print("Why was the game Monopoly created ", end=' ')
        print("a.to ruin friendships, b.for fun,", end=' ')
        print("c.to promote selfishness", end=' ')
        user_answer_gq3 = input(" d.to show how flawed capitalism can be,")
        correct_answer_gq3 = "d"
        if user_answer_gq3 == "return":
            quiz_categories(score)
        if user_answer_gq3 != correct_answer_gq3:
            incorrect_quiz_answer()
        if user_answer_gq3 == "a":
            print("I mean your right but you know what the question meant.")
        if user_answer_gq3 == correct_answer_gq3:
            score += 1
            print("Your score is now", score)
            games_question_3(score)


def games_question_3(score):
    """This function asks the user the fourth games question until its
    correct"""
    print("Alright game on what was the first game ever invented.")
    program_continue = True
    while program_continue:
        user_answer_gq4 = input("a.tag, b.hunting, c.we don't know, d.catch ")
        correct_answer_gq4 = "c"
        if user_answer_gq4 == "return":
            quiz_categories(score)
        if user_answer_gq4 != correct_answer_gq4:
            incorrect_quiz_answer()
        if user_answer_gq4 == correct_answer_gq4:
            score += 1
            print("Your score is now", score)
            games_quiz_end_point(score)


def games_quiz_end_point(score):
    """This function ends the games category and lets the user return to
    the beginning to increase their score"""
    print("Wow good job you finished the games category!")
    print("You even got a score of", score)
    program_continue = True
    while program_continue:
        print("Now if you want to go back and try the other", end=" ")
        # gep stands for games end point
        user_answer_gep = input("categories type return.")
        if user_answer_gep == "return":
            quiz_categories(score)
        else:
            print("You seemed to have mistyped something please try again")


def sciences_questions(score):
    """This function starts the sciences category and asks the user a question
    until its correct"""
    program_continue = True
    print("Welcome to the sciences category!")
    print("What layer of Earth is its center?")
    while program_continue:
        # sq means science question
        print("a.core, b.inner core, c.mantle,", end=" ")
        user_answer_sq1 = input("d.centorium: ")
        correct_answer_sq1 = "b"
        if user_answer_sq1 == "return":
            quiz_categories(score)
        if user_answer_sq1 != correct_answer_sq1:
            incorrect_quiz_answer()
        if user_answer_sq1 == correct_answer_sq1:
            score += 1
            print("Your score is now", score)
            sciences_question_1(score)


def sciences_question_1(score):
    """This function asks the user the second sciences question until its
    correct"""
    # + adds the two sentences together
    print("Alright nice one!" + " Tell me", end=' ')
    print("what does malleable mean?")
    program_continue = True
    while program_continue:
        print("a.its immovable, b.its easy to shape,", end=" ")
        user_answer_sq2 = input("c.melts: ")
        correct_answer_sq2 = "b"
        if user_answer_sq2 == "return":
            quiz_categories(score)
        if user_answer_sq2 != correct_answer_sq2:
            incorrect_quiz_answer()
        if user_answer_sq2 == correct_answer_sq2:
            score += 1
            print("Your score is now", score)
            sciences_question_2(score)


def sciences_question_2(score):
    """This function asks the user the third sciences question until its
    correct"""
    print("Your doing great!", end=' ')
    print(" What animal actively hunts humans?")
    program_continue = True
    while program_continue:
        print("a.lion, b.polar bear, c.hyena,", end=" ")
        user_answer_sq3 = input("d.great white: ")
        correct_answer_sq3 = "b"
        if user_answer_sq3 == "return":
            quiz_categories(score)
        if user_answer_sq3 != correct_answer_sq3:
            incorrect_quiz_answer()
        if user_answer_sq3 == correct_answer_sq3:
            score += 1
            print("Your score is now", score)
            sciences_question_3(score)


def sciences_question_3(score):
    """This function asks the user the fourth sciences question until its
    correct"""
    print("Hey you're pretty good, but are you ready for the last", end=" ")
    print("sciences question?")
    program_continue = True
    while program_continue:
        print("What animal can be as fast as a bullet?", end=' ')
        print("a.osprey, b.mantis shrimp, c.cheetah, d.hedgehog", end=" ")
        user_answer_sq4 = input(" ")
        correct_answer_sq4 = "b"
        if user_answer_sq4 == "return":
            quiz_categories(score)
        if user_answer_sq4 != correct_answer_sq4:
            incorrect_quiz_answer()
        if user_answer_sq4 == "d":
            print("Note how I didn't say a blue hedgehog please try again.")
        if user_answer_sq4 == correct_answer_sq4:
            score += 1
            print("Your score is now", score)
            sciences_quiz_end_point(score)


def sciences_quiz_end_point(score):
    """This function ends the sciences category and lets the user return to
    the beginning to increase their score"""
    print("Wow good job you finished the sciences category!")
    print("You even got a score of", score)
    program_continue = True
    while program_continue:
        print("Now if you want to go back and try the other", end=" ")
        # sep stands for sciences end point
        user_answer_sep = input("categories type return.")
        if user_answer_sep == "return":
            quiz_categories(score)
        else:
            print("You seemed to have mistyped something please try again")


def incorrect_quiz_answer():
    """This function tells the user they answered a question wrong"""
    print("Wrong answer please try again.")


def countdown_loop():
    """ this code was suggested by professor Vanselow and creates a countdown
    that the user sees before starting the quiz"""
    countdown = 0
    for x in range(5, 0, -1):
        countdown += 1
        print(countdown)
        time.sleep(.5)


main()
