#ifndef __MY_QUEUE_TESTS__
#define __MY_QUEUE_TESTS__

#include <test_helpers.h>


class QueueTests final : public UnitTests
{
protected:
    void RunTests() final
    {
        ADD_TEST(QueueTests::LLsingleElementTest);
        ADD_TEST(QueueTests::LLorderingTest);
        ADD_TEST(QueueTests::VECsingleElementTest);
        ADD_TEST(QueueTests::VECorderingTest);
        ADD_TEST(QueueTests::ARRsingleElementTest);
        ADD_TEST(QueueTests::ARRorderingTest);
        ADD_TEST(QueueTests::ARRoverflowTest);
    }

private:
	static bool LLsingleElementTest();
    static bool LLorderingTest();
    static bool VECsingleElementTest();
    static bool VECorderingTest();
    static bool ARRsingleElementTest();
    static bool ARRorderingTest();
    static bool ARRoverflowTest();

    static Test_Registrar<QueueTests> registrar;
};

#endif