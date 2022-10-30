# internalTrainer

A little and very simple trainer for Assault Cube 1.3.0.2 with a gui made with Windows Forms (NOT FOR ONLINE).

HOW TO USE IT:
Basically just compile the project in x86 and inject the resulting dll in assault cube with any Dll injector (NOT INCLUDED).

HOW IT WORKS?
Basically the Win32Api do everything, we only tell him how:
-From the dll entry point we create a thread from where we'll create the form wich (im not really sure how this works) will be runing in another thread.
The Freezing Health and Infinity Jump funcions works with loops so we also need run these on threads so the main control flow won't be affected.
The other 3 Buttons (No Recoil, No ammo decrement and Rapid Fire) Works by patching bytes so we'll just use functions for this.

To control the creation and exit of the threads we use global boolean varibles, to make the button a "switch" wich changes his state from
"active" to "unactive" we use booleans variables declared inside the form class.

The Detach&Exit button first close all the active threads and change the bytes who were patched to its original state, then its supposed to close the main thread (the one we open on the dll entry point) wich would detach the dll from AC and close the form but actually it doesn't work as expected (i'll create a solution later) so when the Detach&Exit is clicked the form closes but the dll still attached to the process.
