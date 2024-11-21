#commands used#
gcc femto_shell.c -o femto.out

#created commands name:#
myEcho
myPwd
myMv
exit

#examples:#


--open shell
ezzat@ezzatPC:~/Desktop/STM_Trainning/2 _Task3/4_Femto_shell$ ./femto.out 


*********************************************************

Welcome to my command shell
Please note that the max command size is 100

*********************************************************
ezzat>myPwd ss
Error!!

ezzat>myPwd           
/home/ezzat/Desktop/STM_Trainning/2 _Task3/4_Femto_shell

ezzat>myEcho

ezzat>myEcho sssss
sssss

ezzat>myMv test3.txt test4.txt   

ezzat>myMv test4.txt /home/ezzat/Desktop

ezzat>exit
Good Bye:)

ezzat@ezzatPC:~/Desktop/STM_Trainning/2 _Task3/4_Femto_shell$ ls
femto.out  femto_shell.c  README.md

