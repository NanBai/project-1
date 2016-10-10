// author: Nan Bai
// catalog.hpp
// CSUF CPSC 131, Fall 2016, Project 1
//
// Classes that define a catalog of supermarket products.

#pragma once

#include <stdexcept>
#include <string>

// A product represents one particular kind of product, such as apples
// or cereal.
class Product {
public:
  // Create a product with a given code, name, and price.
  //
  // code is intended to be a UPC code (bar code) or PLU code in a
  // string.
  //
  // name may be any string.
  //
  // price is in units of dollars. It must be positive, or else this
  // function throws std::invalid_argument.
  Product(const std::string& inCode,
          const std::string& inName,
          double inPrice) {
    // TODO: implement this function properly
    if(inPrice <= 0) throw std::invalid_argument("wrong price!");
    code = inCode;
    name = inName;
    price = inPrice;
  }
  
  Product(){
    code = "0";
    name = "0";
    price = 0;
  }

  ~Product() { }

  // Accessors.
  const std::string& getCode() const { return code; }
  const std::string& getName() const { return name; }
  double getPrice() const { return price; }
  
private:
  std::string code, name;
  double price;
};

// A catalog represents a collection of all of the products available
// at a store.
class Catalog {
public:
  // Create a new catalog.
  //
  // maxProducts is the maximum number of products that can be
  // stored. It must be positive, or else this function throws
  // std::invalid_argument.
  Catalog(int inMaxProducts) {
    // TODO: implement this function properly
    if (inMaxProducts <= 0)
    throw std::invalid_argument("wrong max product number!");
    maxProducts = inMaxProducts;
    product = new Product[maxProducts];
    numberProducts = 0;
  }
  
  ~Catalog() {
    // TODO: implement this function properly
    if (maxProducts <= 0)
    throw std::invalid_argument("wrong max product number!");
    delete []product;
  }

  // Accessors.
  int getMaxProducts() const {
    // TODO: implement this function properly
    if (maxProducts <= 0)
    throw std::overflow_error("max product number error!");
    return maxProducts;
  }
  
  int getNumProducts() const {
    // TODO: implement this function properly
    if (numberProducts > maxProducts)
    throw std::overflow_error("product number error!");
    return numberProducts;
  }

  // Return true when the catalog cannot fit any more products.
  bool isFull() const {
    // TODO: implement this function properly
    if (maxProducts <= 0)
    throw std::overflow_error("max product number error!");
    return (numberProducts >= maxProducts);
  }

  // Add a new product to the catalog with a given code and name.
  //
  // code, name, and price have the same meaning as in a Product. If
  // price is invalid, throw std::invalid_argument.
  //
  // If this catalog is already full, throw overflow_error.
  //
  // Code must be different from all the product codes already in the
  // database. If it's not, throw std::invalid_argument.
  void addProduct(const std::string& inCode,
                  const std::string& inName,
                  double inPrice) {
    // TODO: implement this function properly
    if (isFull()) throw std::overflow_error("catalog is full!");
    for (int i=0; i<=numberProducts; i++){
      if (product[i].getCode() == inCode)
      throw std::invalid_argument("code exits!");
    }   
    product[numberProducts] = Product(inCode,inName,inPrice);
    numberProducts++;
  }

  // Find a product by its code.
  //
  // code is a product code.
  //
  // Returns a const reference to the product with the matching code.
  //
  // Throw std::invalid_argument if no product with that code exists
  // in the catalog.
  const Product& findCode(const std::string& searchCode) const {
    // TODO: implement this function properly
    for (int i=0;i<=numberProducts;i++){
      if (product[i].getCode() == searchCode)
      {return product[i];}
    }
    throw std::invalid_argument("no product with that code exists");
  }

private:
  // TODO: add data members
  int maxProducts, numberProducts;
  Product *product;
};
