#include <initializer_list>
#include <iostream>
#include <cassert>

// Class declarations
class Set;
class Node;
// Function declarations
// Prints elements of the set (this code is given below)
std::ostream &operator<<(std::ostream &out, Set const &rhs);
// Class definitions
class Set
{
public:
    // This is new and will be clearly explained
    Set(std::initializer_list<int> initial_values);
    ~Set();
    // The instructions will describe exactly what to do
    Set(Set const &orig);
    Set(Set &&orig);
    // The instructions will describe exactly what to do
    Set &operator=(Set const &orig);
    Set &operator=(Set &&orig);
    // Size operations
    bool empty() const;
    std::size_t size() const;
    // Clear all items out of the set
    void clear();
    // Find the value item in the set
    // - Return the address of the node if found,
    // and nullptr otherwise.
    Node *find(int const &item) const;
    // Insert the item into the set if it
    // is not already in the set.
    // - Return 1 if the item is new,
    // and 0 otherwise.
    std::size_t insert(int const &item);

    // Insert all the items in the array
    // from array[begin] to array[end - 1]
    // that are not already in the set.
    // - Return the number of items inserted
    // into the set.
    std::size_t insert(int const array[],
                       std::size_t const begin,
                       std::size_t const end);
    // Remove the item from the set and
    // return the number of items removed.
    std::size_t erase(int const &item);
    // Move any items from 'other', whose values
    // do not appear in 'this', to 'this'.
    // Leave any items that already appear
    // in both sets, in both sets.
    std::size_t merge(Set &other);
    // Set operations (Automatic Assigment)
    Set &operator|=(Set const &other); // union
    Set &operator&=(Set const &other); // intersection
    Set &operator^=(Set const &other); // symmetric difference
    Set &operator-=(Set const &other); // minus
    // Set operations (Binary)
    Set operator|(Set const &other) const; // union
    Set operator&(Set const &other) const; // intersection
    Set operator^(Set const &other) const; // symmetric difference
    Set operator-(Set const &other) const; // minus
    // Returns 'true' if 'this' set is a
    // superset of 'other' set; that is,
    // all entries in the 'other' set are
    // also in this set.
    bool operator>=(Set const &other) const;
    // A superset but not equal to.
    bool operator>(Set const &other) const;
    // Is 'this' a subset of the other set?
    bool operator<=(Set const &other) const;
    // A subset but not equal to.
    bool operator<(Set const &other) const;
    bool operator==(Set const &other) const;
    bool operator!=(Set const &other) const;

private:
    Node *p_head_;

    friend std::ostream &operator<<(std::ostream &out, Set const &rhs);
};

class Node
{
public:
    Node(int new_value, Node *new_next);
    int value() const;
    Node *next() const;

private:
    int value_;
    Node *next_;
    // Allow any member function in the class
    // 'Set' to access or modify the member
    // variables of any instance of this class.
    friend class Set;
};

Node::Node(int new_value, Node *new_next) : value_{new_value},
                                            next_{new_next} {}

int Node::value() const
{
    return value_;
}

Node *Node::next() const
{
    return next_;
}

std::ostream &operator<<(std::ostream &out, Set const &rhs)
{
    out << "{";
    if (!rhs.empty())
    {
        out << rhs.p_head_->value();
        for (Node *ptr{rhs.p_head_->next()}; ptr != nullptr; ptr = ptr->next())
        {
            out << ", " << ptr->value();
        }
    }
    out << "}";
    return out;
}

bool Set::empty() const
{
    // returns true if set is empty and false otherwise
    // check if p_head_ is assigned nullptr
    return p_head_ == nullptr;
}
std::size_t Set::size() const
{
    std::size_t list_size{0};

    for (Node *p_node{p_head_};
         p_node != nullptr; p_node = p_node->next())
    {
        ++list_size;
    }

    return list_size;
}
Node *Set::find(int const &item) const
{
    for (Node *p_node{p_head_}; p_node != nullptr; p_node = p_node->next())
    {

        if (p_node->value() == item)
        {
            return p_node;
        }
    }
    return nullptr;
}

std::size_t Set::insert(int const &item)
{
    if (find(item) != nullptr)
    {
        return 0;
    }

    else
    {
        p_head_ = new Node(item, p_head_);
        return 1;
    }
}

void Set::clear()
{
    Node *current = p_head_;
    Node *nextNode = nullptr;

    while (current != nullptr)
    {
        nextNode = current->next();
        delete current;
        current = nextNode;
    }

    p_head_ = nullptr;
}

Set::~Set()
{
    clear();
}

Set::Set(Set const &orig) : p_head_{nullptr}
{ // initlize empty

    for (Node *ptr{orig.p_head_}; ptr != nullptr; ptr = ptr->next())
    {
        insert(ptr->value());
    }
}

Set::Set(Set &&orig) : p_head_{nullptr}
{
    std::swap(p_head_, orig.p_head_);
}

Set &Set::operator=(Set const &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }

    else
    {
        clear();
        for (Node *ptr{rhs.p_head_}; ptr != nullptr; ptr = ptr->next())
        {
            insert(ptr->value());
        }
    }

    return *this;
}

Set &Set::operator=(Set &&rhs)
{
    std::swap(p_head_, rhs.p_head_);
    return *this;
}

