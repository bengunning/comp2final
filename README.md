# comp2final
A sheep-herding simulation and puzzle game. CSE 20212 final project.
Designed by David Mattia, John Nolan, Guixing Lin, and Ben Gunning.

INTRODUCTION
        Our program allows the user to simulate the herd mentality of a flock of sheep within a pen. The           sheep undergo motion that is influenced by the user, other sheep, and the overall environment. The user is able to         interact with the sheep by placing a point that can direct sheep to either congregate in a certain area or flee from         said location. Additionally, the user has the power to add or remove sheep at his or her discretion.

KEY CONCEPTS
        Move Mode:
                Move mode determines how the sheep respond to the point that the user marks in the game window. Based on the                     current move mode, sheep will move either toward or away from the point, providing the user with greater                         versatility in the control and influence over the herd of sheep.
        Click Mode:
		The user has three possible cursors. The default cursor looks like a whistle, and each click marks the position that sheep flee from or coalesce towards. The other two cursors either add or remove sheep. When adding sheep the cursor looks like another grey sheep, but when removing sheep it looks like a wolf. 


CONTROLS
        q: Close the graphics window and quit the program.
        p: If paused, unpause the game. If unpaused, pause the game.
        1: Switch to the first move type, Attract, where sheep are attracted to and congregate around the user's point.
        2: Switch to the second move type, Repel, where sheep generally move away from the user's point.
	Up arrow: Switch to the generative cursor, represented by another sheep, to add more sheep. 
	Down arrow: Switch to the detracting cursor, represented by a wolf, to remove sheep. 
        Esc: Switch to the first click type. In this mode, the cursor is a whistle. Clicks move the location of the user's point.
	




