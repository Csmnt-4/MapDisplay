#pragma once

class Seller
{
public:
	int strPoitionQuantity;
	int defPoitionQuantity;
	int aglPoitionQuantity;
	int vtlPoitionQuantity;
	int lukPoitionQuantity;

	int strPoitionPrice;
	int defPoitionPrice;
	int aglPoitionPrice;
	int vtlPoitionPrice;
	int lukPoitionPrice;

	int coins;

	Seller();

	int BuyPoition(int poition, Seller& seller);
	void Talk(Seller& seller);
};

