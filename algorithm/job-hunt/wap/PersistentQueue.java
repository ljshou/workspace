//package jp.co.wap.exam;

import java.util.NoSuchElementException;

/**
 * The Queue class represents an immutable first-in-first-out(FIFO) 
 * queue of objects
 * O(1) amortized enqueue and dequeue operation; 
 * always thread safe;
 */
public class PersistentQueue<E> {
	private final SList<E> front;
	private final SList<E> rear;
	/**
	 * requires default constructor
	 */
	public PersistentQueue() {
		//both lists are initially emtpy
		//loop inviarant: front is empty when and only when rear is also empty
		front = new SList<E>();
		rear = new SList<E>();
	}

	private PersistentQueue(SList<E> front, SList<E> rear) {
		//loop inviarant: front is empty when and only when rear is also empty
		if (front.isEmpty() && !rear.isEmpty()) {
			this.front = rear.reverse();
			this.rear = new SList<E>();
		}
		else {
			this.front = front;	
			this.rear = rear;
		}
	}

	/**
     * Returns the queue that adds an item into the tail of this queue without modifying this queue
	 * <pre>  
	 * e.g.
	 *   When this queue represents the queue(2, 1, 2, 2, 6) and we enqueue the value 4 into 
	 *   this queue, this method returns a new queue (2, 1, 2, 2, 6, 4) and this object
	 *   still represents the queue (2, 1, 2, 2, 6).
	 * </pre>
	 *   if the element e is null, throws IllegalArgumentException.
	 *   @param e
	 *   @return 
	 *   @throws IllegalArgumentException
	 */
	public PersistentQueue<E> enqueue(E e){
		//TODO: implement this method
		if (e == null) {
			throw new IllegalArgumentException();
		}
		return new PersistentQueue<E>(front, rear.addHead(e));
	}

	/**
	 * Returns the queue that remove the object at the head of this queue without modifying this queue
	 * <pre>
	 *  e.g.
	 *   When this queue represents the queue (7, 1, 3, 3, 5, 1),
	 *   this method returns a new queue (1, 3, 3, 5, 1)
	 *   and this object still represents the queue (7, 1, 3, 3, 5, 1)
	 * </pre>
	 * If this queue is empty, throws java.util.NoSuchElementException.
	 * @return 
	 * @throws java.util.NoSuchElementException
	 */
	public PersistentQueue<E> dequeue() {
		if (isEmpty()) { 
			assert (front.size() + rear.size() == 0);
			throw new java.util.NoSuchElementException();
		}

		return new PersistentQueue<E>(front.removeHead(), rear);
	}

	/**
	 * Looks at the object which is the head of this queue without removing it from the queue
	 * <pre>
	 *   When this queue represents the queue (7, 1, 3, 3, 5, 1),
	 *   this method returns 7 and this object still represents the queue (7, 1, 3, 3, 5, 1)
	 * </pre>
	 * If the queue is empty, throws java.util.NoSuchElementException
	 * @return 
	 * @throws java.util.NoSuchElementException
	 */
	public E peek() {
		if (isEmpty()) { 
			assert (front.size() + rear.size() == 0);
			throw new java.util.NoSuchElementException();
		}

		return front.getHead();
	}

	/**
	 * Returns the number of objects in this queue
	 * @return 
	 */
	public int size() {
		//TODO: implement this method
		return front.size() + rear.size();
	}

	public boolean isEmpty() {
		//queue is empty, when front is empty
		return front.isEmpty();
	}

	/*
	 * Functional single list.
	 */
	class SList<T> {
		//treate base class as empty
		public int size() {
			return 0;
		}	
		//treate base class as empty
		public boolean isEmpty() {
			return true;
		}

		//empty list has no head
		public T getHead() {
			throw new java.util.NoSuchElementException();
		}

		//empty list has no tail 
		public SList<T> getTail() {
			throw new java.util.NoSuchElementException();
		}

		//empty list has no head
		public SList<T> removeHead() {
			throw new java.util.NoSuchElementException();
		}

		//empty become nonempty
		public SList<T> addHead(T t) {
			return new NonEmptyList<T>(t, this);
		}

		//reverse of an empty list is itself
		public SList<T> reverse() {
			return new SList<T>();
		}
	}

	class NonEmptyList<T> extends SList<T> {
		private final T head;
		private final SList<T> tail;
		private final int size;

		public NonEmptyList(T head, SList<T> tail) {
			if (head == null || tail == null) {
				throw new IllegalArgumentException();
			}
			this.head = head;
			this.tail = tail;
			size = 1 + tail.size();
		}

		public int size() {
			return size;
		}

		public boolean isEmpty() {
			return false;
		}

		public T getHead() {
			return head;
		}

		public SList<T> getTail() {
			return tail;
		}

		public SList<T> addHead(T t) {
			if (t == null)  {
				throw new IllegalArgumentException();
			}
			return new NonEmptyList<T>(t, this);
		}

		public SList<T> removeHead() {
			return tail;
		}

		public SList<T> reverse() {
			SList<T> rev = new SList<T>();
			SList<T> it = this;

			int mysize = size();
			for (int i = 0; i < mysize; i++) {
				rev = rev.addHead(it.getHead());
				it = it.getTail();
			}
			return rev;
		}
	}
public static void main(String[] args){
  PersistentQueue<Integer> p = new PersistentQueue<Integer>();
		int num = 0;
		int max = 10000000;
		long current = System.currentTimeMillis();
		while (++num <= max) {
			int value = (int) (Math.random() * 100);
			p = p.enqueue(value);
		}
		System.out.println("enqueue time:"
		 + (System.currentTimeMillis() - current));
		current = System.currentTimeMillis();
		while (--num > 0) {
			p = p.dequeue();
		}
		 System.out.println("dequeue time:"
		 + (System.currentTimeMillis() - current));
}
}


