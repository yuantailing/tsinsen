#include<iostream>

using namespace std;

struct node{
    struct node* next;
    int number;
};

typedef struct node node_t;

//输入num个整数,生成链表head
void get_list(node_t* &head, const int num)
{
    node_t* temp_node;
    node_t* last;
    int temp_num;
    int i;
    for(i=0; i<num; i++){
		cin >> temp_num;
		temp_node = new node_t;
		temp_node->next = NULL;
		temp_node->number = temp_num;
		if(i == 0){
			head = temp_node;
		}
		else{
			last->next = temp_node;
		}
		last = temp_node;
    }
    return;
}

//将两个整数链表list_a,list_b合并为一个list_res,并删除重复元素
//注意这里的结果链表的结点复用原有的结点,重复结点的空间需要释放掉
void merge_list(node_t* &list_a, node_t* &list_b, node_t* &list_res)
{
    node_t *a = list_a, *b = list_b, *tmp;
    if (a->number > b->number) {
        tmp = a;
        a = b;
        b = tmp;
    } else if (a->number == b->number) {
        tmp = b;
        b = b->next;
        delete tmp;
    }
    list_res = a;
    while (a->next && b) {
        if (a->next->number == b->number) {
            tmp = b;
            b = b->next;
            delete tmp;
        }
        else if (a->next->number < b->number)
            a = a->next;
        else {
            tmp = a->next;
            a->next = b;
            b = tmp;
        }
    }
    if (b)
        a->next = b;
}

//删除一个链表,并释放其空间
void delete_list(node_t* &list)
{
    node_t* current_node;
    node_t* next_node;
    
    current_node = list;
	
    while(NULL != current_node){
		next_node = current_node->next;
		delete current_node;
		current_node = next_node;
    }
    return;
}

//打印一个链表里的元素
void print_list(node_t* &list)
{
	node_t* temp_node;
	temp_node = list;
    while(temp_node != NULL){
		cout << temp_node->number << " ";
		temp_node = temp_node->next;
    }
    cout << endl;
}

int main()
{
    int N,M;
	
    node_t *list_a = NULL;
    node_t *list_b = NULL;
    node_t *list_res = NULL;
    
    cin >> M >> N;
	
	//输入M个从小到大排好序的且没有重复元素的整数,生成链表list_a
    get_list(list_a, M);
	//输入N个从小到大排好序的且没有重复元素的整数,生成链表list_b
    get_list(list_b, N);
		
    //合并两个链表,生成list_res,从小到大排列,且没有重复元素
    merge_list(list_a, list_b, list_res);
	
    // 打印链表
	print_list(list_res);
    
	//释放申请的空间
    delete_list(list_res);
	
    return 0;
}
