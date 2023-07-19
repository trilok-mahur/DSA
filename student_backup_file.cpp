#include<bits/stdc++.h>
using namespace std;
// Reverse array and rotate array with d size
void reverse(int arr[], int n, int first) {
    int temp = 0;
    int i = first;
    int j = n-1;
    while(i < j) {
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--; 
    }
    return;
}
void rotate(int *arr, int d, int n){ 
reverse(arr, n, 0);
reverse(arr, n-d, 0);
reverse(arr , n, n-d);
return;

}
// fraction class
class fraction {
    private :
    int numerator;
    int denominator;
    public :
    fraction(int numerator, int denominator) {
        if( denominator == 0) {
            cout << "Invalid denominator" << endl;
            this->denominator = denominator;
            this->numerator = numerator;
        }
        else if(denominator != 0) {
            if(denominator > 0) {
                this->denominator = denominator;
                this->numerator = numerator;
            }
            else if(denominator < 0) {
                this->numerator = -(numerator);
                this->denominator = abs(denominator);
            }
        }
    }
    void print() {
        simplify();
        cout << (this -> numerator) << " / " << (this->denominator) << endl;
    }
    void simplify() {
        int gcd = 1;
        int j = 0;
        if(abs(this->numerator) < abs(this->denominator)) {
            j =abs(this->numerator);
        }
        else {
            j = abs(this->denominator);
        }
        for(int i = 1; i <= j; i++) {
            if(this -> numerator % i == 0 && this -> denominator % i == 0) {
                gcd = i;
            }
        }
        this -> numerator = this -> numerator / gcd;
        this -> denominator = this -> denominator / gcd;
    } // + operator
    fraction operator+(fraction const & f2) const {
        int lcm = (this->denominator)*f2.denominator;
        int num = (this->numerator)*(f2.denominator) + (f2.numerator)*(this->denominator); 
        fraction f(num, lcm);
        return f;
    } // * operator
    fraction operator*(fraction const & f2) const {
        int n = (this->numerator)*(f2.numerator);
        int d = (this->denominator)*(f2.denominator);
        fraction f(n,d);
        return f;
    } // ==operator
    bool operator==(fraction f2) const {
        return (this->numerator == f2.numerator && this->denominator == f2.denominator);
    } // ++ pre-increment operator
    fraction & operator++() {
        numerator += denominator;
        return *this;
    }// ++ post-increment operator
    fraction operator++(int) {
        fraction f(numerator,denominator);
        numerator = numerator + denominator;
        return f;
    }// += operator
    fraction & operator+=(fraction f) {
        int lcm = (this->denominator)*f.denominator;
        this->numerator = (this->numerator)*(f.denominator) + (f.numerator)*(this->denominator); 
        this->denominator = lcm;
        return *this;
    }
};
// Complex Number

class complexNumber {
    int real;
    int imaginary;
    public :
    complexNumber(int real, int imaginary) {
        this->real = real;
        this->imaginary = imaginary;
    }
    void display() { 
        if(imaginary >= 0) {
            cout << real << " + i." << imaginary << endl;
        }
        else {
            cout << real <<" - i." << abs(imaginary) << endl;
        }
    }
    void add(complexNumber const & c2) {
        this->real += c2.real;
        this->imaginary += c2.imaginary;
        display(); 
    }
    void multiplay(complexNumber const & c2) {
        int r = (this->real)*(c2.real) - (this->imaginary)*(c2.imaginary);
        this->imaginary = (this->real)*(c2.imaginary) + (this->imaginary)*(c2.real);
        this->real = r;
        display();
    }

};


// MergeSort
void mergeArray(int arr[], int first, int mid, int last) {
    int n = last - first + 1; //
    int b[n];
    int i = first;
    int j = mid+1;
    int k = 0;
    while (i <= mid && j <= last) { //
        if(arr[i] < arr[j] ) {
            b[k++] = arr[i++];
        }
        else {
            b[k++] = arr[j++];
        }
    }
    
    while(i <= mid) { //
        b[k++] = arr[i++];
    }
    while(j <= last) { //
        b[k++] = arr[j++];
    }
    
    i = first; //
    for(int t = 0; t < n; t++) {
        arr[i] = b[t];
        i++;
    }
    return;
}
void mergeSort(int arr[], int first, int last){
    if(first >= last) {
        return ;
    }
    int mid = (last + first)/2;
    mergeSort(arr, first, mid);
    mergeSort(arr, mid + 1, last);
    mergeArray(arr, first, mid, last);
}


// Dynamic Array
class DynamicArray{
    int *data;
    int nextIndex;
    int capacity;     //Size of Array
    public:
    DynamicArray() {
        data = new int[5];
        capacity = 5;
        nextIndex = 0;
    }
    DynamicArray(DynamicArray const & d) {
        // this->data=d.data;    shallow copy

        //Deep copy
        this->data = new int[d.capacity];
        for(int i  = 0; i < d.capacity; i++) {
            this->data[i] = d.data[i];
        }
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
    }
    void operator=(DynamicArray const & d) {
        // this->data=d.data;    shallow copy

        //Deep copy
        this->data = new int[d.capacity];
        for(int i  = 0; i < d.capacity; i++) {
            this->data[i] = d.data[i];
        }
        this->capacity = d.capacity;
        this->nextIndex = d.nextIndex;
    }
    void addItem(int item) {
        if(nextIndex == capacity) {
            int * newdata = new int[2*capacity];
            for(int i = 0; i < capacity; i++) {
                newdata[i] = data[i]; 
            }
            delete []data;
            data = newdata;
            capacity *= 2; 
        }
        data[nextIndex++] = item;
    }
    int get(int index) {
        if(index < nextIndex) {
            return data[index];
        }
        else {
            return -1;
        }
    }
    int getIndex(){
        return nextIndex;
    }
    void add(int i, int k) {
        if(i < nextIndex) {
            data[i] = k;
        }
        else if(i == nextIndex) {
            addItem(k);
        }
        else {
            return;
        }

        }
    void display() {
        cout << "Array Element is given by" << endl;
        for(int i = 0; i < nextIndex; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
        cout << "Capacity = " << capacity << endl;
    }

};
// Polynomial
class Polynomial {
    int *degCoeff; 
    int capacity;
    public :
    
