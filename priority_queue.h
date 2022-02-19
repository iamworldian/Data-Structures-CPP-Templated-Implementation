#pragma once
#include <exception>

template<class T>
	class PQ{
		private:
			int last;
			vector<T> heap;
			
			inline int parent(int idx){return (idx - 1) / 2;}
			inline int leftChild(int idx){return idx * 2;}
			inline int rightChild(int idx){return idx * 2 + 1;}
			
			inline int hasParent(int idx){return parent(idx) >= 0;}
			inline int hasLeftChild(int idx){return leftChild(idx) < last;}
			inline int hasRightChild(int idx){return rightChild(idx) < last;}
		public:	
			PQ(int size){
				heap.resize(size);
				last = 0;
			}
			PQ(){
				heap.resize(10000);
				last = 0;
			}
			
			inline bool isEmpty(){return last > 0;}
			
			void push(T val){
				heap[last++] = val;
				heapUp();
				cout << last << endl;
			}
			
			T pop(){
				T ret = heap[0];
				heap[0] = heap[last - 1];
				last--;
				heapDown();
				return ret;
			}
			
			void heapUp(){
				int l = last - 1;
				while(hasParent(l) && heap[parent(l)] < heap[l]){
					swap(heap[l] , heap[parent(l)]);
					l = parent(l);
				}
			}
			
			void heapDown(){
				
				int now = 0;
				while(hasLeftChild(now)){
					int smallChild = leftChild(now);
					if(hasRightChild(now) && heap[smallChild] < heap[rightChild(now)]){
						smallChild = rightChild(now);
					}
					
					if(heap[now] < heap[smallChild]){
						swap(heap[now] , heap[smallChild]);
						now = smallChild;
					}else break;
				}
			}
	};
