
#ifndef _H_LSLISTS
#define _H_LSLISTS

#include <stdexcept>

namespace ls
{

struct exp_out_of_bounds : public std::exception
{
    const char * what() const throw()
    {
        return "List index out of bounds";    
    }
};
    
template <class t>
class list
{
	struct node
	{
		t data;
		node *next;

		node(t value) : data(value)
		{
			next = nullptr;
		}
	};
    
	node *head;
    
    int partition(int low, int high)
    {
        t pivot = at(high);
        int i = (low - 1);
        
        for(int j = low; j <= high - 1; j++)
        {
            if(at(j) < pivot)
            {
                i++;
                swap(i, j);
            }
        }
        swap(i + 1, high);
        return(i + 1);
    }
    
    int cpartition(int low, int high, bool(*lessthan) (t,t))
    {
        if(lessthan != nullptr)
        {
        t pivot = at(high);
        int i = (low - 1);
        
        for(int j = low; j <= high - 1; j++)
        {
            if(lessthan(at(j), pivot))
            {
                i++;
                swap(i, j);
            }
        }
        swap(i + 1, high);
        return(i + 1);
        }
        else
        {
             t pivot = at(high);
        int i = (low - 1);
        
        for(int j = low; j <= high - 1; j++)
        {
            if(lessthan(at(j), pivot))
            {
                i++;
                swap(i, j);
            }
        }
        swap(i + 1, high);
        return(i + 1);
        }
    }
    
    void quicksort(int low, int high)
    {
        if(low < high)
        {
            int part = partition(low, high);
            
            quicksort(low, part - 1);
            quicksort(part + 1, high);
        }
    }
    
    void cquicksort(int low, int high, bool (*lessthan)(t, t))
    {
        if(low < high)
        {
            int part = cpartition(low, high, lessthan);
            
            cquicksort(low, part - 1, lessthan);
            cquicksort(part + 1, high, lessthan);
        }
    }

	public:

	list()
	{
		head = nullptr;
	}

	bool is_empty()
    {
        if(head == nullptr)
            return true;
        else
            return false;
    }

	void add_front(t obj)
	{
		if(head == nullptr)
		{
			head = new node(obj);
		}
		else
		{
			node * temp = head;
			head = new node(obj);
			head->next = temp;
		}

	}

	void add_back(t obj)
	{
		if(head == nullptr)
		{
			head = new node(obj);
		}
		else
		{
			node * temp = head;
			while(temp->next != nullptr)
			{
				temp = temp->next;
			}
			temp->next = new node(obj);
		}
	}

	t& at(int index)
	{
        if(index >= 0 && index < size())
        {
            int i = 0;
            node *temp = head;

            while(temp != nullptr)
            {
                if(i == index)
                    return temp->data;

                temp = temp->next;
                i++;
            }
		}
		else
        {
            exp_out_of_bounds e;
            throw e;
        }
        return head->data;
	}
	
	t& operator [](int index)
    {
        return at(index);
    }
    
	void remove(int index)
	{
		int i = 0;
		if(index >= 0 &&  index < size())
		{
			if(index == 0)
			{
				node * temp = head->next;
				delete(head);
				head = temp;
                return;
			}
			else
			{
				node * temp = head;
				node * prev = head;
				i = 0;
	
				while(temp != nullptr)
				{
					if(i == index)
					{
						prev->next = temp->next;
						delete(temp);
                        return;
					}
					if(temp != head)
						prev = prev->next;

					temp = temp->next;
					i++;
				}
			}
		}
	}
	
	void removeItem(t obj)
    {
        node *temp = head;
        
        if(head != nullptr)
        {
            while(temp != nullptr)
            {
                if(temp->data == obj)
                {
                    remove(find_index(obj));
                    return;
                }
                temp = temp->next;
            }
        }
    }

