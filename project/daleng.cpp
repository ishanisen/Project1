#include "daleng.h"

// implementation of date

date::date(int d, int m, int y) : day (d), month (m), year (y)
{
}


void date::read(istream& in)
{
	char temp;
	cout << "Enter Graduation Date (dd/mm/yyyy): ";
	in >>  day >> temp >> month >> temp >> year;
}

void date::write(ostream& out) const
{
	out << "(" << day << "/" << month << "/" << year << ")";
}

//implementation of coop
coop::coop(string c, string l, int m) {
	companyname = c;
	location = l;
	duration = m;
}

void coop::read(istream& in) {
	cout << "--------------------------------------" << endl;
	cout << "Co-op Information" << endl;
	cout << "Enter company name: ";
	in >> companyname; cout << endl;
	cout << "Enter location: ";
	in >> location; cout << endl;
	cout << "Enter duration(months): ";
	in >> duration; cout << endl;
}


void coop::write(ostream& out)const {
	out << "company name: " << companyname << endl;
	out << "location: " << location << endl;
	out << "duration: " << duration << " months" << endl;
}

// implementation of daleng

daleng::daleng(string n, string boo, string dis, float t, int d, int m, int y, string comp, string loc, int dur) : name(n), b00number(boo), discipline(dis), tuition(t), grad_date(d, m, y), workterm(comp, loc, dur)
{
}
daleng::~daleng() {
	list clear();
	
}

void daleng::read(istream& in)
{	
	cout << "Enter student name: ";
	getline(in, name);  cout << endl;
	cout << "Enter B00 number: ";
	in >> b00number; cout << endl;
	cout << "Enter their discipline: ";
	in >> discipline;cout << endl;
	cout << "Enter tuition amount: ";
	in >> tuition; cout << endl;
	
	grad_date.read(in);
	workterm.read(in);
}
void daleng::write(ostream& out) const
{
	out << "Name: " << name << endl;
	out << "B00 number: " << b00number << endl;
	out << "Discipline : " << discipline << endl;
	out << "Tuition: " << tuition << endl;
	grad_date.write(out);
	out << endl;
	workterm.write(out);

}


bool daleng::operator ==(const daleng& other) const
{
	return this->b00number == other.b00number;

}

ostream& operator<<(ostream& out, const daleng& d) {
	d.write(out);
	return out;
}

//implemmentation of scholar
scholar::scholar (string n, string boo, string dis, float t, int d, int m, int y, string comp, string loc, int dur, string sn, float a) :daleng(n, boo, dis, t, d, m, y, comp, loc, dur) {
	sname = sn;
	amount = a;
}


void scholar::read(istream& in) {
	daleng::read(in);
	cout << "Scholarship name: ";
	in >> sname;
	cout << "Amount: ";
	in >> amount;
}


void scholar::write(ostream& out)const {
	daleng::write(out);
	cout << "Scholarship name: " << sname << endl << "Amount: " << amount << endl;
}

// implementation of self funded

selffunded::selffunded(string n, string boo, string dis, float t, int d, int m, int y, string comp, string loc, int dur, float xs, string p) : daleng(n, boo, dis, t, d, m, y, comp, loc, dur),  extscholarship(xs), paymethod(p)
{

}

void selffunded::read(istream& in)
{
	daleng::read(in);

	cout << "Enter amount of external funds/scholarship recieved: ";
	in >> extscholarship; 
	cout << endl;
	cout << "Payment method: ";
	in >> paymethod; 
	cout << endl;
}

void selffunded::write(ostream& out)const
{
	daleng::write(out);
	cout << "External Scholarship Amount: " << extscholarship << endl;
	cout << "Payment Method: " << paymethod << endl;

}

//implementaion of doubly linked list 

node::node(daleng* x) : data(x), prev(NULL), next(NULL) {
}

node::~node() {
	delete data; // corrected destructor
}

list::list(void) {
	start = NULL;
	tail = NULL;
	count = 0;
}

list::~list() {
	clear(); // Delete all nodes and their data
}

