#include "unittests.h"
#include "queues.h"
#include <iostream>

Test_Registrar<QueueTests> QueueTests::registrar;

bool QueueTests::LLsingleElementTest()
{
	LinkedListQueue<int> q;
	VERIFY_TRUE(q.push(1));
	VERIFY_EQ(q.front(), 1);
	VERIFY_EQ(q.back(), 1);
	VERIFY_TRUE(q.pop());
	VERIFY_FALSE(q.pop());
	VERIFY_TRUE(q.push(2));
	VERIFY_EQ(q.front(), 2);

	return true;
}

bool QueueTests::LLorderingTest()
{
	LinkedListQueue<int> q;
	VERIFY_TRUE(q.push(1));
	VERIFY_TRUE(q.push(2));
	VERIFY_TRUE(q.push(3));
	VERIFY_EQ(q.front(), 1);
	VERIFY_EQ(q.back(), 3);
	VERIFY_TRUE(q.pop());
	VERIFY_EQ(q.front(), 2);
	VERIFY_EQ(q.back(), 3);
	VERIFY_TRUE(q.pop());
	VERIFY_EQ(q.front(), 3);
	VERIFY_EQ(q.back(), 3);

	return true;
}

bool QueueTests::VECsingleElementTest()
{
	VectorQueue<int> q;
	VERIFY_TRUE(q.push(1));
	VERIFY_EQ(q.front(), 1);
	VERIFY_EQ(q.back(), 1);
	VERIFY_TRUE(q.pop());
	VERIFY_FALSE(q.pop());
	VERIFY_TRUE(q.push(2));
	VERIFY_EQ(q.front(), 2);

	return true;
}

bool QueueTests::VECorderingTest()
{
	VectorQueue<int> q;
	VERIFY_TRUE(q.push(1));
	VERIFY_TRUE(q.push(2));
	VERIFY_TRUE(q.push(3));
	VERIFY_EQ(q.front(), 1);
	VERIFY_EQ(q.back(), 3);
	VERIFY_TRUE(q.pop());
	VERIFY_EQ(q.front(), 2);
	VERIFY_EQ(q.back(), 3);
	VERIFY_TRUE(q.pop());
	VERIFY_EQ(q.front(), 3);
	VERIFY_EQ(q.back(), 3);

	return true;
}

bool QueueTests::ARRsingleElementTest()
{
	ArrayQueue<int> q;
	VERIFY_TRUE(q.push(1));
	VERIFY_EQ(q.front(), 1);
	VERIFY_EQ(q.back(), 1);
	VERIFY_TRUE(q.pop());
	VERIFY_FALSE(q.pop());
	VERIFY_TRUE(q.push(2));
	VERIFY_EQ(q.front(), 2);

	return true;
}

bool QueueTests::ARRorderingTest()
{
	ArrayQueue<int> q;
	VERIFY_TRUE(q.push(1));
	VERIFY_TRUE(q.push(2));
	VERIFY_TRUE(q.push(3));
	VERIFY_EQ(q.front(), 1);
	VERIFY_EQ(q.back(), 3);
	VERIFY_TRUE(q.pop());
	VERIFY_EQ(q.front(), 2);
	VERIFY_EQ(q.back(), 3);
	VERIFY_TRUE(q.pop());
	VERIFY_EQ(q.front(), 3);
	VERIFY_EQ(q.back(), 3);

	return true;
}
bool QueueTests::ARRoverflowTest()
{
	ArrayQueue<int> q;
	VERIFY_TRUE(q.push(1));
	VERIFY_TRUE(q.push(2));
	VERIFY_TRUE(q.pop());
	VERIFY_TRUE(q.pop());
	VERIFY_FALSE(q.pop());
	VERIFY_TRUE(q.push(1));
	VERIFY_TRUE(q.push(2));
	VERIFY_TRUE(q.push(3));
	VERIFY_TRUE(q.push(4));
	VERIFY_TRUE(q.push(5));
	VERIFY_EQ(q.front(), 1);
	VERIFY_EQ(q.back(), 5);
	VERIFY_TRUE(q.pop());
	VERIFY_EQ(q.front(), 2);
	VERIFY_EQ(q.back(), 5);
	VERIFY_TRUE(q.pop());
	VERIFY_EQ(q.front(), 3);
	VERIFY_EQ(q.back(), 5);
	VERIFY_TRUE(q.pop());
	VERIFY_EQ(q.front(), 4);
	VERIFY_EQ(q.back(), 5);
	VERIFY_TRUE(q.pop());
	VERIFY_EQ(q.front(), 5);
	VERIFY_EQ(q.back(), 5);
	VERIFY_TRUE(q.pop());
	VERIFY_FALSE(q.pop());

	return true;
}
