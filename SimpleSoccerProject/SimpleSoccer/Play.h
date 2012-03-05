#pragma once

class Play
{
	private:
		int weight; // weight of 0 = neutral, < 0 = fails often, > 0 successful often

	public:
		Play(void);
		~Play(void);
};