    Polynomial() {
        capacity = 2;
        degCoeff = new int[capacity+1];
        for(int i = 0; i <= capacity + 1; i++) {
            degCoeff[i] = 0;
        }
    }
    Polynomial(Polynomial const & p2) {
        this->degCoeff = new int[p2.capacity + 1];
        for (int i = 0; i <= p2.capacity; i++) {
          this->degCoeff[i] = p2.degCoeff[i];
        }
        this->capacity = p2.capacity;
    }
    void setCoefficient(int deg, int coff) {
        int l = this->capacity;
        while(deg > this->capacity) {
            this->capacity = 2*(this->capacity);
            int * k = new int[this->capacity + 1];
            for(int i = 0; i <= this->capacity + 1; i++) {
                k[i] = 0;
            }
            for(int i = 0; i <= l; i++) {
                k[i] = this->degCoeff[i];
            }
            delete [] this->degCoeff;
            this->degCoeff = k;
        }
        degCoeff[deg] = coff;
    } 
    Polynomial  operator=(Polynomial const & p2) {
        this->degCoeff = new int[p2.capacity + 1];
        this->capacity = p2.capacity;
        for (int i = 0; i <= p2.capacity; i++) {
          this->degCoeff[i] = p2.degCoeff[i];
        }
        return *this;
    }
    Polynomial operator+(Polynomial const & p2) {
        Polynomial p3;
        if(this->capacity >= p2.capacity ) {
            p3.capacity = this->capacity;
        }
        else{
            p3.capacity = p2.capacity;
        }
        int *z = new int[p3.capacity + 1];
        delete []p3.degCoeff;
        p3.degCoeff = z;
        for(int i = 0; i <= p3.capacity; i++) {
            p3.degCoeff[i] = 0;
        }
        for(int  i = 0; i <= this->capacity; i++) {
            p3.degCoeff[i] = this->degCoeff[i];
        }
        for(int j = 0; j <= p2.capacity; j++) {
            p3.degCoeff[j] += p2.degCoeff[j];
        }
        return p3;
    } 
    Polynomial operator-(Polynomial const & p2) {
        Polynomial p3;
        if(this->capacity >= p2.capacity ) {
            p3.capacity = this->capacity;
        }
        else{
            p3.capacity = p2.capacity;
        }
        int *z = new int[p3.capacity + 1];
        delete []p3.degCoeff;
        p3.degCoeff = z;
        for(int i = 0; i <= p3.capacity; i++) {
            p3.degCoeff[i] = 0;
        }
        for(int  i = 0; i <= this->capacity; i++) {
            p3.degCoeff[i] = this->degCoeff[i];
        }
        for(int j = 0; j <= p2.capacity; j++) {
            p3.degCoeff[j] =(p3.degCoeff[j] - p2.degCoeff[j]);
        }
        return p3;
    }
    Polynomial operator*(Polynomial const & p2) {
        Polynomial p3;
        p3.capacity = (this->capacity)+(p2.capacity);
        int * z = new int[p3.capacity + 1];
        delete []p3.degCoeff;
        p3.degCoeff = z;
        for(int i = 0; i <= p3.capacity; i++) {
            p3.degCoeff[i] = 0;
        }
        for(int i = 0; i <= this->capacity; i++) {
            for(int j = 0; j <= p2.capacity; j++) {
                p3.degCoeff[i+j] += (this->degCoeff[i])*(p2.degCoeff[j]);
            }
        }
        return p3;
    }
    void print() {
        for(int i = 0; i <= capacity; i++) {
            if(degCoeff[i] != 0) {
                cout << degCoeff[i] << "x" << i << " ";
            }
            else {

            }
        }
        cout << endl;
    }

    
};
// Linked List
class Node{
    public :
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};
Node * takeInput(Node * head){
    int data;
    cout <<" Enter the data = ";
    cin >> data;
    while (data != -1) {
        Node * NewNode = new Node(data);
        if(head == NULL) {
            head = NewNode;
        }
        else {
            Node *temp =head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = NewNode;
        }
        cout << endl;
        cout <<" Enter the data = ";
        cin >> data;
    }
    return head;
}
Node * insertNodeFirst(Node * head) {
    int data;
    cout << "Enter the Data = ";
    cin >> data;
    while(data != -1) {
        Node * NewNode = new Node(data);
        if(head == NULL) {
            head = NewNode;
        }
        else {
            Node * temp = head;
            head = NewNode;
            head->next = temp;
        }
        cout << endl;
        cout << "Enter the Data = ";
        cin >> data;
    }
    return head;
}
void printLL(Node * head) {
    if(head == NULL ){
        cout << "Linked list Has no Node" << endl;
    }
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
    return;
}
// insert Node at ith poition use Loop
Node * insertNodeAt_ith_position(Node * head, int data, int position) {
    Node * temp = head;
    int i = 0;
    Node * newNode = new Node(data);
    if(position == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    }
    while(temp != NULL && i < position - 1) {
        temp = temp->next;
        i++;
    }
    if(temp != NULL) {
        newNode->next = temp->next;
        temp->next = newNode;
    }
    else {

    }
    return head;
}
// Delete Node at ith position using loop
Node * deleteNode(Node * head, int position) {
    Node * temp = head;
    int i = 0;
    if(temp == NULL) {
        return head;
    }
    if(position == 0) {
        head = temp->next;
        delete temp;
        return head;
    }
    while(temp != NULL && i < position-1) {
        temp = temp->next;
        i++;
    }
    if(temp != NULL) {
        Node * a = temp->next;
        temp->next = temp->next->next;
        delete a;
    }
    else {

    }
    return head;
}
// Mid point of Linked List method 1
Node *midPoint_1(Node *head) {
	Node * temp = head;
	int l = 0;
	while(temp != NULL) {
		temp = temp->next;
		l++;
	}
   Node *arr[l+1];
   temp = head;
   arr[0] = head;
   int k = 0;
   while(temp != NULL) {
    arr[++k] = temp->next;
    temp = temp->next;
   }
   return arr[(l - 1)/2];
}
// Mid point of Linked List method 2
Node *midPoint_2(Node *head) {
    if(head == NULL) {
        return NULL;
    }
	Node * temp1 = head;
    Node * temp2 = head->next;
    while(temp2 != NULL && temp2->next != NULL) {
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    }
    return temp1;
}
// Delete Node at ith position recursively
Node *Delete_Node_recursively(Node * head, int position) {
    if(head == NULL) {
        return head;
    }
    if(position == 0) {
        Node * result = head->next;
        delete head;
        return result;
    }
    head->next= Delete_Node_recursively(head->next, position - 1); 
    return head;
}
// Insert Node at ith position recursively
Node * insert_node_recursively(Node * head, int data, int position) {
    if(head == NULL) {
        if(position == 0) {
        Node * newNode = new Node(data);
        return newNode;
        }
        else {
            return head;
        }
    }
    if( position == 0 )  {
        Node * newNode = new Node(data);
        newNode->next = head;
        return newNode;
    }
    head->next = insert_node_recursively(head->next, data, position-1);
    return head;
}
Node *appendLastNToFirst(Node *head, int n) {
	if(head == NULL || n == 0) {
		return head;
	}
	Node * temp = head;
	Node * temp2 = head;
	int length = 0;
	while(temp != NULL) {
		length++;
		temp = temp->next;
	}
	while(temp2->next->next != NULL) {
		temp2 = temp2->next;
	}
	int k = length - n;
	temp = head;
	while(k > 1) {
		temp = temp->next;
		k--;
	}
	Node * lastNode = temp;
	temp2->next->next = head;
	temp = lastNode->next;
	lastNode->next = NULL;
	return temp;

}
Node * insert_node_recursively(Node * head, int data) {
	Node *temp = new Node(data);
	temp->next = head;
    return temp;
}


// Stack Using Array
class stack_using_array{
    int * data;
    int nextIndex;
    int capacity;
    public : 
    stack_using_array(int totalSize) {
        data = new int[totalSize];
        nextIndex = 0;
        capacity = totalSize;
}
bool IsEmpty() {
    return nextIndex == 0;
}
void push(int item) {
    if(nextIndex == capacity) {
        cout << "Stack is Overflow \n";
        return;
    }
    data[nextIndex++] = item;
    return;
}
int pop(){
    if(IsEmpty()) {
        cout << "Stack is Underflow\n";
        return INT_MIN;
    }
    nextIndex--;
    cout << "Popped element is = " <<  data[nextIndex] << endl;
    return INT_MIN;
}
void top() {
    if(IsEmpty()) {
        cout << "Stack is Underflow\n";
        return ;
    }
    cout << "top is = " << data[nextIndex - 1] << endl;
    return;
}
void printStack() {
    int temp = nextIndex;
    if(IsEmpty()){
        cout << "Stack is underflow\n";
    }
    for(temp = nextIndex-1; temp >= 0; temp--) {
        cout << data[temp] << endl;
    }
    return ;
}

};
// stack using Linked List
class StackLL {
    Node * head;
    int size;
   public:
    StackLL() {
        head = NULL;
        size = 0;
    }
    int getSize() {
     return size;
    }

