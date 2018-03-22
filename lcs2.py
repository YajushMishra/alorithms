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
	#print(index1,index2)
	#print(matrix)
	if(index1==-1 or index2==-1):
		return 0
	else:
		k=index1-1
		l=index2-1
		if(string_one[index1]==string_two[index2]):
			if(matrix[k][l]==-1):
				matrix[k][l]=lcs(k,l)
			matrix[index1][index2]=1+matrix[k][l]
			return (matrix[index1][index2])
		else:
			#return max(lcs(index1-1,index2),lcs(index1,index2-1))
			if(matrix[k][index2]==-1):
				matrix[k][index2]=lcs(k,index2)
			if(matrix[index1][l]==-1):
				matrix[index1][l]=lcs(index1,l)
			matrix[index1][index2]=max(matrix[k][index2],matrix[index1][l])
			return (matrix[index1][index2])


if __name__ == '__main__':
		main(argv[1:])

