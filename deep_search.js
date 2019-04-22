function deep_comparison(input1, input2){

	if(typeof(input1) != "object" && (input1 == input2)){
		if(input1 === input2){
			return true;
		}
		else{
			return false;
		}
	}
	else{
		if((input1 === null && input2 != null) || (input1 != null && input2 === null)){
			return false;
		}
		else if(input1 === null && input2 === null){
			return true;
		}
		else{
			var num = Object.keys(input1).length;
			var counter = 1;
			if(num != Object.keys(input2).length){
				return false;
			}

			for(var prop in input1){
				counter = 1;
				for(var prop2 in input2){
					if((prop2 === prop) && (input1[prop] === input2[prop2])){
						break;
					}
					counter = counter + 1;
				}
				if(counter > num){
					return false;
				}
			}
			return true;
		}
		return true;
	}

}
