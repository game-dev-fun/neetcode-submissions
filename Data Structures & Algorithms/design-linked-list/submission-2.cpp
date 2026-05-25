struct NodeList
{
    int val;
    NodeList* prev;
    NodeList* next;
    NodeList(int val, NodeList* prev, NodeList* next)
        : val{val}, prev{prev}, next{next}
        {}
};


class MyLinkedList {
private:
    NodeList* head;
    NodeList* tail;
    int length;
public:
    MyLinkedList() 
        : head{nullptr}, tail{nullptr}, length{0}
    {
    }
    
    NodeList* traverse(int index)
    {
        if(index < 0 || index >= length) return nullptr;
        if(index <= length/2)
        {
            int i{0};
            NodeList* trav{head};
            while(i != index)
            {
                trav = trav->next;
                ++i;
            }
            return trav;
        }
        else
        {
            int i{length - 1};
            NodeList* trav{tail};
            while(i != index)
            {
                trav = trav->prev;
                --i;
            }
            return trav;
        }
    }

    int get(int index) {
        if(index < 0 || index >= length) return -1;
        else return traverse(index)->val;
    }
    
    void addAtHead(int val) {
        NodeList* node {new NodeList {val,nullptr,head}};
        if(length == 0)
        {
            head = node;
            tail = node;
        }
        else
        {
            head->prev = node;
            head = node;
        }
        ++length;
    }
    
    void addAtTail(int val) {
        NodeList* node {new NodeList{val,tail, nullptr}};
        if(length == 0)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
        ++length;
    }
    
    void addAtIndex(int index, int val) {
        if(index <0 || index > length) return;
        if(index == 0) 
        {
            addAtHead(val);
            return;
        }
        else if( index == length)
        {
            addAtTail(val);
            return;
        }
        else
        {
            NodeList* trav{traverse(index)};
            NodeList* node {new NodeList{val,trav->prev,trav}};
            trav->prev->next = node;
            trav->prev = node;
            ++length;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index <0 || index >= length) return;
        if(length == 1)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            length = 0;
            return;
        }
        else if( index == 0)
        {
            NodeList* trav{head};
            head = head->next;
            head->prev = nullptr;
            delete trav;
            --length;
            return;
        }
        else if(index == length -1)
        {
            NodeList* trav{tail};
            tail = tail->prev;
            tail->next = nullptr;
            delete trav;
            --length;
            return;
        }
        else
        {
            NodeList* trav{traverse(index)};
            trav->prev->next = trav->next;
            trav->next->prev = trav->prev;
            delete trav;
            --length;
            return;
        }
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