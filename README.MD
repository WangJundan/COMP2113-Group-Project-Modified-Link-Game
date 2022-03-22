# Table of Content
* [Identification of Team Members](https://github.com/WangJundan/COMP2113-Group-Project/blob/main/README.MD#identification-of-team-members)
* [Description of the Game](https://github.com/WangJundan/COMP2113-Group-Project/blob/main/README.MD#description-of-the-game)
    * [Brief Introduction](https://github.com/WangJundan/COMP2113-Group-Project/blob/main/README.MD#brief-introduction)
    * [Game Rules](https://github.com/WangJundan/COMP2113-Group-Project/blob/main/README.MD#game-rules)
* [Features to Implement](https://github.com/WangJundan/COMP2113-Group-Project/blob/main/README.MD#features-to-implement)
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
     * The player need to find out all the connectable letters by pairs. When finding out a pair and input their locations via the windows, they would disappear automaticlly. When all letters disappear, the player wins.  
     * As for so-called "connectable", it refers to: whenever horizonal or vertical, the connecting line can only have at most 3 straight segment.  
     * super-remove button: randomly eliminate one connectable pair regardless the limitation of the above rules.
     

# Features to Implement:

***1. Various maps provided***  
```
We may utilize the coding element 1 (Generation of random game sets or events) and 5 (Program codes in multiple files) to achieve the goal:  
While storing all the codes of various maps in a “map” file, we could initialize the game in another “main body” file.  
Recall the map element by generating a random map from the “map” file which is provided to work on.
```

***2.Judgement and Elimination***  
```
We may utilize the coding element 2 (Data structures for storing game status) & 4(File input/output) to achieve the goal:  
We use a 9*9 square matrix to store 81 char variables, the variables are among 26 english letters, i.e. a, b, c….  
Input:  
Every time input two location coordinates.  
Output:  
1. When it suffices: 1) the  letters of the two selected locations are the same, 2) They can be linked with less than or equal to three straight lines that are not blocked by any nonzero location, change both of them to 0.  
2. When it does not satisfy the condition, output “Error. Select Again”  
3. When all the variables are changed to 0, print out “Game End” and end the programme.
```

***3. Remove button***  
```
We may utilize the coding element 1 (Generation of random game sets or events) to achieve the goal:   
We may generate a random letter from the alphabet and remove its corresponding location to 0 value and thus it can be eliminated.
```

