function create_tinyram_code(cashFrom, cashTo, cashValue) {
	let code = '';
	code += "MOV r1 r0 " + cashFrom + ";" //1 string
	code += "MOV r2 r0 " + cashTo + ";" //2 string
	code += "MOV r3 r0 " + cashValue + ";" //3 string
	//add flag for answer
	code += "MOV r8 r0 1;" //4 string
	//here add total cash =cash1+cash2=r4
	code += "ADD r4 r1 r2;" //5 string
	//here check that cash1>=value 
	code += "CMPAE r0 r1 r3;" //6 string
	//if not compare jump to end(where answer), last param is number of string where answer is
	code += "CNJMP r0 r0 16;" //7 string
	//else make change
	//here r5=cash1-value=new cash1
	code += "SUB r5 r1 r3;" //8 string
	//here cash2+value=r6=new cash2
	code += "ADD r6 r2 r3;" //9 string
	//here new toal cash=new cash1+new cash2
	code += "ADD r7 r5 r6;" //10 string
	//here check that total cash old=total cash n
	code += "CMPAE r0 r4 r7;" //11 string
	//if not compare jump to end(where answer), last param is number of string where answer is
	code += "CNJMP r0 r0 16;" //12 string
	//else change value of flag
	code += "MOV r8 r0 0;" //13 string
	//and store new cash1 value into 1 memory
	code += "STOREW r5 r0 1;" //14 string
	//and store new cash2 value into 2 memory
	code += "STOREW r6 r0 2;" //15 string
	//this is numberstring to jump and answer
	code += "ANSWER r0 r0 r8" //16 string
	return code
}

function binary_string_to_int(string1) {

	const string2 = string1.slice(1,string1.length()-1).split(' ')
	let valueInMemory=0
	if (string2!=['']) {
		for (let i=0;i<string2.length();++1) {
			valueInMemory+=int(string2[i])*Math.pow(2,i)
		}
	}
	return valueInMemory

}


export default {
	create_tinyram_code,
	binary_string_to_int
}