void list::store(daleng* x)
{
	node* ptr = new node(x); // Create a new node with the pointer

	// Special case: if list is empty, initialize start and tail to this node
	if (empty()) {
		start = tail = ptr;
	}
	// General case: append the node to the end of the list
	else {
		tail->next = ptr;
		ptr->prev = tail;
		tail = ptr;
	}
	count++;
}



int list::size(void) const           // return count
{
	return(count);
}
bool list::empty(void) const         // check for an empty list
{
	return (count == 0);
}

void list::write(ostream& out) const    // send the stored data to out
{
	if (empty()) {
		out << "The student database is empty.\n";
		return;
	}


	node* ptr = start;
	int record_num = 1;


	out << "========== STUDENT RECORDS ==========\n\n";


	while (ptr != nullptr) {
		out << "---- Record #" << record_num++ << " ----\n";


		// Use virtual function to write correct subclass data
		ptr->data->write(out);


		out << "\n-----------------------------\n\n";
		ptr = ptr->next;
	}


	out << "Total records: " << count << "\n";
	out << "======================================\n";
}


void list::removeByB00(const string& b00) {
	if (start == nullptr) {
		cout << "The student database is empty. No records to remove.\n";
		return;
	}

	node* ptr = start;

	while (ptr != nullptr) {
		if (ptr->data->b00number == b00) {
			// Case 1: Head
			if (ptr == start) {
				start = ptr->next;
				if (start != nullptr) start->prev = nullptr;
				else tail = nullptr;
			}
			// Case 2: Tail
			else if (ptr == tail) {
				tail = ptr->prev;
				if (tail != nullptr) tail->next = nullptr;
				else start = nullptr;
			}
			// Case 3: Middle
			else {
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}

			cout << "Student with B00 number " << b00 << " removed successfully!\n";
			delete ptr->data;
			delete ptr;
			count--;
			return;
		}
		ptr = ptr->next;
	}

	cout << "Error: Student with B00 number " << b00 << " not found!\n";
}

void list::clear() {
	node* ptr = start;

	while (ptr != NULL) {
		node* temp = ptr;
		ptr = ptr->next;
		delete temp; // This will call node::~node(), which deletes data
	}

	start = nullptr;
	tail = nullptr;
	count = 0;
	cout << "The records have been cleared!" << endl;
}

node* list::partition(node* low, node* high) {
	daleng* pivot = high->data; // Pivot is the last element (pointer)

	node* i = low->prev; // Pointer for smaller elements

	for (node* j = low; j != high; j = j->next) {
		if (j->data->b00number < pivot->b00number) { // Compare using b00number
			i = (i == nullptr) ? low : i->next; // Move i forward safely
			swap(i->data, j->data); // Swap pointers, not objects
		}
	}

	i = (i == nullptr) ? low : i->next; // Move i forward for final swap
	swap(i->data, high->data); // Place pivot in correct position
	return i;
}


void list::quickSortHelper(node* low, node* high) {
	if (low != nullptr && high != nullptr && low != high && low != high->next) {
		node* pivot = partition(low, high);
		quickSortHelper(low, pivot->prev);  // Sort left part
		quickSortHelper(pivot->next, high); // Sort right part
	}
}

void list::sort() {
	if (start == nullptr) return;

	node* last = start;
	while (last->next != nullptr) {
		last = last->next; // Find the last node
	}

	quickSortHelper(start, last);
}

void list::swap(daleng*& a, daleng*& b) {
	daleng* temp = a;
	a = b;
	b = temp;
}

void list::retrieve(const string& b00) {
	if (start == nullptr) {
		cout << "The student database is empty.\n";
		return;
	}
	node* ptr = start; // Start from the head of the list

	while (ptr != nullptr) {
		if (ptr->data->b00number == b00) { // Compare B00 number
			cout << "Student Record Found:\n";
			ptr->data->write(cout);
			return;
		}
		ptr = ptr->next; // Move to the next node
	}

	// If we reach here, no matching record was found
	cout << "Student with B00 Number " << b00 << " not found.\n";
}