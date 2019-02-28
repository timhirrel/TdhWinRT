# TdhWinRT

Trying to port a desktop app developed in C++ to the Windows App Store, I ran into some problems:
1. how to get the install directory (for read only access)
2. how to get the data directory (for read/write access)
3. how to display the help pdf file. 

There were no simple functions to accomplish these necessary tasks, so I delved into the arcane world of WinRT and, after much time and
frustration, developed some functions and put them into a library, TdhWinRT. The header, import library and dll's are provided so 
these functions can be used as is within an (x86) app. The source code and VS project file are provided so the functions may be examined, 
modified or extended. 

Note: these functions can be used only within an app has been "converted" to a uwp app, which can be done in VS with the store | create
app package option. So it's best to incoprate them conditionally, based on some preprocessor defintion that can be defined or not. 

These files may be used without consideration to me, at the sole decretion and responsibility of the user.
