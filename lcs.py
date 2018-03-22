from sys import argv



def main(argv):
	#this algortihm uses dynamic programming to compute lcs
	global string_one,string_two,matrix
	string_one=str(argv[0])
	string_two=str(argv[1])
	matrix=[[-1 for w in range(len(string_two))] for i in range(len(string_one))]
	max_lcs_length=lcs(len(string_one)-1,len(string_two)-1)
	
	print(max_lcs_length)

def lcs(index1,index2):
	if(index1==-1 or index2==-1):
		return 0
	else:
		if(string_one[index1]==string_two[index2]):
			return (1+lcs(index1-1,index2-1))
		else:
			return max(lcs(index1-1,index2),lcs(index1,index2-1))




	


if __name__ == '__main__':
		main(argv[1:])

