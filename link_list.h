// this is code for double  link list;
struct node{
	struct node *prev;
	struct node *next;
	int data;
};
int indexval(struct node *p,int n){
	// returns nth index value in a link list index starts from 0.
	while(p!=NULL&&n>0){
		p=p->next;
		n--;
	}
	if(n==0){
		return p->data;
	}
	return 0;
}
struct node *create_node(int data){
	// create a  node and returns its values
	struct node *m;
	m=(struct node *)malloc(sizeof(int ));
	m->data=data;
	m->prev=NULL;
	m->next=NULL;
	return m;
}
struct node *reverse(struct node *p){
	// this function reverse the link list
	struct node *swap,*l;
	while(p!=NULL)
	{
		l=p;
		p=p->next;
		swap=l->next;
		l->next=l->prev;
		l->prev=swap;

	}
	return l;
}

struct node *create_link_list(int *a,int n){

	// this function returns first node of the link list created
	struct node *p,*q,*m;
	int i=0;
	p=create_node(a[0]);
	q=p;
	for(i=1;i<n;i++){
		m=create_node(a[i]);
		p->next=m;
		m->prev=p;
		p=m;
	}
	return q;

}


void add_in_last(struct node *p,int data){

	// add values in the last of the node
	struct node *m,*l;
	l=p;
	
	//if(p==NULL)
		//return m;
	if(p){
		m=create_node(data);
		while(l->next)
			l=l->next;
		l->next=m;
		m->prev=l;
		//return p;
	}
}
void print(struct node *p){
	//prints link list
	while(p){
		printf("  %d ",p->data);
		p=p->next;
		
	}
	printf("\n");
}
void delete_last(struct node *p){
	//deletes last node
	if(p){
		while(p->next)
		{
			p=p->next;
		}
		p->prev->next=NULL;
		free(p);
	}
}
struct node *delete_first(struct node *p){
	//deletes first node of link list
	if(p){
		p=p->next;
		free(p);
	}
	return p;
}
struct node *delete_element(struct node *p,int data){
	//deletes node of given element
	if(p){
		struct node *q;
		q=p;
		while(p){
			if(p->data==data){
				break;
			}
		}
		if(p==q){
			q=delete_first(q);
		}
		else if(p!=q){
			if(p->next){
				p->prev->next=p->next;
				p->next->prev=p->prev;
				free(p);
			}
			else if(p){
				p->prev->next=NULL;
				free(p);
			}
		}
		return q;
	}
	return NULL;
}
struct node *search(struct node *p,int data){
	//searches element and returns address
	while(p)
	{
		if(p->data==data)
			return p;
	}
	return NULL;
}
struct node *add_top(struct node *p,int data)
{
	// adds a node on the top
	struct node *m=NULL;
	if(p){
		m=create_node(data);
		m->next=p;
		p->prev=m;
	}
	return m;
}
struct node *add_before(struct node *p,int data,int before)
{
	//adds node before given value
	struct node *q,*m;
	if(p){
		q=search(p,before);
		if(p==q){
			m=add_top(p,data);
			return m;
		}
		else if(q)
		{
			m=create_node(data);
			m->prev=q->prev;
			m->next=q;
			m->prev->next=m;
			q->prev=m;
			return p;
		}	
	}
	return NULL;
}



