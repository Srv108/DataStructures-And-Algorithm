class Node{
    constructor (data) {
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}
class LinkedList{
    
    constructor (){
        this.head = null;
        this.tail = null;
        this.prev = null;
    }

    getHead(){
        // linked list is empty
        if(this.head == null) return undefined;
        else return this.head.data;
    }

    getTail(){
        if(this.tail == null) return undefined;
        else return this.tail.data;
    }

    removeAtHead(){
        // if linked list is empty
        if(this.head == null) return;
        else{
            const newHead = this.head.next;
            this.head.next = null;
            newHead.prev = null;
            this.head = newHead;
            // if head is null then update the tail also
            
            if(this.head == null) this.tail = null;
        }
    }

    removeAtTail(){
        // linked list is empty
        if(this.head == null) return;
        else{
            const prevTail = this.tail.prev;
            prevTail.next = null;
            this.tail = prevTail;
        }
    }

    addAtHead(data){
        // if linked list is empty
        if(this.head == null){
            const newHead = new Node(data);
            this.head = newHead;
            this.tail = newHead;
            this.prev = newHead;
        }else{
            const newHead = new Node(data);
            newHead.next = this.head;
            this.head.prev = newHead;
            this.head = newHead;
        }
    }
    addAtTail(data){
        // linked list is empty
        if(this.head == null){
            const newHead = new Node(data);
            this.head = newHead;
            this.tail = newHead;
            this.prev = newHead;
        }else{
            const newTail = new Node(data);
            this.tail.next = newTail;
            newHead.prev = this.tail;
            this.tail = newTail;
        }
    }

    isEmpty(){
        if(this.head == null) return true;
        else return false;
    }
}

class Queue{
    constructor (){
        this.ll = new LinkedList();
    }

    enqueue(data){
        this.ll.addAtTail(data);
    }

    front(){
        return this.ll.getHead();
    }

    back(){
        return this.ll.getTail();
    }
    dequeue(){
        this.ll.removeAtHead();
    }
    isEmpty(){
        return this.ll.isEmpty();
    }

}


const q = new Queue();
q.enqueue(10);
q.enqueue(20);
q.enqueue(30);
q.enqueue(40);
q.enqueue(50);

console.log(q.front());
console.log(q.back());

q.dequeue();
console.log(q.front());
q.dequeue();
q.dequeue();
q.dequeue();
console.log(q.front());
q.dequeue();
console.log(q.front());
console.log(q.isEmpty());
