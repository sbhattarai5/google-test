#include <gtest/gtest.h> // including the library

// everything is made public to make this easy

template <typename T>
class Node      
{
public:
    Node(T val, Node< T > *next=NULL)
        : val_(val), next_(next)
    {}
    T val_;
    Node< T > *next_;
};

template <typename T>
class LinkedList
{
public:
    LinkedList()
        : head_(NULL)
    {}
    ~LinkedList()
    {
        while (head_ != NULL)
        {
            Node < T > * head = head_->next_;
            delete head_;
            head_ = head;
        }
    }
    void print() const
    {
        Node< T > *cptr = head_;
        while (cptr != NULL)
        {
            std::cout << cptr->val_ << ' ';
            cptr = cptr->next_;
        }
        std::cout << std::endl;
    }
    
    void addtohead(T val)
    {
        head_ = new Node< T >(val, head_);
    }
    Node< T > * deletehead() // returns pointer to the deleted node
    {
        if (head_ == NULL) return NULL;
        Node< T > * head = head_;
        head_ = head_ -> next_;
        return head;
    }
    Node< T > *head_;
};

TEST(LinkedListTest, InitializationTest)
{
    LinkedList< int > ll;
    EXPECT_EQ(ll.head_, nullptr);
}

TEST(LinkedListTest, AddToNonEmptyListTest)
{
  LinkedList< int > ll;
  ll.addtohead(5);
  ASSERT_NE(ll.head_, nullptr);
  EXPECT_EQ(5, ll.head_->val_);
}

TEST(LinkedListTest, DeleteFromNonEmptyListTest)
{
    LinkedList< int > ll;
    ll.addtohead(5);
    Node< int > *n = ll.deletehead();
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(n->val_, 5);
    delete n;
}

class NonEmptyLinkedListTest : public ::testing::Test
{
public:
    NonEmptyLinkedListTest()
        : ll1(new LinkedList< int >)
    {
        ll1->addtohead(5);
    }
    ~NonEmptyLinkedListTest()
    {
        delete ll1;
    }
    LinkedList< int > * ll1;
};

TEST_F(NonEmptyLinkedListTest, AddToHeadTest)
{
    ASSERT_NE(ll1->head_, nullptr);
    EXPECT_EQ(5, ll1->head_->val_);
}

TEST_F(NonEmptyLinkedListTest, DeleteHeadTest)
{
    Node< int > *n = ll1->deletehead();
    ASSERT_NE(n, nullptr);
    EXPECT_EQ(n->val_, 5);
    delete n;
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv); // initializing it
    return RUN_ALL_TESTS(); // this will run all your tests
}