	int size()
	{
		int i = 0;
		node *temp = head;

		while(temp != nullptr)
		{
			temp = temp->next;
			i++;
		}
		return i;
	}

	void clear()
	{
		while(head != nullptr)
		{
			this->remove(0);
		}
	}
	
	void swap(int index1, int index2)
    {
        if(index1 == index2)
            return;
        
        t temp = at(index1);
        at(index1) = at(index2);
        at(index2) = temp;
    }

	void sort()
    {
        quicksort(0, size() - 1);
    }
    
    void csort(bool(*lessthan) (t, t))
    {
        cquicksort(0, size() - 1, lessthan);
    }

	t* find(t obj1)
	{
		node *temp = head;
		while(temp != nullptr)
		{
			if(temp->data == obj1)
				return &(temp->data);

			temp = temp->next;
		}
		return nullptr;
	}
	
	int find_index(t obj)
    {
        int i = 0;
        node *temp = head;
        if(head != nullptr)
        {
            while(temp != nullptr)
            {
                if(temp->data == obj)
                    return i;
            
                temp = temp->next;
                i++;
            }
        }
        return -1;
    }

	void condense()
	{
		node *temp = head;
		list <t> found;
        
		while(temp != nullptr)
		{
			if(found.find(temp->data) == nullptr) //Not in the list...
				found.add_back(temp->data);	
            else
                remove(find_index(temp->data));

			temp = temp->next;
		}
        
	}

	virtual ~list()
	{
		clear();
	}

};

template<class t>
class stack : protected list<t>
{
	public:

	void push(t obj)
	{
		this->add_front(obj);
	}

	t pop()
	{
		t ret = this->at(0);
		this->remove(0);
		return ret;
	}

	t& peak()
	{
		return this->at(0);
	}

	virtual ~stack()
	{
		this->clear();
	}
};

template<class t>
class queue : protected list<t>
{
	public:

	void enqueue(t obj)
	{
		this->add_back(obj);
	}

	t dequeue()
	{
		t ret = this->at(0);
		this->remove(0);
		return ret;
	}

	t& peak()
	{
		return this->at(0);
	}

    virtual ~queue()
	{
		this->clear();
	}
};
template<class t>
class bst
{
    struct n
    {
        n *left;
        n *right;
        t data;
        
        n(t value) : data(value)
        {
            left = nullptr;
            right = nullptr;
        }
    };
    
	n * add(n *node, t obj)
    {   
        if(node == nullptr)
            return new n(obj);
        if(obj < node->data)
            node->left = add(node->left, obj);
        else
            node->right = add(node->right, obj);

		return node;
    }
    
	void printPostOrder(n * node)
	{
		if(node == nullptr) //reached the end
			return;

		printPostOrder(node->left);
		printPostOrder(node->right);
		
        printed.add_back(&(node->data));
	}
	
	void printInOrder(n *node)
	{
		if(node == nullptr)
			return;

		printInOrder(node->left);
		
        printed.add_back(&(node->data));
		printInOrder(node->right);
	}

	void printPreOrder(n *node)
	{
		if(node == nullptr)
			return;

        printed.add_back(&(node->data));
		printPreOrder(node->left);
		printPreOrder(node->right);
	}
	
	void clear(n *node)
	{
		if (node == nullptr) 
            return;  
  
    	clear(node->left);  
    	clear(node->right);  
    
        delete node; 
	}	

	n *root;
	
	public:
        
    list<t*> printed;

	bst()
	{
		root = nullptr;
	}

	void add(t obj)
	{
        if(root == nullptr)
            root = new n(obj);
        else
            add(root, obj);
	}

	void printPostOrder()
	{
		 printPostOrder(root);
	}
    
	void printInOrder()
	{
		printInOrder(root);
	}

	void printPreOrder()
	{
        printPreOrder(root);
	}

	void clear()
	{
		clear(root);
	}
	
	virtual ~bst()
	{
		clear(root);
	}
};
}

#endif

