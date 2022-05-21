作文以记之 ~ 最小栈
=
# 0、前言
本篇博客是力扣上 [155. 最小栈](https://leetcode.cn/problems/min-stack/) 题的题解，挺简单的，就是想写个博客！

具体博客内容可 [点击此处](https://blog.csdn.net/m0_51961114/article/details/124901654) 进行查看！
# 1、题目描述
![在这里插入图片描述](https://img-blog.csdnimg.cn/6b38aca451ef4f9997d895e80be7ff8f.png)


# 2、解题思路
## 2.1 方法1 ~ 利用stack
### 2.1.1 思路
此处就是利用两个栈去实现问题目标，有点像利用栈实现队列的感觉。具体可直接看下述代码！
### 2.1.2 程序代码


	class MinStack {
	public:
	    /** initialize your data structure here. */
	    MinStack() {
	
	    }
	    
	    void push(int val) {
	        tmp.push(val);
	        if(res.empty() || res.top() >= val)
	            res.push(val);
	    }
	    
	    void pop() {
	        if(res.top() == tmp.top())
	            res.pop();
	        tmp.pop();
	    }
	    
	    int top() {
	        return tmp.top();
	    }
	    
	    int getMin() {
	        return res.top();
	    }
	private:
	    stack<int> tmp;
	    stack<int> res;
	
	};
	
	/**
	 * Your MinStack object will be instantiated and called as such:
	 * MinStack* obj = new MinStack();
	 * obj->push(val);
	 * obj->pop();
	 * int param_3 = obj->top();
	 * int param_4 = obj->getMin();
	 */

## 2.2 方法2 ~ 利用vector
### 2.2.1 思路
此处思路就是将所有数据存入数组中，然后当输出最小值时对数组内数据进行遍历找出目标数据即可！
### 2.1.2 程序代码


	class MinStack {
	public:
	    MinStack() {
	        
	    }
	    
	    void push(int val) {
	        _data.push_back(val);
	    }
	    
	    void pop() {
	        if(!_data.empty())
	            _data.pop_back();
	    }
	    
	    int top() {
	        return _data[_data.size()-1];
	    }
	    
	    int getMin() {
	        int minnum = INT_MAX;
	        for(int& d:_data)
	            minnum = min(minnum,d);
	        return minnum;
	    }
	private:
	    vector<int> _data;
	};
	
	/**
	 * Your MinStack object will be instantiated and called as such:
	 * MinStack* obj = new MinStack();
	 * obj->push(val);
	 * obj->pop();
	 * int param_3 = obj->top();
	 * int param_4 = obj->getMin();
	 */

