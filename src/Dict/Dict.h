// Copyright 2024 Randall Araya. ECCI-UCR. CC BY 4.0
#ifndef DICT_HPP
#define DICT_HPP

class Dict {
 public:
  // Pure virtual method to insert a value
  /**
   * Requires: An integer value.
   * Effects: Inserts the value into the dictionary.
   * Modifies: The structure of the dictionary.
   */
  virtual void insert(int value) = 0;

  // Pure virtual method to check if a value is in the dictionary
  /**
   * Requires: An integer value.
   * Effects: Checks if the value is present in the dictionary.
   * Modifies: Nothing.
   */
  virtual bool contains(int value) = 0;

  // Pure virtual method to remove a value from the dictionary
  /**
   * Requires: An integer value.
   * Effects: Removes the value from the dictionary if found.
   * Modifies: The structure of the dictionary.
   */
  virtual void erase(int value) = 0;

  // Virtual destructor
  /**
   * Requires: Nothing.
   * Effects: Safely destroys the dictionary object.
   * Modifies: The memory used by the dictionary.
   */
  virtual ~Dict() = default;
};

#endif // DICT_HPP
