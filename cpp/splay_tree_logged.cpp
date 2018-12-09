/*
Top-down splay tree heavily modeled on C implementation of D. Sleator, from
https://www.link.cs.cmu.edu/link/ftp-site/splaying/top-down-splay.c
*/

#include "splay_tree.h"
#include "splay_tree_logged.h"
#include <iostream>

// Define the log object
MemLog *SplayTreeLogged::log_ = new MemLog();

void update_greatest_depth(MemLog *log, uint32_t dep) {
  log->set_greatest_depth((dep > log->greatest_depth()) ? dep : log->greatest_depth());
}

/*
SplayTree::SplayTree(const SplayTree &obj) {
  root_ = obj.root_;
}
*/

// Logged splay tree constructors
SplayTreeLogged::SplayTreeLogged() {
  root_ = nullptr;
  log_->incr_size(sizeof(SplayTree)); // Set initial size to BARE splay tree.
}


SplayTreeLogged::SplayTreeLogged(SplayNode *root) {
  root_ = root;
  log_->incr_size(sizeof(SplayTree)); // Set initial size to BARE splay tree.
}

/*
void SplayTreeLogged::splay(int search_key) {
  SplayTree::splay(search_key);
  update_greatest_depth(log_, this->depth());
}
*/


uint32_t SplayTreeLogged::depth() {
  if (root_ == nullptr) {
    return 0;
  }
  return root_->height();

}

SplayNode* SplayTreeLogged::search(int search_key) {
  SplayNode *node = SplayTree::search(search_key);
  update_greatest_depth(log_, this->depth());
  return node;
}


bool SplayTreeLogged::insert(int search_key, int new_value) {
  bool node_inserted = SplayTree::insert(search_key, new_value);
  if (node_inserted) {
    log_->incr_size(sizeof(SplayNode));
  }
  std::cout << "I'm inserting!" << std::endl;
  update_greatest_depth(log_, this->depth());
  return node_inserted;
}


bool SplayTreeLogged::remove(int search_key) {
  bool node_removed = SplayTree::remove(search_key);
  if (node_removed) {
    log_->incr_size(-int(sizeof(SplayNode)));
  }
  update_greatest_depth(log_, this->depth());
  return node_removed;
}


void SplayTreeLogged::check()
{
  //TOOD
  return;
}
