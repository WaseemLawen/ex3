
#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>


template <class T>
class Queue
{
private:
    class Node
    {
        public:
        T m_data;
        Node *next;
        Node& operator=(const Node& node){
            if(this == &node){
                return *this;
            }
            this->m_data = node.m_data;
            return *this;
        }
        explicit Node(T data):m_data(data),next(nullptr){}
    
        T& operator*()
        {
            return m_data;
        }
    };

    Node* m_head;
    Node* m_tail;
    int m_size=0;

public:
    void pushBack(const T& data);
    T& front();
    const T& front() const;
    void popFront();
    int size() const;
    
    class EmptyQueue {};
    Queue();
    Queue<T>& operator=(const Queue<T>&);
    ~Queue();
    Queue(const Queue<T> &copy_from);
    class Iterator;
    class ConstIterator;
    Iterator begin();
    ConstIterator begin() const;
    Iterator end();
    ConstIterator end() const;
    template<class condition>
    Queue<T> filter(const Queue<T> queue,condition cond);
    template<class transFunc>
    void transform(Queue<T> &queue,transFunc function);

};

template<class T>
Queue<T>::Queue():
    m_head(nullptr),
    m_tail(nullptr),
    m_size(0)
    {        
    }


template<class T>
Queue<T>::~Queue()
{
    while(m_size>0)
    {
        this->popFront();
    }
}

template<class T>
Queue<T>::Queue(const Queue<T> &cpyT)
{
    m_head = nullptr;
    for(typename Queue<T>::ConstIterator it = cpyT.begin(); it != cpyT.end(); ++it)
    {
        pushBack(*(it));
    }

}



template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T>& t)
{
    if(this==&t)
    {
        return *this;
    }
    Node *currNode=m_head;
    Node *nextNode=m_head;
    while(nextNode != nullptr){
        nextNode = currNode->next;
        delete(currNode);
        currNode = nextNode;
    }
    //delete m_head;
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
    Node *oNode = t.m_head;
    while (oNode != nullptr){
        pushBack(oNode->m_data);
        m_size += 1;
        oNode = oNode->next;
    }
    return *this;
    /*
    this->m_size = t.m_size;
    //this->m_head = t.m_head;
    Node *currNode=m_head;
    Node *tNode=m_head;
    while(currNode)
    {
        currNode=tNode;
        delete currNode;
        currNode=currNode->m_next;
    }
    //m_head=new Node*;
    m_tail=nullptr;
    m_size=0;
    m_head->next=m_tail;
    m_tail=m_head;
    for(T element: t)
    {
        this->pushBack(element);
    }*/
   // return *this;
}

template<class T>
class Queue<T>::Iterator
 {
        private:
        Node *m_node;
        Iterator(Node *node); 
    
        public:
        friend class Queue<T>;
        Iterator operator++();
        bool operator!=(Iterator itNode);
        Iterator& operator= (const Iterator&) = default;
        T& operator*();
        class InvalidOperation{};

};
template<class T>
class Queue<T>::ConstIterator
{
        private:
            Node *m_node;
            ConstIterator(Node *node); 
        
        public:
            friend class Queue<T>;
            ConstIterator operator++();
            ConstIterator& operator= (const ConstIterator&) = default;
            bool operator!=(ConstIterator itNode);
            const T& operator*() const;
            class InvalidOperation{};

};
template<class T>
typename Queue<T>::Iterator Queue<T>::begin()
{
    return Iterator(m_head);
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::begin() const
{
    return ConstIterator(m_head);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end()
{
    /*if(m_tail)
    {
        return Iterator(m_tail->next);
    }
    else
    {
        return nullptr;
    }*/
    return nullptr;
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::end() const
{
    /*if(m_tail)
    {
        return ConstIterator(m_tail->next);
    }
    else
    {
        return nullptr;
    }*/
    return nullptr;
}


template<class T>
void Queue<T>::pushBack(const T& data)
{
    Node *tmp = new Node(data);
    if(m_head == nullptr)
    {
        m_head = tmp;
        m_tail = tmp;
    }
    else
    {
        m_tail->next = tmp;
        m_tail = m_tail->next;
    }
    ++m_size;
}

template<class T>
T& Queue<T>::front()
{
    if(m_head == nullptr)
    {
        throw EmptyQueue();
    }
    else
    {
        return m_head->m_data;
    }
}

template<class T>
const T& Queue<T>::front() const
{
    if(m_head == nullptr)
    {
        throw EmptyQueue();
    }
    else
    {
        return m_head->m_data;
    }
}


template<class T>
int Queue<T>::size() const
{
    return m_size;
}

template<class T>
void Queue<T>::popFront()
{
    if(m_head != nullptr)
    {
        if(m_size == 1)
        {
            delete m_head;
            m_head = nullptr;
            m_tail = nullptr;
        }
        else{
        Node *tmp = m_head;
        m_head = m_head->next;
        delete tmp;
        }   
    }
    else
    {
        throw EmptyQueue(); 
    }
    --m_size;
}



template<class condition,class T>
Queue<T> filter(const Queue<T> &queue, condition cond)
{
    Queue<T> filteredQueue;
    if(!queue.size()) {
        return filteredQueue;
    }
    for(typename Queue<T>::ConstIterator it = queue.begin(); it != queue.end(); ++it)
    {
        if(cond(*it))
        {
            filteredQueue.pushBack(*it);
        }
    }
    return filteredQueue;
}
template<class T, class transFunc>
void transform(Queue<T> &queue,transFunc function)
{
    if(!queue.size()){
        return;
    }

    typename Queue<T>::Iterator it = queue.begin();
    while(it!=queue.end()){
        function(*it);
        ++it;
    }
}

template<class T>
typename Queue<T>::Iterator Queue<T>::Iterator::operator++()
{
    if(m_node == nullptr)
    {
        throw InvalidOperation();
    }
    m_node = m_node->next;
    return *this;
}

template<class T>
typename Queue<T>::ConstIterator Queue<T>::ConstIterator::operator++()
{
    if(m_node == nullptr)
    {
        throw InvalidOperation();
    }
    m_node = m_node->next;
    return *this;
}

template<class T>
T& Queue<T>::Iterator::operator*()
{
    if(m_node == nullptr)
    {
        throw InvalidOperation();
    }
    return m_node->m_data;
}

template<class T>
const T& Queue<T>::ConstIterator::operator*() const
{
    if(m_node == nullptr)
    {
        throw InvalidOperation();
    }
    return m_node->m_data;
}

template<class T>
bool Queue<T>::Iterator::operator!=(Queue<T>::Iterator itNode)
{
    return m_node != itNode.m_node;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(Queue<T>::ConstIterator itNode)
{
    return m_node != itNode.m_node;
}

template<class T>
Queue<T>::Iterator::Iterator(Queue<T>::Node *node)
{
    m_node = node;
}

template<class T>
Queue<T>::ConstIterator::ConstIterator(Queue<T>::Node *node)
{
    m_node = node;
}


#endif