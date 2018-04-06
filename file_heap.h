

class heap{        //this class generates min heap

	private: 
	int heap_array[50];
	char heap_char[50];
	int index;
	public:
	void buildheap(int array[],char array_two[],int n);
	void min_heapify_top(int i);
	void min_heapify_bottom(int i);
	void insert_heap(int val);
	void showheap();
	int left_child(int i)
	{ 
		int k=(2*i);
		
		if(k>index)
		{
			return -1;
		}
		else{
			return k;
		}
					// returns left child
	}
	int right_child(int i)
	{ 
		int k=(2*i);
		if(k>index)
		{
			return -1;
		}
		else{
			return k+1;
		}
					// retuns right child

         }  
	int parent(int i){
		int k;
		k=((i-1)/2);
		return k;
	} 	// reutrns parent
	char delete_heap();


};
char heap::delete_heap()
{
	char val;
	val=heap_char[0];
	heap_array[0]=heap_array[index];
	heap_char[0]=heap_char[index];
	index--;
	min_heapify_top(0);
	heap_array[index+1]=0;
	heap_char[index+1]='0';
	return val;

}
void heap::min_heapify_bottom(int i)
{
	if(i>0)
	{
		int parent_index,swap;
		parent_index=parent(i);
		if(heap_array[i]<heap_array[parent_index])
		{
			swap=heap_array[parent_index];
			heap_array[parent_index]=heap_array[i];
			heap_array[i]=swap;
			min_heapify_bottom(parent_index);

		}
	}
}

void heap::insert_heap(int val)
{
	int i=index;
	i++;
	heap_array[i]=val;
	min_heapify_bottom(i);
	index++;
}

void heap::min_heapify_top(int i)
{
	int leftchild,rightchild,swap,swap_char;
	if(i<=index/2)
	{
	leftchild=left_child(i);
	rightchild=right_child(i);
	if(leftchild!=-1&&rightchild!=-1)
	{	
		if(heap_array[i]>heap_array[leftchild]||heap_array[i]>heap_array[rightchild]||rightchild==-1)
		{
			swap=heap_array[i];
			swap_char=heap_char[i];
			if(heap_array[leftchild]<=heap_array[rightchild])
			{
				heap_array[i]=heap_array[leftchild];
				heap_char[i]=heap_char[leftchild];
				heap_array[leftchild]=swap;
				heap_char[leftchild]=swap_char;
				min_heapify_top(leftchild);
			}
			else
			{
				heap_array[i]=heap_array[rightchild];
				heap_char[i]=heap_char[rightchild];
				heap_array[rightchild]=swap;
				heap_char[rightchild]=swap_char;
				min_heapify_top(rightchild);

			}
		}
	}
	}
	
}
void heap::showheap()
{
	int i;
	for(i=0;i<=index;i++)
	{
		std::cout<<heap_char[i]<<" "<<heap_array[i]<<" ";
	}
}	
void heap::buildheap(int array[],char array_two[],int n)
{
	index=n-1;
	int i;
	for(i=0;i<=index;i++){
		heap_array[i]=array[i];
		heap_char[i]=array_two[i];
	}
	for(i=index/2;i>=0;i--)
	min_heapify_top(i);
}

