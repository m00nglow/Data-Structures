cmake_minimum_required(VERSION 3.31)
project(Data-structures)

set(CMAKE_CXX_STANDARD 20)

add_executable(LinkedListDemo LinkedList/inClassList.cpp)
add_executable(QueuesDemo Queues/InClass.cpp)
add_executable(LinkedQueuesDemo Queues/InClass2.cpp)
add_executable(ArrayStack Stacks/ArrayStack.cpp)
add_executable(ParenthesisBalance Stacks/ParenthesisBalance.cpp)
add_executable(printReverse Recursion/printReverse.cpp)
add_executable(Quiz2 Quizzes/Quiz2.cpp)
add_executable(StackNQueueQuiz Quizzes/StackNQueueQuiz/testSimulation.cpp)
add_executable(BinaryTree "Binary Trees/BinaryTree.cpp")
add_executable(BinarySearchTree "Binary Trees/BinarySearchTree.cpp")
add_executable(ParticipationQueues ParticipationQueues/queueArrayQues.cpp)
add_executable(Project1Execute Project1Calculator/Project1Calculator.cpp)
add_executable(AVLTree "AVL Trees/AVLTree.cpp")
add_executable(Heap Heaps/Heap.cpp)
add_executable(adjMatrixGraph Graphs/adjMatrixGraph.cpp)
add_executable(GraphBFS GraphBFS/GraphBFS.cpp)
add_executable(GraphDFS GraphDFS/GraphDFS.cpp)
add_executable(Hashtable "Hash Tables/hashtable.cpp")
