Dear students,

This directory contains several files associated with project #10. They are:

-- README.txt – this file.

-- ospd.txt -- the official Scrabble player's dictionary (it contains 79,339 words).

-- boggle-in.txt -- a dice configuration file for the Boggle program.

-- boggle.exe -- a Windows executable with user selectable game level. 
See instructions below how to run it.

-- boggle-Mac -- a version of the above executable for MacOS. 
See instructions below how to run it.

-- boggle-gen.exe – a Windows executable that will generate a new, 
random boggle-in.txt dice configuration file.

-- boggle-gen-Mac -- a version of the above executable for MacOS

-- boggle-gen.cpp – the source code for the above executable. This file is provided 
so you can see how it works. DO NOT incorporate this code into your program. Your 
program should always read a board configuration from the provided boggle-in.txt 
file. [You can add this code to your program after the end of the semester so that 
you can have a true stand-alone game.] Hint: review this code to see how to open 
and process a file of char data.

-- boggle-dice.txt -- a file containing the dice of the actual Boggle game; 
used by boggle-gen.

=====================

For Windows users...

You should be able to open a Command Prompt window (or you can use PowerShell), and 
navigate to the directory holding the above files. You can then run the Boggle 
executable by typing:
.\boggle

If it complains that there are missing DLL's, then you need to include them in you 
environment. Please go to the project #7 page in Brightspace and follow the instructions 
in the document titled "visualization on Windows". Then attempt to run the executable 
again. (It may require a reboot of your machine.)

You should be able to run the Boggle generation executable by typing:
.\boggle-gen


=====================

For Mac users...

The following instructions apply to both the Boggle executable (boggle-Mac) and the 
Boggle Generation executable (boggle-gen-Mac).

You will first need to turn on the execution flag for the file. To do this, open a 
terminal window, navigate to the folder holding the above files, and enter the command:
chmod +x boggle-Mac

Then do the same for boggle-gen-Mac.

You can then attempt to run the program. Type:
./boggle-Mac

You will likely get a message that says the developer cannot be verified or that the 
program is not from a trusted source and that they will not run the program since it 
could be malware. If that happens, please go to the following web address and follow 
the instructions in the section titled "If you want to open an app that hasn’t been 
notarized or is from an unidentified developer" 

https://support.apple.com/en-us/HT202491

Perform the same activities for boggle-gen-Mac and then run it by typing:
./boggle-gen-Mac


