# Clipboard-Chat-Application 
## First real app I've ever made 😎. Built in Embarcadero RAD 13 using C++. First real challenge in my programming career.🤠
Check out the "master" branch.

Folder contains:

-Client: Used to run the client side of the project, cannot run without server side. ✅

-Server: Ensures to log every user action and send packages to every single client. ✅

Here is an example of Client 1 discussing with Client 2 and using most of the application's functionalities.
### Client 1
![image alt](https://github.com/crx-21/Clipboard-Chat-Application/blob/master/Client%201.PNG?raw=true)
### Client 2
![image alt](https://github.com/crx-21/Clipboard-Chat-Application/blob/master/Client%202.PNG?raw=true)
### This is what happens on the Server:
![image alt](https://github.com/crx-21/Clipboard-Chat-Application/blob/master/Server.PNG?raw=true)

Every message sent towards the server comes with flags attached to the message. The Server's job is to parse this messages and send back to the clients in such way that the message can be succesfuly interpreted.
Other functionalities not present in the photos:
-Theme Selector. Users can select one of the 3 themes available. They are remembered on the next login.
-Message Saver. Users can save select messages. (They are saved in a backup txt file for safety reasons)
-Presets. Users can work on long messages, and use them as a presets. You can load the chat into the Preset and edit it as you wish. Then save it to a txt file.




