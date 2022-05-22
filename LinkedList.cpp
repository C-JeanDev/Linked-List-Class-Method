#include <iostream>

/**
 * METHOD LIST
 *  
 * print
 * print_recursively
 * print_reverse_recursively
 * pop
 * push
 * insert_begin
 * delete_first
 * insert n position
 * delete n position
 * reverse
 * reverse_recursively
 * Sort
 * Is_sorted{ Decreasing-Increasing }
 * get_len
 *
 */

struct Node
{
    int data;
    Node *next;
    Node() = default;
    Node(int data, Node *p)
    {
        this->data = data;
        this->next = p;
    }
};

class LinkedList
{
private:
    struct Node
    {
        int data;
        Node *next;
        Node() = default;
        Node(int data, Node *p)
        {
            this->data = data;
            this->next = p;
        }
    };

    void swap(int &x, int &y)
    {
        int a;
        a = x;
        x = y;
        y = a;
    }

    Node *head = nullptr;

public:
    LinkedList() {}

    LinkedList(std::initializer_list<int> lists)
    {
        for (auto element : lists)
        {
            push(element);
        }
    }

    void print()
    {
        Node *temp = head;
        int i = 0;
        while (temp->next != nullptr)
        {
            std::cout << "[" << i << "]: " << temp->data << '\n';
            temp = temp->next;
            i++;
        }
        std::cout << "[" << i << "]: " << temp->data << '\n';
    }

    int q = 0;
    void print_recursively(Node *head)
    {
        if (head == NULL)
            return;
        std::cout << "[" << q << "]: " << head->data << std::endl;
        q++;
        print_recursively(head->next);
    }

    void print_recursively()
    {
        print_recursively(head);
        q = 0;
    }

    void print_reverse_recursively(Node *head)
    {
        if (head == NULL)
            return;
        print_reverse_recursively(head->next);
        std::cout << "[" << q << "]: " << head->data << std::endl;
        q++;
    }

    void print_reverse_recursively()
    {
        print_reverse_recursively(head);
        q = 0;
    }

    void print_head()
    {
        std::cout << head << std::endl;
    }

    int get_len()
    {
        Node *p = head;
        int len = 0;
        while (p->next != nullptr)
        {
            p = p->next;
            len++;
        }

        return len;
    }

    void push(int data)
    {
        Node *newNode = new Node(data, nullptr);

        if (!head)
        {
            head = newNode;
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void pop()
    {
        Node *temp = head;
        Node *temp1;
        while (temp->next != nullptr)
        {
            temp1 = temp;
            temp = temp->next;
        }

        temp1->next = nullptr;
        delete[] temp;
    }

    void delete_first()
    {
        Node *temp = head;
        head = head->next;
        delete[] temp;
    }

    void insert_begin(int data)
    {
        Node *temp = head;
        Node *newNode = new Node(data, temp);
        head = newNode;
    }

    void insert(int pos, int data)
    {
        Node *temp = head;
        Node *temp1;
        int i = 0;

        while (i <= pos)
        {
            temp1 = temp;
            if (i == pos - 1)
            {
                Node *newNode = new Node(data, temp->next);
                temp1->next = newNode;
            }
            temp = temp->next;
            i++;
        }
    }

    void delete_node(int pos)
    {
        Node *prev;
        Node *current = head;
        Node *next;

        Node *temp = head;
        if (pos == 1)
        {
            head = temp->next;
            free(temp);
            return;
        }

        int i = 0;

        while (i <= pos)
        {
            prev = current;
            current = current->next;
            next = current->next;
            if (i == pos - 1)
            {
                delete[] current;
                prev->next = next;
            }
            i++;
        }
    }

    void reverse()
    {
        Node *current = head;
        Node *prev = NULL;
        Node *next;
        while (current != NULL)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void reverse_recursively(Node *temp)
    {
        if (temp->next == NULL)
        {
            head = temp;
            return;
        }
        reverse_recursively(temp->next);
        Node *q = temp->next;
        q->next = temp;
        temp->next = NULL;
    }
    void reverse_recursively()
    {
        reverse_recursively(head);
    }


    bool is_sorted()
    {

        int len = get_len();

        bool incSorted = true;
        bool decSorted = true;
        Node *temp = head;
        Node *temp1 = temp->next;
        for (int i = 0; i < len; i++)
        {
            if (temp->data > temp1->data)
            {
                incSorted = false;
                std::cout<<"1 for";
                break;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }

        // if(incSorted == true){
        //     return true;
        // }

            Node *t = head;
            Node *t1 = temp->next;
        for (int i =0; i<len;i++)
        {
            if (t->data < t1->data)
            {
                decSorted = false;
                std::cout<<"2 for";
                break;
            }
            t = t->next;
            t1 = t1->next;
        }

        return incSorted+decSorted;
    }

    void sort()
    {
        int len = get_len();

        for (int i = 0; i < len; i++)
        {
            Node *temp = head;
            Node *temp1 = temp->next;
            for (int j = 0; j < len; j++)
            {
                if (temp->data > temp1->data)
                {
                    swap(temp->data, temp1->data);
                }
                temp = temp->next;
                temp1 = temp->next;
            }
        }
    }

    ~LinkedList()
    {
        //std::cout<< "" <<std::endl;
    }
};

int main()
{
    LinkedList l2({11, -90, 8, 1, 9, 4});
    //l2.sort();
    std::cout << l2.is_sorted() << std::endl;
    l2.print();

    // HEAP
    LinkedList *l = new LinkedList;

    l->push(1);
    l->push(2);
    l->push(3);
    l->push(4);
    l->insert(4, 5);
    // l->insert_begin(0);
    l->pop();
    l->delete_first();
    l->reverse();
    // l->print_reverse_recursively();
    // l->print();
    free(l);

    // STACK
    LinkedList l1;

    l1.push(10);
    l1.push(20);
    l1.push(30);
    l1.push(40);
    l1.insert(4, 50);
    //.l1.insert_begin(0);
    l1.pop();
    l1.delete_first();
    l1.reverse();
    // l1.print_recursively();
    // l.print();

    return 0;
}
