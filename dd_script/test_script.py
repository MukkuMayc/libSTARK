import subprocess
import linecache
import os
import create_asm_file
import test_string_work
import test_db_script
import time
#add testing security params
security_value1=5
security_value2=10
security_param1='-t'+str(security_value1)  
security_param2='-s'+str(security_value2)
#add params for fixed string
opportiunityTrsnsactionStringNumber = 4;
valueOfFirstUsersCashStringNumber = 2;
valueOfSecondUsersCashStringNumber = 3;
stringOpportunity = "can make this transaction"
stringCash1Check = "new cash is : "
stringCash2Check = "new cash is : "
#add testing array data
array_cash = [20,20,20,20];
backup_array_cash = array_cash[:];
array_value_of_transaction= [10,6,58,2,3,4];

startTime = time.time()

test_db_script.cleanUpForTesting()
test_db_script.addBackupData()
quantity_transaction = test_db_script.getQuantityTransaction()
# print("suck qua ", quantity_transaction)

#-------------------------------------------------------------------------------------------
#try to include db
for i in range(quantity_transaction):
	print("transaction", i)
	data = test_db_script.getData(i)
	fromID = data[0]
	toID = data[1]
	cashFrom = data[2]
	cashTo = data[3]
	cashValue = data [4]
	cashID = data [5]
	# print("data suck", data)
	# print(fromID, toID, cashFrom, cashTo, cashValue)

	#------------------------------------------------------------------------
	#start tinyRAM with db values

	#create  asm file
	create_asm_file.create_asm_file(cashFrom, cashTo, cashValue)
	#create .txt with console duplication for parcing
	f=open("condoub.txt", 'w') 	
	#run tinyram
	subprocess.call(["./../tinyram/stark-tinyram/stark-tinyram", "test.asm", security_param1, security_param2], stdout=f)
	f.close()

	#get string from tunyRAM output
	inputOpportunityString = linecache.getline('condoub.txt', opportiunityTrsnsactionStringNumber);

	inputFirstCash = linecache.getline('condoub.txt',valueOfFirstUsersCashStringNumber);
	inputSecondCash = linecache.getline('condoub.txt',valueOfSecondUsersCashStringNumber);


	r = open("condoub.txt", 'r')
	dfghd= r.read()
	print(dfghd)
	r.close()


	#chech that we "can make this transaction"
	if inputOpportunityString[:len(inputOpportunityString)-1]==stringOpportunity:
		# print(i)
		#check binarystring with user's cash
		#first user cash 
		if (inputFirstCash[:14])==stringCash1Check:
			#add new user's 1 cash 
			# print("fuckfuck", inputFirstCash)
			# print("fuckfuckfuck   ", test_string_work.binary_string_to_int(inputFirstCash[14:len(inputFirstCash)-1]))
			cashFrom=test_string_work.binary_string_to_int(inputFirstCash[14:len(inputFirstCash)-1])
			# print("fuck 1 fuck", array_cash)
		#second user cash
		if inputSecondCash[:14]==stringCash2Check:
			#add new user's 2 cash
			cashTo=test_string_work.binary_string_to_int(inputSecondCash[14:len(inputSecondCash)-1])
			# print("fuck 2 fuck",array_cash)
			# print("-------------------------------------------")
		if i==quantity_transaction-1:
			print("transaction completed successfully")
			
		test_db_script.updateDB(cashFrom, cashTo, fromID, toID, cashID)

	else:
		print("ERROR: can't make transaction")
		test_db_script.callBackup()
		break

	
	os.remove("test.asm")
	linecache.clearcache()
	os.remove("condoub.txt")
test_db_script.deleteBackupData()
test_db_script.printDB()
print("time", "--- %s seconds ---" % (time.time() - startTime))

#end of try include db
#---------------------------------------------------------------------------------------------------------------------------



# #start use tinyram 
# for i in range(len(array_value_of_transaction)):
# 	print(array_cash)

# 	#create  asm file
# 	create_asm_file.create_asm_file(array_cash[i % len(array_cash)], array_cash[(i+1) % len(array_cash)], array_value_of_transaction[i])
# 	# create_asm_file.create_asm_file(array_cash[i], array_cash[i+1], array_value_of_transaction[i])
# 	# print(i, array_cash[i % len(array_cash)], array_cash[(i+1) % len(array_cash)], array_value_of_transaction[i])
# 	# print(linecache.getline('test.asm', 1))
# 	# print(linecache.getline('test.asm', 2))
# 	# print(linecache.getline('test.asm', 3))

# 	#create .txt with console duplication for parcing
# 	f=open("condoub.txt", 'w') 	
# 	#run tinyram
# 	subprocess.call(["./../build/tinyram/stark-tinyram/stark-tinyram", "test.asm", security_param1, security_param2], stdout=f)
# 	f.close()

# 	#all info after finish tinyRAM now in condoub.txt, start parsing file
# 	f=open("condoub.txt", 'r')

# 	inputOpportunityString = linecache.getline('condoub.txt', opportiunityTrsnsactionStringNumber);
# 	inputFirstCash = linecache.getline('condoub.txt',valueOfFirstUsersCashStringNumber);
# 	inputSecondCash = linecache.getline('condoub.txt',valueOfSecondUsersCashStringNumber);
# 	#print(inputOpportunityString, "\n", inputFirstCash, "\n", inputSecondCash)

# 	#chech that we "can make this transaction"
# 	if inputOpportunityString[:len(inputOpportunityString)-1]==stringOpportunity:
# 		# print(i)
# 		#check binarystring with user's cash
# 		#first user cash 
# 		if (inputFirstCash[:14])==stringCash1Check:
# 			#add new user's 1 cash 
# 			array_cash[i % len(array_cash)]=test_string_work.binary_string_to_int(inputFirstCash[14:len(inputFirstCash)-1])
# 			# print("fuck 1 fuck", array_cash)
# 		#second user cash
# 		if inputSecondCash[:14]==stringCash2Check:
# 			#add new user's 2 cash
# 			array_cash[(i+1) % len(array_cash)]=test_string_work.binary_string_to_int(inputSecondCash[14:len(inputSecondCash)-1])
# 			# print("fuck 2 fuck",array_cash)
# 			# print("-------------------------------------------")
# 		if i==len(array_value_of_transaction):
# 			print("transaction completed successfully")
# 			print(array_cash)
# 	else:
# 		print("ERROR: can't make transaction")
# 		array_cash=backup_array_cash
# 		print(array_cash) 
# 		break
# 	f.close()
# 	os.remove("test.asm")
# 	linecache.clearcache()
# 	os.remove("condoub.txt")