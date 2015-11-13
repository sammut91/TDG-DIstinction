#pragma once
class Cost
{
public:
	Cost();
	~Cost();

	int GetCost(){ return m_Cost; }
	int GetRefund(){ return (m_Cost*0.6); }

	void SetCost(float amount);

private:
	int m_Cost;
};

