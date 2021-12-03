#include<iostream>
#include"datamodel.h"
#include<vector>

using namespace std;

vector<Product>allProducts = {

    Product(1,"Sugar",42),
    Product(2,"Chana-Dall",80),
    Product(1,"Dall",100),
    Product(1,"Rice",42),
    Product(1,"Atta",27),
    Product(1,"Mustard-Oil",200)

    
    };


Product* chooseProduct(){

	//Display the list of products
	string productList;
	cout<<"Available Products "<<endl;

	for(auto product : allProducts){
		productList.append(product.getDisplayName());
	}
	cout << productList <<endl;

	cout<<"----------------"<<endl;
	string choice;
	cin>>choice;

	for(int i=0; i< allProducts.size(); i++){
		if(allProducts[i].getShortName()==choice){
			return &allProducts[i];
		}
	}
	cout<<"Product not found!" <<endl;
	return NULL;
}

bool checkout(Cart &cart){
	if(cart.isEmpty()){
		return false;
	}

	int total = cart.getTotal();
	cout<<"Pay in Cash";

	int paid;
	cin>> paid;

	if(paid>=total){
		cout<<"Change " <<paid - total << endl;
		cout<<"Thank you for shopping!";
		return true;
	}

	else{
		cout<<"Not enough cash!";
		return false;
	}

}

int main(){

	char action;
	Cart cart;

	while(true){
		cout<<"Select an action -  (a)dd item, (v)iew cart, (c)heckout" <<endl;
		cin>> action;

		if(action=='a'){ 
			Product * product = chooseProduct();
			if(product!=NULL){
				cout<<"Added to the Cart "<<product->getDisplayName() <<endl;
				cart.addProduct(*product);
			}

		}
		else if(action=='v'){
			
			cout<<"------------------" <<endl;
			cout << cart.viewCart();
			cout<<"------------------"<<endl;
		}
		else{
			
			cart.viewCart();
			if(checkout(cart)){
				break;
			}
		}
	}

	return 0;
