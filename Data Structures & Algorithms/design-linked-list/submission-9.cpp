struct NodeList
{
    int val;
    NodeList* prev;
    NodeList* next;
    NodeList(int val, NodeList* prev, NodeList* next)
        : val{val}, prev{prev}, next{next}
        {}
    NodeList(): NodeList(0,nullptr,nullptr)
    {
    }
};


class MyLinkedList {
    NodeList* head;
    NodeList* tail;
    int length;
public:
    MyLinkedList()
        : head{new NodeList{}}, 
        tail{new NodeList{}},
        length{0} 
    {
        head->next = tail;
        tail->prev = head;
    }
    
    NodeList* traverse(int index) const
    {
        if(index <= length/2)
        {
            NodeList* trav{head->next};
           for(int i{0}; i < index; ++i)
           {
            trav = trav->next;
           }
            return trav;
        }
        else 
        {
            
            NodeList* trav{tail->prev};
            for(int i{length - 1}; i > index; --i)
            {
                trav = trav->prev;
            }
            return trav;
        }
    }

    int get(int index) const {
       if(index < 0 || index >= length) return -1;
       else return traverse(index)->val;
    }
    
    void addAtHead(int val) {
        NodeList* node {new NodeList{val, head, head->next}};
        head->next->prev = node;
        head->next = node;
        ++length;
    }
    
    void addAtTail(int val) {
        NodeList* node {new NodeList{val,tail->prev, tail}};
        tail->prev->next = node;
        tail->prev = node;
        ++length; 
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0 || index > length) return;
        if(index == 0)
        {
            addAtHead(val);
        }
        else if(index == length)
        {
            addAtTail(val);
        }
        else
        {
            NodeList* trav{traverse(index)};
            NodeList* node{new NodeList{val,trav->prev,trav}};
            trav->prev->next = node;
            trav->prev = node;
            ++length;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index < 0 || index >= length ) return;
        NodeList* trav{traverse(index)};
        trav->prev->next = trav->next;
        trav->next->prev = trav->prev;
        delete trav;
        --length;
    }
    ~MyLinkedList()
    {
        while(head)
        {
            NodeList* temp{head};
            head = head->next;
            delete temp;
        }
           length = 0;
            head = nullptr;
            tail = nullptr;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */