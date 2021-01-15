#ifndef CHARLIST_HPP
#define CHARLIST_HPP

class CharList
{
private:
    //structure for the nodes of the linked list
    struct ListNode
    {
        //value contained in the node
        char value;
        //pointer that points to the next node
        struct ListNode *next;
    };

    // head (first node) of the list.
    ListNode *head;

public:
    //destructor
    ~CharList();

    //constructor
    CharList(){ head = nullptr; }

    // Useful operations for linked list
    void appendNode(char);
    void insertNode(char);
    void deleteNode(char);
    void displayList() const;
};

#endif // CHARLIST_HPP
