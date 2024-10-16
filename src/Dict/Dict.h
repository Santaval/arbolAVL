// Copyright 2024 Randall Araya. ECCI-UCR. CC BY 4.0
#pragma once

class Dict {
 public:
  // Pure virtual method to insert an element
  /**
   * Requires: An integer element.
   * Effects: Inserts the element into the dictionary.
   * Modifies: The structure of the dictionary.
   */
  virtual void insert(int element) = 0;

  // Pure virtual method to check if a element is in the dictionary
  /**
   * Requires: An integer element.
   * Effects: Checks if the element is present in the dictionary.
   * Modifies: Nothing.
   */
  virtual bool contains(int element) = 0;

  // Pure virtual method to remove a element from the dictionary
  /**
   * Requires: An integer element.
   * Effects: Removes the element from the dictionary if found.
   * Modifies: The structure of the dictionary.
   */
  virtual void erase(int element) = 0;

  // Virtual destructor
  /**
   * Requires: Nothing.
   * Effects: Safely destroys the dictionary object.
   * Modifies: The memory used by the dictionary.
   */
  virtual ~Dict() = default;
};

