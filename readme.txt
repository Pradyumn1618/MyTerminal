    
This terminal can execute myls,myps,mycp,mymv and mygrep with few options:

1)myls:
	myls [OPTION]
	This works as original command ls.
	This can be executed with following options:
	1) -l 2) -s 3) -g 4) -lS 5) -ls 6) -a
2)myps:
	myps [OPTION]
	This works as original command ps.
	This can be executed with following options:
	1) -a 2) -F 3) -aF 4) -e 5) -eF
3)mycp:
	mycp [OPTION] [SOURCE] [TARGET]
	mycp [SOURCE] [SOURCE]..... [DIRECTORY]
	This works as original command cp.
	This can be executed with following options:
	1) -i 2) -n 3) -u 4) -v
4)mymv:
	mymv [OPTION] [SOURCE] [TARGET]
	mymv [SOURCE] [SOURCE]..... [DIRECTORY]
	This works as original command mv.
	This can be executed with following options:
	1) -i 2) -n 3) -u 4) -v
5)mygrep:
	mygrep [OPTION] PATTERN [FILE] [FILE]...
	This works as original command grep.
	NO NEED TO PUT QUOTES AROUND THE PATTERN!
	This can be executed with following options:
	1) -s 2) -n 3) -c 4) -m

Type 'help' and ENTER for detailed usage of options for every command.
Type '[COMMAND] --help' and ENTER for detailed usage of options for a particular command.
	

cd is getting executed with the help of chdir().

The requirements to execute this terminal are :
-> A Linux Ubuntu machine.
-> GCC should be installed in the machine:
	If GCC is not installed in your machine, do the following:
	Open the terminal on your machine and run the following commands:
		-> "sudo apt update"
		-> "sudo apt install build-essential"
		OR
		-> "sudo apt install gcc"
	To check if install then run the following command:
	        -> "gcc --version"
-> libreadline :
Install libreadline in your machine:
For that run the following command on your terminal:
		-> "sudo apt-get install libreadline8 libreadline-dev"
Now you are ready to run this terminal!

Steps to execute:

-> Change the directory to the directory where the files are located.
-> Now run the following commands: 
    -> "make" (To compile the executable files.)
    -> "./terminal" (To execute the terminal.)

Now you can run whichever command you want to run from the above mentioned commands.



