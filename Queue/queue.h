/**
 *  @author       : Ankush Singhal [ankushsinghal1995@gmail.com]
 *  @date         : Monday, 4th January, 2021
 *  @description  : Header file for Queue Class
 *  @file         : queue.h
 */

#ifndef QUEUE_H
#define QUEUE_H

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wreturn-type"

#include <iostream>
#include <stdio.h>
#include <malloc.h>

#define kMaxQueueSize 5

template <class T>
class Queue
{
 private:
	// Array with fix size of kMaxQueueSize
	T array_[kMaxQueueSize];

	// Max size of the queue
	int max_size_;

	// front index of the queue where dequeue will happen
	int front_;

	// back index of the queue where enqueue will happen
	int back_;

 public:
	// Default Constructor
	Queue();

	// Enqueue function to push element in queue
	void enqueue(T value);

	// Dequeue function to remove element from queue
	T dequeue();

	// Function to check if queue is empty
	bool empty();

	// Function to check if queue is full
	bool full();

	// at function - Only to be used for Gtest validation
	T at(int index);
};

template <class T>
Queue<T>::Queue()
{
	max_size_ = kMaxQueueSize;
	front_ = 0;
	back_ = 0;
}

template <class T>
void Queue<T>::enqueue(T value)
{
	if (!full())
	{
		array_[back_] = value;
		back_ = (back_ + 1) % max_size_;
	}
}

template <class T>
T Queue<T>::dequeue()
{
	if (!empty())
	{
		T value = array_[front_];
		front_ = (front_ + 1) % max_size_;
		return value;
	}
}

template <class T>
bool Queue<T>::empty()
{
	if (front_ == back_)
	{
		return true;
	}
	return false;
}

template <class T>
bool Queue<T>::full()
{
	if (back_ == front_)
	{
		return false;
	}
	else if (back_ > front_)
	{
		if (back_ - front_ == max_size_ - 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if (front_ - back_ == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

template <class T>
T Queue<T>::at(int index)
{
	if (index < max_size_)
	{
		return array_[index];
	}
}

#pragma GCC diagnostic pop

#endif //QUEUE_H