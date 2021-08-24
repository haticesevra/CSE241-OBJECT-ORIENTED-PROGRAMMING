
WHAT IS NEW IN THE GAME

1 - I added 'SAVE' and 'LOAD' processes to my game. 

2 - If the user enters the 'SAVE FILENAME.TXT' command, I stopped the game. I opened a txt file according to the name entered by the user.
    I have transferred all the information about the players and gameboard to this file.
    In order to load this information in the future, I opened a file named previous_game.txt and copied the information from the user's file there.
    Finally I finished the game.

3 - If the user enters the command 'LOAD FILENAME.TXT' I restored the old game information from my previous_game.txt file.

4 - I also used decltype, auto, enum in my homework.

5 - I have added a mechanism to the game that can distinguish whether the input is command or coordinate. (it is in file_operations function)

6 - In my zip file there are two different 'save files' named GAME.TXT and previous_game.txt.

7 - You can look at the functions.h file to take a look at the short descriptions of the functions I wrote for HW2.

8 - The game continues according to the rules of the previous game after the 'load' command is entered. 
That is, the game type (computer-user or user1-user2), board size and game board information are updated according to the 'saved' game.

9 - 