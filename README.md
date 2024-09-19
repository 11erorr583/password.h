Add files via upload
I have tried to create a header file named as password  which is a alternative solution to password management including features authentication , hide password , show password and function to  automatically  generate password
I have used _getch() to handle user input which enables to accept data from user by no need to press enter 
also I have used special escape sequences to handle cursor position 

USAGE:
Authentication
password pwd;
char user_input[] = "your_input";
bool is_authenticated = pwd.authentication(user_input, strlen(user_input));
show_password:
bool is_valid = pwd.show();
Hide_password:
bool is_valid = pwd.hide();
Generate_ password:
string new_password = pwd.pass_generator(8); // Generates an 8-character password
I am trying to further improve my code :)
