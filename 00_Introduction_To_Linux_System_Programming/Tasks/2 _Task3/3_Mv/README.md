#commands used#
gcc myMv.c -o myMv.out

#created command name:#
myMv

#examples:#

-- enter zero argument which produces an error
ezzat@ezzatPC:~/Desktop/STM_Trainning/2 _Task3/3_Mv$ ./myMv.out
>>Error! please enter 2 file name or pathes as argument

-- enterz one argument which produces an error
ezzat@ezzatPC:~/Desktop/STM_Trainning/2 _Task3/3_Mv$ ./myMv.out test.txt
>>Error! please enter 2 file name or pathes as argument

--renaming the file test.txt to test3.txt
ezzat@ezzatPC:~/Desktop/STM_Trainning/2 _Task3/3_Mv$ ./myMv.out test.txt test3.txt

--moving the file test.txt to /home/ezzat/Desktop/STM_Trainning, but an error will be produced 
--because we already renamed it :)
ezzat@ezzatPC:~/Desktop/STM_Trainning/2 _Task3/3_Mv$ ./myMv.out test.txt /home/ezzat/Desktop/STM_Trainning
>>Can not open the source file :(

--moving the file test3.txt to /home/ezzat/Desktop/STM_Trainning
ezzat@ezzatPC:~/Desktop/STM_Trainning/2 _Task3/3_Mv$ ./myMv.out test3.txt /home/ezzat/Desktop/STM_Trainning
