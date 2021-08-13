#include <iostream>

using namespace std;

class Queue{
private:

	int rear;
	int arr[1000001];

public:
	int front;
	int numTeams=1000001;

	Queue(){
 	front = -1;
 	rear = -1;
 	for(int i=0;i<numTeams;i++){
   	arr[i]=0;
 	}
	}
	bool isEmpty(){
    	if(front ==-1 && rear ==-1)
        	return true;
    	else
        	return false;
	}
	bool isFull(){
    	if(rear == numTeams-1)
        	return true;
    	else
        	return false;
	}
	void enqueue(int val){
    	if(isFull()){
        	cout << "Fila Cheia"<< endl;
        	return;
    	} else if(isEmpty()){
        	rear=0;
        	front =0;
       	arr[rear] = val;
    	} else{
        	rear++;
       	arr[rear]= val;
    	}
	}

	int dequeue(){

    	int x;
    	if(isEmpty()){
        	cout << "Fila vazia"<< endl;
        	return 0;
    	} else if( front == rear){
        	x=arr[front];
       	arr[front]=0;
        	rear = -1;
        	front = -1;
        	return x;
    	}else{
        	x=arr[front];
       	arr[front] =0;
        	front++;
        	return x;
    	}
	}
	int count(){
   	if(rear==-1 && front==-1)
        	return 0;
    	else
    	return rear-front+1;
	}
};


int teamBelongTo[1000001];

int main()
{
	int T = 1;
	int numTeams;
	Queue teamQueue[1001];

	while (cin >> numTeams, numTeams)
	{
    	for (int t = 0; t < numTeams; ++t)
    	{
       	while (!teamQueue[t].isEmpty())
            	teamQueue[t].dequeue();
        	int numElem;
        	cin >> numElem;
        	while (numElem--)
        	{
            	int elem;
            	cin >> elem;
            	teamBelongTo[elem] = t;
        	}
    	}

    	Queue combinedQueue;

    	cout << "Scenario #" << T++ << '\n';
    	string command;
    	while (cin >> command, command[0] != 'S')
    	{
        	if (command[0] == 'E')
        	{
            	int num;
            	cin >> num;
            	int team = teamBelongTo[num];
            	if (teamQueue[team].isEmpty())
            	{
                	combinedQueue.enqueue(team);
            	}

            	teamQueue[team].enqueue(num);
        	}
        	else
        	{
            	int team = combinedQueue.front;
            	cout << teamQueue[team].front << '\n';
            	teamQueue[team].dequeue();
            	if (teamQueue[team].isEmpty())
                	combinedQueue.dequeue();
        	}
    	}
    	cout << '\n';
	}
}