    bool isEmpty() {
        return size == 0 ? true : false;
    }

    void push(int element) {
        Node * newNode = new Node(element);
        if(head == NULL) {
            head = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Stack is empty \n";
            return -1;
        } 
        else {
          int data = head->data;
          size--;
          head = head->next;
          cout << "Popped Element is = " << data << endl;
          return data;
        }
    }

    int top() {
        if(isEmpty() ) {
            cout << " stack is empty \n";
            return -1;
        }
        else {
            cout << "Top element is = " << head->data << endl;
            return head->data;
        }
    }
};
// Queue using Array
class Queue_using_array{
    int *data;
    int size;
    int firstIndex;
    int nextIndex;
    int capacity;
    public :
    Queue_using_array(int capacity) {
        this->data = new int[capacity];
        this->firstIndex = -1;
        this->nextIndex = 0;
        this->capacity = capacity;
        this->size = 0;
    }
    int getsize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
    void enqueue(int item) {
        if(size == capacity) {
            cout << "Queue is full\n";
            return;
        }
        data[nextIndex] = item;
        nextIndex = (nextIndex + 1) % capacity;
        size++;
        if(firstIndex == -1) {
            firstIndex++;
        }
    }
    int front() { 
        if(isEmpty()) {
            cout <<" Queue is Empty\n";
            return INT_MIN;
        }
        return data[firstIndex];
    }
    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is Empty\n";
            return INT_MIN;
        }
        int ans = data[firstIndex];
        size--;
        firstIndex = (firstIndex + 1) % capacity;
        if(size == 0) {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

};
// Queue using dynamic Array
class DynamicQueue{
    int *data;
    int size;
    int firstIndex;
    int nextIndex;
    int capacity;
    public :
    DynamicQueue(int capacity) {
        this->data = new int[capacity];
        this->firstIndex = -1;
        this->nextIndex = 0;
        this->capacity = capacity;
        this->size = 0;
    }
    int getsize() {
        return size;
    }
    bool isEmpty() {
        return size == 0;
    }
    void enqueue(int item) {
        if(size == capacity) {
           int * new_data = new int[2*capacity];
           int j = 0;
           for(int i = firstIndex; i < capacity; i++) {
            new_data[j] = data[i];
            j++;
           }
           for(int i = 0; i < firstIndex; i++) {
            new_data[j] = data[i];
            j++;
           }
           firstIndex = 0;
           nextIndex = capacity;
           capacity = 2 * capacity;
           delete [] data;
           data = new_data;
        }
        data[nextIndex] = item;
        nextIndex = (nextIndex + 1) % capacity;
        size++;
        if(firstIndex == -1) {
            firstIndex++;
        }
    }
    int front() { 
        if(isEmpty()) {
            cout <<" Queue is Empty\n";
            return INT_MIN;
        }
        return data[firstIndex];
    }
    int dequeue() {
        if(isEmpty()) {
            cout << "Queue is Empty\n";
            return INT_MIN;
        }
        int ans = data[firstIndex];
        size--;
        firstIndex = (firstIndex + 1) % capacity;
        if(size == 0) {
            firstIndex = -1;
            nextIndex = 0;
        }
        cout << "Dequeue element is = " << ans << endl;
        return ans;
    }
    void getCapacity() {
        cout << "capacity of queue is  = " << capacity << endl;
    }

};

// Queue using Linked List
class Queue {
	Node * first;
	Node * rear;
	int size;

