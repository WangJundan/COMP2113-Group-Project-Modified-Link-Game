# Table of Content
* [Identification of Team Members](https://github.com/WangJundan/COMP2113-Group-Project-Modified-Link-Game/blob/main/README.MD#identification-of-team-members)
* [Description of the Game](https://github.com/WangJundan/COMP2113-Group-Project-Modified-Link-Game/blob/main/README.MD#description-of-the-game)
    * [Brief Introduction](https://github.com/WangJundan/COMP2113-Group-Project-Modified-Link-Game/blob/main/README.MD#brief-introduction)
    * [Game Rules](https://github.com/WangJundan/COMP2113-Group-Project-Modified-Link-Game/blob/main/README.MD#game-rules)
* [Features to Implement](https://github.com/WangJundan/COMP2113-Group-Project-Modified-Link-Game/blob/main/README.MD#features-to-implement)
* [Compilation and execution instructions](https://github.com/WangJundan/COMP2113-Group-Project-Modified-Link-Game/blob/main/README.MD#compilation-and-execution-instructions)
# Identification of Team Members: 
   **Student 1:** Wang Jundan  
   **Student uid:** 3035771464  
   **Student 2:** Wu Shuang  
   **Student uid:** 3035772767
# Description of the Game:
  ### Brief Introduction:
    We decide to create a link game, in which the player can eliminate two blocks as long as they are connected together, i.e. can be linked with less than or equal to three straight lines， and the game ends when all the blocks are eliminated.

  
  
  ### Game Rules:
     * To start the game, the player need to enter a number of 1 to 5 to choose a map.
     * During the playing process, the user-interfece would provide the player with 2 location coordinates input windows and the map chosen with random integer number distribution.
     * Normally, the player need to find out all the connectable numbers which are exactly the same by pairs. When finding out a pair and input their locations via the windows by entering 4 numbers (the row of the first number, the column of the first number, the row of the second number, the column of the second number), they would disappear automaticlly (turn to 0). When all letters disappear, the player wins.  
     * As for "connectable", it refers to: whenever horizonal or vertical, the connecting line between these two numbers can only have straight segments and at most 3 segments. 
     * Except for normal elimination, we extra provide the super-remove operation: when the four input numbers are 0, 0, 0 and 9 correspondingly, we then implement the super-remove operation. It would randomly generate an integer from 1 to 9. And then probably eliminate all this integer in the map regardless the limitation of the above rules but also have low posibility to .
     

# Features to Implement:
Notice that our implementation should include all following coding elements:
```
    1. Generation of random game sets or events
    2. Data structures for storing game status
    3. Dynamic memory management
    4. File input/output (e.g., for loading/saving game status)
    5. Program codes in multiple files
 ```
Therefore we could implement following features utilizing the above coding elements:  
***1. Storing Map Information***  
```
We may utilize the coding element 2 (Data structures for storing game status) to achieve the goal:  
We use a 8*8 2D array to store 36 variables, the variables are integers(i.e. 1,2,3...).The varaibles belong to the outer circle remain constantly 0.
And as for the blank entries (when letters are eliminated, the corresponding entries go blank), we store its value as 0.
This data structure is convenient for us to compare value and make judgement in our subsequent works.
```
***2. Judgement and elimination operation***  
```
We may utilize the coding element 5 (program codes in multiple files) to achieve the goal:
We have 3 various file for the program which are the header file(.h), the function definition file (.cpp) and the main body file (.cpp).
In the header file we have all the function declarations and this header file is included in both function definition file and the main body file.
In the function definition file we have all the function definition codes which is convenient for game implement like check whether the input coordinates can be eliminate legally
In the main body file we have stored the map infomations by initializing arrays and the codes for judgement process by using the functions contained in the header file.
Input:  
Every time input two location coordinates.  
Judgement and Output:  
1. When it suffices: 1) the  integers of the two selected locations are the same, 2) They can be linked with less than or equal to three straight lines (namely two turns) that are not blocked by any nonzero location, change both of them to 0 and thus implement eliminations.  
2. When it does not satisfy the condition 1), output error message to let the player choose coordinates again.
3. After each of the successful elimination, store the current data status by updating the dynamic memory array and print the refreshed array again for the convenience of the user action.
When all the variables are changed to 0, print out “Game End” and end the programme.
```


***3. Super-Remove Operation***  
```
We may utilize the coding element 1 (Generation of random game sets or events) and coding element 3 (dynamic memory management) to achieve the goal:   
When the input is 0,0,0,9, We may generate a random number from the 1 to 9 and mark this number as key.
For each super-remove operation, we have a dynamic array 
```

***4. Storing unfinished game status***
```
We may utilize the coding element 4 (file input/output) to achieve the goal:
We have a txt file for saving the unfinished game map infomation.
Before the game, we would check whether the file is empty or not. If empty, then it means there're no unfinished game status save, thus start the new game; if not, then it means there's an unfinished game and we use file output to the current map to keep working on the unfinished game.
When in a gaming process, we use file input to record every change of the current operating map.
And when the game is over i.e. the player wins, the file would be cleaned to an empty file.
```

# Compilation and execution instructions:
```
* Step 1:
* Step 2:
```

