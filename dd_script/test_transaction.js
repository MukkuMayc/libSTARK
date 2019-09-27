'use strict'
import {create_tinyram_code, binary_string_to_int} from "./func.js"
// DATA
const security_value1 = 5;
const security_value2 = 10;
const security_param1 = '-t' + security_value1;
const security_param2 = '-s' + security_value2;

const opportiunityTrsnsactionStringNumber = 3;
const valueOfFirstUsersCashStringNumber = 1;
const valueOfSecondUsersCashStringNumber = 2;
const stringOpportunity = "can make this transaction";
const stringCash1Check = "new cash is : ";
const stringCash2Check = "new cash is : ";

//start timer
const start = new Date().getTime();


// test_db_script.cleanUpForTesting()
// test_db_script.addBackupData()
// quantity_transaction = test_db_script.getQuantityTransaction()

for (let i = 0; i < quantity_transaction; ++i) {
	console.log("transaction", i);
	// data = test_db_script.getData(i)
	// let fromID = data[0];
	// let toID = data[1];
	// let cashFrom = data[2];
	// let cashTo = data[3];
	// let cashValue = data[4];
	// let cashID = data[5];

	//add new asm instaructions
	const tinyramCode = create_tinyram_code(cashFrom,cashTo,cashValue);

	//run stark-tinyram.js

	//here must be output from stark-tinyram.js
	let lines ='';

	//get string for amswer after make tinyram
	const inputOpportunityString = lines[opportunityTransactionStringNumber];
	const inputFirstCash = lines[valueOfFirstUsersCashStringNumber];
	const inputSecondCash = lines[valueOfSecondUsersCashStringNumber];

	//chech that we "can make this transaction"
	if (inputOpportunityString == stringOpportunity) {

		//check binarystring with user's cash
		//first user cash 
		if (inputFirstCash.slice(0,14) == stringCash1Check){
			//add new user's 1 cash
			cashFrom = binary_string_to_int(inputFirstCash.slice(14,inputFirstCash.length()));
		}
		//second user cash
		if (inputSecondCash.slice(0,14) == stringCash2Check){
			//add new user's 2 cash
			cashTo = binary_string_to_int(inputSecondCash.slice(14,inputSecondCash.length()));
		}
		if (i == quantity_transaction-1){
			console.log("transaction completed successfully");
		}
			
		//test_db_script.updateDB(cashFrom, cashTo, fromID, toID, cashID);
	}
	else {
		console.log("ERROR: can't make transaction");
		//test_db_script.callBackup();
		break;	
	}

// test_db_script.deleteBackupData()
// test_db_script.printDB()
//end timer
const end = new Date().getTime();
//print time 
console.log('time: ${(end-start)/1000}ms')

}