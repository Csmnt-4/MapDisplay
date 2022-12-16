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

	std::string greeting;

	int BuyPoition(int poition);
	void Talk();
	void Refill();
};

