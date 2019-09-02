def create_asm_file(cash1,cash2,value):
	f=open("test.asm",'w')
	#create asm opcode file 
	#here add data to register
	#print(cash1, cash2, value)
	f.write("MOV"+" "+"r1"+" "+"r0"+" " + str(cash1) +'\n') #1 string
	f.write("MOV"+" "+"r2"+" "+"r0"+" " + str(cash2) + '\n') #2 string
	f.write("MOV"+" "+"r3"+" "+"r0"+" " + str(value) + '\n') #3 string
	#add flag for answer
	f.write("MOV"+" "+"r8"+" "+"r0"+" "+"1"+'\n') #4 string
	#here add total cash =cash1+cash2=r4
	f.write("ADD"+" "+"r4"+" "+"r1"+" "+"r2"+'\n') #5 string
	#here check that cash1>=value 
	f.write("CMPAE"+" "+"r0"+" "+"r1"+" "+"r3"+'\n') #6 string
	#if not compare jump to end(where answer), last param is number of string where answer is
	f.write("CNJMP"+" "+"r0"+" "+"r0"+" "+"16"+'\n') #7 string
	#else make change
	#here r5=cash1-value=new cash1
	f.write("SUB"+" "+"r5"+" "+"r1"+" "+"r3"+'\n') #8 string
	#here cash2+value=r6=new cash2
	f.write("ADD"+" "+"r6"+" "+"r2"+" "+"r3"+'\n') #9 string
	#here new toal cash=new cash1+new cash2
	f.write("ADD"+" "+"r7"+" "+"r5"+" "+"r6"+'\n') #10 string
	#here check that total cash old=total cash n
	f.write("CMPAE"+" "+"r0"+" "+"r4"+" "+"r7"+'\n') #11 string
	#if not compare jump to end(where answer), last param is number of string where answer is
	f.write("CNJMP"+" "+"r0"+" "+"r0"+" "+"16"+'\n') #12 string
	#else change value of flag
	f.write("MOV"+" "+"r8"+" "+"r0"+" "+"0"+'\n') #13 string
	#and store new cash1 value into 1 memory
	f.write("STOREW"+" "+"r5"+" "+"r0"+" "+"1"+'\n') #14 string
	#and store new cash2 value into 2 memory
	f.write("STOREW"+" "+"r6"+" "+"r0"+" "+"2"+'\n') #15 string
	#this is numberstring to jump and answer
	f.write("ANSWER"+" "+"r0"+" "+"r0"+" "+"r8") #16 string



 

