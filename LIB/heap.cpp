#include<bits/stdc++.h>

using namespace std;

class heap{
    vector<int> heap_arr;
    int end;

    void swap(int p1, int p2){
        int c = heap_arr[p1];
        heap_arr[p1] = heap_arr[p2];
        heap_arr[p2] = c;
    }

    void buble_up(int pos){
        int p;
        if(pos % 2 == 0) p = pos/2 - 1;
        else p = (pos-1)/2;
        if(heap_arr[p] < heap_arr[pos]) return;
        swap(p, pos);
        buble_up(p);
    }

    void buble_down(int pos){
        int l = 2*pos+1, r = 2*pos+2;
        if(heap_arr[l] < heap_arr[pos]) {swap(l, pos); buble_down(l);}
        else if(heap_arr[r] < heap_arr[pos]) {swap(r, pos); buble_down(r);}
        else return;
    }

    public:

    void add(int a){
        heap_arr.push_back(a);
        end = heap_arr.size()-1;
        buble_up(end);
    }

    void pop(){
        swap(0, end--);
        heap_arr.pop_back();
        buble_down(0);
    }

    int top(){return heap_arr[0];}

    void remove(int a){
        auto i = find(heap_arr.begin(), heap_arr.end(), a);
        int p = i - heap_arr.begin();
        swap(p, end--);
        heap_arr.pop_back();
        if(p > floor((p-1)/2)) buble_down(p);
        else buble_up(p);
    }
};

