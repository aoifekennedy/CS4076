The aim of my game is to use the Map to try find the Winning Room without running out of lives and losing the game. 
The game is programmed to change the Winning Room every time it is restarted, so no round is the same.
The game is lost by running out of lives or won by finding the Winning Room.
To Play:
        -Use the "North" "South" "East" "West" buttons to move in your desired direction.
        -Use the "Teleport" command to be teleported from your current room to a random room on the map.
        -Use the "Map" button to view the map and the direction of each room.
        -Use the "Info" button for an explanation on how to play the game.
        -The "Health" box shows how much health remains. The value is 3 health values per 1 life.
        -The "Lives" box shows how many lives are remaining. You start with 3 lives.
        -There are items in certain rooms, you can double click to pick them up and double click to drop them again. If these items are food/water, by picking these up you will gain health!
        -Use the "Character Info" button to view what items you are carrying.
        -Use the "Room Items" button to view if/what items are in the room you are in.
        -Use the "Character Items" button to drop unwanted items.
        -Use the "See Winning Room" button to foretell the Winning Room in that round. The number shown once the button is pressed corresponds to that value on the alphabet. Eg. 4 = D.
        
        
      
C++ Assessment Criteria:
Listed below are the C++ concepts I have implemented into my Zork Project.

-Inheritance:
  -> Used in MainWindow.h. MainWindow inherits from QMainWindow.
-Arrays & Pointers:
  -> Vectors are used in the room creations. Vectors are similar to dynamic arrays.
-Private,Public,Protected
  -> Used in header files.
 -Friendship:
  ->There are multiple examples of friend class declarations. For example in MainWindow.h, Character is a friend class of MainWindow which means MainWindow can access private and protected members of Character.
 -Destructors:
  -> Used in MainWindow.cpp, deletes MainWindow ui.
 -Header Files (Inlusion Guards):
  -> Most files have #include statements.
 -Pointers:
  -> Multiple examples of local variables that directly reference a value. Eg. MainWindow.h & randomRoom
 -namespaces:
  -> There are multiple examples of the use of namespaces. Eg. ZorkUl.h & namespace std.