   public:
    Queue() {
		first = NULL;
		rear = NULL;
		size = 0;
	}
	int getSize() {
		return  size;
	}
    bool isEmpty() {
		return size == 0;
	}
    void enqueue(int data) {
		Node * newData = new Node(data);
		if(rear == NULL) {
			rear = newData;
			first = newData;
			size++;
		}
		else {
			rear->next = newData;
			rear = rear->next;
			size++;
		}
	}

    int dequeue() {
        if(first == NULL) {
			return -1;
		}
		else {
			Node * deleteNode = first;
			int ans = first->data;
			first = first->next;
			delete deleteNode;
			size--;
			if(size == 0) {
				rear = NULL;
			}
			return ans;
		}
    }

    int front() {
        if(first == NULL) {
			return -1;
		}
		else {
			return first->data;
		}
    }
};

// TREE with more than 2 children
class treeNode{
    public :
    int data;
    vector<treeNode *>  child;
    treeNode(int data) {
        this->data = data;
    }
};
//print Tree
void printTree(treeNode * root) {
  if(root == NULL) {
    return;
  }
  cout << root->data << " : ";
  int t = root->child.size();
  for(int i = 0; i < t;  i++) {
    cout  <<  root->child[i]->data << " ,";
  }
  cout << endl;
  int z = root->child.size();
  for(int i = 0; i < z; i++) {
    printTree(root->child[i]);
  }
  
};
treeNode * take_input_for_tree() {
    int rootData;
    cout << "Enter the data = ";
    cin >> rootData;
    treeNode * root = new treeNode(rootData);
    cout << "\nEnter the no. of childer of " << rootData << " are = ";
    int n;
    cin >> n;
    cout << endl;
    for(int i = 0; i < n; i++) {
        treeNode * child = take_input_for_tree();
        root->child.push_back(child);
    }
    return root;
}
// Take input level wise
treeNode * take_input_level_wise() {
    int rootData;
    cout << "Enter the root data = ";
    cin >> rootData;
    treeNode * root = new treeNode(rootData);
    queue < treeNode * > pendingNode;
    pendingNode.push(root);
    while(pendingNode.size() != 0) {
        treeNode * front = pendingNode.front();
        pendingNode.pop();
        int numChild;
        cout <<"\nEnter the number of child of " << front->data << " = ";
        cin >> numChild;
        for(int i = 1; i <= numChild; i++) {
            int childData;
            cout <<"\nEnter the " << i  <<"th child of " << front->data << " = ";
            cin >> childData;
            treeNode* child = new treeNode(childData);
            pendingNode.push(child);
            front->child.push_back(child);
        }
    }
    return root;

}

// print Tree level wise
void printLevelWise(treeNode* root) {
    queue<treeNode * > pendingNode;
    pendingNode.push(root);
    while(pendingNode.size() != 0) {
        treeNode*  front = pendingNode.front();
        cout << front->data <<":";
        int t = front->child.size(); 
        for(int i = 0; i < t; i++) {
            pendingNode.push(front->child[i]);
        }
        int z =  front->child.size();
        for(int i = 0; i < z; i++){
          cout << front->child[i]->data;
          int xxx = front->child.size();
          if(i < xxx - 1 ) {
            cout << ",";
          }
        }
        cout << endl;
        pendingNode.pop();
    }
}
int countTreeNode(treeNode * root) {
    if(root == NULL) {
        return 0;
    }
    int ans = 0;
    int t = root->child.size();
    for(int i = 0; i < t; i++) {
        ans += countTreeNode(root->child[i]);
    }
    return ans + 1;
}

// Maximum data node in  Tree
treeNode* maxDataNode(treeNode* root) {
    if(root == NULL) {
        return  NULL;
    }
    treeNode* max = root; 
    int t = root->child.size();
    for(int i = 0; i < t; i++) {
        treeNode* maxchild = maxDataNode(root->child[i]);
        if(max->data < maxchild->data) {
            max = maxchild;
        }
    }
    return max;  
}
// Count of Leaf Node in Tree
int getLeafNodeCount(treeNode* root) {
    if(root == NULL) {
        return 1;
    }
    int ans = 0;
    int t = root->child.size();
    for( int i = 0; i < t; i++) {
        ans += getLeafNodeCount(root->child[i]);
    }
    return ans > 1 ? ans : 1;
}
// Binary Tree
class Binary_tree{
    public :
    int data;
    Binary_tree * left;
    Binary_tree * right;
    Binary_tree(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
    ~Binary_tree(){
        delete left;
        delete right;
    }
};
Binary_tree * takeInput_BT() {
    int data;
    cout << "Enter the data = ";
    cin  >> data;
    if(data == -1) {
        return NULL;
    }
    Binary_tree * root = new Binary_tree(data);
    Binary_tree * leftChild = takeInput_BT();
    Binary_tree * rightchild = takeInput_BT();
    root->left = leftChild;
    root->right = rightchild;
    return root;
}
void printBinaryTree(Binary_tree * root){
    if(root == NULL) {
        return;
    }
    cout << root->data << " : ";
    if(root->left) {
        cout << "L : " << root->left->data;
    }
    if(root->right) {
        cout << ", R : " << root->right->data;
    }
    cout << endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}
void printBinaryTreeLevelWise(Binary_tree *root) {
    if(root == NULL) {
        return;
    }
    queue<Binary_tree * > pendingNode;
    pendingNode.push(root);
    while (pendingNode.size() != 0) {
        Binary_tree * front = pendingNode.front();
        cout << front->data << " : ";
        if(front->left ) {
            cout << "L : " << front->left->data;
           pendingNode.push(front->left);
        }
        if(front->right) {
            cout << " , R : " << front->right->data;
            pendingNode.push(front->right);
        }
        pendingNode.pop();
        cout << endl;
    }
}
// Hight of Binary Tree
int hight(Binary_tree * root) {
    if(root == NULL ){
		return 0;
	}
	
	return 1 + max(hight(root->left), hight(root->right));
}
// Mirror Image of given binary Tree
void mirrorImageOfTree(Binary_tree * root) {
    if(root == NULL) {
        return;
    }
    Binary_tree * temp = root->left;
    root->left = root->right;
    root->right = temp;
    mirrorImageOfTree(root->left);
    mirrorImageOfTree(root->right);
    return;
}// post order Binary Tree print
void postOrder(Binary_tree *root) {
	if(root == NULL) {
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout << root->data << " ";
}
//preOrder Binary Tree print 
void preOrder(Binary_tree * root) {
	if(root == NULL) {
		return;
	}
    cout << root->data << " ";
	preOrder(root->left);
	preOrder(root->right);
    return ;
}
// inOrder Binary Tree Print 

void inOrder(Binary_tree * root) {
    if(root == NULL) {
        return ;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
    return;
}
// BuildTree using preOrder and inOrder
Binary_tree * buildTreePre(int *preorder, int preLength, int *inorder, int inLength) {
    if(preLength == 0 || inLength == 0) {
		return NULL;
	}
	Binary_tree * root = new Binary_tree( preorder[0] );
	int i = 0;
	while(preorder[0] != inorder[i] ) {
		i++;
	}
	root->left = buildTreePre(preorder +1, i, inorder, i);
	root->right = buildTreePre(preorder + i +1,  preLength-i -1, inorder +1 +i, inLength -1-i);
	return  root;
}
// BuildTree using PostOrder and inOrder
Binary_tree * buildTreePost(int *postorder, int postLength, int *inorder, int inLength) {
    if(postLength == 0) {
		return NULL;
	}
	Binary_tree * root = new Binary_tree(postorder[postLength-1]);
	int  i = 0;
	while(postorder[postLength-1] != inorder[i]) {
		i++;
	}
	root->left = buildTreePost(postorder, i, inorder, i);
	root->right = buildTreePost(postorder + i, postLength -i -1,inorder + 1 + i,inLength -i - 1);
	return root;
}
// Maximum and Minimum both in same function using pair class
pair<int, int> getMinAndMax(Binary_tree *root) {
	if(root == NULL ){
		pair<int ,int > ans;
		ans.second = INT_MIN;
		ans.first = INT_MAX;
		return ans;
	}
	pair<int, int> ans;
	pair<int, int> temp;
	ans.first = root->data;
	ans.second = root->data;
	temp.first = root->data;
	temp.second = root->data;
	temp = getMinAndMax(root->left);
	if(temp.first < ans.first) {
		ans.first = temp.first;
	}
	if(temp.second > ans.second ){
		ans.second = temp.second;
	}
	temp = getMinAndMax(root->right);
	if(temp.first < ans.first) {
		ans.first = temp.first;
	}
	if(temp.second > ans.second) {
		ans.second = temp.second;
	}
	return ans;
}
// Diameter of Binary Tree using hight and diameter function
pair<int, int> hightDiameter(Binary_tree * root) {
  if(root == NULL) {
    pair<int , int> p;
    p.first = 0;
    p.second = 0;
    return p;
  }
  pair<int, int> Lf = hightDiameter(root->left);
  pair<int, int> Rt = hightDiameter(root->right);
  int hight = 1 + max(Lf.first , Rt.first);
  int diameter = max(Lf.first + Rt.first, max(Lf.second, Rt.second));
  pair <int, int> ans;
  ans.first =  hight;
  ans.second = diameter;
  return ans;

}
// Nodes without sibling in binary Tree

void printNodesWithoutSibling(Binary_tree * root) {
    if(root == NULL) {
        return;
    }
    if(root->left != NULL && root->right == NULL) {
        cout << root->left->data << " ";
    }
    if(root->left == NULL && root->right != NULL) {
        cout << root->right->data << " ";
    }
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}

// is_BST or Not  
class triplet{
	public:
	int max;
	int min;
	bool is_bst;
};
triplet BST(Binary_tree * root) {
	if(root == NULL) {
		triplet a;
		a.max = INT_MIN;
		a.min = INT_MAX;
		a.is_bst = true;
		return a;
	}
	triplet outputLeft = BST(root->left);
	triplet outputRight = BST(root->right);
	triplet ans;
	ans.max = max(root->data, max (outputLeft.max, outputRight.max ) );
	ans.min = min(root->data, min(outputRight.min, outputLeft.min ) );
	ans.is_bst = root->data >= outputLeft.max && root->data <= outputRight.min && outputRight.is_bst && outputLeft.is_bst;
	return ans;
	
}
bool isBST(Binary_tree * root) {
	triplet ans = BST(root);
	return ans.is_bst;
}
// is_BST or not 2nd method

bool util(Binary_tree * root, int max = INT_MAX, int min = INT_MIN) {
	if(root == NULL) {
		return true;
	}
	if(root-> data < min || root->data > max ) {
		return false;
	}
	bool leftOk = util(root->left,root->data ,min );
	bool rightOk = util(root->right, max, root->data);
	return leftOk && rightOk; 
}
bool is_BST(Binary_tree *root) {
	return util(root);
}
//Code: Construct BST from a Sorted Array

Binary_tree* util(int *input, int start, int end) {
	if( start > end) {
		return NULL;
	}
	int mid = (start + end) / 2;
	Binary_tree * root  = new Binary_tree(input[mid]);
	root->left = util(input, start, mid-1);
	root->right = util(input, mid+1,end);
	return root;
}

Binary_tree* constructTree(int *input, int n) {
	return util(input, 0, n-1);
}
// Sorted Linked List from a Binary Search Tree
Node * constructSortedLinkedListFromBST(Binary_tree  * root) {
    if(root == NULL) {
        return NULL;
    }
    Node * Lhead = constructSortedLinkedListFromBST(root->left);
    Node * Rhead = constructSortedLinkedListFromBST(root->right);
    if(Lhead == NULL) {
        Lhead = new Node(root->data);
        Lhead->next = Rhead;
        return Lhead;
    }
    Node * temp = Lhead;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new Node(root->data);
    temp->next->next = Rhead;
    return Lhead;
} 
// 2nd Method for Sorted Linked List from a Binary Search Tree
Node * headNode = NULL;             // Global variable for this Question
Node * ResultNode = NULL;           // Global variable for this Question
void const_SLL_F_BST_helper(Binary_tree * root) {
    if(root == NULL) {
        return;
    }
    const_SLL_F_BST_helper(root->left);
    if(headNode == NULL) {
        headNode = new Node(root->data);
        ResultNode = headNode;
    }
    else {
        headNode->next = new Node(root->data);
        headNode = headNode->next;
    }
    const_SLL_F_BST_helper(root->right);
}
Node * const_SLL_F_BST(Binary_tree * root) {
    const_SLL_F_BST_helper(root);
    return ResultNode;   
}
//      Find Path in BST for some data
vector<int>* getpath_in_BST(Binary_tree *root , int data) {
	if(root == NULL) {
		return 0;
	}
	vector<int> * result =  new vector<int>();
	while(root != NULL) {
		if(root->data == data) {
			result->push_back(root->data);
			break;
		}
		else if(root->data > data){
			result->push_back(root->data);
			root = root->left;
		}
		else if(root->data < data) {
			result->push_back(root->data);
			root = root->right;
		}
	}
	if(result->back() == data) {
		reverse( result->begin(), result->end() );
		return result;
	}
	else {
		return 0;
	}
} // Find Path in BS for some data
vector<int> * getpath_in_BT(Binary_tree * root, int data) {
    if(root == NULL) {
        return NULL;
    }
    if(root->data == data) {
        vector<int> * output = new std :: vector<int>();
        output->push_back(root->data);
        return output;
    }
    vector<int> * leftOutput = getpath_in_BT(root->left, data);
    if(leftOutput != NULL) {
        leftOutput->push_back(root->data);
        return leftOutput;
    }
    vector<int> * rightOutput = getpath_in_BT(root->right, data);
    if(rightOutput != NULL) {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else {
        return NULL;
    }
}
 // Code  for calling GetPath function
// int main() {
//     Binary_tree *root = takeInput();
//     int k;
//     cin >> k;
//     vector<int> *output = getPath(root, k);

//     if (output != NULL) {
//         for (int i = 0; i < output->size(); i++) {
//             cout << output->at(i) << " ";
//         }
//     }

//     delete root;
// }

// FORM A BINARY TREE
Binary_tree * FormBinaryTree() {
    Binary_tree * root = new Binary_tree(1);        // root
    root->left = new Binary_tree(2);                // 1 L = 2
    root->right = new Binary_tree(9);                // 1 R = 9
    root->left->left = new Binary_tree(3);           //  2 L = 3
    root->left->right = new Binary_tree(5);           // 2 R = 5
    root->right->left = new Binary_tree(10);
    root->right->right = new Binary_tree(11);
    root->left->left->left = new Binary_tree(4);
    root->left->left->right = new Binary_tree(8);
    root->left->right->left = new Binary_tree(7);
    root->left->right->right = new Binary_tree(6);
    root->right->right->left = new Binary_tree(12);
    root->right->right->right = new Binary_tree(13);
    root->left->right->right->left = new Binary_tree(18);
    root->right->right->left->left = new Binary_tree(14);
    root->left->right->right->left->left = new Binary_tree(20);
    root->right->right->left->left->right = new Binary_tree(15);
    root->left->right->right->left->right = new Binary_tree(19);
    root->left->right->right->left->left->left = new Binary_tree(23);
    root->left->right->right->left->left->right = new Binary_tree(24);
    root->right->right->left->left->right->left = new Binary_tree(16);
    root->left->right->right->left->right->left = new Binary_tree(21);
    root->left->right->right->left->right->right = new Binary_tree(22);
    root->right->right->left->left->right->right = new Binary_tree(17);
    return root;
}
//         ABOVE TREE IS GIVEN BY
    //                                               1



    //                     2                                                       9



    //         3                       5                               10                        11



    // 4                8     7                   6                                    12                    13



    //                                      18 (L-6)                             14 (L-12)


    //                             20                      19                                      15
                        
    //                     23              24         21          22                         16            17

//construct BST by given one by one data
Binary_tree * insert_data_in_BST_helper(Binary_tree * root , int data) {
    if(root == NULL) {
        root = new Binary_tree(data);
        return root;
    }
    if(data < root->data) {
        root->left = insert_data_in_BST_helper(root->left, data);
    }
    else {
        root->right = insert_data_in_BST_helper(root->right, data);
    }
    return root;
}
Binary_tree * insert_data_in_BST(Binary_tree * root) {
    int data;
    cout << "Enter the Data = ";
    cin >> data;
    while(data != -1) {
        root = insert_data_in_BST_helper(root, data);
        cout << "\nEnte the Data = ";
        cin >> data;
    }
    return root;
}
// Delete Node From Binary Search Tree (BST)
Binary_tree * delete_Node_from_BST(Binary_tree * root , int data) {
    if(root == NULL ) {
        return NULL;
    }
    if(data < root->data) {
        root->left = delete_Node_from_BST(root->left, data);
        return root;
    }
    else if(data > root->data) {
        root->right = delete_Node_from_BST(root->right, data);
        return root;
    }
    else {
        if(root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }
        else if(root->right == NULL) {
            Binary_tree * temp = root->left;
            root->left = NULL;
            delete root;
            return temp;
        }
        else if(root->left == NULL) {
            Binary_tree * temp = root->right;
            root->right = NULL;
            delete root;
            return temp;
        }
        else {
            Binary_tree * rightMin = root->right;
            while(rightMin->left != NULL) {
                rightMin = rightMin->left;
            }
            int rightMIN = rightMin->data;
            root->data = rightMIN;
            root->right = delete_Node_from_BST(root->right, rightMIN);
            return root;
        }
    }
}
 bool search_data_in_BST( Binary_tree* Node, int data) {
        if(Node == NULL) {
            return false;
        }
        if(Node->data == data){
            return true;
        }
        else if(Node->data > data) {
            return search_data_in_BST(Node->left, data);
        }
        else{
            return search_data_in_BST(Node->right, data);
        }
    }
// Binary Search Tree class with 4 function
class BST {
    Binary_tree * root;
   public:
    BST() { 
        root = NULL;
    }

	/*----------------- Public Functions of BST -----------------*/
    private:
    Binary_tree * remove( Binary_tree * Node, int data) {
        if(Node == NULL) {
            return NULL;
        }
        if(Node->data > data) {
            Node->left = remove(Node->left, data);
            return Node;
        }
        else if(Node->data < data) {
            Node->right = remove(Node->right,data);
            return  Node;
        }
        else{
            if(Node->left == NULL && Node->right == NULL) {
                delete Node;
                return NULL;
            }
            else if(Node->right == NULL ) {
                Binary_tree * temp = Node->left;
                Node->left = NULL;
                delete Node;
                return temp;
            }
            else if(Node->left == NULL) {
                Binary_tree * temp = Node->right;
                Node->right = NULL;
                delete Node;
                return temp;
            }
            else{
                Binary_tree * minRight = Node->right;
                while(minRight->left != NULL) {
                    minRight = minRight->left;
                }
                int min_right = minRight->data;
                Node->data = min_right;
                Node->right = remove(Node->right, min_right);
                return Node;
            }
        }
    } 
    public :

    void remove(int data) { 
    this->root = remove(this->root, data);
    return;
    }
    private :

    void print(Binary_tree * Node) {
        if(Node == NULL) {
            return;
        }
        cout << Node->data<<":";
        if(Node->left) {
            cout <<"L:" <<Node->left->data << ",";
       }
       if(Node->right) {
           cout << "R:" << Node->right->data;
       }
       cout << endl;
       print(Node->left);
       print(Node->right);
        return;
    }
    public :

    void print() { 
        print(this->root);
        return;
    }
    private :

    Binary_tree * insert(Binary_tree * Node, int data){
        if(Node == NULL) {
            Binary_tree * newNode = new Binary_tree(data);
            Node = newNode;
            return Node;
        }
        if(Node->data >= data) {
            Node->left = insert(Node->left,  data);
            return Node;
        }
        else{
            Node->right = insert(Node->right,  data);
            return Node;
        }
    }
    public:

    void insert(int data) { 
        this->root = insert(this->root, data);
        return;
        
    }
    private:
    bool searchk( Binary_tree * Node, int data) {
        if(Node == NULL) {
            return false;
        }
        if(Node->data == data){
            return true;
        }
        else if(Node->data > data) {
            return searchk(Node->left, data);
        }
        else{
            return searchk(Node->right, data);
        }
    }
    public :

    bool search(int data) {
        return searchk(this->root, data);
    }
};
// Insert Dupicate Node in Binary Tree
void insertDuplicateNode(Binary_tree *root) {
    if(root == NULL) {
        return;
    }
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    Binary_tree * temp = root->left;
    Binary_tree * temp2 = new Binary_tree(root->data);
    root->left = temp2;
    root->left->left = temp;
    return;
}
// pair sum in Binary tree using array

void convert_binary_tree_into_array(Binary_tree * root, vector<int> & v) {
	if(root == NULL) {
		return;
	}
	v.push_back(root->data);
	convert_binary_tree_into_array(root->left,v);
    convert_binary_tree_into_array(root->right,v);
	return;
}
void pairSum(Binary_tree *root, int sum) {
    vector<int> v;
    convert_binary_tree_into_array(root,v);
	sort(v.begin(), v.end());
	int j = v.size();
	for(int i = 0; i < j; i++) {
		if(v[i] +v[j-1] == sum && i != j-1) {
			cout << v[i] << " " << v[j-1] << endl;
		}
		if(v[i] + v[j-1] > sum) {
			i--;
			j--;
		}
	}
}
//   LCA of Binary Tree
//  Given a binary tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the binary tree.
//  LCA - LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants. 
int getLCA(Binary_tree * root , int a, int b) {
    if(root == NULL) {
		return -1;
	}
	if(root->data == a || root->data == b) {
		return root->data;
	}
	int left = getLCA(root->left,  a,  b);
	int right = getLCA(root->right,  a, b);
	if(left != -1 && right != -1){
		return root->data;
	}
	if(left == -1  && right == -1) {
		return -1;
	}
	if(left != -1 && right == -1) {
		return left;
	}
	else {
		return right;
	}
}
//  LCA of Binary Search Tree (BST)
int getLCA_BST(Binary_tree * root , int a , int b){
	if(root == NULL) {
	return -1;
	}
	if(root->data == a || root->data == b) {
		return root->data;
	}
	int left = -1;
	int right = -1;
    if (root->data > a && root->data > b) {
        left = getLCA_BST(root->left, a, b);
    } 
    else if (root->data < a && root->data < b) {
        right = getLCA_BST(root->right, a, b);
    } 
    else {
        left = getLCA_BST(root->left, a, b);
        right = getLCA_BST(root->right, a, b);
    }
    if(left != -1 && right != -1) {
        return root->data;
	}
	if(left == -1  && right == -1) {
		return -1;
	}
	if(left != -1 && right == -1) {
		return left;
	}
	else {
		return right;
	}
}
//      Largest Binary search Subtree  in Binary Tree
class fourpair{
    public :
    int min;
    int max;
    int hight;
    bool is_bst;
};
fourpair is_BST_with_hight_with_MAX_MIN(Binary_tree * root) {
	if (root == NULL) {
		fourpair  output;
		output.max = INT_MIN;
		output.min = INT_MAX;
		output.hight = 0;
		output.is_bst = true;
        return output;
	}
	fourpair leftOutput = is_BST_with_hight_with_MAX_MIN(root->left);
	fourpair rightOutput = is_BST_with_hight_with_MAX_MIN(root->right);
	fourpair ans;
	ans.max	 = max(root->data, max(leftOutput.max, rightOutput.max));
	ans.min = min(root->data, min(leftOutput.min, rightOutput.min));
	ans.is_bst = root->data >= leftOutput.max && root->data < rightOutput.min && leftOutput.is_bst && rightOutput.is_bst;
	ans.hight = 1 + max(leftOutput.hight, rightOutput.hight);
	return ans;
}
int largestBSTSubtree(Binary_tree * root) {
	fourpair ans = is_BST_with_hight_with_MAX_MIN(root);
	if(ans.is_bst) {
		return ans.hight;
	}
	int left = largestBSTSubtree(root->left);
	int right = largestBSTSubtree(root->right);
	return max(left,right);
}
//  Priority Queue
class priorityQueue_MIN{
    vector<int> pq;
    public :
    priorityQueue_MIN() {

    }
    bool isEmpty() {
        return pq.size() == 0;
    }
    int getSize() {
        return pq.size();
    }
    int getMin() {
        if(isEmpty()) {
            return 0;
        }
        return pq[0];
    }
    void insert_in_priorityQueue(int data) {
        pq.push_back(data);
        int n = pq.size() - 1;
        // follong condition (in While loop) is called UP-HEAPIFY
        while(pq[n] < pq[(n-1)/2] && n > 0) {
            int temp = pq[n];
            pq[n] = pq[(n-1)/2];
            pq[(n-1)/2] = temp;
            n = (n-1)/2;
        }

    }
    void printPriorityQueue() {
        cout << "Queue element is given by\n";
        cout << "Index = ";
        int k = getSize();
        for(int i = 0; i < k; i++) {
            cout << i << " ";
        }
        cout << "\nElemt = ";
        for(int i = 0; i < k; i++) {
            cout << pq[i] << " ";
        }
        cout << endl;
    }
    int removeMin_from_priorityQueue() {
        if(isEmpty()) {
            return 0;
        }
        int temp = pq[0];
        int n = getSize() - 1;
        pq[0] = pq[n];
        pq[n] = temp;
        pq.pop_back();
        int parentIndex = 0;
        // following condition (in while loop) is called DOWN-HEAPIFY
        while ( (2 * parentIndex + 2 < getSize() )&& (pq[parentIndex] > pq[2 *parentIndex +1] || pq[parentIndex] > pq[2 * parentIndex + 2] ) ) {
            bool flag = false;
            if(pq[2 * parentIndex +1 ] > pq[2 * parentIndex + 2]) {
                flag = true;
            }
            if(flag) {
                int temp2 = pq[parentIndex];
                pq[parentIndex] = pq[ 2 * parentIndex + 2];
                pq[ 2 * parentIndex + 2] = temp2;
                parentIndex = 2 * parentIndex +2;
            } else {
              int temp2 = pq[parentIndex];
              pq[parentIndex] = pq[2 * parentIndex + 1];
              pq[2 * parentIndex + 1] = temp2;
              parentIndex = 2 * parentIndex + 1;
            }
        }
        return temp;
    }
};

// MAX Priority Queue 
class PriorityQueue_MAX {
    vector<int> pq;

   public:
    PriorityQueue_MAX() {
        // Implement the constructor here
    }

    /**************** Implement all the public functions here ***************/

    void insert(int element) {
        pq.push_back(element);
        int n = pq.size() - 1;
        while(n > 0 && pq[n] > pq[(n-1)/2] ) {
            int temp = pq[n];
            pq[n] = pq[(n-1)/2];
            pq[(n-1)/2] = temp;
            n = (n - 1)/2;
        }

    }

    int getMax() {
        if(!pq.size()) {
            return INT_MIN;
        }
        return pq[0];
    }

    int removeMax() {
        if(pq.size() == 0) {
            return INT_MIN;
        }
        int temp = pq[0];
        int n = pq.size() - 1;
        pq[0] = pq[n];
        pq.pop_back();
        int p = 0;
        while(2 * p + 1 < pq.size() && ( pq[p] < pq[(2 * p +1)] || pq[p] < pq[(2 * p + 2)] )){
            bool flag = false;
            if(pq[ (2 * p + 1)] < pq[(2 * p + 2)]) {
                flag = true;
            }
            if(flag) {
                int temp2 = pq[p];
                pq[p] = pq[(2* p +2)];
                pq[(2 *p + 2)] = temp2;
                p = 2 * p + 2;
            }
            else {
                int temp2 = pq[p];
                pq[p] = pq[(2 *p +1)];
                pq[( 2 * p + 1)] = temp2;
                p = 2 * p + 1;
            }
        }
        return temp;
    }

    int getSize() { 
        return pq.size();
    }

    bool isEmpty() {
        return pq.size() == 0;
    }
};
// K Sorted Array
// An element in array can  moves only kth distance from its current position
void k_sorted_array(int arr[], int size, int k) {
    if(k == 0  || size == 0 || k > size) {
        return;
    }
    priority_queue<int> pq;
    for(int i = 0 ; i < k; i++) {
        pq.push(arr[i]);
    }
    int j = 0;
    for(int i = k; i < size; i++) {
        arr[j++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }
    while(!pq.empty()) {
        arr[j++] = pq.top();
        pq.pop();
    }
}
//       K smallest Elements
vector<int> kSmallest(int arr[], int n, int k) {
    priority_queue<int> pq;
    for(int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }
    for(int i = k; i < n; i++) {
        pq.push(arr[i]);
        pq.pop();
    }
    vector<int> v;
    while(!pq.empty()) {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}
//      min Priority Queue syntax is --   priority_queue< int, vector<int>, greater<int> > p; 
//      ( inbuilt min priority queue)


//           K largest elements
vector<int> kLargest(int input[], int n, int k){
    priority_queue<int, vector<int> , greater<int> > p;
    for(int i  = 0; i < k ; i++) {
        p.push(input[i]);
    }
    vector<int> v;
    for(int i = k; i < n; i++) {
        p.push(input[i]);
        p.pop();
    }
    while(!p.empty()) {
        v.push_back(p.top());
        p.pop();
    }
    return v;
}
//          Check Max-Heap (with - less time complexity)
bool isMaxHeap(int arr[], int n) {
    int parent = 0;
    while((2 * parent +1 < n ) ) {
        if(arr[parent] < arr[2 * parent + 1] || arr[parent] < arr[2 * parent + 1]) {
            return false;
        }
        parent++;
    }
    return true;
}
//      2nd Method    Check Max-Heap  (with high Timp complexity)
bool isMax_Heap(int arr[], int n) {
    priority_queue<int> p;
    for(int i = 0 ; i < n; i ++ ) {
        p.push(arr[i]);
    }
    bool flag = true;
    for(int i = 0; i < n; i++ ) {
        if(arr[i] != p.top() ) {
            flag = false;
            break;
        }
        p.pop();
    }
    return flag;
}