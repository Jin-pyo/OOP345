// Workshop 8 - Smart Pointers
// 2019/11 - Cornel


#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace sdds {
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (auto i = 0u; i < desc.size(); i++)
		{
			for (auto j = 0u; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					Product *product = new Product(desc[i].desc,price[j].price);
					product->validate();
					priceList += product;
					delete product;

				}
			}
		}


		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price) {
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers
		for (auto i = 0u; i < desc.size(); i++)
		{
			for (auto j = 0u; j < price.size(); j++)
			{
				if (desc[i].code == price[j].code)
				{
					std::unique_ptr<Product> product(new Product(desc[i].desc, price[j].price));
					product->validate();
					priceList += std::move(product);
					//priceList += product;
					//If you do "move" in List.h
					

				}
			}
		}


		return priceList;
	}
}