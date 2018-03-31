#pragma once


class States
{
public:
	States();
	~States();
	void check(bool &isClosed);

private:
	char active_state;
	bool active;

};