std::size_t Set::insert(int const array[], std::size_t const begin, std::size_t const end)
{
    std::size_t counter{0};

    for (std::size_t i{begin}; i < end; ++i)
    {
        counter += insert(array[i]);
    }

    return counter;
}

std::size_t Set::erase(int const &item) //FINISH THIS
{
    Node* previous = nullptr; 

    for (Node* current{p_head_}; current != nullptr;) {
        Node* next = current->next_; 

        if (current->value() == item) {
            if (previous == nullptr) {
                p_head_ = next; 
            }

            else {
                previous->next_ = next; 
            }

            delete current; 
            return 1; 
        }

        previous = current; 
        current = next; 
    }

    return 0; 

}

std::size_t Set::merge(Set &other)
{

    std::size_t moveCount = 0;
    Node *previous = nullptr;

    for (Node *current{other.p_head_}; current != nullptr;)
    {

        Node *next = current->next_;
        if (find(current->value()) != nullptr)
        {
            previous = current;
        }

        else
        {
            if (previous == nullptr)
            {
                other.p_head_ = next;
            }

            else
            {
                previous->next_ = next;
            }
            current->next_ = p_head_;
            p_head_ = current;
            moveCount++;
        }

        current = next; // go to the next node
    }

    return moveCount;
}

// Any member function that returns a set
// by reference should return *this;
// v---- the & indicates a return by reference
Set &Set::operator|=(Set const &rhs)
{
    for (Node *ptr{rhs.p_head_}; ptr != nullptr; ptr = ptr->next_)
    {
        insert(ptr->value());
    }

    return *this;
}

Set &Set::operator&=(Set const &rhs)
{

    for (Node *ptr{p_head_}; ptr != nullptr;)
    { // avoid using the ptr = ptr->next_ to avoid danging memoery

        Node *next = ptr->next_;

        if (rhs.find(ptr->value()) == nullptr)
        {
            erase(ptr->value());
        }

        ptr = next;
    }

    return *this;
}

Set &Set::operator^=(Set const &rhs)
{
    for (Node *ptr{rhs.p_head_}; ptr != nullptr; ptr = ptr->next_)
    {
        if (find(ptr->value()) != nullptr)
        {
            erase(ptr->value());
        }

        else
        {
            insert(ptr->value());
        }
    }

    return *this;
}

Set &Set::operator-=(Set const &rhs)
{
    for (Node *ptr{rhs.p_head_}; ptr != nullptr; ptr = ptr->next_)
    {
        erase(ptr->value());
    }

    return *this;
}

Set Set::operator|(Set const &rhs) const
{
    // Create a copy of 'this'.
    Set tmp{*this};
    // Make 'tmp' the intersection of
    // 'tmp' and the right-hand side.
    tmp |= rhs;
    // Return the temporary set that is now the
    // intersection of this and 'rhs'.
    return tmp;
}

Set Set::operator&(Set const &rhs) const
{
    // Create a copy of 'this'.
    Set tmp{*this};
    // Make 'tmp' the intersection of
    // 'tmp' and the right-hand side.
    tmp &= rhs;
    // Return the temporary set that is now the
    // intersection of this and 'rhs'.
    return tmp;
}

Set Set::operator^(Set const &rhs) const
{
    // Create a copy of 'this'.
    Set tmp{*this};
    // Make 'tmp' the intersection of
    // 'tmp' and the right-hand side.
    tmp ^= rhs;
    // Return the temporary set that is now the
    // intersection of this and 'rhs'.
    return tmp;
}

Set Set::operator-(Set const &rhs) const
{
    // Create a copy of 'this'.
    Set tmp{*this};
    // Make 'tmp' the intersection of
    // 'tmp' and the right-hand side.
    tmp -= rhs;
    // Return the temporary set that is now the
    // intersection of this and 'rhs'.
    return tmp;
}


bool Set::operator>=(Set const &rhs) const {
    for (Node* ptr{rhs.p_head_}; ptr != nullptr; ptr = ptr->next_) {
        if (find(ptr->value()) == nullptr) {
            return false; 
        }
    }

    return true; 
}

bool Set::operator>(Set const &rhs) const { 
    if ((*this >= rhs) && (size() > rhs.size())) {
        return true; 
    }

    return false; 
}

bool Set::operator<=(Set const &rhs) const { 
    if (rhs >= *this) {
        return true; 
    }

    return false; 
}

bool Set::operator<(Set const &rhs) const { 
    if (rhs > *this) {
        return true; 
    }

    return false; 
}


bool Set::operator==(Set const &rhs) const {  
    if ((*this >= rhs) && (rhs >= *this)) {
        return true; 
    }

    return false; 
}

bool Set::operator!=(Set const &rhs) const {  
    if (!((*this >= rhs) && (rhs >= *this))) {
        return true; 
    }

    return false; 
}


Set::Set(std::initializer_list<int> inital_values) : p_head_{nullptr}
{
    for (int const &value : inital_values)
    {
        insert(value);
    }
}

int main()
{

    Set my_data_1{1, 3, 5, 2, 4, 8, 5, 3, 1};
    // This should print '6'
    std::cout << my_data_1.size() << std::endl;
    // This should print '0' ('false')
    std::cout << my_data_1.empty() << std::endl;
    assert(my_data_1.find(0) == nullptr);
    assert(my_data_1.find(1)->value() == 1);
    assert(my_data_1.find(5)->value() == 5);
    assert(my_data_1.find(6) == nullptr);
    assert(my_data_1.find(8)->value());
}