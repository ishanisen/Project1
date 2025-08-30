
#ifndef DALENG_H
#define DALENG_H

#include <iostream>
#include <string>

using namespace std;

// composition class date 

class date {
private:
	int day;
	int month;
	int year;
public:
	date(int d = 0, int m = 0, int y = 0);
	void read(istream& in);
	void write(ostream& out)const;

};

// composition class coop

class coop {
private:
	string companyname;
	string location;
	int duration;

public:
	coop(string c = "", string l = "", int m = 0);
	void read(istream& in);
	void write(ostream& out) const;
};



// parent class daleng
class daleng {

private:
	string name;
	string b00number;
	string discipline;
	float tuition;
	date grad_date;
	coop workterm;

public:
	daleng(string n = "", string boo = "", string dis = "", float t = 0.0, int d = 0, int m = 0, int y = 0, string comp = "", string loc = "", int dur = 0);
	virtual ~daleng();
	virtual void read(istream& in);
	virtual void write(ostream& out) const;
	virtual bool operator ==(const daleng& other)const;
	friend ostream& operator<<(ostream& out, const daleng& d);
	friend class list;
};


// scholar class
class scholar : public daleng {
private:
	string sname;
	float amount;

public:
	scholar(string n = " ", string boo = " ", string dis = " ", float t= 0.0, int d=0, int m=0, int y=0, string comp=" ", string loc= " ", int dur= 0, string sn = " ", float a = 0.0);
	void read(istream& in);
	void write(ostream& out)const;

};

// self funded class
class selffunded : public daleng {
private:
	
	float extscholarship;
	string paymethod;

public:
	selffunded(string n = "", string boo = "", string dis = "", float t = 0.0, int d = 0, int m = 0, int y = 0, string comp = "", string loc = "", int dur = 0, float xs = 0.0, string p = "");
	void read(istream& in);
	void write(ostream& out)const;
};

class node {
	friend class list;    // list can access node's private members
private:
	daleng* data;           // this is the data stored in a node
	node* next;       // pointer to the next node in the list
	node* prev;       // pointer to the previous node in the list
public:
	node(daleng* x);       // Constructor for node with pointer to daleng
	~node();               // Destructor to delete the node's data
};

class list {
private:
	node* start;      // pointer to node at the start of the list
	node* tail;       // pointer to the node at the end of the list
	int count;         // number of nodes in the list
	//helper functions for quicksort
	void swap(daleng*& a, daleng*& b);
	node* partition(node* low, node* high);
	void quickSortHelper(node* low, node* high);

public:
	list(void);                                 // constructor of an empty list
	~list();
	void store(daleng* x);                     //to add items to the data structure
	void retrieve(const string& b00);          // to search for a specific item using B00 number
	void removeByB00(const string& b00);		       // to remove a record from the data structure
	int size(void) const;					  // return count
	bool empty(void) const;					  // check for an empty list
	void write(ostream& out) const;          // send the stored data to out
	void clear(void);                        // to empty the data structure
	void sort(void);
};
#endif