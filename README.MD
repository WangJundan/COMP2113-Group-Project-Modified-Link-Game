# Table of Content
* [Identification of Team Members](https://github.com/WangJundan/COMP2113-Group-Project-Modified-Link-Game/blob/main/README.MD#identification-of-team-members)
* [Description of the Game](https://github.com/WangJundan/COMP2113-Group-Project-Modified-Link-Game/blob/main/README.MD#description-of-the-game)
    * [Brief Introduction](https://github.com/WangJundan/COMP2113-Group-Project-Modified-Link-Game/blob/main/README.MD#brief-introduction)
    * [Game Rules](https://github.com/WangJundan/COMP2113-Group-Project-Modified-Link-Game/blob/main/README.MD#game-rules)
* [Features to Implement](https://github.com/WangJundan/COMP2113-Group-Project-Modified-Link-Game/blob/main/README.MD#features-to-implement)
* [Compilation and execution instructions]()
# Identification of Team Members: 
   **Student 1:** Wang Jundan  
   **Student uid:** 3035771464  
   **Student 2:** Wu Shuang  
   **Student uid:** 3035772767
# Description of the Game:
  ### Brief Introduction:
    We decide to create a link game, in which the player can eliminate two blocks as long as they are connected together, i.e. can be linked with less than or equal to three straight lines， and the game ends when all the blocks are eliminated.

  
  
  ### Game Rules:
     * The user-interfece would provide the player with a super-remove botton, 2 location coordinates input windows and a map with random English letters distribution.  
     * The player need to find out all the connectable letters which are exactly the same by pairs. When finding out a pair and input their locations via the windows, they would disappear automaticlly (turn to 0). When all letters disappear, the player wins.  
     * As for so-called "connectable", it refers to: whenever horizonal or vertical, the connecting line can only have at most 3 straight segment.  
     * super-remove button: randomly eliminate one pair of the same letters regardless the limitation of the above rules.
     

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
***2. Various Maps Provided***  
```
We may utilize the coding element 1 (Generation of random game sets or events) and 5 (Program codes in multiple files) to achieve the goal:  
While storing all the codes of various maps in a “map” file, we could initialize the game in another “main body” file.  
Recall the map element by generating a random map from the “map” file which is provided to work on.
```

***3. Judgement and Elimination***  
```
We may utilize the coding element 4 (File input/output) and 3 (Dynamic memory management) to achieve the goal:  
As for every new game, we use a dynamic memory matrix to record updates of data.
Input:  
Every time input two location coordinates.  
Judgement and Output:  
1. When it suffices: 1) the  integers of the two selected locations are the same, 2) They can be linked with less than or equal to three straight lines (namely two turns) that are not blocked by any nonzero location, change both of them to 0 and thus implement eliminations.  
2. When it does not satisfy the condition 1), output “Error. Select Again”  
After every opration of elimination, store the current data status by updating the dynamic memory matrix.  
When all the variables are changed to 0, print out “Game End” and end the programme.
```

***4. Super-Remove Button***  
```
We may utilize the coding element 1 (Generation of random game sets or events) to achieve the goal:   
We may generate a random letter from the alphabet and remove its corresponding location to 0 value and thus it can be eliminated.
```

# Compilation and execution instructions:
```
* Step 1:
* Step 2:
```

