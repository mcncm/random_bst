#ifndef DEPRECATED_TESTS_H_
#define DEPRECATED_TESTS_H_


void test_skip_list() {
  /*
  A very primitive test suite for the SkipList class. To compile, run
  $ g++ SkipList_test.cpp SkipList.cpp
  */
  SkipNode *n = new SkipNode(1, 10, 4);
  std::cout << "SkipNode level is " << n->level << ".\n";

  SkipList *list = new SkipList(16, 0.5);
  std::cout << "INT_MIN is " << INT_MAX << ".\n";


  //std::cout << list->header_->value << std::endl;
  //std::cout << list->header_->key << std::endl;
  SkipNode* nil_ptr = list->search(INT_MAX);

  if (nil_ptr == nullptr)
    std::cout << "Pointer is null." << std::endl;
  else
    std::cout << "Header value is " << nil_ptr->value << std::endl;

    //  std::cout << "Here are some random levels: "
    //  << list->random_level() << " "
    //  << list->random_level() << " "
    //  << list->random_level() << " "
    //  << list->random_level() << " "
    //  << list->random_level() << " "
    //  << list->random_level() << " "
    //  << list->random_level() << " "
    //  << list->random_level() << " "
    //  << list->random_level() << " "
    //  << list->random_level() << " "
    //  << list->random_level() << " "
    //  << list->random_level() << " "
    //  << list->random_level() << " "
    //  << list->random_level() << " "
    //  << list->random_level() << ". Does that distribution look right?"
    //  << std::endl;

  list->insert(2, 20);
  list->insert(4, 40);
  list->insert(3, 30);
  list->insert(1, 10);
  list->insert(5, 50);

  std::cout << "Value at key 3 is " << list->search(3)->value << std::endl;
  std::cout << "Value at key 2 is " << list->search(2)->value << std::endl;
  std::cout << "Value at key 4 is " << list->search(4)->value << std::endl;
  std::cout << "Value at key 1 is " << list->search(1)->value << std::endl;
  std::cout << "Value at key 5 is " << list->search(5)->value << std::endl;

  std::cout << "Level at key 3 is " << list->search(3)->level << std::endl;
  std::cout << "Level at key 2 is " << list->search(2)->level << std::endl;
  std::cout << "Level at key 4 is " << list->search(4)->level << std::endl;
  std::cout << "Level at key 1 is " << list->search(1)->level << std::endl;
  std::cout << "Level at key 5 is " << list->search(5)->level << std::endl;

  // Insert some new values
  list->insert(4, 400);
  list->insert(3, 300);
  list->insert(5, 500);
  list->insert(2, 200);
  list->insert(1, 100);

  std::cout << "Ok, now some values have been changed." << std::endl;
  std::cout << "Value at key 1 is " << list->search(1)->value << std::endl;
  std::cout << "Value at key 2 is " << list->search(2)->value << std::endl;
  std::cout << "Value at key 3 is " << list->search(3)->value << std::endl;
  std::cout << "Value at key 4 is " << list->search(4)->value << std::endl;
  std::cout << "Value at key 5 is " << list->search(5)->value << std::endl;

  // Delete some stuff
  list->remove(3);
  std::cout << "Ok, now some stuff has been deleted." << std::endl;
  //std::cout << "Level at key 3 is " << list->search(3)->level << std::endl;
  std::cout << "Level at key 2 is " << list->search(2)->level << std::endl;
  std::cout << "Level at key 4 is " << list->search(4)->level << std::endl;
  std::cout << "Level at key 1 is " << list->search(1)->level << std::endl;
  std::cout << "Level at key 5 is " << list->search(5)->level << std::endl;

  delete n;
  delete list;
}

#endif
