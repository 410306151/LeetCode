//// Every open bracket has its corresponding close bracket
//// Start by ), ] or } => false 
//bool isValid(char * s){
//	int position = 0;
//	int string_len = strlen(s);
//	char *stack_temp = malloc(sizeof(char) * string_len);
//
//	for(; *(s) != NULL;){
//		if(*(s) == '(' || *(s) == '[' || *(s) == '{'){
//			stack_temp[position] = *(s);
//			position++;
//			// If open brackets have more than half of string, it means that it doesn't have enough of close brackets => false
//			if(position > string_len / 2){
//				free(stack_temp);
//				return false;
//			}
//		} else{
//			// Must have a open bracket to be closed, or it's false
//			if(position == 0){
//				free(stack_temp);
//				return false;
//			}
//			// Check if close bracket is with corresponding open bracket
//			if(*(s) == ')'){
//				if(stack_temp[position - 1] == '('){
//					position--;
//				} else{
//					free(stack_temp);
//					return false;
//				}
//			} else if(*(s) == ']'){
//				if(position > 0 && stack_temp[position - 1] == '['){
//					position--;
//				} else{
//					free(stack_temp);
//					return false;
//				}
//			} else if(*(s) == '}'){
//				if(position > 0 && stack_temp[position - 1] == '{'){
//					position--;
//				} else{
//					free(stack_temp);
//					return false;
//				}
//			}
//		}
//		*s++;
//	}
//	free(stack_temp);
//	return (position == 0);
//}